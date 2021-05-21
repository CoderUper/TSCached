//
// Created by 金祝光 on 2021/4/20.
//

#include "BlockData.h"

namespace TSCached{

BlockData::BlockData()
:pointNum_(0),startTime_(-1),endTime_(-1),
statusCode_(BlockData::OPEN),createdTime_(time(nullptr))
{

}

//插入数据到一块BlockData中
void BlockData::AppendPoint(const Point &point) {
    //插入数据时修改数据块的起止时间
    if (startTime_==-1 && point.metrics_size()>0){
        startTime_ = point.metrics(0).timestamp();
        endTime_ = point.metrics(point.metrics_size()-1).timestamp();
    } else if (endTime_!=-1 && point.metrics_size()>0){
        endTime_ = point.metrics(point.metrics_size()-1).timestamp();
    }
    //开始插入数据
    for (const Metrics& metrics : point.metrics()) {
        timeList_.push_back(metrics.timestamp());
        for(const auto& filed : metrics.fields()){
            data_[filed.first].push_back(filed.second);
        }
        ++pointNum_;
    }
}

BlockData::StatusCode BlockData::Status() const {
    return statusCode_;
}

void BlockData::Query(const QueryRequest &queryRequest, QueryResponse &queryResponse) {
    for (int i = 0; i < pointNum_; ++i) {
        Metrics metrics;
        metrics.set_timestamp(timeList_[i]);
//        std::map<std::string,double> fields;
        auto fields = metrics.mutable_fields();
        for (const auto& field : data_){
            (*fields)[field.first] = field.second[i];
        }
        queryResponse.mutable_metrics()->Add(std::move(metrics));
    }
}




//bool BlockData::IsOpen() const {
//    return this->is_open_;
//}
//向外提供关闭接口
//void BlockData::MoveData() {
//    if (!append_list_.empty()){
//        moveData();
//    }
//}

//void BlockData::moveData() {
//    for (std::vector<Field> &fields : append_list_) {
//        for (Field &field : fields) {
//            closed_block_.push_back(std::move(field));
//        }
//        fields.clear();
//    }
//    //清空追加列表，并不回收内存，以备后续使用
//    append_list_.clear();
//}

void BlockData::SetClosed() {
    statusCode_ = BlockData::CLOSED;
}

uint64_t BlockData::GetPointNum() const {
    return pointNum_;
}

uint64_t BlockData::GetCreatedTime() const {
    return createdTime_;
}

uint64_t BlockData::GetEndTime() const {
    return endTime_;
}
//
//void BlockData::SetOpen() {
//    assert(!is_open_);
//    this->is_open_ = true;
//    closed_block_.clear();
//}
//
//void BlockData::Clear() {
//
//}






}