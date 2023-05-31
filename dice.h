#include <iostream>
#include <cstdlib>
using namespace std;

class Dice {
    const int faces; 

    public:
    Dice() : faces(6) {} // Constructor to data initialization
    Dice(const int &faces) : faces(faces) {} // Constructor with const data initialization
    Dice(const Dice& other) : faces(other.faces) {} //Copy constructor
    ~Dice() {} //Destructor

    int roll() //Method to roll dice
    {
        int result = rand() % faces + 1;
        return result; //Return the dice result
    }
};

