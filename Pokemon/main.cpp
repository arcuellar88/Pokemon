#include<iostream>

using namespace std;

enum class PokemonType {Fire, Electric, Water, Earth, Normal};

class Pokemon {
public:   // access specifier
    string name;
    int number;
    PokemonType type;
    string character;


    Pokemon() {
        name = "";
        number = 0;
        type = PokemonType::Normal;
        character="";

    }

    // Constructor
    Pokemon(string& n, const int nr, PokemonType t, string& c) : name(n), number(nr), type(t), character(c) {}
    Pokemon(string&& n, const int nr, PokemonType t,string&& c) : name(std::move(n)), number(nr), type(t), character(std::move(c)) {}

    // Method
     void selection() const {
        cout  << number << ". " << name << endl;
    }
    void selected() const {
        cout << "Professor Oak: You chose " << name << " A " << character << " choice." << endl;;
    }

};

enum class PokemonChoice {
    Bulbasaur,
    Charmander,
    Squirtle,
    InvalidChoice,
};

int main(){

    PokemonChoice chosen_pokemon=PokemonChoice::InvalidChoice;
    Pokemon pokemon;

    string player_name;

    // Write (output) to console
    cout << "Enter your name: ";

    // Read (input) from console
    cin >> player_name;

    cout << "Great Start " << player_name << ", looks like you have understood the main() function properly now!" << endl;

    int pokemon_id;

    Pokemon pokemons_choices[4]={
        Pokemon( "Bulbasaur",1,PokemonType::Earth,"wise"),
        Pokemon( "Charmander",2,PokemonType::Fire,"fiery"),
        Pokemon( "Squirtle",3,PokemonType::Water,"cool"),
        Pokemon("Pikachu",4,PokemonType::Electric,"humble")
    };

    cout << "Hello! I am Professor Oak. Please choose a POKEMON. Enter the number:" << endl;

    for (Pokemon p : pokemons_choices) {
        if (p.number < 4) {
            p.selection();
        }
    }

    int choice;
    cin >> choice;

    if (choice>3 || choice<1){
        cout << "Professor Oak: Hmm, that doesn't seem right. Let me choose for you...\n" << endl;
        pokemon = pokemons_choices[3]; // Default if no valid choice is made
        cout << "Professor Oak: Just kidding! Let's go with Pikachu, the surprise guest!\n";
    }
    else {
        pokemon=pokemons_choices[choice-1];
        pokemon.selected();
    }

    cout << "Ah, an excellent choice!" << endl;
    cout << "But beware, Trainer," << endl;
    cout << "this is only the beginning." << endl;
    cout << "Your journey is about to unfold." << endl;
    cout << "Now let’s see if you’ve got what it takes to keep going!" << endl;
    cout << "Good luck, and remember… Choose wisely!"<< endl;


    return 0;
}