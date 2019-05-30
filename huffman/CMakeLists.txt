cmake_minimum_required(VERSION 3.7)
project(huffman)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        huffman main.cpp
        src/tree/Node.cpp
        src/tree/Node.h
        src/tree/Tree.cpp
        src/tree/Tree.h
        src/heap/Heap.cpp
        src/heap/Heap.h
)