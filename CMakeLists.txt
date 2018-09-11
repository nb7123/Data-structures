cmake_minimum_required(VERSION 3.10)
project(BTree)

set(CMAKE_CXX_STANDARD 11)

add_executable(BTree main.cpp src/BTree.cpp src/BTree.h src/Node.cpp src/Node.h)