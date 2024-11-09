// Created by Noel Sebastian Marquez Tovar on 06/11/24.

#include "MonsterClass.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

// add a monster to the linked list
void MonsterClass::addMonster(Monsters* monster) {
    if (!head) {
        head = monster;
    } else {
        Monsters* current = head;
        while (current->getNext()) {
            current = current->getNext();
        }
        current->setNext(monster);
    }
}

// function to convert a string
float safe_stof(const std::string& str) {
    try {
        return std::stof(str);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Unable to convert '" << str << "' to float. Default value: 0" << std::endl;
        return 0.0f;
    }
}

//  function to convert a string to int
int safe_stoi(const std::string& str) {
    try {
        return std::stoi(str);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: Unable to convert '" << str << "' to int. Default value: 0" << std::endl;
        return 0;
    }
}

// load from a CSV file and add them to the list
void MonsterClass::loadMonstersFromCsv(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);

    while (getline(file, line)) {
        std::string name, type, size, align, crStr, acStr, hpStr;

        std::stringstream ss(line);

        // read and assign values from all the coluns
        std::getline(ss, name, ',');
        std::getline(ss, crStr, ',');
        std::getline(ss, type, ',');
        std::getline(ss, size, ',');
        std::getline(ss, acStr, ',');
        std::getline(ss, hpStr, ',');
        std::getline(ss, align, ',');

        // convert strings
        float cr = safe_stof(crStr);
        int ac = safe_stoi(acStr);
        int hp = safe_stoi(hpStr);

        // create a new monster and add it to the list
        Monsters* monster = new Monsters(name, cr, type, size, ac, hp, align);
        addMonster(monster);
    }

    file.close();
}

// display all monsters
void MonsterClass::displayMonsters() {
    Monsters* current = head;
    while (current) {
        std::cout   << "Name: " << current->getName();
        std::cout   << ", CR: " << current->getCR();
        std::cout   << ", Type: " << current->getType();
        std::cout   << ", Size: " << current->getSize();
        std::cout   << ", AC: " << current->getAC();
        std::cout   << ", HP: " << current->getHP();
        std::cout   << ", Alignment: " << current->getAlign() << std::endl;
        current = current->getNext();
    }
}
