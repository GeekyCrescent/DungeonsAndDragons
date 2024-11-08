#pragma once
#include "Spells.h"

using namespace std;

class SpellClass {
private:
    Spells* head;
public:
    SpellClass(): head(nullptr) {}
    Spells* getHead();
    void addSpell(Spells* spell);
    void loadSpellsFromCsv(string& filename, Player& player);
    void displaySpells();
    void displayFilteredSpells(int playerMana);
    bool castSpell(std::string spellName);
};


