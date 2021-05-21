//
// Created by 金祝光 on 2021/5/21.
//

#include "TSCachedClient.h"

using grpc::Status;

namespace TSCached{


TSCached::TSCachedClient::TSCachedClient(std::string &serverAddress):
serverAddress_(serverAddress),
stub_(TSCachedService::NewStub(
        grpc::CreateChannel(
                serverAddress_,
                grpc::InsecureChannelCredentials())
                ))
{

}

QueryResponse TSCachedClient::QueryPoints(const QueryRequest &queryRequest) {
    assert(stub_);
    if (!queryRequest.IsInitialized()){
        std::cout<<"QueryRequest has not initialized!\n";
        return QueryResponse();
    }
    QueryResponse queryResponse;
    //开始查询
    Status status = stub_->QueryPoints(new ClientContext(),
            queryRequest,&queryResponse);
    if (!status.ok()){
        std::cout<<"Query Error ! Error Code : "<<status.error_code()<<
        ","<<"Error Message : "<<status.error_message()<<std::endl;
    }
    return queryResponse;
}

WriteResponse TSCachedClient::WritePoints(const WriteRequest &writeRequest) {
    assert(stub_);
    if (!writeRequest.IsInitialized()){
        std::cout<<"QueryRequest has not initialized!\n";
        return WriteResponse();
    }
    WriteResponse writeResponse;
    Status status = stub_->WritePoints(new ClientContext(),
            writeRequest,&writeResponse);
    if (!status.ok()){
        std::cout<<"Write Error ! Error Code : "<<status.error_code()<<
                 ","<<"Error Message : "<<status.error_message()<<std::endl;
    }
    return writeResponse;
}

}


