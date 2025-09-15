#include<iostream>
#include <map>

using namespace std;


class Pokemon {
public:   // access specifier
    string name;
    int number;
    string type;

    Pokemon() {
        name = "";
        number = 0;
        type = "";
    }

    // Constructor
    Pokemon(string n, const int nr, string t) : name(n), number(nr), type(t) {}

    // Method
    void selection() {
        cout  << number << ". " << name << endl;
    }
    void selected() {
        cout << "You chose " << name << " A " << type << " choice." << endl;;
    }

};


int main(){

    string player_name;
    // Write (output) to console
    cout << "Enter your name: ";

    // Read (input) from console
    cin >> player_name;

    cout << "Great Start " << player_name << ", looks like you have understood the main() function properly now!" << endl;

    int pokemon_id;

    Pokemon pokemons[3]={
        Pokemon( "Bulbasaur (Grass)",1,"wise"),
        Pokemon( "Charmander (Fire)",2,"fiery"),
        Pokemon( "Squirtle (Water)",3,"cool")
    };

    cout << "Hello! I am Professor Oak. Please choose a POKEMON. Enter the number:" << endl;

    for (Pokemon p : pokemons) {
        p.selection();
    }

    cin>> pokemon_id;

    if (pokemon_id>3 || pokemon_id<1){
        cout << "Invalid choice. Please restart the game." << endl;
    }
    else {
        pokemons[pokemon_id-1].selected();
    }

    return 0;
}