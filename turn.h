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
        Board b;
        Player iterador;
        Dice dice;
        int turnnum;
        int diceValue;

    public:
        Turn(){}//Empty constructor
        string getNombre(){return iterador.getName();}//Get the name of the player
        int getPos(){return iterador.getPos();}//Get the position of the player
        char getType(){return b.getBoard()[iterador.getPos()]->getType();}//Get the type of the tile
        int getMove(){return b.getBoard()[iterador.getPos()]->getMove();}//Get the movement of the tile
        int getTurno(){return turnnum;}//Get the turn
        int getDiceValue(){return diceValue;}//Get the dice value


        void reTurno(Board &b,Player &iterador,int &turnnum,int &diceValue);//Change the turn values

        ~Turn(){}//Destructor
};

ostream & operator<<(ostream &out, Turn &t) //print overload
{   
    cout<< t.getTurno() << " " << t.getNombre() << " " << t.getPos() << " " << t.getType() << " " << t.getMove() << endl;
    return out;
}

void Turn::reTurno(Board &b,Player &iterador,int &turnnum,int &diceValue)
{
    this->b=b;
    this->iterador=iterador;
    this->turnnum=turnnum;
    this->diceValue=diceValue;
}