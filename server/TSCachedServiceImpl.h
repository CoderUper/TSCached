//
// Created by 金祝光 on 2021/5/10.
//

#ifndef TSCACHED_TSCACHEDSERVICEIMPL_H
#define TSCACHED_TSCACHEDSERVICEIMPL_H


#include "protobuf/point.pb.h"
#include "protobuf/point.grpc.pb.h"
#include "storage/TimeSeriesMap.h"
#include <grpcpp/grpcpp.h>

#include <memory>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using TSCached::TSCachedService;
using TSCached::QueryRequest;
using TSCached::QueryResponse;
using TSCached::WriteRequest;
using TSCached::WriteResponse;

namespace TSCached{

class TSCachedServiceImpl final : public TSCachedService::Service{
public:
    explicit TSCachedServiceImpl(
            std::shared_ptr<TimeSeriesMap> timeSeriesMap);
public:
    ::grpc::Status QueryPoints(::grpc::ServerContext *context, const ::TSCached::QueryRequest *request,
            ::TSCached::QueryResponse *response) override;
    ::grpc::Status WritePoints(::grpc::ServerContext *context, const ::TSCached::WriteRequest *request,
            ::TSCached::WriteResponse *response) override;

private:

    std::shared_ptr<TimeSeriesMap> timeSeriesMap_;
};

} //TSCached


#endif //TSCACHED_TSCACHEDSERVICEIMPL_H
