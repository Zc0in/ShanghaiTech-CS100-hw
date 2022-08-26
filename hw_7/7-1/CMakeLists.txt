cmake_minimum_required(VERSION 2.8.12)
set(exe_name rational)
project(${exe_name})

# set(CMAKE_CXX_FLAGS "${CAMKE_CXX_FLAGS} -std=c++11")
# set(CMAKE_BUILD_TYPE "Debug")

aux_source_directory(. SRC_LIST)
add_executable(${exe_name} ${SRC_LIST})