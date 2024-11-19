#pragma once
#include "Monster.h"
#include "Player.h"
#include <string>
#include <vector>

class MonsterClass {
private:
    Monsters* head;
public:
    MonsterClass() : head(nullptr) {}

    void addMonster(Monsters* monster);
    void loadMonstersFromCsv(const std::string& filename);
    void displayMonsters();
    std::vector<Monsters*> getRandomMonster(string difficilty);
};

