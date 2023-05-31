#include <iostream>
#include <string>
using namespace std;

#include "person.h"

#pragma once

class Player : public Person
{
    int posPlayer;
    public:
        Player() : Person () {}
        Player(const string &name) : Person(name) {}
        ~Player() {}
        
        void setPos(int pos, int dice){ posPlayer = pos + dice; }  //sets new position based on past position and dice adding
        int getPos(); //gets 
        void printPlayerInfo(); //prints at end of turn the data collected by individual
};

void Player::printPlayerInfo()
{
    cout << "Player name: " << getName() << "\n";
    cout << "Player position: " << posPlayer << "\n";
}
