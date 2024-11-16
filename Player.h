#pragma once
#include <string>
#include <vector>
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
    int money = 0;
    SpellClass* spells;
    vector<Monsters*> monsters;
public:
    // CONSTRUCTOR
    Player(string n, string r);
    // GETTERS
    string getRace();
    int getLp();
    int getMana();
    int getHp();
    int getMoney();
    // SETTERS
    void setLp(int lp);
    void setHp(int hp);
    void setMana(int mana);
    void setMoney(int money);
    void addMonster(Monsters* monster);
    // SPELLS METHODS
    void loadSpellsFromCsv(string& filename);
    void displaySpells();
    bool castSpell(Monsters* monster);
    void displayFilteredSpells();
    // ATTACK METHODS
    int attackDice();
    int healDice();
    // EXPERIENCE AND STORE
    void addExperience();
    void showStore();
    // Defeated Monsters
    void displayDefeatedMonsters();
};