cmake_minimum_required(VERSION 3.27)
project(DungeonsAndDragons)

set(CMAKE_CXX_STANDARD 17)

add_executable(DungeonsAndDragons main.cpp
        Player.h
        Player.cpp
        Spells.h
        Spells.cpp
        SpellClass.h
        SpellClass.cpp
        spells.csv
        MonsterClass.cpp
        MonsterClass.h
        MonsterClass.h
        monster.h
        monster.cpp
        Monster.h
)

