cmake_minimum_required(VERSION 3.12)
 
project(leetcode)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

set(SOURCE 
    src/leetcode15.cpp
    main.cpp)

include_directories(include)

add_executable(leetcode ${SOURCE})