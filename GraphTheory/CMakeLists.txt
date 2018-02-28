cmake_minimum_required(VERSION 3.8)
project(GraphTheory)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DenseGraph.h SparseGraph.h GraphSearch.h Path.h)
add_executable(GraphTheory ${SOURCE_FILES})