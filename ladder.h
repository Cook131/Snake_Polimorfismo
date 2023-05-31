#include <iostream>
using namespace std;

#include "tile.h"
#pragma once 

class Ladder : public Tile {
    public:
        Ladder () : Tile('L',3) {} // Constructor to data initialization                                                             
        Ladder(const char &type) : Tile(type,move) {} // Constructor with const data initialization
        int Climb() { return getMove(); }
        ~Ladder() {}
};