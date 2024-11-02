cmake_minimum_required(VERSION 3.27)
project(DungeonsAndDragons)

set(CMAKE_CXX_STANDARD 17)

add_executable(DungeonsAndDragons main.cpp
        Monsters.h
        Monsters.cpp
        Player.h
        Player.cpp
        Spells.h
        Spells.cpp
        SpellClass.h
        SpellClass.cpp
        spells.csv)

