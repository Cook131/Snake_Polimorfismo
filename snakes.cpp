#include <iostream>
#include <string>
#include "board.h"
#include "dice.h"
#include "snake.h"
#include "ladder.h"
#include "player.h"

int numPlayers, Smove, Lmove, maxTurns, numLadders, numSnakes, sizeBoard;
char mode;
Dice dice;

using namespace std;

int main() {

    cout << "Bienvenido a Serpientes y Escaleras \n" << endl;

    cout << "Ingrese el numero de jugadores: \n" << endl;
    cin >> numPlayers;
    cout << "Ingrese el numero de turnos antes de que acabe el juego: \n" << endl;
    cin >> maxTurns;

    cout << "Ingrese el numero de tamaño del tablero: \n" << endl;
    cin >> sizeBoard;

    cout << "Ingrese el numero de escaleras que desea en el juego\n(mientras mas pongas, mas posibilidades de que salgan): \n" << endl;
    cin >> numLadders;
    cout <<"Decida el premio por escalera: \n" << endl;
    cin >> Lmove;
    Ladder l;
    l.setMove(Lmove);

    cout << "Ingrese el numero de serpientes que desea en el juego\n(aplica lo mismo en serpientes): \n" << endl;
    cout <<"Decida el castigo por serpiente: \n" << endl;
    cin >> Smove;
    cin >> numSnakes;
    Snake s;
    s.setMove(Smove);

    Board board(sizeBoard);
    board.setRandomTiles(numSnakes, numLadders, s, l);
    board.printBoard();

    vector<Player> players;
    int i=1;
    for (auto iterador: players)
    {
        string name;
        cout << "Ingrese el nombre del jugador " << i << endl;
        cin >> name;
        players.push_back(Player(name));
        i++;
    }

    cout << "Elije tu modo (A: Automatico, M: Manual)" << endl;
    cin >> mode;
    cout << "Comienza el juego" << endl;

    
    
    Snake s;
    cout << s.getType() << endl;

    Player p;
    p.setName("Jose");
    cout << p.getName() << endl;
    return 0;
}