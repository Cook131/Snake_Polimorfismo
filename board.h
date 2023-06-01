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

    public:
        Board(const int &sizeBoard);
        Board(const vector<Tile*> &t) : sizeBoard(t.size()), board(t), randomEngine(random_device{}()) {}
        Board(const Board &other) : sizeBoard(other.sizeBoard), board(other.board), randomEngine(random_device{}()){}
        ~Board(){}

    void setSize(int sizeBoard) { this -> sizeBoard = sizeBoard; }
    int getSize(){ return sizeBoard; }
    vector<Tile*> getBoard(){ return board; }
    void setRandomTiles(int, int, Snake, Ladder);
    void printBoard () const;

    private:
        default_random_engine randomEngine;
        int randomPositions()
        {
            uniform_int_distribution<int> distribution(3, getSize() - 3);
            return distribution(randomEngine);
        }
};

Board::Board(const int &sizeBoard) : sizeBoard(sizeBoard), board(sizeBoard)
{
    for (int i = 0; i < sizeBoard; i++)
    {
        board.push_back(new Tile());
    }
    
}


void Board::setRandomTiles(int numSnakes, int numLadders,Snake s, Ladder l)
{
    for (int i = 0; i < numSnakes; ++i) 
    {
        int position = randomPositions();

        // Check if the position is occupied
        while (board[position] -> getType() != 'N') 
        {
            position = randomPositions();
            cout <<"pone serpientes" << endl;
        }

        board[position] = new Snake(s);
    }

    for (int i = 0; i < numLadders; ++i) 
    {
        int position = randomPositions();

        // Check if the position is occupied
        while (board[position] -> getType() != 'N') 
        {
            position = randomPositions();
            cout <<"pone escaleras" << endl;

        }

        board[position] = new Ladder(l);
    }
}



void Board::printBoard() const
{
    for (const auto& tile : board) 
    {
        cout << tile -> getType() << "\n";
    }
    cout << endl;
}