//
// Created by 金祝光 on 2021/5/18.
//

#ifndef TSCACHED_POINTUTILS_H
#define TSCACHED_POINTUTILS_H

#include "protobuf/point.pb.h"


namespace TSCached{


class PointUtils {
public:
    static std::string GetKey(const Point& point)  ;
    static std::string GetKey(const QueryRequest& queryRequest)  ;
};


}  //TSCached




#endif //TSCACHED_POINTUTILS_H
