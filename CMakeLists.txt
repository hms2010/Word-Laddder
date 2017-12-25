cmake_minimum_required(VERSION 3.9)
project(Word_Ladder)

set(CMAKE_CXX_STANDARD 11)

add_executable(Word_Ladder
        src/main.cpp
        src/WordGraph.cpp
        src/WordGraph.h
        src/WordNode.cpp
        src/WordNode.h)
