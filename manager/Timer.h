//
// Created by 金祝光 on 2021/5/19.
//

#ifndef TSCACHED_TIMER_H
#define TSCACHED_TIMER_H
#include <functional>


namespace TSCached{


class Timer {
public:
    typedef std::function<void(void)> Callback;

    Timer(uint64_t expire,Callback callback);

    //定时器函数调用接口
    void RunTask() ;
    [[nodiscard]] uint64_t GetExpireTime() const ;
private:
    //回调函数
    Callback callback_;
    //超时时间
    uint64_t expire_;
};


}




#endif //TSCACHED_TIMER_H
