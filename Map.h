//
// Created by Adrián Pacheco on 08/11/24.
//

#ifndef MAP_H
#define MAP_H
#include "Dungeon.h"


class Map {
private:
    int vertices;
    Dungeon** adjlist;
public:
    Map(int vertices) : vertices(vertices) {
        adjlist = new Dungeon* [vertices];
        for(int i = 0; i < vertices; i++) {
            adjlist[i] = nullptr;
        }
    }
    ~Map() {
        for(int i=0; i < vertices; i++) {
            Dungeon* tmp = adjlist[i];
            while(tmp) {
                Dungeon* toDelete = tmp;
                tmp = tmp->getNext();
                delete toDelete;
            }
        }
    }

    void addDungeon(int src, int dest);
    void displayMap();
};



#endif //MAP_H
