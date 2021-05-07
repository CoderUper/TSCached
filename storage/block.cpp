//
// Created by 金祝光 on 2021/4/20.
//

#include "block.h"

namespace TSCached{

Block::Block():is_open_(true), created_time_(time(nullptr)){
}

void Block::AppendPoint(Point &point) {
    if (append_list_.empty()){
        this->start_ = point.GetStartTime();
        this->end_ = point.GetEndTime();
    }
    this->append_list_.push_back(point.GetFields());
}


bool Block::IsOpen() const {
    return this->is_open_;
}
//向外提供关闭接口
//void Block::MoveData() {
//    if (!append_list_.empty()){
//        moveData();
//    }
//}

void Block::moveData() {
    for (std::vector<Field> &fields : append_list_) {
        for (Field &field : fields) {
            closed_block_.push_back(std::move(field));
        }
        fields.clear();
    }
    //清空追加列表，并不回收内存，以备后续使用
    append_list_.clear();
}

void Block::SetClosed() {
    if (!append_list_.empty()){
        moveData();
    }
    this->is_open_ = false;
}

void Block::SetOpen() {
    assert(!is_open_);
    this->is_open_ = true;
    closed_block_.clear();
}

void Block::Clear() {

}

void Block::Query(QueryPoints &queryPoints)  {
    if (!append_list_.empty()){
        for (auto &v : append_list_){
            for (auto &field : v){
                queryPoints.Insert(field);
            }
        }
    }
    for (auto &field : closed_block_){
        queryPoints.Insert(field);
    }
}




}