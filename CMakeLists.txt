cmake_minimum_required(VERSION 3.30)
project(projektStudia)

set(CMAKE_CXX_STANDARD 17)

add_executable(projektStudia main.cpp
        projects.cpp
        projects.h
        tasks.cpp
        tasks.h
        contributors.cpp
        contributors.h
        commonFunctions.cpp
        commonFunctions.h)
