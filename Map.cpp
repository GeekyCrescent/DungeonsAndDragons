//
// Created by Adrián Pacheco on 08/11/24.
//

#include "Map.h"
#include <iostream>
using namespace std;

void Map::addDungeon(int src, int dest) {
    Dungeon* newDungeon = new Dungeon(dest);
    newDungeon->setNext(adjlist[src]);
    adjlist[src] = newDungeon;

    newDungeon = new Dungeon(src);
    newDungeon ->setNext(adjlist[dest]);
    adjlist[dest] = newDungeon;
}
void Map::displayMap() {
    for(int i = 0; i < vertices; i++) {
        Dungeon* temp = adjlist[i];
        cout << "Dungeon pos: " << i << ": ";
        while(temp) {
            cout << "->" << temp->getNumber();
            temp = temp->getNext();
        }
        cout << "\n";
    }
}

