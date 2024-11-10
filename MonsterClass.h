#pragma once
#include "Monster.h"
#include <string>

class MonsterClass {
private:
    Monsters* head;
public:
    MonsterClass() : head(nullptr) {}

    void addMonster(Monsters* monster);
    void loadMonstersFromCsv(const std::string& filename);
    void displayMonsters();
};

