cmake_minimum_required(VERSION 3.8)
project(miniSpanTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Edge.h DenseGraph.h SparseGraph.h lazyPrim.h UnionFind.h Kruskal.h Dijkstra.h)
add_executable(miniSpanTree ${SOURCE_FILES})