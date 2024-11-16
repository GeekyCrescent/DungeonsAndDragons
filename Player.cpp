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

int Player::getMoney() {
    return this->money;
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

void Player::setMoney(int money) {
    this->money = money;
}

void Player::addMonster(Monsters* monster) {
    this->monsters.push_back(monster);
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
    // Random number between 0.0 and 10.0 from ChatGPT because other codes would always return 2
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<float> distrib(0.0, 10.0);
    // Generate a random number and round it to one decimal place
    float random_number = distrib(gen);
    random_number = std::round(random_number * 10) / 10.0f;
    cout << "----------------------------------------------------------" << endl;
    cout << "You gained 100 experience, you improve your statistics by:" << endl;
    cout << "+50 life points" << endl;
    cout << "+20 mana" << endl;
    cout << "+5 attack points" << endl;
    cout << "+" << random_number * 100 << " money" << endl;

    this->setLp(this->getLp() + 50);
    this->setMana(this->getMana() + 20);
    this->setHp(this->getHp() + 5);
    this->setMoney(this->getMoney() + random_number * 100);
}

void Player::showStore() {
    cout << "----------------------------------------------------------" << endl;
    cout << "Welcome to the store!" << endl;
    cout << "You have " << this->getMoney() << " money." << endl;
    cout << "You can buy the following items:" << endl;
    cout << "1. Life Potion (50 LP): 1000 money" << endl;
    cout << "2. Mana Potion (50 Mana): 1500 money" << endl;
    cout << "3. Attack Potion (5 Attack): 500 money" << endl;
    cout << "4. Exit" << endl;
    cout << "----------------------------------------------------------" << endl;
    int choice;
    cin >> choice;

    while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        cin >> choice;
    }

    switch (choice) {
        case 1:
            if (this->getMoney() >= 1000) {
                this->setLp(this->getLp() + 50);
                this->setMoney(this->getMoney() - 1000);
                cout << "You bought a life potion and gained 50 life points!" << endl;
            } else {
                cout << "You do not have enough money to buy a life potion." << endl;
            }
            break;

        case 2:
            if (this->getMoney() >= 1500) {
                this->setMana(this->getMana() + 50);
                this->setMoney(this->getMoney() - 1500);
                cout << "You bought a mana potion and gained 50 mana!" << endl;
            } else {
                cout << "You do not have enough money to buy a mana potion." << endl;
            }
            break;

        case 3:
            if (this->getMoney() >= 500) {
                this->setHp(this->getHp() + 5);
                this->setMoney(this->getMoney() - 500);
                cout << "You bought an attack potion and gained 5 attack points!" << endl;
            } else {
                cout << "You do not have enough money to buy an attack potion." << endl;
            }
            break;
        case 4:
            cout << "You left the store." << endl;
            break;

        default:
            break;
    }
}

void Player::displayDefeatedMonsters() {
    cout << "----------------------------------------------------------" << endl;
    cout << "Defeated Monsters" << endl;
    for (Monsters* monster : monsters) {
        cout << monster->getName() << endl;
    }
}