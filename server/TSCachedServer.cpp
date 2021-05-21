//
// Created by 金祝光 on 2021/5/21.
//

#include "TSCachedServer.h"



namespace TSCached{

TSCachedServer::TSCachedServer(std::string networkAddr):
networkAddr_(std::move(networkAddr)),
timeManager_(std::make_shared<TimerManager>()),
clearTaskManager_(std::make_shared<ClearTaskManager>(timeManager_))
{
}

void TSCachedServer::InitGRPCServer() {
    TSCachedServiceImpl tsCachedService(std::make_shared<TimeSeriesMap>(timeManager_));
    ServerBuilder serverBuilder;
    serverBuilder.AddListeningPort(networkAddr_,
            grpc::InsecureServerCredentials());
    serverBuilder.RegisterService(&tsCachedService);
    std::unique_ptr<Server> server(serverBuilder.BuildAndStart());
    std::cout<<"\nTSCachedServer Listening On Address : "<<networkAddr_<<std::endl;
    server->Wait();
}

void TSCachedServer::InitBanner() {
    std::fstream inBanner("./server/banner.txt");

    std::string line;
    while (getline(inBanner,line)){
        std::cout<<line<<std::endl;
    }
}

void TSCachedServer::Run() {
    assert(timeManager_);
    assert(clearTaskManager_);
    InitBanner();
    InitGRPCServer();
}

}