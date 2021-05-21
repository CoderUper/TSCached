//
// Created by 金祝光 on 2021/5/19.
//

#include "ClearTaskManager.h"

namespace TSCached{


ClearTaskManager::ClearTaskManager(
        std::shared_ptr<TimerManager>& timerManager):
stop_(false),timerManager_(timerManager),
expiredBlockClearThread_(&ClearTaskManager::ClearExpiredBlock, this),
purgeThread_(&ClearTaskManager::Purge, this)
{
}

ClearTaskManager::~ClearTaskManager() {
    stop_ = true;
    if (expiredBlockClearThread_.joinable()){
        expiredBlockClearThread_.join();
    }
    if (purgeThread_.joinable()){
        purgeThread_.join();
    }
}

void ClearTaskManager::Purge() {
    assert(timerManager_);
    while (!stop_){
        if (timerManager_->Empty()){
            continue;
        }
        if (timerManager_->GetRecentTimeOut()<=0){
            timerManager_->RunAllTasks();
        }
        std::this_thread::sleep_for(std::chrono::seconds(timerManager_->GetRecentTimeOut()));
        timerManager_->RunAllTasks();
    }
}
void ClearTaskManager::ClearExpiredBlock() {
    assert(timerManager_);
    while (!stop_){
        if (timerManager_->ExpiredEmpty()){
            continue;
        }
        if (timerManager_->GetClearTaskRecentTimeOut()<=0){
            timerManager_->RunAllClearTasks();
        }
        std::this_thread::sleep_for(std::chrono::seconds(timerManager_->GetClearTaskRecentTimeOut()));
        timerManager_->RunAllClearTasks();
    }
}


}