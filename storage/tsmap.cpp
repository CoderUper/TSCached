//
// Created by 金祝光 on 2021/4/21.
//
#include "tsmap.h"

namespace TSCached{

void TSMap::Insert(Point &point) {
    //加 互斥锁，可能涉及到内存结构的修改
    rw_lock_.lock();
    //如果该TS不存在，看看缓存池中还有没有，若没有则生成新的TS
    std::string key = point.GetKey();
    if (ts_m_.count(key)==0){
        if (!unused_v_.empty()){
            //缓存池中有空闲TS
            std::shared_ptr<TS> ts = unused_v_.back();
            ts->SetAlive();
            ts->SetName(point.GetKey());
            ts_m_[point.GetKey()] = ts;
            unused_v_.pop_back();
        } else{
            //缓存池中没有空闲，则新生成TS
            std::shared_ptr<TS> ts = std::make_shared<TS>(point.GetKey());
            ts_v_.push_back(ts);
            ts_m_[point.GetKey()] = ts;
        }
    }
    //2.往ts的open_block中插入数据
    auto ts = ts_m_[point.GetKey()];
    assert(ts->IsOpen());
    ts->SetBusy(true);  //将此TS设置为繁忙
    rw_lock_.unlock();
    ts->Insert(point);
}
void TSMap::DeleteTS(std::string& key) {
    std::unique_lock lock(rw_lock_);
    if (ts_m_.count(key)==0)
        return;
    //查看该ts当前是否繁忙
    auto& ts = ts_m_[key];
    while (ts->IsBusy());
    ts->SetTombstone();
    unused_v_.push_back(ts);
    ts_m_.erase(key);
}

void TSMap::Query(QueryPoints &queryPoints)  {
    //加上读锁
    rw_lock_.lock_shared();
    if (ts_m_.count(queryPoints.GetKey())==1){
        ts_m_[queryPoints.GetKey()]->Query(queryPoints);
    }
}

}
