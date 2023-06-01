// --- PERSON CLASS  ---
// Jorge Luis Nájera Espinosa - A01424106
// Andrea Carolina Figueroa Orihuela - A01424250

#include <iostream>
#include <string>
using namespace std;

#pragma once

class Person {
    private:
        string name;
    
    public:
        Person() {} //Empty constructor
        Person(const string& name) : name(name) {} //Constructor with name as input which will be inherited
        Person(const Person &otro) : name(otro.name) {} //Copy constructor which will be inherited
        ~Person(){} //Destructor

        string getName() const { return name; } //Getter of player's name
        void setName(const string& name) { this -> name = name; } //Setter of player's name
};