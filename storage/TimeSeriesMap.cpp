//
// Created by 金祝光 on 2021/4/21.
//
#include "TimeSeriesMap.h"

namespace TSCached{

TimeSeriesMap::TimeSeriesMap(std::shared_ptr<TimerManager> timerManager):
pointNum_(0),
timeSeriesNum_(0),
timerManager_(timerManager)
{
    timerManager_->AddTimer(time(nullptr)+Config::purgeTimeSeriesTime,
            [this] { ClearExpiredTimeSeries(); });
}

//插入数据
void TimeSeriesMap::AppendPoint(const Point &point){
    RWLGuard guard(rwSpinLock_);
    std::string key = PointUtils::GetKey(point);
    assert(!key.empty());
    if (timeSeriesMap_.count(key)==0){
        //该时间序列不存在，新产生一个
        auto timeSeries = std::make_shared<TimeSeries>(key,timerManager_);
        timeSeriesMap_[key] = timeSeries;
        timeSeriesList_.push_back(timeSeries);
    }
    auto timeSeries = timeSeriesMap_[key];
    timeSeries->AppendPoint(point);
    pointNum_ += point.metrics_size();
}
void TimeSeriesMap::Delete(std::string& key) {
    RWLGuard guard(rwSpinLock_);
    if (timeSeriesMap_.count(key)==0){
        XLOGF(WARNING,"TimeSeries %s is Not Exist\n",key);
        return;
    }
    auto timeSeries = timeSeriesMap_[key];
    timeSeries->SetState(TimeSeries::DELETE);
    pointNum_ -= timeSeriesMap_[key]->GetPointNum();
    --timeSeriesNum_;
    //删除这个timeseries,先加入待删除列表
    expiredTimeSeries_.push_back(timeSeries);
    timeSeriesMap_.erase(key);
    //遍历vector删除指针
    for(auto tsIt=timeSeriesList_.begin(); tsIt!=timeSeriesList_.end();tsIt++){
        if (*tsIt == timeSeries){
            timeSeriesList_.erase(tsIt);
            break;
        }
    }
}

void TimeSeriesMap::Query(const QueryRequest &queryRequest,QueryResponse& queryResponse)  {
    //加上读锁
    RWLSGuard guard(rwSpinLock_);
    std::string key  = PointUtils::GetKey(queryRequest);
    assert(!key.empty());
    if (timeSeriesMap_.count(key)==0){
        XLOGF(WARNING,"TimeSeries %s is Not Exist\n",key);
        return;
    }
    timeSeriesMap_[key]->Query(queryRequest,queryResponse);
}

void TimeSeriesMap::ClearExpiredTimeSeries() {
    RWLGuard guard(rwSpinLock_);
    //清理过期的TS
    uint64_t clearedTimeSeriesNum = 0;
    while (!expiredTimeSeries_.empty() &&clearedTimeSeriesNum < Config::maxPurgeTimeSeriesNum){
        //删除开头的时间序列
        expiredTimeSeries_.erase(expiredTimeSeries_.begin());
        //已经清理的个数增加
        ++clearedTimeSeriesNum;
    }

    //清理完成后，重新设置定时器便于下次清理
    timerManager_->AddTimer(time(nullptr)+Config::purgeTimeSeriesTime,
            [this] { ClearExpiredTimeSeries(); });
}

}
