// --- SNAKE CLASS ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
using namespace std;
#include "tile.h"
#pragma once 

class Snake : public Tile {
    public:
        Snake () : Tile('S',-3) {} // Constructor to data initialization                                                             
        Snake(const char &type, const int &move) : Tile(type,move) {} // Constructor with const data initialization
        int Slide() { return getMove(); } //Snake movement
        ~Snake() {} //Destructor
};