cmake_minimum_required(VERSION 2.8.12)
set(exe_name k-mean)
project(${exe_name})

# set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++14")
set(CMAKE_BUILD_TYPE "Release")
find_package(Threads REQUIRED)

aux_source_directory(. SRC_LIST)
add_executable(${exe_name} ${SRC_LIST})
target_link_libraries(${exe_name} ${CMAKE_THREAD_LIBS_INIT})