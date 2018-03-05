cmake_minimum_required(VERSION 3.8)
project(InsertSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SortTestHelper.h)
add_executable(InsertSort ${SOURCE_FILES})