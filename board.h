// --- BOARD CLASS ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <vector>
#include <random>
using namespace std;

#include "tile.h"
#include "snake.h"
#include "ladder.h"

#pragma once

class Board 
{
    int sizeBoard; 
    vector<Tile*> board;
    //vector of Tile pointers to create the board

    public:
        Board() : sizeBoard(0) {} //Empty constructor
        Board(const int &sizeBoard); //Constructor that uses a set size to create the vector board
        Board(const vector<Tile*> &t) : sizeBoard(t.size()), board(t), randomEngine(random_device{}()) {} //Constructor that uses a vector of Tile pointers as the board
        Board(const Board &other) : sizeBoard(other.sizeBoard), board(other.board), randomEngine(random_device{}()){} //Copy constructor
        ~Board(){} //Destructor

    void setSize(int sizeBoard); //methpd to change size of the board and creat a tile vector of said size
    const int getSize(){ return sizeBoard; }
    const vector<Tile*> getBoard(){ return board; }
    void setRandomTiles(int, int, int, int); //Method to create and set the snakes and ladders in random positions
    void printBoard () const;

    private:
        default_random_engine randomEngine; //Random engine library used to create the random positions
        int randomPositions()
        {
            uniform_int_distribution<int> distribution(3, getSize() - 3); //uniformally distributes S and L positions
            return distribution(randomEngine);
        }
};

Board::Board(const int &sizeBoard) : sizeBoard(sizeBoard), board(sizeBoard)
{
    for (int i = 0; i < sizeBoard; i++)
    {
        board[i] = new Tile();
    }
    
}


void Board::setSize(int sizeBoard) 
{
    this -> sizeBoard = sizeBoard; 
        board.resize(sizeBoard);  
    for (int i = 0; i < sizeBoard; i++) //create tile vector inside emtpy one
    {
        board[i] = new Tile();
    }
    
}

void Board::setRandomTiles(int numSnakes, int numLadders, int Smove, int Lmove )
{
    for (int i = 0; i < numSnakes; ++i) 
    {
        //create random position
        int position = randomPositions();

        // Check if the position is occupied
        while (board[position] -> getType() != 'N') 
        {
            position = randomPositions();
        }

        //creat and set Snake
        board[position] = new Snake();
        board[position] -> setMove(Smove);
    }

    for (int i = 0; i < numLadders; ++i) 
    {        
        //create random position
        int position = randomPositions();

        // Check if the position is occupied
        while (board[position] -> getType() != 'N') 
        {
            position = randomPositions();
        }

        //creat and set Snake
        board[position] = new Ladder();
        board[position] -> setMove(Lmove);
    }
}



void Board::printBoard() const
{
    for (const auto& tile : board) 
    {
        cout << tile -> getType() << "\n"; //print full list of Tiles (by char)
    }
    cout << endl;
}