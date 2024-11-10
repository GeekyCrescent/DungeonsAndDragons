#include "Monster.h"
#include <iostream>
using namespace std;

// getters
string Monsters::getName() {
    return this->name;
}

float Monsters::getCR() {
    return this->cr;
}

string Monsters::getType() {
    return this->type;
}

string Monsters::getSize() {
    return this->size;
}

int Monsters::getAC() {
    return this->ac;
}

int Monsters::getHP() {
    return this->hp;
}

string Monsters::getAlign() {
    return this->align;
}

Monsters* Monsters::getNext() {
    return this->next;
}

// setter
void Monsters::setNext(Monsters *monster) {
    this->next = monster;
}

void Monsters::setHP(int hp) {
    this->hp = hp;
}

// display
void Monsters::displayMonster() {
    cout << "Name: " << this->getName() << ", ";
    cout << "CR: " << this->getCR() << ", ";
    cout << "Type: " << this->getType() << ", ";
    cout << "Size: " << this->getSize() << ", ";
    cout << "AC: " << this->getAC() << ", ";
    cout << "HP: " << this->getHP() << ", ";
    cout << "Alignment: " << this->getAlign() << endl;
}
