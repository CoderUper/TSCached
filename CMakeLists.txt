cmake_minimum_required(VERSION 3.16)
project(TSCached)

set(CMAKE_CXX_STANDARD 17)


set(SOURCE_FILES main.cpp storage/point.h storage/point.cpp storage/block.h storage/block.cpp storage/ts.h storage/ts.cpp storage/tsmap.h storage/tsmap.cpp)

add_executable(TSCached ${SOURCE_FILES})