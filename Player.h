#pragma once
#include <string>

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
    Player(string n, string r);
    string getRace();
    void loadSpellsFromCsv(string& filename);
    void displaySpells();
};