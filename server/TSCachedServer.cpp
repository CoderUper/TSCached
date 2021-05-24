//
// Created by 金祝光 on 2021/5/21.
//

#include "TSCachedServer.h"



namespace TSCached{

TSCachedServer::TSCachedServer():
timeManager_(std::make_shared<TimerManager>()),
clearTaskManager_(std::make_shared<ClearTaskManager>(timeManager_))
{
}

void TSCachedServer::InitGRPCServer(Config& config) {
    TSCachedServiceImpl tsCachedService(std::make_shared<TimeSeriesMap>(timeManager_,config));
    ServerBuilder serverBuilder;
    serverBuilder.AddListeningPort(config.serverAddress,
            grpc::InsecureServerCredentials());
    serverBuilder.RegisterService(&tsCachedService);
    std::unique_ptr<Server> server(serverBuilder.BuildAndStart());
    std::cout<<"\nTSCachedServer Listening On Address : "<<config.serverAddress<<std::endl;
    server->Wait();
}

void TSCachedServer::InitBanner(Config& config) {
    std::fstream inBanner(config.bannerPath);

    std::string line;
    while (getline(inBanner,line)){
        std::cout<<line<<std::endl;
    }
}

void TSCachedServer::Run() {
    assert(timeManager_);
    assert(clearTaskManager_);
    //读取配置文件
    Config config;
    InitConfig(config);

    InitBanner(config);
    InitGRPCServer(config);
}

void TSCachedServer::InitConfig(Config& config) {
    //加载配置文件
    YAML::Node conf = YAML::LoadFile("./config.yaml");
    if (conf.IsNull()){
        XLOG(ERR,"TSCached Can't Find config.yaml File in Project Path!");
        return;
    }
    auto serverAddress = conf["serverAddress"].as<std::string>();
    auto bannerPath = conf["bannerPath"].as<std::string>();
    auto changeDataBlockTime = conf["changeDataBlockTime"].
            as<uint64_t>();
    if (changeDataBlockTime <=0 ){
        XLOG(ERR,"conf changeDataBlockTime can't less than 0 \n");
        return;
    }
    auto purgeTimeSeriesTime = conf["purgeTimeSeriesTime"].
            as<uint64_t>();
    if (purgeTimeSeriesTime <=0 ){
        XLOG(ERR,"conf purgeTimeSeriesTime can't less than 0 \n");
        return;
    }
    auto reserveDataBlockTime = conf["reserveDataBlockTime"].
            as<uint64_t>();
    if (reserveDataBlockTime <=0 ){
        XLOG(ERR,"conf reserveDataBlockTime can't less than 0 \n");
        return;
    }
    auto maxPurgeTimeSeriesNum = conf["maxPurgeTimeSeriesNum"].
            as<uint64_t>();
    if (maxPurgeTimeSeriesNum <=0 ){
        XLOG(ERR,"conf maxPurgeTimeSeriesNum can't less than 0 \n");
        return;
    }
    auto maxMemoryUsage = conf["maxMemoryUsage"].
            as<uint64_t>();
    if (maxMemoryUsage <=0 ){
        XLOG(ERR,"conf maxMemoryUsage can't less than 0 \n");
        return;
    }

    config.changeDataBlockTime = changeDataBlockTime;
    config.purgeTimeSeriesTime = purgeTimeSeriesTime;
    config.serverAddress = serverAddress;
    config.bannerPath = bannerPath;
    config.reserveDataBlockTime = reserveDataBlockTime;
    config.maxPurgeTimeSeriesNum = maxPurgeTimeSeriesNum;
    config.maxMemoryUsage = maxMemoryUsage;
}

}