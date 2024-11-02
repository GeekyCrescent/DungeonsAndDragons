#include "Spells.h"
#include <iostream>
using namespace std;

// GETTERS ------------------------------------------------------------------
string Spells::getName() {
    return this->name;
}
string Spells::getType() {
    return this->type;
}
string Spells::getEffect() {
    return this->effect;
}
int Spells::getAmountEffect() {
    return amountEffect;
}
int Spells::getMana() {
    return mana;
}
Spells* Spells::getNext() {
    return next;
}

// SETTER ------------------------------------------------------------------
void Spells::setNext(Spells *spell) {
    this->next = spell;
}

// DISPLAY ------------------------------------------------------------------
void Spells::displaySpell() {
    cout << "Name: " << this->getName() << ", ";
    cout << "Type: " << this->getType() << ", ";
    cout << "Effect: " << this->getEffect() << ", ";
    cout << "Amount: " << this->getAmountEffect() << ", ";
    cout << "Mana: " << this->getMana() << ", ";
}
