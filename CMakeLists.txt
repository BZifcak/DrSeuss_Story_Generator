cmake_minimum_required(VERSION 4.0)
project(HashMapStudents_Updated_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HashMapStudents_Updated_
        HashMap.cpp
        HashMap.h
        HNode.cpp
        HNode.h
        main.cpp
        voice.cpp
        voice.h)
