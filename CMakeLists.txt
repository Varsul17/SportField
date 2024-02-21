cmake_minimum_required(VERSION 3.23)
project(SportField)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SportField
        field.cpp
        field.h
        Date.h
        User.cpp
        User.h
        main.cpp)
