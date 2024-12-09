cmake_minimum_required(VERSION 3.30)
project(projektStudia)

set(CMAKE_CXX_STANDARD 17)

add_executable(projektStudia main.cpp
        projekty.cpp
        projekty.h
        zadania.cpp
        zadania.h
        czlonkowie.cpp
        czlonkowie.h
        wspolneFunkcje.cpp
        wspolneFunkcje.h)
