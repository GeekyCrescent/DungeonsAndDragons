//
// Created by juanr on 01/11/2024.
//
#include "Monsters.h"

string Monsters::getName() {
    return name;
}

void Monsters::setName(string name) {
    this->name = name;
}

float Monsters::getCR() {
    return cr;
}

void Monsters::setCR(float cr) {
    this->cr = cr;
}

string Monsters::getType() {
    return type;
}

void Monsters::setType(string type) {
    this->type = type;
}

string Monsters::getSize() {
    return size;
}

void Monsters::setSize(string size) {
    this->size = size;
}

int Monsters::getAC() {
    return ac;
}

void Monsters::setAC(int ac) {
    this->ac = ac;
}

int Monsters::getHP() {
    return hp;
}
void Monsters::setHP(int hp) {
    this->hp = hp;
}
