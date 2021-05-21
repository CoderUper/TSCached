//
// Created by 金祝光 on 2021/5/19.
//

#ifndef TSCACHED_CONFIG_H
#define TSCACHED_CONFIG_H


#include <cstdint>

namespace TSCached{

class Config {
public:
    //一个数据块接收数据的时间长度，超过这个时间将会关闭，并产生新的数据块
    static const uint64_t changeDataBlockTime = 2*60*60;
    //清理已删除时间序列的时间周期
    static const uint64_t purgeTimeSeriesTime = 1*60;
    //一个数据块的保留时间
    static const uint64_t reserveDataBlockTime = 12*60*60;
    //为避免回收时间序列太耗时太耗内存，限制一次最多回收的个数
    static const uint64_t maxPurgeTimeSeriesNum = 100 ;
};

}




#endif //TSCACHED_CONFIG_H
