#include <iostream>
#include "SpellClass.h"
#include "Player.h"
#include "MonsterClass.h"
#include "Dungeon.h"
#include "Monster.h"
#include <thread>  // Include this header for sleep functionality
#include <chrono>  // Include this header for duration

using namespace std;

Player* createCharacter(); // Function prototype
int showBattleMenu(Player* player); // Function prototype
bool continuePlaying(Player* player, Monsters* monster); // Function prototype
string chooseDifficulty();

int main() {
    Dungeon dungeon(20);
    string difficulty = chooseDifficulty();
    dungeon.addMonsters(difficulty);

// Adding edges
    dungeon.addEdge(0, 1);
    dungeon.addEdge(0, 5);
    dungeon.addEdge(1, 6);
    dungeon.addEdge(2, 3);
    dungeon.addEdge(1, 2);
    dungeon.addEdge(2, 7);
    dungeon.addEdge(3, 4);
    dungeon.addEdge(3, 8);
    dungeon.addEdge(4, 9);
    dungeon.addEdge(5, 6);
    dungeon.addEdge(5, 10);
    dungeon.addEdge(6, 7);
    dungeon.addEdge(6, 11);
    dungeon.addEdge(7, 8);
    dungeon.addEdge(7, 12);
    dungeon.addEdge(8, 9);
    dungeon.addEdge(8, 13);
    dungeon.addEdge(9, 14);
    dungeon.addEdge(10, 11);
    dungeon.addEdge(10, 15);
    dungeon.addEdge(11, 12);
    dungeon.addEdge(11, 16);
    dungeon.addEdge(12, 13);
    dungeon.addEdge(12, 17);
    dungeon.addEdge(13, 14);
    dungeon.addEdge(13, 18);
    dungeon.addEdge(14, 19);
    dungeon.addEdge(15, 16);
    dungeon.addEdge(16, 17);
    dungeon.addEdge(17, 18);
    dungeon.addEdge(18, 19);

    Player* player = createCharacter();
    string spells = "spells.csv";
    player->loadSpellsFromCsv(spells);
    bool alive = true;
    std::vector<Room*> rooms = dungeon.getRooms();
    Room* currentRoom = rooms[0];
    int new_room = 0;

    while (true) {
        alive = continuePlaying(player, currentRoom->getMonster());

        if (!alive) {
            cout << "Game Over!" << endl;
            player->displayDefeatedMonsters();
            break;
        }

        new_room =  dungeon.changeRoom(new_room);
        currentRoom = rooms[new_room];
    }
    return 0;
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
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "--------------------------------------------------------" << endl;
        cout << "Choose an action:" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Cast Spell" << endl;
        cout << "3. Heal" << endl;
        cout << "-> ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            break; // valid choice entered
        } else {
            cout << "Invalid choice. Please enter 1 for Attack or 2 for Cast Spell." << endl;
        }
    }

    // Handle the chosen action
    if (choice == 1) {
        cout << "--------------------------------------------------------" << endl;
        return 1;
        // Attack logic here
    } else if (choice == 2) {
        cout << "--------------------------------------------------------" << endl;
        cout << "You choose to cast a spell" << endl;
        return 2;
    } else if (choice == 3) {
        cout << "--------------------------------------------------------" << endl;
        cout << "You choose to heal" << endl;
        return 3;
    }
    return 0;
}

// Logic for keep playing the game and for turns
bool continuePlaying(Player* player, Monsters* monster) {
    // If you have already defeated a monster, you can not fight again
    if (monster->getHP() < 0) {
        cout << "You have already defeated " << monster->getName() <<"! Moving to the next room..." << endl;
        return true;
    }
    // Damage done by the monster
    int monsterDamagePermanent = static_cast<int>(monster->getHP() * 0.2);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "--------------------------------------------------------" << endl;
    cout << "A " << monster->getName() << " appears!" << endl;
    cout << "Monster Health: " << monster->getHP() << endl;
    while (player->getLp() > 0 && monster->getHP() > 0) {
        bool possibleSpell = true;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "--------------------------------------------------------" << endl;
        cout << "Health: " << player->getLp() << endl;
        cout << "Mana: " << player->getMana() << endl;
        cout << "Damage: " << player->getHp() << endl;
        // Player logic
        int selection = showBattleMenu(player);

        while (selection != 1 && selection != 2 && selection != 3) {
            cout << "Invalid choice. Please enter 1 for Attack, 2 for Cast Spell, or 3 for Heal." << endl;
            selection = showBattleMenu(player);
        }

        // Player attack logic
        if (selection == 1) {
            cout << "You attack the monster!" << endl;
            int dice = player->attackDice();
            int damage = dice * player->getHp() / 2;
            cout << "The dice rolls: " << dice << endl;
            // Decide to deal `damage * dice / 2` of the total hp of the player
            cout << "You deal " << damage << " damage to the monster!" << endl;
            monster->setHP(monster->getHP() - damage);
        }
        // Spell Logic
        else if (selection == 2) {
            possibleSpell = player->castSpell(monster);
            if (!possibleSpell) {
                continuePlaying(player, monster);
            }
        }
        // Player heal logic
        else if (selection == 3) {
            cout << "You heal yourself!" << endl;
            int dice = player->healDice();
            cout << "The dice rolls: " << dice << endl;
            // Decide to heal `dice * 2` of the total hp of the player
            cout << "You heal " << dice * 2 << " life points!" << endl;
            player->setLp(player->getLp() + dice * 2);
        }

        // Monster logic
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (monster->getHP() > 0) {
            cout << "--------------------------------------------------------" << endl;
            cout << "Monster Health: " << monster->getHP() << endl;
            cout << monster->getName() << " attacks!" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            // I will choose 20% of the total hp of the monster
            cout << "It deals " << monsterDamagePermanent << " damage to you!" << endl;
            player->setLp(player->getLp() - monsterDamagePermanent);
        }

        // Add 5 mana to player
        if (possibleSpell && player->getLp() > 0) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            cout << "You gained 5 mana!" << endl;
            player->setMana(player->getMana() + 5);
        }
    }

    if (player->getLp() < 0) {
        return false;
    } else {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "You defeated " << monster->getName() << "!" << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        // Add experience
        player->addExperience();
        // Add money according to the monster
        cout << "--------------------------------------------------------" << endl;
        cout << "Health: " << player->getLp() << endl;
        cout << "Mana: " << player->getMana() << endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        player->showStore();
        player->addMonster(monster);
        return true;
    }
}

string chooseDifficulty() {
    string difficulty;
    while (true) {
        cout << "Choose difficulty level (Easy, Medium, Hard): ";
        cin >> difficulty;
        if (difficulty == "Easy" || difficulty == "Medium" || difficulty == "Hard") {
            cout << "You have chosen the " << difficulty << " difficulty level!" << endl;
            break; // valid difficulty entered
        } else {
            cout << "Invalid difficulty. Please enter one of the following: Easy, Medium, Hard." << endl;
        }
    }
    return difficulty;
}

