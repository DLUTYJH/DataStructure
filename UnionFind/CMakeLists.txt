cmake_minimum_required(VERSION 3.8)
project(UnionFind)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp UnionFind.h UnionFindTestHelper.h QuickUnion.h)
add_executable(UnionFind ${SOURCE_FILES})