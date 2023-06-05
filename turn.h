// --- TURN CLASS ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250


//a terminar, por favor

#include <iostream>
#include <string>
#include "board.h"
#include "dice.h"
#include "snake.h"
#include "ladder.h"
#include "player.h"
#include "Game.cpp"


using namespace std;

#pragma once

class Turn
{
    private:        
        //Create the game objects
        Board b;
        vector<Player> players;
        Dice dice;

    public:
        Turn(){}//Empty constructor
        ~Turn(){}//Destructor

};

ostream & operator<<(ostream &out, Game &g){
    cout << "----------------------------------------" << endl;
    cout << "Turno de " << iterador.getName() << endl;
    //no button for dice roll
    int diceValue = dice.roll();
    cout << "El dado cayo en " << diceValue << endl;
    iterador.setPos(iterador.getPos(),diceValue); //Set the position according to the dice
    if (iterador.getPos() >= sizeBoard) {iterador.setPos(sizeBoard, 0);}
    cout << "Ahora estas en la casilla " << iterador.getPos() << endl;
    if (iterador.getPos() >= sizeBoard) //Verify if it wins
    {
        cout << "Felicidades " << iterador.getName() << " has ganado" << endl;
        cout << "\nGAME OVER" << endl;
        return 0;
    }
    if(b.getBoard()[iterador.getPos()]->getType()=='S' || b.getBoard()[iterador.getPos()]->getType()=='L')
    {

        cout << "Caiste en: " << b.getBoard()[iterador.getPos()]->getType() << "    te mueves acorde" << endl; 
        iterador.setPos(iterador.getPos(),b.getBoard()[iterador.getPos()]->getMove()); //Give the punishment/reward
        cout << "Ahora estas en la casilla " << iterador.getPos() << endl;
    }
    cout << "----------------------------------------" << endl;
}