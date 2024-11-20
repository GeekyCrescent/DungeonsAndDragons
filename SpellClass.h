#pragma once
#include "Spells.h"

using namespace std;

class SpellClass {
private:
    Spells* head;
public:
    // Constructor
    SpellClass(): head(nullptr) {}
    // GETTERS
    Spells* getHead();
    // ADD
    void addSpell(Spells* spell);
    // LOAD
    void loadSpellsFromCsv(string& filename, Player& player);
    // DISPLAY
    void displaySpells();
    void displayFilteredSpells(int playerMana);
    // CAST
    bool castSpell(std::string spellName);
};


