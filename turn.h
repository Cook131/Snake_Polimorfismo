// --- TURN CLASS ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>
#include "board.h"
#include "dice.h"
#include "snake.h"
#include "ladder.h"
#include "player.h"


using namespace std;

#pragma once

class Turn
{
    private:        
        //Create the game objects
        int turnNum;
        string namePlayer;
        int orgPos;
        int diceValue;
        char type;
        int lastPos;

    public:
        Turn(){}//Empty constructor

        const int getTurn(){return turnNum;}//Get the turn
        const string getName(){return namePlayer;}//Get the name of the player
        const int getOrgPos(){return orgPos;}//Get the position of the player
        const int getDiceValue(){ return diceValue;}
        const char getType(){return type;}//Get the type of the tile
        const int getLastPos(){return lastPos;}//Get the original position


        void setTurn(int, string, int, int, char, int);//Change the turn values

        ~Turn(){}//Destructor
};

ostream & operator<<(ostream &out,  Turn &t) //print overload
{   
    out <<  t.getTurn() << " " << t.getName() << " " << t.getOrgPos()  << " " << t.getDiceValue() << " " << t.getType() << " " << t.getLastPos() << endl;
    out << "----------------------------------------" << endl;
    return out;
}

void Turn::setTurn(int turnNum, string playerName, int orgPos, int diceValue, char type, int lastPos) //edit the Turno values for each turn
{
    this -> turnNum = turnNum;
    this -> namePlayer = playerName;
    this -> orgPos = orgPos;
    this -> diceValue = diceValue;
    this -> type = type;
    this -> lastPos = lastPos;

}