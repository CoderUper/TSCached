# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/e/Clion/TSCached

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/e/Clion/TSCached/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/client.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/client.cpp.o: ../client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/client.cpp.o -c /mnt/e/Clion/TSCached/client.cpp

CMakeFiles/client.dir/client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/client.cpp > CMakeFiles/client.dir/client.cpp.i

CMakeFiles/client.dir/client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/client.cpp -o CMakeFiles/client.dir/client.cpp.s

CMakeFiles/client.dir/storage/BlockData.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/storage/BlockData.cpp.o: ../storage/BlockData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/storage/BlockData.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/storage/BlockData.cpp.o -c /mnt/e/Clion/TSCached/storage/BlockData.cpp

CMakeFiles/client.dir/storage/BlockData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/storage/BlockData.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/storage/BlockData.cpp > CMakeFiles/client.dir/storage/BlockData.cpp.i

CMakeFiles/client.dir/storage/BlockData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/storage/BlockData.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/storage/BlockData.cpp -o CMakeFiles/client.dir/storage/BlockData.cpp.s

CMakeFiles/client.dir/storage/TimeSeries.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/storage/TimeSeries.cpp.o: ../storage/TimeSeries.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client.dir/storage/TimeSeries.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/storage/TimeSeries.cpp.o -c /mnt/e/Clion/TSCached/storage/TimeSeries.cpp

CMakeFiles/client.dir/storage/TimeSeries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/storage/TimeSeries.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/storage/TimeSeries.cpp > CMakeFiles/client.dir/storage/TimeSeries.cpp.i

CMakeFiles/client.dir/storage/TimeSeries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/storage/TimeSeries.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/storage/TimeSeries.cpp -o CMakeFiles/client.dir/storage/TimeSeries.cpp.s

CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.o: ../storage/TimeSeriesMap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.o -c /mnt/e/Clion/TSCached/storage/TimeSeriesMap.cpp

CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/storage/TimeSeriesMap.cpp > CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.i

CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/storage/TimeSeriesMap.cpp -o CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.s

CMakeFiles/client.dir/protobuf/point.pb.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/protobuf/point.pb.cc.o: ../protobuf/point.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/client.dir/protobuf/point.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/protobuf/point.pb.cc.o -c /mnt/e/Clion/TSCached/protobuf/point.pb.cc

CMakeFiles/client.dir/protobuf/point.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/protobuf/point.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/protobuf/point.pb.cc > CMakeFiles/client.dir/protobuf/point.pb.cc.i

CMakeFiles/client.dir/protobuf/point.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/protobuf/point.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/protobuf/point.pb.cc -o CMakeFiles/client.dir/protobuf/point.pb.cc.s

CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.o: ../protobuf/point.grpc.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.o -c /mnt/e/Clion/TSCached/protobuf/point.grpc.pb.cc

CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/protobuf/point.grpc.pb.cc > CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.i

CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/protobuf/point.grpc.pb.cc -o CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.s

CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.o: ../server/TSCachedServiceImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.o -c /mnt/e/Clion/TSCached/server/TSCachedServiceImpl.cpp

CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/server/TSCachedServiceImpl.cpp > CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.i

CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/server/TSCachedServiceImpl.cpp -o CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.s

CMakeFiles/client.dir/utils/PointUtils.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/utils/PointUtils.cpp.o: ../utils/PointUtils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/client.dir/utils/PointUtils.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/utils/PointUtils.cpp.o -c /mnt/e/Clion/TSCached/utils/PointUtils.cpp

CMakeFiles/client.dir/utils/PointUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/utils/PointUtils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/utils/PointUtils.cpp > CMakeFiles/client.dir/utils/PointUtils.cpp.i

CMakeFiles/client.dir/utils/PointUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/utils/PointUtils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/utils/PointUtils.cpp -o CMakeFiles/client.dir/utils/PointUtils.cpp.s

CMakeFiles/client.dir/manager/ClearTaskManager.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/manager/ClearTaskManager.cpp.o: ../manager/ClearTaskManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/client.dir/manager/ClearTaskManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/manager/ClearTaskManager.cpp.o -c /mnt/e/Clion/TSCached/manager/ClearTaskManager.cpp

CMakeFiles/client.dir/manager/ClearTaskManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/manager/ClearTaskManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/manager/ClearTaskManager.cpp > CMakeFiles/client.dir/manager/ClearTaskManager.cpp.i

CMakeFiles/client.dir/manager/ClearTaskManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/manager/ClearTaskManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/manager/ClearTaskManager.cpp -o CMakeFiles/client.dir/manager/ClearTaskManager.cpp.s

CMakeFiles/client.dir/manager/Config.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/manager/Config.cpp.o: ../manager/Config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/client.dir/manager/Config.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/manager/Config.cpp.o -c /mnt/e/Clion/TSCached/manager/Config.cpp

CMakeFiles/client.dir/manager/Config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/manager/Config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/manager/Config.cpp > CMakeFiles/client.dir/manager/Config.cpp.i

CMakeFiles/client.dir/manager/Config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/manager/Config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/manager/Config.cpp -o CMakeFiles/client.dir/manager/Config.cpp.s

CMakeFiles/client.dir/manager/Timer.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/manager/Timer.cpp.o: ../manager/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/client.dir/manager/Timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/manager/Timer.cpp.o -c /mnt/e/Clion/TSCached/manager/Timer.cpp

CMakeFiles/client.dir/manager/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/manager/Timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/manager/Timer.cpp > CMakeFiles/client.dir/manager/Timer.cpp.i

CMakeFiles/client.dir/manager/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/manager/Timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/manager/Timer.cpp -o CMakeFiles/client.dir/manager/Timer.cpp.s

CMakeFiles/client.dir/manager/TimerManager.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/manager/TimerManager.cpp.o: ../manager/TimerManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/client.dir/manager/TimerManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/manager/TimerManager.cpp.o -c /mnt/e/Clion/TSCached/manager/TimerManager.cpp

CMakeFiles/client.dir/manager/TimerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/manager/TimerManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/manager/TimerManager.cpp > CMakeFiles/client.dir/manager/TimerManager.cpp.i

CMakeFiles/client.dir/manager/TimerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/manager/TimerManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/manager/TimerManager.cpp -o CMakeFiles/client.dir/manager/TimerManager.cpp.s

CMakeFiles/client.dir/server/TSCachedServer.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/server/TSCachedServer.cpp.o: ../server/TSCachedServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/client.dir/server/TSCachedServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/server/TSCachedServer.cpp.o -c /mnt/e/Clion/TSCached/server/TSCachedServer.cpp

CMakeFiles/client.dir/server/TSCachedServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/server/TSCachedServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/server/TSCachedServer.cpp > CMakeFiles/client.dir/server/TSCachedServer.cpp.i

CMakeFiles/client.dir/server/TSCachedServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/server/TSCachedServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/server/TSCachedServer.cpp -o CMakeFiles/client.dir/server/TSCachedServer.cpp.s

CMakeFiles/client.dir/client/TSCachedClient.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/client/TSCachedClient.cpp.o: ../client/TSCachedClient.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/client.dir/client/TSCachedClient.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/client/TSCachedClient.cpp.o -c /mnt/e/Clion/TSCached/client/TSCachedClient.cpp

CMakeFiles/client.dir/client/TSCachedClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/client/TSCachedClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/e/Clion/TSCached/client/TSCachedClient.cpp > CMakeFiles/client.dir/client/TSCachedClient.cpp.i

CMakeFiles/client.dir/client/TSCachedClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/client/TSCachedClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/e/Clion/TSCached/client/TSCachedClient.cpp -o CMakeFiles/client.dir/client/TSCachedClient.cpp.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/client.cpp.o" \
"CMakeFiles/client.dir/storage/BlockData.cpp.o" \
"CMakeFiles/client.dir/storage/TimeSeries.cpp.o" \
"CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.o" \
"CMakeFiles/client.dir/protobuf/point.pb.cc.o" \
"CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.o" \
"CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.o" \
"CMakeFiles/client.dir/utils/PointUtils.cpp.o" \
"CMakeFiles/client.dir/manager/ClearTaskManager.cpp.o" \
"CMakeFiles/client.dir/manager/Config.cpp.o" \
"CMakeFiles/client.dir/manager/Timer.cpp.o" \
"CMakeFiles/client.dir/manager/TimerManager.cpp.o" \
"CMakeFiles/client.dir/server/TSCachedServer.cpp.o" \
"CMakeFiles/client.dir/client/TSCachedClient.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/client.cpp.o
client: CMakeFiles/client.dir/storage/BlockData.cpp.o
client: CMakeFiles/client.dir/storage/TimeSeries.cpp.o
client: CMakeFiles/client.dir/storage/TimeSeriesMap.cpp.o
client: CMakeFiles/client.dir/protobuf/point.pb.cc.o
client: CMakeFiles/client.dir/protobuf/point.grpc.pb.cc.o
client: CMakeFiles/client.dir/server/TSCachedServiceImpl.cpp.o
client: CMakeFiles/client.dir/utils/PointUtils.cpp.o
client: CMakeFiles/client.dir/manager/ClearTaskManager.cpp.o
client: CMakeFiles/client.dir/manager/Config.cpp.o
client: CMakeFiles/client.dir/manager/Timer.cpp.o
client: CMakeFiles/client.dir/manager/TimerManager.cpp.o
client: CMakeFiles/client.dir/server/TSCachedServer.cpp.o
client: CMakeFiles/client.dir/client/TSCachedClient.cpp.o
client: CMakeFiles/client.dir/build.make
client: /usr/local/lib/libgrpc++_reflection.a
client: /usr/local/lib/libgrpc++.a
client: /usr/local/lib/libprotobuf.a
client: /usr/local/lib/libfolly.a
client: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
client: /usr/local/lib/libgrpc.a
client: /usr/local/lib/libssl.a
client: /usr/local/lib/libcrypto.a
client: /usr/local/lib/libgpr.a
client: /usr/local/lib/libabsl_str_format_internal.a
client: /usr/local/lib/libabsl_strings.a
client: /usr/local/lib/libabsl_throw_delegate.a
client: /usr/local/lib/libabsl_strings_internal.a
client: /usr/local/lib/libabsl_base.a
client: /usr/local/lib/libabsl_dynamic_annotations.a
client: /usr/local/lib/libabsl_spinlock_wait.a
client: /usr/lib/x86_64-linux-gnu/librt.so
client: /usr/local/lib/libabsl_int128.a
client: /usr/local/lib/libabsl_bad_optional_access.a
client: /usr/local/lib/libabsl_raw_logging_internal.a
client: /usr/local/lib/libabsl_log_severity.a
client: /usr/local/lib/libupb.a
client: /usr/local/lib/libz.a
client: /usr/local/lib/libcares.a
client: /usr/local/lib/libaddress_sorting.a
client: /usr/local/lib/libfmt.a
client: /usr/lib/x86_64-linux-gnu/libboost_context.so
client: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
client: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
client: /usr/lib/x86_64-linux-gnu/libboost_regex.so
client: /usr/lib/x86_64-linux-gnu/libboost_system.so
client: /usr/lib/x86_64-linux-gnu/libboost_thread.so
client: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
client: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
client: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
client: /usr/lib/x86_64-linux-gnu/libdouble-conversion.so
client: /usr/lib/x86_64-linux-gnu/libglog.so
client: /usr/lib/x86_64-linux-gnu/libevent.so
client: /usr/local/lib/libz.so
client: /usr/lib/x86_64-linux-gnu/libssl.so
client: /usr/lib/x86_64-linux-gnu/libcrypto.so
client: /usr/lib/x86_64-linux-gnu/liblzma.so
client: /usr/lib/x86_64-linux-gnu/liblz4.so
client: /usr/lib/x86_64-linux-gnu/libsnappy.so
client: /usr/lib/x86_64-linux-gnu/libdwarf.so
client: /usr/lib/x86_64-linux-gnu/libiberty.a
client: /usr/lib/x86_64-linux-gnu/libunwind.so
client: /usr/lib/x86_64-linux-gnu/libboost_system.so
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /mnt/e/Clion/TSCached/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/e/Clion/TSCached /mnt/e/Clion/TSCached /mnt/e/Clion/TSCached/cmake-build-debug /mnt/e/Clion/TSCached/cmake-build-debug /mnt/e/Clion/TSCached/cmake-build-debug/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend
