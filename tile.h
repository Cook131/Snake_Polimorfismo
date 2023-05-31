#include <iostream>
using namespace std;

#pragma once 

class Tile {
    protected:
        char type;
        int move;
    public:
        Tile () : type('N'), move(0) {} // Constructor to data initialization                                                             
        Tile(const char &type, const int &move) : type(type), move(move) {} // Constructor with const data initialization
        Tile(const Tile& other) : type(other.type), move(other.move) {} //Copy constructor

        virtual ~Tile() {} //Destructor

        char getType() const { return type; } //Getter
        int getMove() const { return move; } //Getter
        virtual void setType(const char &type) { this -> type = type; } //Setter
        virtual void setMove(const int &move) { this -> move = move; } //Setter
        virtual void printTile() { cout << "Esta casilla es: " << getType() << " ;y mueve " << getMove() << " al jugador." << "\n"; }
};