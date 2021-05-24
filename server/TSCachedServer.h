//
// Created by 金祝光 on 2021/5/21.
//

#ifndef TSCACHED_TSCACHEDSERVER_H
#define TSCACHED_TSCACHEDSERVER_H

#include "TSCachedServiceImpl.h"
#include "manager/ClearTaskManager.h"
#include <yaml-cpp/yaml.h>
#include <fstream>

namespace TSCached{

class TSCachedServer {
public:
    explicit TSCachedServer();
    void Run() ;

private:
    void InitBanner(Config&);
    void InitGRPCServer(Config&);
    void InitConfig(Config&);
private:

    std::shared_ptr<TimerManager> timeManager_;
    std::shared_ptr<ClearTaskManager> clearTaskManager_;
};

}




#endif //TSCACHED_TSCACHEDSERVER_H
