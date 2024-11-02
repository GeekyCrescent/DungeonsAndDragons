#include "SpellClass.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Add a spell to the linked list
void SpellClass::addSpell(Spells* spell) {
    if (!head) {
        head = spell;
    } else {
        Spells* current = head;
        while (current->getNext()) {
            current = current->getNext();
        }
        current->setNext(spell);
    }
}

// Load spells from a CSV file, only of the race of the player
void SpellClass::loadSpellsFromCsv(std::string &filename, Player& player) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;

    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string name, type, effect, amountEffectStr, manaStr, race;

        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, effect, ',');
        std::getline(ss, amountEffectStr, ',');
        std::getline(ss, manaStr, ',');
        std::getline(ss, race, ',');


        int amountEffect = std::stoi(amountEffectStr);
        int mana = std::stoi(manaStr);

        if (race == player.getRace()) {
            Spells* newSpell = new Spells(name, type, effect, amountEffect, mana);
            addSpell(newSpell);
        }
    }

    file.close();
}

// Display all spells
void SpellClass::displaySpells() {
    Spells* current = head;
    while (current != nullptr) {
        current->displaySpell();
        cout << endl;
        current = current->getNext();
    }
}

// Display spells of a certain type
void SpellClass::displayFilteredSpells(std::string type) {
    Spells* current = head;
    while (current != nullptr) {
        if (current->getType() == type) {
            current->displaySpell();
            cout << endl;
        }
        current = current->getNext();
    }
}