#include "Player.h"
#include "SpellClass.h" // Include the SpellClass header file
#include <string>

Player::Player(string n, string r) : name(n), race(r), spells(new SpellClass()) {}

string Player::getRace() {
    return this->race;
}

int Player::getLp() {
    return this->lp;
}

int Player::getMana() {
    return this->mana;
}

void Player::loadSpellsFromCsv(string& filename) {
    this->spells->loadSpellsFromCsv(filename, *this);
}

void Player::displaySpells() {
    this->spells->displaySpells();
}

bool Player::useSpell(string spellName) {
    // Implement this function
    return false;
}

void Player::displayFilteredSpells() {
    this->spells->displayFilteredSpells(this->getMana());
}

