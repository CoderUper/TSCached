//
// Created by 金祝光 on 2021/5/10.
//

#include "TSCachedServiceImpl.h"
#include <map>
using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;




namespace TSCached{

TSCachedServiceImpl::TSCachedServiceImpl(
        std::shared_ptr<TimeSeriesMap> timeSeriesMap):
timeSeriesMap_(timeSeriesMap)
{
}

::grpc::Status TSCachedServiceImpl::QueryPoints(::grpc::ServerContext *context, const ::TSCached::QueryRequest *request,
        ::TSCached::QueryResponse *response) {
    assert(timeSeriesMap_);
    XLOGF(INFO,"Query Request From : %s",context->peer().c_str());
    if (!request->IsInitialized()){
        return Status::CANCELLED;
    }
    timeSeriesMap_->Query(*request,*response);
    return Status::OK;
}



::grpc::Status TSCachedServiceImpl::WritePoints(::grpc::ServerContext *context, const ::TSCached::WriteRequest *request,
    ::TSCached::WriteResponse *response) {
    assert(timeSeriesMap_);
    XLOGF(INFO,"Query Request From : %s",context->peer().c_str());
    if (!request->IsInitialized()){
        return Status::CANCELLED;
    }

    if (request->points_size()==0){
        response->set_statuscode(TSCached::StatusCode::ERROR);
        response->set_message("No Points in Request \n");
        return Status::CANCELLED;
    }

    for (int i = 0; i < request->points_size(); ++i) {
        timeSeriesMap_->AppendPoint(request->points(i));
    }
    response->set_message("Points Write Successful! \n");
    response->set_statuscode(TSCached::StatusCode::OK);
    return Status::OK;
}

}   //TSCached
