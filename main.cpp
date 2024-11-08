#include <iostream>
#include "SpellClass.h"
#include "Player.h"
#include <thread>  // Include this header for sleep functionality
#include <chrono>  // Include this header for duration

using namespace std;

Player* createCharacter(); // Function prototype
int showBattleMenu(Player* player); // Function prototype
bool continuePlaying(Player* player); // Function prototype

int main() {
    Player* player = createCharacter();
    string spellsFile = "spells.csv";

    player->loadSpellsFromCsv(spellsFile);
    continuePlaying(player); // Start the game loop

}

Player* createCharacter() {
    cout << "Welcome to Dungeons and Dragons" << endl;
    cout << "Enter your name: ";
    string name;
    cin >> name; // get the name of the player

    string race; // Get the race of the player
    while (true) {
        cout << "Depending on the race you choose, you will have different spells." << endl;
        cout << "Enter your race (Warrior, Mage, Cleric, Rogue): ";
        cin >> race;

        if (race == "Warrior" || race == "Mage" || race == "Cleric" || race == "Rogue") {
            cout << "You have chosen the " << race << " race!" << endl;
            break; // valid race entered
        } else {
            cout << "Invalid race. Please enter one of the following: Warrior, Mage, Cleric, Rogue." << endl;
        }
    }

    cout << "Creating player..." << endl << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Welcome " << name << ", a " << race << "!" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "You stand at the edge of an ancient forest, the whispers of adventure calling to you from within the shadows of the towering trees." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "As a " << race << ", you possess unique strengths and abilities that will aid you on your journey." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Will you brave the unknown and seek glory, or will you protect the realm as a guardian of peace?" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "Your adventure begins now. Gather your allies, prepare your spells, and sharpen your blades." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "The fate of your world lies in your hands. Ready your heart, for peril and treasure await!" << endl;

    Player* player = new Player(name, race);
    return player;
}

int showBattleMenu(Player* player) {
    int choice;
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout << "--------------------------------------------------------" << endl;
        cout << "Choose an action:" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Cast Spell" << endl;
        cout << "-> ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            break; // valid choice entered
        } else {
            cout << "Invalid choice. Please enter 1 for Attack or 2 for Cast Spell." << endl;
        }
    }

    // Handle the chosen action
    if (choice == 1) {
        cout << "--------------------------------------------------------" << endl;
        cout << "You attack the enemy!" << endl;
        return 1;
        // Attack logic here
    } else if (choice == 2) {
        cout << "--------------------------------------------------------" << endl;
        cout << "You choose to cast a spell" << endl;
        return 2;
    }
    return 0;
}

// Logic for keep playing the game and for turns
bool continuePlaying(Player* player) {
    while (player->getLp() > 0) { // Or monster Lp = 0
        cout << "--------------------------------------------------------" << endl;
        cout << "Health: " << player->getLp() << endl;
        cout << "Mana: " << player->getMana() << endl;
        // Player logic
        int selection = showBattleMenu(player);
        // 1 if attack, 2 if spell
        if (selection == 1) {
            // Damage logic
        }
        else if (selection == 2) {
            player->castSpell();
        }

        // Monster logic

        // Add 10 mana to player
        cout << "You gained 10 mana!" << endl;
        player->setMana(player->getMana() + 10);
    }

    if (player->getLp() < 0) {
        cout << "Lost" << endl;
    } else {
        cout << "Win" << endl;
    }
}