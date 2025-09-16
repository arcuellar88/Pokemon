#include<iostream>

using namespace std;

enum class PokemonType {Fire, Electric, Water, Earth, Normal};

class Pokemon {
public:   // access specifier
    string name;
    int number;
    PokemonType type;
    string character;
    int health;


    Pokemon() {
        name = "";
        number = 0;
        type = PokemonType::Normal;
        character="";
        health = 100;

    }

    // Constructor
    Pokemon(string& n, const int nr, PokemonType t, string& c) : name(n), number(nr), type(t), character(c) {health = 100;}
    Pokemon(string&& n, const int nr, PokemonType t,string&& c) : name(std::move(n)), number(nr), type(t), character(std::move(c)) {health = 100;}

    void attack() const{ cout << name << "attacks with a powerful move!\n"; }

    // Method
     void selection() const {
        cout  << number << ". " << name << endl;
    }
    void selected() const {
        cout << "Professor Oak: " << name << "! A " << character << " choice." << endl;;
    }

};

class Player {
    public:
    string name;
    Pokemon pokemon;

    Player(string& p_name):name(p_name){  cout << "hello " << name << endl;}
    Player(string&& p_name):name(std::move(p_name)){cout << "hello " << name << endl;}

    void choosePokemon(int choice) {

        switch (choice) {
            case 1:
                pokemon=Pokemon( "Bulbasaur",1,PokemonType::Earth,"wise");
                break;
            case 2:
                pokemon=Pokemon( "Charmander",2,PokemonType::Fire,"fiery");
                break;
            case 3:
                pokemon=Pokemon( "Squirtle",3,PokemonType::Water,"cool");
                break;
            default:
                cout << "Hmm, that doesn't seem right. Let me choose for you...\n" << endl;

                pokemon=Pokemon("Pikachu",4,PokemonType::Electric,"humble");
        }

            pokemon.selected();
    }

};

class ProfessorOak {
    public:
    string name;
    string pokemons_choices[3]={
        "1. Bulbasaur",
        "2. Charmander",
        "3. Squirtle"
    };
    ProfessorOak(string& p_name):name(p_name){}
    ProfessorOak(string&& p_name):name(std::move(p_name)){}


    void talk(const string& message) {
        cout << name << " : " << message << endl;
    }

    void greetPlayer(Player &player) {
        talk("Hello there! Welcome to the world of Pokemon!");
        talk("My name is Oak. People call me the Pokemon Professor!");
        talk("But enough about me. Let's talk about you!");
    }

    void offerPokemonChoices(Player &player) {

        talk("Please choose a POKEMON. Enter the number:");

        for (string p : pokemons_choices) {
            cout << "   - "<<p << endl;
        }

        int choice;
        cin >> choice;

        player.choosePokemon(choice);
    }

};
int main(){

    ProfessorOak po= ProfessorOak("Professor Oak");

    string player_name;

    // Write (output) to console
    cout << "Enter your name: ";

    // Read (input) from console
    cin >> player_name;

    auto* player = new Player(player_name);

    po.greetPlayer(*player);
    po.offerPokemonChoices(*player);

    po.talk(player->pokemon.name + " and you, " + player->name +", are going to be the best of friends!");

    po.talk("Your journey begins now! Get ready to explore the vast world of Pokemon!");


    delete player;
    return 0;
}