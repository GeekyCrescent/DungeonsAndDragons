#include "Player.h"
#include "SpellClass.h" // Include the SpellClass header file
#include <string>
#include <iostream>
#include <random>

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

int Player::getHp() {
    return this->hp;
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

// SPELL METHODS
void Player::loadSpellsFromCsv(string& filename) {
    this->spells->loadSpellsFromCsv(filename, *this);
}

void Player::displaySpells() {
    this->spells->displaySpells();
}

bool Player::castSpell(Monsters* monster) {
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
        if (current->getType() == "OFFENSIVE") {
            int amountEffect = current -> getAmountEffect();
            cout << "You cast " << current->getName() << " and dealt " << amountEffect << " damage to " << monster->getName() << endl;
            monster->setHP(monster->getHP() - amountEffect);
            this->setMana(this->getMana() - current->getMana());
            return true;
        }

        if (current->getType() == "DEFENSIVE") {
            int amountEffect = current -> getAmountEffect();
            this->setLp(this->getLp() + amountEffect);
            this->setMana(this->getMana() - current->getMana());
            cout << "You cast " << current->getName() << " and gained " << amountEffect << " life points" << endl;
            return true;
        }

        if (current->getType() == "BUFF") {
            int amountEffect = current -> getAmountEffect();
            this->setHp(this->getHp() + amountEffect);
            this->setMana(this->getMana() - current->getMana());
            cout << "You cast " << current->getName() << " and gained " << amountEffect << " attack points" << endl;
            return true;
        }
    }
    else {
        cout << "There was no spell with that name" << endl;
        return false;
    }
    return false;
}

void Player::displayFilteredSpells() {
    this->spells->displayFilteredSpells(this->getMana());
}

// ATTACK METHODS
int Player::attackDice() {
    // Random number between 1 and 10 from ChatGPT because other codes would always return 2
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> distrib(1, 10);
    return distrib(gen);
}

int Player::healDice() {
    // Same problem with the attack dice
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> distrib(1, 6);
    return distrib(gen);
}

// EXPERIENCE
void Player::addExperience() {
    cout << "----------------------------------------------------------" << endl;
    cout << "You gained 100 experience, you improve your statistics by:" << endl;
    cout << "+50 life points" << endl;
    cout << "+20 mana" << endl;
    cout << "+5 attack points" << endl;

    this->setLp(this->getLp() + 50);
    this->setMana(this->getMana() + 20);
    this->setHp(this->getHp() + 5);
}