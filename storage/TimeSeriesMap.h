//
// Created by 金祝光 on 2021/4/21.
//

#ifndef TSCACHED_TIMESERIESMAP_H
#define TSCACHED_TIMESERIESMAP_H

#include "TimeSeries.h"
#include "manager/TimerManager.h"
#include "utils/PointUtils.h"
#include "manager/Config.h"
#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <folly/RWSpinLock.h>
#include <shared_mutex>
#include <memory>



namespace TSCached{

class TimeSeriesMap{
public:
    explicit TimeSeriesMap(std::shared_ptr<TimerManager> timerManager) ;
    ~TimeSeriesMap() = default;
    TimeSeriesMap(const TimeSeriesMap&) = delete ;
    TimeSeriesMap& operator=(const TimeSeriesMap&) = delete ;
    //插入一个数据和一组数据
    void AppendPoint(const Point& point);

    //删除一个ts
    void Delete(std::string& key);
    //查询时间范围内的数据
    void Query(const QueryRequest& queryRequest,QueryResponse& queryResponse);  ;

    //清理过期的TS
    void ClearExpiredTimeSeries();

private:
    typedef std::lock_guard<folly::RWSpinLock> RWLGuard;
    typedef std::shared_lock<folly::RWSpinLock> RWLSGuard;
private:
    std::vector<std::shared_ptr<TimeSeries>> timeSeriesList_;
    std::unordered_map<std::string,std::shared_ptr<TimeSeries>> timeSeriesMap_;
    //待删除的时间序列列表
    std::list<std::shared_ptr<TimeSeries>> expiredTimeSeries_;
    folly::RWSpinLock rwSpinLock_;

    //数据点数量
    uint64_t pointNum_ ;
    uint64_t timeSeriesNum_;

    //时间管理器
    std::shared_ptr<TimerManager> timerManager_;
};

}


#endif //TSCACHED_TIMESERIESMAP_H
