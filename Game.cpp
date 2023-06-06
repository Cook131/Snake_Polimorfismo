// --- GAME CLASS AND MAIN PROGRAM---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>
#include "board.h"
#include "dice.h"
#include "snake.h"
#include "ladder.h"
#include "player.h"
#include "turn.h"


using namespace std;


//Game class
class Game 
{
    private:
        //Parametric variables
        int numPlayers, Smove, Lmove, maxTurns, numLadders, numSnakes, sizeBoard;
        char gamemode;

        //Create the game objects
        Board b;
        vector<Player> players;
        Dice dice;
        Turn ta;
        Turn tm;
    public:
        Game(){}//Empty constructor
        ~Game(){}//Destructor
        //Method to start game, with all the logic process
        int start()
        {
            cout << "-----------------Bienvenido a Serpientes y Escaleras-----------------" << endl;
            //The user enters all the parameters
            cout << "Ingrese el numero de jugadores: " << endl;
            cin >> numPlayers;
            cout << "Ingrese el numero de turnos antes de que acabe el juego: " << endl;
            cin >> maxTurns;

            cout << "Ingrese el numero de tamaño del tablero: " << endl;
            cin >> sizeBoard;

            cout << "Ingrese el numero de escaleras que desea en el juego\n(mientras mas pongas, mas posibilidades de que salgan): " << endl;
            cin >> numLadders;
            cout <<"Decida el premio por escalera (num. de casillas que avanza): " << endl;
            cin >> Lmove;

            cout << "Ingrese el numero de serpientes que desea en el juego: " << endl;
            cin >> numSnakes;
            cout <<"Decida el castigo por serpiente (num. de casillas que retrocede): " << endl;
            cin >> Smove;

            //Create the board according to the paramaters
            
            b.setSize(sizeBoard);

            b.setRandomTiles(numSnakes, numLadders, -1*Smove, Lmove);
            cout << "TABLERO: " << endl;
            b.printBoard();


            int i=0;
            //Create the Players vector accordin to the number entered
            while (i < numPlayers)
            {
                string name;
                cout << "Nombre jugador " << i+1 << ": " << endl;
                cin >> name;
                players.push_back(Player(name));
                i++;
            }
            //The user selected the gamemode
            while(gamemode!='A' && gamemode!='M')
            {
                cout << "Elije tu modo (A: Automatico, M: Manual)" << endl;
                cin >> gamemode;
            }
            cin.ignore();

            //Game starts in interface
            cout << "\n-------------------Comienza el juego--------------------------\n" << endl;

            //Manual mode
            if(gamemode=='M')
            {
                //Turn loop
                for (int i = 0; i < maxTurns; i++)
                {
                    //Player loop
                    for (auto& iterador: players)
                    {   
                        int turno=i; //get turn number
                        int diceValue=dice.roll(); //get integer from dice
                        int posicionorg=iterador.getPos(); //get original position
                        
                        cout << "----------------------------------------" << endl;
                        cout << "Presiona enter para lanzar el dado" << endl;
                        cin.get();

                        iterador+diceValue; //Set the position according to the dice
                        int posicionorg=iterador.getPos(); //get original position

                        if(b.getBoard()[iterador.getPos()]->getType()=='S' || b.getBoard()[iterador.getPos()]->getType()=='L') //Verify the tile
                        {
                            iterador+(b.getBoard()[iterador.getPos()]->getMove()); //Give the punishment/reward
                        }
                        if (iterador.getPos() >= sizeBoard) {iterador.setPos(sizeBoard, 0);}

                        tm.reTurno(b,iterador,turno,diceValue,);//edit printable turn object
                        cout << "Turno: " << turno << endl;
                        
                        if (iterador.getPos() >= sizeBoard) //Verify if it wins
                        {
                            cout << "Player " << iterador.getName() << " is the winner" << endl;
                            cout << "\nGAME OVER" << endl;
                            return 0;
                        }
                        cout << "----------------------------------------" << endl;
                    }
                }
                cout << "Turnos maximos" << "\nGAME OVER" << endl;
            }
            //Automatic mode
            else if(gamemode=='A')
            {
                for (int i = 0; i < maxTurns; i++)
                {
                    for (auto& iterador: players)
                    {
                        int turno=i; //get turn number
                        int diceValue=dice.roll(); //get integer from dice
                        
                        cout << "----------------------------------------" << endl;

                        iterador+diceValue; //Set the position according to the dice
                        
                        if(b.getBoard()[iterador.getPos()]->getType()=='S' || b.getBoard()[iterador.getPos()]->getType()=='L') //Verify the tile
                        {
                            iterador+(b.getBoard()[iterador.getPos()]->getMove()); //Give the punishment/reward
                        }
                        if (iterador.getPos() >= sizeBoard) {iterador.setPos(sizeBoard, 0);}

                        ta.reTurno(b,iterador,turno,diceValue);//edit printable turn object
                        cout << "Turno: " << turno << endl;//print said object
                        
                        if (iterador.getPos() >= sizeBoard) //Verify if it wins
                        {
                            cout << "Player " << iterador.getName() << " is the winner" << endl;
                            cout << "\nGAME OVER" << endl;
                            return 0;
                        }
                        cout << "----------------------------------------" << endl;
                    }
                }
                //game over if max turns
                cout << "Turnos maximos" << "\nGAME OVER" << endl;
            }
        return 0;}
};

//Main program
int main() {
    Game g;
    g.start();
    return 0;
}