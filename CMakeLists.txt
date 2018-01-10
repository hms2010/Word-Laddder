cmake_minimum_required(VERSION 3.0)
project(wordLadder)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
set(SOURCE_LIST src/main.cpp src/WordNode.cpp src/WordGraph.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_LIST})