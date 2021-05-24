cmake_minimum_required(VERSION 3.16)
project(TSCached)

set(CMAKE_CXX_STANDARD 17)

include_directories(".")

#假设已经安装好grpc了
find_package(Threads REQUIRED)

find_package(
        Boost 1.58.0 REQUIRED
        COMPONENTS
        filesystem
        system
)

find_package(Folly REQUIRED)


set(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)


# Find gRPC installation
# Looks for gRPCConfig.cmake file installed by gRPC's cmake installation.
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

set(_GRPC_GRPCPP gRPC::grpc++)

SET(CMAKE_CXX_FLAGS -pthread)

set(SOURCE_FILES storage/BlockData.h storage/BlockData.cpp storage/TimeSeries.h
        storage/TimeSeries.cpp storage/TimeSeriesMap.h storage/TimeSeriesMap.cpp protobuf/point.pb.h
        protobuf/point.pb.cc protobuf/point.grpc.pb.h protobuf/point.grpc.pb.cc server/TSCachedServiceImpl.h server/TSCachedServiceImpl.cpp
        utils/PointUtils.h utils/PointUtils.cpp manager/ClearTaskManager.h manager/ClearTaskManager.cpp
        manager/Config.cpp manager/Config.h manager/Timer.cpp manager/Timer.h manager/TimerManager.cpp manager/TimerManager.h
        server/TSCachedServer.cpp server/TSCachedServer.h client/TSCachedClient.cpp client/TSCachedClient.h client/QueryResult.h client/WriteRequest.h)

file(GLOB files *.cpp)
foreach(file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} ${SOURCE_FILES})
    target_link_libraries(${exe}
            ${_REFLECTION}
            ${_GRPC_GRPCPP}
            ${_PROTOBUF_LIBPROTOBUF}
            ${FOLLY_LIBRARIES}
            Boost::filesystem
            libyaml-cpp.so)
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach()


