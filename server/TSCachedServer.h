//
// Created by 金祝光 on 2021/5/21.
//

#ifndef TSCACHED_TSCACHEDSERVER_H
#define TSCACHED_TSCACHEDSERVER_H

#include "TSCachedServiceImpl.h"
#include "manager/ClearTaskManager.h"
#include <fstream>

namespace TSCached{

class TSCachedServer {
public:
    explicit TSCachedServer(std::string networkAddr);
    void Run() ;

private:
    void InitBanner();
    void InitGRPCServer();
private:
    std::string bannerPath_;
    std::string networkAddr_;
    std::shared_ptr<TimerManager> timeManager_;
    std::shared_ptr<ClearTaskManager> clearTaskManager_;
};

}




#endif //TSCACHED_TSCACHEDSERVER_H
