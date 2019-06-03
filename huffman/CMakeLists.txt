cmake_minimum_required(VERSION 3.7)
project(huffman)

find_package(OpenCV REQUIRED)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
add_executable(
        huffman main.cpp
        src/tree/Node.cpp
        src/tree/Node.h
        src/tree/Tree.cpp
        src/tree/Tree.h
        src/heap/Heap.cpp
        src/heap/Heap.h
)
TARGET_LINK_LIBRARIES(huffman ${OpenCV_LIBS})