//
// Created by 金祝光 on 2021/4/20.
//

#ifndef TSCACHED_BLOCK_H
#define TSCACHED_BLOCK_H

#include "point.h"
#include <list>
#include <vector>
#include <mutex>
#include <memory>
#include <cassert>


namespace TSCached{

class Block{
public:
    Block();
    ~Block()=default;
    void AppendPoint(Point& point);
    [[nodiscard]] bool IsOpen() const ;
    void SetClosed();
    void Clear();  //将所有数据清空
    void SetOpen();   //由墓碑状态下的关闭变换到开启状态
    void Query(QueryPoints& queryPoints);
private:
    void moveData();  //将链表数据移动到vector连续内存中，方便遍历和查找
private:
    time_t start_;
    time_t end_;
    bool is_open_; //是否在打开
    time_t created_time_; //该block创建时间
    std::list<std::vector<Field>> append_list_;  //存储追加数据
    std::vector<Field> closed_block_;    //block关闭时写进连续的内存
};

}   //TSCached



#endif //TSCACHED_BLOCK_H
