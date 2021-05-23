//
// Created by 金祝光 on 2021/5/21.
//

#include "client/TSCachedClient.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    string addr("127.0.0.1:50000");
    TSCached::TSCachedClient tsCachedClient(addr);

    string dataBase = "test";
    string tableName = "jzg";
    google::protobuf::Map<string,string> tags;
    tags["location"] = "shanghai";
    tags["direction"] = "South";
    WriteRequest writeRequest;
    Point point;
    std::cout<<"开始初始化.................\n";
    //初始化
    point.set_database(dataBase);
    point.set_tablename(tableName);
    (*point.mutable_tags()) = tags;
    //插入100条数据
    for (int i = 0; i < 100; ++i) {
        Metrics metrics;
        metrics.set_timestamp(time(nullptr)+i);
        auto fields = metrics.mutable_fields();
        (*fields)["temp"] = i+1;
        (*fields)["speed"] = i*i;
        point.mutable_metrics()->Add(std::move(metrics));
    }
    writeRequest.mutable_points()->Add(std::move(point));
    std::cout<<"开始写入数据...............\n";
    WriteResponse writeResponse =
            tsCachedClient.WritePoints(writeRequest);
    if (writeResponse.statuscode() == TSCached::StatusCode::ERROR){
        cout<<writeResponse.message()<<endl;
    }

    QueryRequest queryRequest;
    queryRequest.set_database(dataBase);
    queryRequest.set_tablename(tableName);
    (*queryRequest.mutable_tags()) = tags;
    queryRequest.set_starttime(time(nullptr));
    queryRequest.set_endtime(time(nullptr));

    QueryResponse queryResponse;
    std::cout<<"开始插入数据.................\n";
    queryResponse=tsCachedClient.QueryPoints(queryRequest);
    std::cout<<queryResponse.metrics_size()<<std::endl;
    for (int j = 0; j < queryResponse.metrics_size(); ++j) {
        Metrics metrics = queryResponse.metrics(j);
        cout<<metrics.timestamp()<<" ";
        for (const auto& field : metrics.fields()) {
            cout<<field.first<<"="<<field.second<<" ";
        }
        cout<<endl;
    }
}