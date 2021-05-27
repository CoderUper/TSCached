//
// Created by 金祝光 on 2021/5/19.
//

#ifndef TSCACHED_TIMERMANAGER_H
#define TSCACHED_TIMERMANAGER_H

#include "Timer.h"
#include <memory>
#include <mutex>
#include <shared_mutex>
#include <folly/RWSpinLock.h>
#include <queue>
#include <condition_variable>


namespace TSCached{

class TimerManager {
public:
    typedef std::lock_guard<folly::RWSpinLock> RWLGuard;
    typedef std::shared_lock<folly::RWSpinLock> RWLSGuard;

    TimerManager() = default;
    std::shared_ptr<Timer> AddTimer(uint64_t timeout,const Timer::Callback& callback);
    std::shared_ptr<Timer> AddClearTimer(uint64_t timeout,const Timer::Callback& callback);
    [[nodiscard]] int64_t GetRecentTimeOut() const ;
    [[nodiscard]] int64_t GetClearTaskRecentTimeOut() const ;
    //void DelTimer(std::shared_ptr<Timer> timer);
    void RunAllTasks();
    void RunAllClearTasks();
    [[nodiscard]] bool Empty() const ;
    bool ExpiredEmpty() const ;

private:
    struct cmp{
        bool operator()(std::shared_ptr<Timer>& lhs,std::shared_ptr<Timer>& rhs){
            return lhs->GetExpireTime() > rhs->GetExpireTime();
        }
    };

    mutable std::mutex mutex1_;
    mutable std::mutex mutex2_;
//    std::condition_variable_any
//    folly::MicroSpinLock microSpinLock_;
//    typedef folly::MSLGuard MSLGuard;
    //清理过期TS，新block结束周期的定时事件
    std::priority_queue<std::shared_ptr<Timer>,
    std::vector<std::shared_ptr<Timer>>,
    cmp> priorityQueue_;
    //清理过期block的定时事件
    std::priority_queue<std::shared_ptr<Timer>,
    std::vector<std::shared_ptr<Timer>>,
    cmp> expiredBlockQueue_;

};


}



#endif //TSCACHED_TIMERMANAGER_H
