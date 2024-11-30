#include "BinaryTree.h"
#include "Pokemon.h"
using namespace std;

int main() {
    BinaryTree<Pokemon> pokedex;
    ifstream inputFile("pokedex.txt");
    string name;
    int index = 0;
    int numOfPokemon = 0;
    if(!inputFile){
        cout << "Error opening pokedex.txt";
        return -1;
    }

    while(inputFile >> index >> name){
        Pokemon pokemon(index, name);
        if(!pokedex.searchNode(pokemon)){
            pokedex.insertNode(pokemon);
            cout << "Inserting Pokemon with index " << index << "into the Pokedex. " << endl;
            numOfPokemon ++;
        }
        else{
            cout << "Oops! The Pokemon with the index " << index << "is already in the Pokedex. " << endl; 
        }
    }

    inputFile.close();

    cout << numOfPokemon << " Pokemon have been added to the Pokedex! " << endl;

    cout << "************************POKEDEX:************************" << endl;
    pokedex.displayInOrder();

    

    return 0;
}