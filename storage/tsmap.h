//
// Created by 金祝光 on 2021/4/21.
//

#ifndef TSCACHED_TSMAP_H
#define TSCACHED_TSMAP_H

#include "ts.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <shared_mutex>

namespace TSCached{

class TSMap{
public:
    TSMap() = default;
    ~TSMap() = default;
    TSMap(const TSMap&) = delete ;
    TSMap& operator=(const TSMap&) = delete ;
    //插入一个数据和一组数据
    void Insert(Point& point);

    //删除一个ts
    void DeleteTS(std::string& key);
    //查询时间范围内的数据
    void Query(QueryPoints& queryPoints)  ;

private:

private:
    std::vector<std::shared_ptr<TS>> ts_v_;
    std::unordered_map<std::string,std::shared_ptr<TS>> ts_m_;
    std::vector<std::shared_ptr<TS>> unused_v_;

    std::shared_mutex rw_lock_;
};

}


#endif //TSCACHED_TSMAP_H
