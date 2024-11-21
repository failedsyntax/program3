#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>

using namespace std;

class Pokemon {
    private:
        int Index;
        string Name;

    public:
        Pokemon() {
            Index = 0;
            Name = "None";
        };

        Pokemon(int newIndex, string newName) {
            Index = newIndex;
            Name = newName;
        };

        void setID(int newID) {
            Index = newID;
        }

        void setName(string newName) {
            Name = newName;
        };

        int getID() {
            return Index;
        };

        string getName() {
            return Name;
        };

        friend ostream & operator<< (ostream& os, Pokemon Item) {
            os << "Pokemon ID: " << Item.getID() << "      |      Name: " << Item.getName() << endl;
        }

        friend bool operator== (const Pokemon &Left, const Pokemon &Right) {
            return Left.Index == Right.Index;
        }

        friend bool operator< (const Pokemon &Left, const Pokemon &Right) {
            return Left.Index < Right.Index;
        }
};

#endif