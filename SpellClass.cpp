#include "SpellClass.h"
#include <iostream>
#include <fstream>
#include <sstream>

// GETTERS
Spells* SpellClass::getHead() {
    return this->head;
}


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

        // Read each value to the variables
        std::getline(ss, name, ',');
        std::getline(ss, type, ',');
        std::getline(ss, effect, ',');
        std::getline(ss, amountEffectStr, ',');
        std::getline(ss, manaStr, ',');
        std::getline(ss, race, ',');

        // Transform into ints
        int amountEffect = std::stoi(amountEffectStr);
        int mana = std::stoi(manaStr);

        // If race selected is the same as the spells
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

// Display spells filtered
void SpellClass::displayFilteredSpells(int playerMana) {
    Spells* current = head;
    string type;
    while (true) {
        cout << "Type (OFFENSIVE, DEFENSIVE, BUFF): ";
        cin >> type;
        if (type == "OFFENSIVE" || type == "DEFENSIVE" || type == "BUFF") {
            break; // valid type entered
        } else {
            cout << "Invalid type. Please enter one of the following: OFFENSIVE, DEFENSIVE, BUFF." << endl;
        }
    }
    cout << "-----------------------------------" << endl;
    cout << "Filtered Spells" << endl;
    while (current != nullptr) {
        if (current->getMana() <= playerMana && current->getType() == type) {
            current->displaySpell();
            cout << endl;
        }
        current = current->getNext();
    }
}