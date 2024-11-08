#include "Player.h"
#include "SpellClass.h" // Include the SpellClass header file
#include <string>
#include <iostream>

using namespace std;

// CONSTRUCTOR
Player::Player(string n, string r) : name(n), race(r), spells(new SpellClass()) {}

// GETTERS
string Player::getRace() {
    return this->race;
}

int Player::getLp() {
    return this->lp;
}

int Player::getMana() {
    return this->mana;
}

// SETTERS
void Player::setLp(int lp) {
    this->lp = lp;
}

void Player::setHp(int hp) {
    this->hp = hp;
}

void Player::setMana(int mana) {
    this->mana = mana;
}


void Player::loadSpellsFromCsv(string& filename) {
    this->spells->loadSpellsFromCsv(filename, *this);
}

void Player::displaySpells() {
    this->spells->displaySpells();
}

bool Player::castSpell() {
    displayFilteredSpells();
    cout << "------------------------------" << std::endl;
    cout << "Select a spell from the list above" << std::endl;
    string spell;
    cout << "-> ";
    cin >> spell;

    Spells* current = spells->getHead();
    while (current != nullptr && current->getName() != spell){
        current = current->getNext();
    }
    if (current) {
        if (current->getMana() > this->getMana()) {
            cout << "You do not have enough mana to cast this spell" << endl;
            return false;
        }
        if (current->getType() == "DEFENSIVE") {
            int amountEffect = current -> getAmountEffect();
            this->setLp(this->getLp() + amountEffect);
            this->setMana(this->getMana() - current->getMana());
            cout << "You cast " << current->getName() << " and gained " << amountEffect << " life points" << endl;
            return true;
        }
    }
    else {
        cout << "There was no spell with that name" << endl;
    }
}

void Player::displayFilteredSpells() {
    this->spells->displayFilteredSpells(this->getMana());
}

