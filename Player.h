#pragma once
#include <string>
#include "Monster.h"

using namespace std;

// Forward declaration of SpellClass
class SpellClass;

class Player {
private:
    string name;
    string race;
    int hp = 10;
    int lp = 100;
    int mana = 100;
    SpellClass* spells;
    // Monster Defeated
public:
    // CONSTRUCTOR
    Player(string n, string r);
    // GETTERS
    string getRace();
    int getLp();
    int getMana();
    // SETTERS
    void setLp(int lp);
    void setHp(int hp);
    void setMana(int mana);
    // OTHER
    void loadSpellsFromCsv(string& filename);
    void displaySpells();
    bool castSpell(Monsters* monster);
    void displayFilteredSpells();
};