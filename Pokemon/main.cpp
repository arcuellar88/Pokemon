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


    // Default Constructor
    Pokemon() {
        name="Pikachu";
        number = 0;
        type = PokemonType::Electric;
        character="";
        health = 10;

    }
    // Copy constructor
    Pokemon(const Pokemon &other) {
        name = other.name;
        number = other.number;
        type = other.type;
        character=other.character;
        health = other.health;
    }

    // Constructor
    Pokemon(string& n, PokemonType t, int h) : name(n), type(t), health(h) {character="";number=0;}
    Pokemon(string&& n, PokemonType t,int h) : name(std::move(n)), type(t), health(h) {character="";number=0;}

    Pokemon(string& n, const int nr, PokemonType t, string& c) : name(n), number(nr), type(t), character(c) {health = 100;}
    Pokemon(string&& n, const int nr, PokemonType t,string&& c) : name(std::move(n)), number(nr), type(t), character(std::move(c)) {health = 100;}

    Pokemon(string& n, const int nr, PokemonType t, int h) : name(n), number(nr), type(t), health(h) {character="";}
    Pokemon(string&& n, const int nr, PokemonType t,int h) : name(std::move(n)), number(nr), type(t), health(h) {character="";}

    // Destructor
    ~Pokemon() {
        cout << "Pokemon is getting destroyed"<< endl;
        // Perform cleanup operations here, e.g., save player data to a file or log a message.
    }

    //Methods
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

    // Default constructor
    Player() {
        name="Trainer";
        pokemon = Pokemon();
    }
    Player(const string& p_name):name(p_name){  cout << "hello " << name << endl;}
    Player(string&& p_name):name(std::move(p_name)){cout << "hello " << name << endl;}

    Player(const string& p_name, const Pokemon &p_pokemon) {
        name=p_name;
        pokemon=p_pokemon;
        cout << "hello " << name << endl;
    }

    // Copy constructor
    Player(const Player &other) {
        name=other.name;
        pokemon=other.pokemon;
    }

    //Destructor
    ~Player() {
        cout << "Player is getting destroyed" << endl;
    }

    void choosePokemon(const int choice) {

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

    Pokemon  b("Bulbasaur",2,PokemonType::Earth, 100);
    Pokemon cb=b;

    cout<< b.name << " "<< (int)b.type << " Health: " << b.health << endl;
    cout<< cb.name << " "<< (int)cb.type <<  " Health: " << cb.health << endl;

    cb.health=80;

    cout<< b.name << " "<< (int)b.type << " Health: " << b.health << endl;
    cout<< cb.name << " "<< (int)cb.type <<  " Health: " << cb.health << endl;


    {
        Pokemon squirtle("Squirtle",2, PokemonType::Water, 100); // Pokemon will be destroyed at the end of this scope
    }

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