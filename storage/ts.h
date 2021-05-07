//
// Created by 金祝光 on 2021/4/20.
//

#ifndef TSCACHED_TS_H
#define TSCACHED_TS_H


#include "block.h"
#include <cassert>

namespace TSCached{

class TS{
public:
    explicit TS(std::string   ts_name);
    ~TS() = default;
    void Insert(Point& point);
//    void Insert( std::vector<Point>& points);

    [[nodiscard]] bool IsTombstone() const ;
    [[nodiscard]] bool IsOpen() const ;
    void SetTombstone();
    void SetAlive();
    void SetName(std::string ts_name);
    [[nodiscard]] std::string GetName() const ;
    void SetBusy(bool busy);
    [[nodiscard]] bool IsBusy() const ;
    void Query(QueryPoints& queryPoints);
private:

    void CoolDown();
    void insert(Point& point);

private:
    //数据块状态
    enum State {NEW_BLOCK,RECYCLING,LAST_BLOCK};
    State State_;
    std::mutex mutex_; //自旋锁优化
    std::string ts_name_;
    std::vector<std::shared_ptr<Block>>  closed_blocks_;
    int capacity_ = 0;   //可重复利用的Block数量
    int block_index_ = -1; // 当前可重复利用的Block下标
    bool is_appending_;
    Block* open_block_;
    double time_limit_ = 2*60*60;
    bool tombstone_;   //是否是墓碑
    bool is_busy_;    //当前block是否繁忙
};

}  //TSCached


#endif //TSCACHED_TS_H
