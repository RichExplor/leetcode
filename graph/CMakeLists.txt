cmake_minimum_required(VERSION 3.10)

project(leetcode)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -O3")

set(SOURCE 
    src/leetcode207.cpp
    src/leetcode210.cpp
    src/leetcode785.cpp
    main.cpp)

include_directories(include)

add_executable(leetcode ${SOURCE})