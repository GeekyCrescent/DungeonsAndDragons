#include "Dungeon.h"
#include <iostream>
#include "Room.h"
#include <algorithm>
#include "MonsterClass.h"

using namespace std;

Dungeon::Dungeon(int vertices) : vertices(vertices) {
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

Dungeon::~Dungeon() {
    for (int i = 0; i < vertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Dungeon::addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;  // Assuming bidirectional connections
}

void Dungeon::displayMatrix() {
    std::cout << "Matrix: " << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (int j = 0; j < vertices; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Dungeon::addMonsters(string difficulty) {
    MonsterClass monsterClass;
    monsterClass.loadMonstersFromCsv("monsters_patched.csv");  // Ensure this method loads monsters

    // Retrieve the loaded monsters
    std::vector<Monsters*> loadedMonsters = monsterClass.getRandomMonster(difficulty);

    for (Monsters* monster : loadedMonsters) {
        // Add the monster to its corresponding room based on roomNumber
        int roomNumber = monster->getRoomNumber();
        Room* newRoom = new Room(monster);
        rooms.push_back(newRoom);
    }
}

std::vector<Room*> Dungeon::getRooms() {
    return rooms;
}

int** Dungeon::getAdjMatrix() {
    return adjMatrix;
}

int Dungeon::changeRoom(int currentRoom) {
    vector<int> possibleRooms;
    int newRoom;
    for (int i=0; i<vertices; i++) {
        for (int j=0; j<vertices; j++)
            if (adjMatrix[i][j] == 1 && i == currentRoom) {
                possibleRooms.push_back(j);
                cout << "You can move to room: " << j << endl;
            }
    }

    while (true) {
        cout << "Where would you like to move to?" << endl;
        cin >> newRoom;
        if (find(possibleRooms.begin(), possibleRooms.end(), newRoom) != possibleRooms.end()) {
            cout << "You moved to room " << newRoom << endl;
            return newRoom;
        }
        else {
            cout << "Invalid room number. Please select a valid room." << endl;
        }
    }

}