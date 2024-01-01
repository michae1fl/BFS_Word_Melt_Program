cmake_minimum_required(VERSION 3.26)
project(BFS_Word_Melt_Program)

set(CMAKE_CXX_STANDARD 17)

add_executable(BFS_Word_Melt_Program main.cpp
        arrayqueue.h
        location.cpp
        location.h
        maze.cpp
        maze.h)
