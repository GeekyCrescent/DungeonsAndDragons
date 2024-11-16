#pragma once
#include <vector>
#include "Room.h"
#include "MonsterClass.h"

class Dungeon {
private:
    int vertices;
    int** adjMatrix;
    std::vector<Room*> rooms; // List of rooms in the dungeon

public:
    Dungeon(int vertices);
    ~Dungeon();

    void addEdge(int src, int dest);
    void displayMatrix();
    void addMonsters();
    std::vector<Room*> getRooms();  // To retrieve rooms with monsters
    int** getAdjMatrix();
    int changeRoom(int currentRoom);
};
