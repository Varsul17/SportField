cmake_minimum_required(VERSION 3.23)
project(SportField)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SportField
        Field.cpp
        Field.h
        Branch.cpp
        Branch.h
        Date.h
        User.cpp
        User.h
        Menu.cpp
        Menu.h
        main.cpp
        DataBase.cpp Player.cpp Player.h
        MainProgram.cpp Manager.cpp Manager.h)
