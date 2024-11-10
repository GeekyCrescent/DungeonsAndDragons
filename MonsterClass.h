//
// Created by Noel Sebastian Marquez Tovar on 06/11/24.
//

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

