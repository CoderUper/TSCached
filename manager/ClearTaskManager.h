//
// Created by 金祝光 on 2021/5/19.
//

#ifndef TSCACHED_CLEARTASKMANAGER_H
#define TSCACHED_CLEARTASKMANAGER_H

#include "Config.h"
#include "TimerManager.h"
#include "storage/TimeSeriesMap.h"
#include <thread>
#include <chrono>

namespace TSCached{

class ClearTaskManager {
public:
    explicit ClearTaskManager(std::shared_ptr<TimerManager>&) ;
    ~ClearTaskManager();
    void Purge();
    void ClearExpiredBlock();
private:
    std::shared_ptr<TimerManager> timerManager_;
    bool stop_;
    std::thread expiredBlockClearThread_;
    std::thread purgeThread_;
};

}   //TSCached




#endif //TSCACHED_CLEARTASKMANAGER_H
