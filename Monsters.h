#pragma once
#include <iostream>
using namespace std;

class Monsters {
private:
    string name;
    float cr;
    string type;
    string size;
    int ac;
    int hp;
    string align;
public:
    Monsters(string name, float cr, string type, string size, int ac, int hp, string align) {
        this->name = name;
        this->cr = cr;
        this->type = type;
        this->size = size;
        this->ac = ac;
        this->hp = hp;
        this->align = align;
    }
    string getName();
    void setName(string name);
    float getCR();
    void setCR(float cr);
    string getType();
    void setType(string type);
    string getSize();
    void setSize(string size);
    int getAC();
    void setAC(int ac);
    int getHP();
    void setHP();
};


