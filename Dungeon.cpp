//
// Created by Adrián Pacheco on 08/11/24.
//
#include <iostream>
#include "Dungeon.h"
using namespace std;

void Dungeon::setMonster(Monsters Monster) {
    this->Monster = Monster;
}

Monsters Dungeon::getMonster() {
    return Monster;
}

Dungeon *Dungeon::getNext() {
    return Next;
}

void Dungeon::setNext(Dungeon* Next) {
    this->Next = Next;
}

int Dungeon::getNumber() {
    return number;
}

void Dungeon::setNumber(int number) {
    this->number = number;
}
