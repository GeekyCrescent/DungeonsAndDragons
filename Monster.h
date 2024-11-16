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
    int roomNumber = 1;
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
    int getRoomNumber();

    // setter
    void setNext(Monsters* nextMonster);
    void setHP(int hp);
    void setRoomNumber(int number);

    // display
    void displayMonster(); // Asegúrate de que esta línea esté presente
};
