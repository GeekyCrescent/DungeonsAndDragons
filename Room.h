#pragma once
#include "Monster.h"

class Room {
private:
    Monsters* monster;  // Each room will store a pointer to a monster
    Room* next;  // Pointer to the next room (if needed)
public:
    // Constructor takes a pointer to a Monster
    Room(Monsters* monster, Room* next = nullptr)
            : monster(monster), next(next) {}

    // Getter and setter methods for monster and next room
    Monsters* getMonster() { return monster; }
    Room* getNext() { return next; }

    void setMonster(Monsters* monster) { this->monster = monster; }
    void setNext(Room* next) { this->next = next; }
};
