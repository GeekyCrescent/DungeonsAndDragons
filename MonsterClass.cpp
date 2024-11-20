#include "MonsterClass.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <random>

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

        // read and assign values from all the columns
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
        current->displayMonster();
        current = current->getNext();
    }
}

// Get random monster from the list
std::vector<Monsters*> MonsterClass::getRandomMonster(string difficulty) {
    // Create a random device and a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());


    // Create a uniform distribution in the range [1, 760]
    std::uniform_int_distribution<> dis(1, 760);

    // Vector to hold the pointers of selected monsters
    std::vector<Monsters*> selectedMonsters;

    // Loop to select 20 random monsters
    while (selectedMonsters.size() < 20) {
        int i = 1;
        int randomIndex = dis(gen);

        // Traverse the list to find the monster at the random index
        Monsters* current = head;
        int currentIndex = 1;  // Start from 1 since the list is 1-based in terms of index
        while (current) {
            if (currentIndex == randomIndex) {
                if (difficulty == "Easy" && current->getHP() < 50) {
                    selectedMonsters.push_back(current);
                    current->setRoomNumber(i + 1);
                    break;
                } else if (difficulty == "Medium" && current->getHP() >= 50 && current->getHP() <= 150) {
                    selectedMonsters.push_back(current);
                    current->setRoomNumber(i + 1);
                    break;
                } else if (difficulty == "Hard" && current->getHP() > 150) {
                    selectedMonsters.push_back(current);
                    current->setRoomNumber(i + 1);
                    break;
                }
                else if (difficulty == "Mixed") {
                    selectedMonsters.push_back(current);
                    current->setRoomNumber(i + 1);
                    break;
                }
            }
            current = current->getNext();
            currentIndex++;
        }
    }

    return selectedMonsters;  // Optionally return a monster or a list
}

