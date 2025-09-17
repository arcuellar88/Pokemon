#include<iostream>
#include <cstdlib>

using namespace std;

enum class PokemonType {Fire, Electric, Water, Earth, Normal};

void clear_console() {
    system("clear");
};

void wait_for_enter() {
    cin.get();
};


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
        //cout << "Pokemon is getting destroyed"<< endl;
        // Perform cleanup operations here, e.g., save player data to a file or log a message.
    }

    //Methods
    void attack() const{ cout << name << "attacks with a powerful move!\n"; }

    // Method
     void selection() const {
        cout  << number << ". " << name << endl;
    }
    void
    selected() const {
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
        //cout << "Player is getting destroyed" << endl;
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


    void talk(const string& message, const int wait=1) {

        if (wait == 1) {
            talk_with_pause(name, message);
        }
        else {
            talk_without_pause(name, message);
        }
    }
    void talk(const string& message, Player &player,const int wait=1) {
        if (wait == 1) {
            talk_with_pause(player.name, message);
        }
        else {
            talk_without_pause(player.name, message);
        }
    }

    void greetPlayer(Player &player) {
        talk("Hello there! Welcome to the world of Pokemon!");
        talk("My name is Oak. People call me the Pokemon Professor!");
        talk("But enough about me. Let's talk about you!");
        talk("First, tell me, what’s your name? [Please Enter Your Name]:",0);
        string player_name;

        // Read (input) from console
        cin >> player_name;
        player.name = player_name;

        wait_for_enter(); // Skip default enter after user input

        talk("Ah, "+player.name+"! What a fantastic name!",1);

        cout<<"H";
    }

    void offerPokemonChoices(Player &player) {

        talk("You must be eager to start your adventure. But first, you’ll need a Pokemon of your own!");
        talk("I have three Pokemon here with me. They’re all quite feisty!");
        string choices="Choose wisely... [Enter the number]:\n";


        for (string p : pokemons_choices) {
           choices+="   - "+p+"\n";
        }
        talk(choices,0);

        int choice;
        cin >> choice;

        player.choosePokemon(choice);

        wait_for_enter(); // Skip default enter after user input

        talk(player.pokemon.name + " and you, " + player.name +", are going to be the best of friends!");

        talk("Your journey begins now! Get ready to explore the vast world of Pokemon!");

    }
    void explainQuest(Player &player) {
        talk("Oak-ay  "+player.name+", I am about to explain you about your upcoming grand adventure.");
        talk("You see, becoming a Pokémon Master is no easy feat. It takes courage, wisdom, and a bit of luck.");
        talk("Your mission, should you choose to accept it (and trust me, you really don’t have a choice) is to collect all the Pokémon Badges and conquer the Pokémon League.");
        talk("Wait... that sounds a lot like every other Pokémon game out there.",player);
        talk("Shhh! Don't break the fourth wall "+player.name+"! This is serious business.");
        talk("To achieve this, you’ll need to battle wild Pokémon, challenge gym leaders, and of course, keep your Pokémon healthy at the PokeCenter.");
        talk("Along the way, you'll capture new Pokémon to strengthen your team. Just remember—there’s a limit to how many Pokémon you can carry, so choose wisely!");
        talk("Sounds like a walk in the park... right?",player);
        talk("h! That’s what they all say! But beware, young Trainer, the path to victory is fraught with challenges. And if you lose a battle... well, let’s just say you'll be starting from square one.");
        talk(", what do you say? Are you ready to become the next Pokémon Champion?");
        talk("Ready as I’ll ever be, Professor!",player);
        talk("at’s the spirit! Now, your journey begins.");
        talk("t first... let's just pretend I didn't forget to set up the actual game loop... Ahem, onwards!");

    }
private:
    void talk_without_pause(const string& voice, const string& message) const {
        cout << voice << " : " << message  << endl;
    }
    void talk_with_pause(const string& voice, const string& message) const {
        cout << voice << " : " << message << " [ Press enter to continue...]";
        wait_for_enter();
    }



};


  void gameLoop(Player &player) {
    int choice;
    bool keepPlaying = true;

    while (keepPlaying) {
        // Clear console before showing options
        clear_console();

        // Display options to the player
        cout << "\nWhat would you like to do next, " << player.name << "?\n";
        cout << "1. Battle Wild Pokémon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge Gyms\n";
        cout << "4. Enter Pokémon League\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear the newline character left in the buffer after cin >> choice
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        // Process the player's choice and display the corresponding message
        switch (choice) {
            case 1:
                cout << "You look around... but all the wild Pokémon are on "
                             "vacation. Maybe try again later?\n";
                break;
            case 2:
                cout
                    << "You head to the PokeCenter, but Nurse Joy is out on a coffee "
                       "break. Guess your Pokémon will have to tough it out for now!\n";
                break;
            case 3:
                cout << "You march up to the Gym, but it's closed for renovations. "
                             "Seems like even Gym Leaders need a break!\n";
                break;
            case 4:
                cout << "You boldly step towards the Pokémon League... but the "
                             "gatekeeper laughs and says, 'Maybe next time, champ!'\n";
                break;
            case 5:
                cout << "You try to quit, but Professor Oak's voice echoes: "
                             "'There's no quitting in Pokémon training!'\n";
                cout << "Are you sure you want to quit? (y/n): ";
                char quitChoice;
                cin >> quitChoice;
                if (quitChoice == 'y' || quitChoice == 'Y') {
                    keepPlaying = false;
                }
                break;
            default:
                cout << "That's not a valid choice. Try again!\n";
                break;
        }
    }
    cout << "Goodbye, " << player.name << "! Thanks for playing!\n";

};

int main(){

    ProfessorOak po= ProfessorOak("Professor Oak");

    Player player = Player();

    po.greetPlayer(player);


    clear_console();

    po.offerPokemonChoices(player);

    clear_console();

    po.explainQuest(player);

    clear_console();

    // Placeholder for where the game loop will start
    gameLoop(player);
    return 0;
}
