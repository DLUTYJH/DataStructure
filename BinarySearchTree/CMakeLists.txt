cmake_minimum_required(VERSION 3.8)
project(BinarySearchTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp binarysearch.h BST.h SequenceST.h)
add_executable(BinarySearchTree ${SOURCE_FILES})