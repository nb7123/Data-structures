cmake_minimum_required(VERSION 3.10)
project(BTree)

set(CMAKE_CXX_STANDARD 11)

include_directories(src)

add_executable(BTree
        src/bstree/BSTree.cpp
        src/bstree/BSTree.h
        src/bstree/BSNode.cpp
        src/bstree/BSNode.h
        main.cpp src/btree/BTree.cpp src/btree/BTree.h src/btree/BNode.cpp src/btree/BNode.h)
