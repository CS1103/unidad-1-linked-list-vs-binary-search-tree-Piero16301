cmake_minimum_required(VERSION 3.13)
project(BinarySearch)

set(CMAKE_CXX_STANDARD 17)

add_executable(BinarySearch main.cpp BinarySearchTree.h BinarySearchTree.cpp LinkedList.h LinkedList.cpp Location.h Location.cpp)