#include <iostream>
#include <string>
using namespace std;

#pragma once

class Person {
    private:
        string name;
    
    public:
        Person() {}
        Person(const string& name) : name(name) {}
        Person(const Person &otro) : name(otro.name) {}
        ~Person(){}

        string getName() const { return name; }
        void setName(const string& name) { this -> name = name; }
};