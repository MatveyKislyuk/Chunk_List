cmake_minimum_required(VERSION 3.27)
project(ChunkList_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(ChunkList)
include_directories(Tests)
include_directories(googletest-main)

add_executable(ChunkList_master
        ChunkList/ChunkList.h
        Tests/Tests.cpp
        googletest-main/googletest/include/gtest/gtest.h
)
