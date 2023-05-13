cmake_minimum_required(VERSION 3.12)

project(leetcode)

# 设置C++11标准
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")

set(SOURCE
    leetcode55.cpp)

add_executable(leetcode ${SOURCE})