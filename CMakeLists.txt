cmake_minimum_required(VERSION 3.27)
project(DungeonsAndDragons)

set(CMAKE_CXX_STANDARD 17)

add_executable(DungeonsAndDragons main.cpp
        Monsters.h
        Monsters.cpp
        Dungeon.h
        Dungeon.cpp
        Map.h
        Map.cpp)
