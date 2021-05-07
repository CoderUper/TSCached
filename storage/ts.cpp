//
// Created by 金祝光 on 2021/4/20.
//

#include "ts.h"

#include <utility>

namespace TSCached{

TS::TS(std::string   ts_name)
:ts_name_(std::move(ts_name)),is_appending_(true),tombstone_(false),State_(NEW_BLOCK){
    this->open_block_ = new Block();
}

bool TS::IsTombstone() const {
    return this->tombstone_;
}

//设为墓碑，表面上删除
void TS::SetTombstone() {
    std::lock_guard<std::mutex> lock(this->mutex_);
    this->tombstone_= true;
    this->is_appending_ = false;
    //如果当前的Block还没关闭，则关闭它
    if (open_block_->IsOpen()){
        open_block_->SetClosed();
    }
    closed_blocks_.push_back(std::make_shared<Block>(*open_block_));
    open_block_ = nullptr;
    capacity_ = closed_blocks_.capacity();
    block_index_ = -1 ;
    State_ = RECYCLING;
    is_busy_ = false;
}

//重新利用起来,把这个ts恢复成能用的样子
void TS::SetAlive() {
    std::lock_guard<std::mutex> lock(mutex_);
    assert(open_block_ == nullptr);
    assert(capacity_ > 0);
    assert(block_index_ == -1);
    tombstone_= false;
    //取出一个空闲的block,capacity也要减一;
    open_block_ = closed_blocks_[++block_index_].get();
    open_block_->SetOpen();
    if (--capacity_==0){
        State_ = LAST_BLOCK;
    }
}

bool TS::IsOpen()  const {
    return open_block_!= nullptr&&is_appending_;
}

void TS::Insert(Point &point) {
    std::lock_guard<std::mutex> lock(this->mutex_);
    assert(is_appending_);
    assert(open_block_!= nullptr);
    SetBusy(true);
    insert(point);
    SetBusy(false);
}
void TS::insert(Point &point) {
    this->open_block_->AppendPoint(point);
}



//更换block的时候需要考虑block的来源，新建或利用已有的
void TS::CoolDown() {
    //先更换一个新的block块，再慢慢的额把原来的block块移动到数据集中
    std::lock_guard<std::mutex> lock(this->mutex_);

    this->open_block_->SetClosed();  //关闭数据块

    if (State_ == RECYCLING){
        //重复利用状态
        open_block_ = closed_blocks_[++block_index_].get();
        if (!open_block_->IsOpen()){
            open_block_->SetOpen();
        }
        if (--capacity_==0) State_ = LAST_BLOCK;
    }else if (State_ == LAST_BLOCK){
        open_block_ = new Block();
        if (!open_block_->IsOpen()) open_block_->SetOpen();
        State_ = NEW_BLOCK;
    } else{
        Block *tmp = open_block_;
        this->open_block_ = new Block();
        this->closed_blocks_.push_back(std::make_shared<Block>(*tmp));
    }
    //2.把旧的数据移动到数据集中

}

void TS::SetName(std::string ts_name) {
    ts_name_ = std::move(ts_name);
}
std::string TS::GetName() const {
    return ts_name_;
}

void TS::SetBusy(bool busy) {
    this->is_busy_ = busy;
}

bool TS::IsBusy() const {
    return is_busy_;
}

void TS::Query(QueryPoints &queryPoints) {
    if (open_block_!= nullptr){
        open_block_->Query(queryPoints);
    }
    for (const auto &block : closed_blocks_){
        block->Query(queryPoints);
    }
}


}  //TSCached