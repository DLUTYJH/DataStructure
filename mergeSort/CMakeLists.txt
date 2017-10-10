cmake_minimum_required(VERSION 3.8)
project(mergeSort)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        MergeSort.h
        SortTestHelper.h)

add_executable(mergeSort ${SOURCE_FILES})