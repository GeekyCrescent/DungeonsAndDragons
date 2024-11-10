#pragma once
#include <string>

class Monsters {
private:
    std::string name;
    float cr;
    std::string type;
    std::string size;
    int ac;
    int hp;
    std::string align;
    Monsters* next;

public:
    // constructor
    Monsters(std::string name, float cr, std::string type, std::string size, int ac, int hp, std::string align)
        : name(name), cr(cr), type(type), size(size), ac(ac), hp(hp), align(align), next(nullptr) {}

    // getters
    std::string getName();
    float getCR();
    std::string getType();
    std::string getSize();
    int getAC();
    int getHP();
    std::string getAlign();
    Monsters* getNext();

    // setter
    void setNext(Monsters* nextMonster);
    void setHP(int hp);

    // display
    void displayMonster(); // Asegúrate de que esta línea esté presente
};
