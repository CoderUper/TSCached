//
// Created by 金祝光 on 2021/4/20.
//

#include "TimeSeries.h"

#include <utility>

namespace TSCached{

TimeSeries::TimeSeries(std::string&  key,std::shared_ptr<TimerManager>& timerManager,Config* config)
:key_(key),dataBlockNum_(1),
config_(config),
pointNum_(0),state_(State::ALIVE),startTime_(-1),endTime_(-1),
openBlock_(std::make_unique<BlockData>()),
timerManager_(timerManager)
{
    //初始化第一块block的定时事件
    //存活Config::changeDataBlockTime后，关闭该数据块；
    timerManager_->AddTimer(openBlock_->GetCreatedTime()+config_->changeDataBlockTime,
            [this]{ProduceNewBlock();});
}

//bool TimeSeries::IsTombstone() const {
//    return this->tombstone_;
//}

//设为墓碑，表面上删除
//void TimeSeries::SetTombstone() {
//    std::lock_guard<std::mutex> lock(this->mutex_);
//    this->tombstone_= true;
//    this->is_appending_ = false;
//    //如果当前的Block还没关闭，则关闭它
//    if (open_block_->IsOpen()){
//        open_block_->SetClosed();
//    }
//    closed_blocks_.push_back(std::make_shared<Block>(*open_block_));
//    open_block_ = nullptr;
//    capacity_ = closed_blocks_.capacity();
//    block_index_ = -1 ;
//    State_ = RECYCLING;
//    is_busy_ = false;
//}

//重新利用起来,把这个ts恢复成能用的样子
//void TimeSeries::SetAlive() {
//    std::lock_guard<std::mutex> lock(mutex_);
//    assert(open_block_ == nullptr);
//    assert(capacity_ > 0);
//    assert(block_index_ == -1);
//    tombstone_= false;
//    //取出一个空闲的block,capacity也要减一;
//    open_block_ = closed_blocks_[++block_index_].get();
//    open_block_->SetOpen();
//    if (--capacity_==0){
//        State_ = LAST_BLOCK;
//    }
//}

//bool TimeSeries::IsOpen()  const {
//    return open_block_!= nullptr&&is_appending_;
//}

//插入数据
void TimeSeries::AppendPoint(const Point &point) {
    SLGuard guard(spinLock_);
//    assert(is_appending_);
    assert(openBlock_);
    assert(point.metrics_size()>0);
    //更新时间
    if (startTime_==-1 ){
        //起止时间都要更新
        startTime_ = point.metrics(0).timestamp();
        endTime_ = point.metrics(point.metrics_size()-1).timestamp();
    }else if (startTime_!=-1 ){
        //只需更新结束时间
        endTime_ = point.metrics(point.metrics_size()-1).timestamp();
    }
    openBlock_->AppendPoint(point);
    pointNum_ += point.metrics_size();
}


uint64_t TimeSeries::GetBlockNum() const {
    return dataBlockNum_;
}

uint64_t TimeSeries::GetPointNum() const {
    return pointNum_;
}

TimeSeries::State TimeSeries::GetState() const {
    return state_;
}

void TimeSeries::SetState(State state) {
    SLGuard guard(spinLock_);
    state_ = state;
}
void TimeSeries::ProduceNewBlock() {
    SLGuard guard(spinLock_);
    //关闭旧的数据块
    openBlock_->SetClosed();
    timerManager_->AddClearTimer(openBlock_->GetClosedTime()+config_->reserveDataBlockTime,
            [this]{TimeSeries::ClearExpiredBlock();});
    closedBlocks_.push_back(std::move(openBlock_));
    //产生新的数据块
    openBlock_ = std::make_unique<BlockData>();
    timerManager_->AddTimer(openBlock_->GetCreatedTime()+config_->changeDataBlockTime,
            [this]{TimeSeries::ProduceNewBlock();});
    ++dataBlockNum_;
    XLOGF(INFO,"TimeSeries %s Produce New Block Successful!\n",key_.c_str());
}

void TimeSeries::ClearExpiredBlock() {
    //检查是否有超时的旧数据
    SLGuard guard(spinLock_);
    time_t now = time(nullptr);
    for (auto blockIt = closedBlocks_.begin();blockIt!=closedBlocks_.end();) {
        //若没有过期则退出
        if (now - (*blockIt)->GetEndTime() < config_->reserveDataBlockTime){
            break;
        }
        //超时的话则清除数据
        --dataBlockNum_;
        pointNum_ -= (*blockIt)->GetPointNum();
        closedBlocks_.erase(blockIt++);
    }
}

//更换block的时候需要考虑block的来源，新建或利用已有的
//void TimeSeries::CoolDown() {
//    //先更换一个新的block块，再慢慢的额把原来的block块移动到数据集中
//    std::lock_guard<std::mutex> lock(this->mutex_);
//
//    this->open_block_->SetClosed();  //关闭数据块
//
//    if (State_ == RECYCLING){
//        //重复利用状态
//        open_block_ = closed_blocks_[++block_index_].get();
//        if (!open_block_->IsOpen()){
//            open_block_->SetOpen();
//        }
//        if (--capacity_==0) State_ = LAST_BLOCK;
//    }else if (State_ == LAST_BLOCK){
//        open_block_ = new Block();
//        if (!open_block_->IsOpen()) open_block_->SetOpen();
//        State_ = NEW_BLOCK;
//    } else{
//        Block *tmp = open_block_;
//        this->open_block_ = new Block();
//        this->closed_blocks_.push_back(std::make_shared<Block>(*tmp));
//    }
//    //2.把旧的数据移动到数据集中
//
//}


const std::string& TimeSeries::GetKey() const {
    return key_;
}

//void TimeSeries::SetBusy(bool busy) {
//    this->is_busy_ = busy;
//}

//bool TimeSeries::IsBusy() const {
//    return is_busy_;
//}

void TimeSeries::Query(const QueryRequest& queryRequest,QueryResponse& queryResponse) {
    SLGuard guard(spinLock_);
    if (openBlock_!= nullptr){
        openBlock_->Query(queryRequest,queryResponse);
    }
    for (const auto& closedBlock : closedBlocks_ ){
        closedBlock->Query(queryRequest,queryResponse);
    }
}

uint64_t TimeSeries::GetCurrentBlockCreatedTime() {
    SLGuard guard(spinLock_);
    assert(openBlock_);
    return openBlock_->GetCreatedTime();
}




}  //TimeSeriesCached