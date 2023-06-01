#include <iostream>
#include <string>
#include "board.h"
#include "dice.h"
#include "snake.h"
#include "ladder.h"
#include "player.h"


using namespace std;
int numPlayers, Smove, Lmove, maxTurns, numLadders, numSnakes, sizeBoard;
char gamemode;
Dice dice;

class Game
{
    public:
        Game(){}
        ~Game(){}
        int start()
        {
            cout << "-----------------Bienvenido a Serpientes y Escaleras-----------------" << endl;

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

            Board b(sizeBoard);
            b.setRandomTiles(numSnakes, numLadders, -1*Smove, Lmove);
            cout << "TABLERO: " << endl;
            b.printBoard();


            vector<Player> players;
            int i=0;

            while (i < numPlayers)
            {
                string name;
                cout << "Nombre jugador " << i+1 << ": " << endl;
                cin >> name;
                players.push_back(Player(name));
                i++;
            }

            while(gamemode!='A' && gamemode!='M')
            {
                cout << "Elije tu modo (A: Automatico, M: Manual)" << endl;
                cin >> gamemode;
            }
            cout << "\n-------------------Comienza el juego--------------------------\n" << endl;


            if(gamemode=='M')
            {
                for (int i = 0; i < maxTurns; i++)
                {
                    for (auto& iterador: players)
                    {
                        cout << "----------------------------------------" << endl;
                        cout << "Turno de " << iterador.getName() << endl;
                        cout << "Presiona doble enter para lanzar el dado" << endl;
                        cin.ignore();
                        cin.get();
                        int diceValue = dice.roll();
                        cout << "El dado cayo en " << diceValue << endl;
                        iterador.setPos(iterador.getPos(), diceValue);
                        if (iterador.getPos() >= sizeBoard) {iterador.setPos(sizeBoard, 0);}
                        cout << "Ahora estas en la casilla " << iterador.getPos() << endl;
                                        if (iterador.getPos() >= sizeBoard)
                        {
                            cout << "Felicidades " << iterador.getName() << " has ganado" << endl;
                            cout << "\nGAME OVER" << endl;
                            return 0;
                        }
                        if(b.getBoard()[iterador.getPos()]->getType()=='S' || b.getBoard()[iterador.getPos()]->getType()=='L')
                        {
                            cout << "IMPORTANTE" << endl;
                            cout << "Caiste en: " << b.getBoard()[iterador.getPos()]->getType() << "    te mueves acorde" << endl;
                            iterador.setPos(iterador.getPos(),b.getBoard()[iterador.getPos()]->getMove());
                            cout << "Ahora estas en la casilla " << iterador.getPos() << endl;
                        }
                        cout << "----------------------------------------" << endl;
                    }
                }
                cout << "Turnos maximos" << "\nGAME OVER" << endl;
            }
            else if(gamemode=='A')
            {
                for (int i = 0; i < maxTurns; i++)
                {
                    for (auto& iterador: players)
                    {
                            cout << "----------------------------------------" << endl;
                            cout << "Turno de " << iterador.getName() << endl;
                            int diceValue = dice.roll();
                            cout << "El dado cayo en " << diceValue << endl;
                            iterador.setPos(iterador.getPos(),diceValue);
                            if (iterador.getPos() >= sizeBoard) {iterador.setPos(sizeBoard, 0);}
                            cout << "Ahora estas en la casilla " << iterador.getPos() << endl;
                            if (iterador.getPos() >= sizeBoard)
                            {
                                cout << "Felicidades " << iterador.getName() << " has ganado" << endl;
                                cout << "\nGAME OVER" << endl;
                                return 0;
                            }
                            if(b.getBoard()[iterador.getPos()]->getType()=='S' || b.getBoard()[iterador.getPos()]->getType()=='L')
                            {
                                cout << "IMPORTANTE" << endl;
                                cout << "Caiste en: " << b.getBoard()[iterador.getPos()]->getType() << "    te mueves acorde" << endl;
                                iterador.setPos(iterador.getPos(),b.getBoard()[iterador.getPos()]->getMove());
                                cout << "Ahora estas en la casilla " << iterador.getPos() << endl;
                            }
                            cout << "----------------------------------------" << endl;
                    }
                }
                cout << "Turnos maximos" << "\nGAME OVER" << endl;
            }
        }
};

int main() {
    Game g;
    g.start();
    return 0;
}