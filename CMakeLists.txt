cmake_minimum_required(VERSION 3.10)
project(BTree)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(BTree
        src/BTree.cpp
        src/BTree.h
        src/Node.cpp
        src/Node.h
        main.cpp)
