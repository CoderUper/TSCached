//
// Created by 金祝光 on 2021/4/20.
//

#ifndef TSCACHED_BLOCKDATA_H
#define TSCACHED_BLOCKDATA_H

#include "protobuf/point.pb.h"

#include <list>
#include <vector>
#include <string>
#include <mutex>
#include <memory>
#include <cassert>


namespace TSCached{

class BlockData{
public:
    enum StatusCode {
        OPEN,
        CLOSED
    };

    BlockData();
    ~BlockData()=default;
    void AppendPoint(const Point& point);
    [[nodiscard]] StatusCode Status() const ;

    void Query(const QueryRequest& queryRequest,QueryResponse& queryResponse);

    //关闭该数据块
    void SetClosed() ;

    [[nodiscard]] uint64_t GetPointNum() const ;

    //获取数据块创建事件
    [[nodiscard]] uint64_t GetCreatedTime() const ;

    //获取关闭时间
    uint64_t GetClosedTime() const ;

    //获取数据块中数据的结束时间
    [[nodiscard]] uint64_t GetEndTime() const ;

private:
    uint64_t pointNum_;

    time_t startTime_;
    time_t endTime_;
    StatusCode statusCode_; //是否在打开
    time_t createdTime_; //该block创建时间
    //关闭时间
    time_t closedTime_;
    typedef std::vector<double> dataList;
    std::vector<time_t> timeList_;
    std::map<std::string,dataList> data_;
};

}   //TSCached



#endif //TSCACHED_BLOCKDATA_H
