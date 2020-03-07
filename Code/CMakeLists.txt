cmake_minimum_required(VERSION 3.3.2)

set(CMAKE_CXX_COMPILER "/cygdrive/c/cygwin64/bin/clang++")
set(CMAKE_C_COMPILER "/cygdrive/c/cygwin64/bin/clang")

project(MicromouseTeamYikes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    direction.cpp
        main.cpp
        maze.cpp
        mouse.cpp
        )


add_executable(MicromouseTeamYikes ${SOURCE_FILES})
# standard

