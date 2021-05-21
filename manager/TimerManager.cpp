//
// Created by 金祝光 on 2021/5/19.
//

#include "TimerManager.h"

namespace TSCached{


std::shared_ptr<Timer> TimerManager::AddTimer(uint64_t timeout, const Timer::Callback& callback) {
    std::shared_ptr<Timer> timer = std::make_shared<Timer>(timeout,callback);
    priorityQueue_.push(timer);
    return timer;
}

std::shared_ptr<Timer> TimerManager::AddClearTimer(uint64_t timeout, const Timer::Callback &callback) {
   std::shared_ptr<Timer> timer = std::make_shared<Timer>(timeout,callback);
   expiredBlockQueue_.push(timer);
   return timer;
}

int64_t TimerManager::GetClearTaskRecentTimeOut() const {
    time_t now = time(nullptr);
    return now - expiredBlockQueue_.top()->GetExpireTime();
}

int64_t TimerManager::GetRecentTimeOut() const {
    time_t now = time(nullptr);
    return now - priorityQueue_.top()->GetExpireTime();
}


void TimerManager::RunAllClearTasks() {
    time_t  now = time(nullptr);
    while (!expiredBlockQueue_.empty() && expiredBlockQueue_.top()->GetExpireTime()<=now){
        expiredBlockQueue_.top()->RunTask();
        expiredBlockQueue_.pop();
    }
}
void TimerManager::RunAllTasks() {
    time_t  now = time(nullptr);
    while (!priorityQueue_.empty() && priorityQueue_.top()->GetExpireTime()<=now){
        priorityQueue_.top()->RunTask();
        priorityQueue_.pop();
    }
}

bool TimerManager::ExpiredEmpty() const {
    return expiredBlockQueue_.empty();
}

bool TimerManager::Empty() const {
    return priorityQueue_.empty();
}


}


