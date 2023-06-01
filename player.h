// --- PLAYER CLASS ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>
using namespace std;

#include "person.h"

#pragma once

class Player : public Person
{
    int posPlayer = 0;
    public:
        Player() : Person () {} //Emty constructor
        Player(const string &name) : Person(name) {} //Constructor with name as input
        ~Player() {} //Destructor
        
        void setPos(int pos, int dice){ posPlayer = pos + dice; }  //sets new position based on past position and dice adding
        int getPos(); //gets 
        void printPlayerInfo(); //prints at end of turn the data collected by individual
};

void Player::printPlayerInfo() //Print player attributes
{
    cout << "Player name: " << getName() << "\n";
    cout << "Player position: " << posPlayer << "\n";
}
