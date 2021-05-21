//
// Created by 金祝光 on 2021/5/18.
//

#include "PointUtils.h"

namespace TSCached{


std::string TSCached::PointUtils::GetKey(const TSCached::Point &point) {
    assert(!point.database().empty());
    assert(!point.tablename().empty());
    assert(!point.tags().empty());
    std::string key=point.database()+"&"+point.tablename();
    for(const auto& kv : point.tags()){
        key +="&" + kv.first + "=" +kv.second;
    }
    return key;
}

std::string TSCached::PointUtils::GetKey(const TSCached::QueryRequest &queryRequest) {
    assert(!queryRequest.database().empty());
    assert(!queryRequest.tablename().empty());
    assert(!queryRequest.tags().empty());
    std::string key=queryRequest.database()+"&"+queryRequest.tablename();
    for(const auto& kv : queryRequest.tags()){
        key +="&" + kv.first + "=" +kv.second;
    }
    return key;
}


} //TSCached


