//
// Created by Adrián Pacheco on 08/11/24.
//

#ifndef DUNGEON_H
#define DUNGEON_H
#include "Monsters.h"


class Dungeon {
private:
    Monsters Monster;
    Dungeon* Next;
    int number;
    /*Podríamos incluir el drop como parte del calabozo, es decir poner un objeto de tipo "item" dentro
     * de los atributos de la clase dungeon, que solo salga si el monstruo del calabozo fue derrotado
     */
public:
    Dungeon(int number): number(number), Next(nullptr), Monster(Monsters()){}
    void setMonster(Monsters Monster);
    Monsters getMonster();
    Dungeon* getNext();
    void setNext(Dungeon* Next);
    int getNumber();
    void setNumber(int number);
    /*En caso de hacerlo así, faltaría la parte del item, entonces:
     *void setItem(Item item);
     *item getItem();
     */
};
#endif //DUNGEON_H
