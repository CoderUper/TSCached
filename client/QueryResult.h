//
// Created by 金祝光 on 2021/5/21.
//

#ifndef TSCACHED_QUERYRESULT_H
#define TSCACHED_QUERYRESULT_H

#include "protobuf/point.pb.h"
#include <string>
#include <memory>

namespace TSCached{


class QueryResult {
public:
    //状态码
    enum Status{
        OK,
        ERROR
    };
    //构造函数
    QueryResult(Status status,std::string message,QueryResponse* queryResponse = nullptr):
    status_(status),
    message_(message),
    queryResponse_(queryResponse)
    {};
    //析构函数
    ~QueryResult(){
        delete queryResponse_;
    }
    //状态码
    Status status_;
    //查询信息
    std::string message_;
    //查询的数据集合
    QueryResponse* queryResponse_;
};


}




#endif //TSCACHED_QUERYRESULT_H
