//
// Created by 金祝光 on 2021/4/20.
//

#ifndef TSCACHED_TIMESERIES_H
#define TSCACHED_TIMESERIES_H

#include "BlockData.h"
#include "manager/TimerManager.h"
#include "manager/Config.h"
#include <folly/SpinLock.h>
#include <folly/logging/xlog.h>
#include <folly/logging/Init.h>
#include <memory>
#include <cassert>

namespace TSCached{

class TimeSeries{
public:
    enum State {ALIVE,DELETE};

    typedef std::lock_guard<folly::SpinLock> SLGuard;

    explicit TimeSeries(std::string&  key,std::shared_ptr<TimerManager>&,Config* config);
    ~TimeSeries() = default;
    void AppendPoint(const Point& point);

    [[nodiscard]]const std::string& GetKey() const ;

    void Query(const QueryRequest& queryRequest,QueryResponse& queryResponse);
    //返回数据块数量
    uint64_t GetBlockNum() const ;
    //返回数据点数量
    uint64_t GetPointNum() const ;
    //返回当前写入数据块的创建时间
    uint64_t GetCurrentBlockCreatedTime()  ;
    //获取和设置状态
    State GetState() const ;
    void SetState(State state);

    void ProduceNewBlock();

    void ClearExpiredBlock();
private:
    //配置项
    const Config* config_;
    //起止时间
    time_t startTime_;
    time_t endTime_;
    //数据块状态
    State state_;
    //自旋锁
    folly::SpinLock spinLock_;
    //时间序列的key
    const std::string key_;
    //数据库数量
    uint64_t dataBlockNum_;
    //数据点的数量
    uint64_t pointNum_;
    //用于写入的数据块
    std::unique_ptr<BlockData> openBlock_;
    //已经关闭的数据块
    std::list<std::unique_ptr<BlockData>> closedBlocks_;
    //时间管理器
    std::shared_ptr<TimerManager> timerManager_;
};

}  //TSCached


#endif //TSCACHED_TIMESERIES_H
