//
// Created by 金祝光 on 2021/5/21.
//

#ifndef TSCACHED_TSCACHEDCLIENT_H
#define TSCACHED_TSCACHEDCLIENT_H

#include "protobuf/point.pb.h"
#include "protobuf/point.grpc.pb.h"
#include <grpcpp/grpcpp.h>

#include <memory>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using TSCached::TSCachedService;
using TSCached::QueryResponse;
using TSCached::QueryRequest;
using TSCached::WriteResponse;
using TSCached::WriteRequest;
using TSCached::Metrics;
using TSCached::Point;

namespace TSCached{


class TSCachedClient {
public:
    explicit TSCachedClient(std::string&);
    QueryResponse QueryPoints(const QueryRequest&);
    WriteResponse WritePoints(const WriteRequest&);
private:
    std::string serverAddress_;
    std::unique_ptr<TSCachedService::Stub> stub_;
};


}




#endif //TSCACHED_TSCACHEDCLIENT_H
