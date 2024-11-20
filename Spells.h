#pragma once
#include <string>
#include "Player.h"

using namespace std;

class Spells {
    string name;
    string type;
    string effect;
    int amountEffect;
    int mana;
    Spells* next;
public:
    // CONSTRUCTOR and GETTERS
    Spells(string n, string t, string e, int a, int m) : name(n),type(t), effect(e), amountEffect(a), mana(m), next(nullptr) {}
    string getName();
    string getType();
    string getEffect();
    int getAmountEffect();
    int getMana();
    Spells* getNext();
    void setNext(Spells* spell);
    // DISPLAY spell
    void displaySpell();
};


