//
// Created by 金祝光 on 2021/5/19.
//

#ifndef TSCACHED_CONFIG_H
#define TSCACHED_CONFIG_H

#include <string>
#include <cstdint>

namespace TSCached{

class Config {
public:
    //服务器监听IP端口
    std::string serverAddress ;
    //logo文件路径
    std::string bannerPath;
    //一个数据块接收数据的时间长度，超过这个时间将会关闭，并产生新的数据块
    uint64_t changeDataBlockTime ;
    //清理已删除时间序列的时间周期
    uint64_t purgeTimeSeriesTime ;
    //一个数据块的保留时间
    uint64_t reserveDataBlockTime ;
    //为避免回收时间序列太耗时太耗内存，限制一次最多回收的个数
    uint64_t maxPurgeTimeSeriesNum ;
    //最大内存使用限制,以字节为单位
    uint64_t maxMemoryUsage ;
};

}




#endif //TSCACHED_CONFIG_H
