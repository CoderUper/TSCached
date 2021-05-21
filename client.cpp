//
// Created by 金祝光 on 2021/5/21.
//

#include "client/TSCachedClient.h"
#include <iostream>
#include <string>

#define DATA_NUM 100;

using namespace std;

int main(){
    string addr("127.0.0.1:50001");
    TSCached::TSCachedClient tsCachedClient(addr);

    string dataBase = "test";
    string tableName = "jzg";
    google::protobuf::Map<string,string> tags;
    tags["location"] = "shanghai";
    tags["direction"] = "South";
    WriteRequest writeRequest;
    Point point;
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

    WriteResponse writeResponse =
            tsCachedClient.WritePoints(writeRequest);
    if (writeResponse.statuscode() == TSCached::StatusCode::ERROR){
        cout<<writeResponse.message()<<endl;
    }


}