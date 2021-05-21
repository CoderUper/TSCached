//
// Created by 金祝光 on 2021/5/19.
//

#include "Timer.h"

#include <utility>

namespace TSCached{

Timer::Timer(uint64_t expire, Callback callback)
:expire_(expire),callback_(callback)
{
}

uint64_t Timer::GetExpireTime() const {
    return expire_;
}

void Timer::RunTask() {
    callback_();
}

}