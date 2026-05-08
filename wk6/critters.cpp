//George Smith Coding 1
//final assignment. Pokemon
//g++ critters.cpp -o critters && ./critters

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <xlocale/_wchar.h>

using namespace std;
vector<string> globalNames;
void fetchNamesFromFile()
{
    globalNames.clear();
    string line;
    ifstream file("pokenames.txt");
    if(file.is_open())
    {
        while(getline(file, line))
        {
            globalNames.push_back(line);
        }
    }
    file.close();
}
class Pokemon
{
    string name;
    int currentHealth;
    int maxHealth;
    int damage;
    int hunger;
    bool isDead;
public:
    //Be sure to instantiate after fetchNames is called
    Pokemon()
    {
        name = globalNames[rand() % globalNames.size()];
        maxHealth = rand() % 10 + 25;
        currentHealth = maxHealth;
        damage = rand() % 5 + 5;
        hunger = rand() % 3;
        isDead = false;
        if(rand() % 100 > 98)
        {
            name = "Mega " + name;
            maxHealth += 100;
            damage += 100;
            currentHealth = maxHealth;
        }
    }
    void Hello()
    {
        cout << "\nHi trainer! My name is " << name << "!\nMy stats are:\n";
        cout << "Max Health: " << maxHealth << endl;
        cout << "Current Health: " << currentHealth << endl;
        cout << "Damage: " << damage << endl;
        cout << "Hunger: " << hunger << endl;
        cout << "I am ";
        if(isDead)
            cout << "dead :D\n";
        else
        {
            if(currentHealth <= 15)
                cout << "mildly injured.\n";
            else if(currentHealth <= 10)
                cout << "injured.\n";
            else if (currentHealth <= 5)
                cout << "in critical condition!\n";
            else
                cout << "alive and thriving!\n";
        }
    }
    bool AttackOpponent(Pokemon& opponentBeingAttacked)
    {
        opponentBeingAttacked.TakeDamage(damage);
        cout << "\n" << name << " attacked " << opponentBeingAttacked.GetName() << " for " << damage << " damage!\n";
        return opponentBeingAttacked.GetDeathStatus();
    }
    string GetName()
    {
        return name;
    }
    void SetName(string newName)
    {
        name = newName;
    }
    int GetCurrentHealth()
    {
        return currentHealth;
    }
    void TakeDamage(int damage)
    {
        currentHealth -= damage;
        if(currentHealth <= 0)
        {
            currentHealth = 0;
            isDead = true;
        }
    }
    void Heal(int amount)
    {
        currentHealth += amount;
        if(currentHealth > maxHealth)
            currentHealth = maxHealth;
        if(currentHealth > 0)
            isDead = false;
    }
    int GetMaximumHealth()
    {
        return maxHealth;
    }
    void LevelHealth(int changeBy)
    {
        maxHealth += changeBy;
    }
    int GetDamage()
    {
        return damage;
    }
    void LevelDamage(int changeBy)
    {
        damage += changeBy;
    }
    int GetHunger()
    {
        return hunger;
    }
    void IncrementHunger(int changeBy)
    {
        hunger += changeBy;
        if(hunger < 0)
            hunger = 0;
    }
    bool GetDeathStatus()
    {
        return isDead;
    }
};
int main()
{
    cout << "Let's play Pokemon!\n";
    srand(time(0));
    string input;
    fetchNamesFromFile();
    // name a 'critter' (or 'monster', or 'robot', or 'slime', or 'puppy' - whatever you like!)
    Pokemon playerPokemon;
    //Introduce player to their randomly chosen pokemon
    playerPokemon.Hello();
    vector<Pokemon> opponents(6);
    while(true)
    {
        cout << "\nWhat would you like to do with your Pokemon?\n(feed, train, listen, battle, heal, rename, pokedex, quit game)\n";
        getline(cin, input);
        // feed their critter
        if(input == "feed")
        {
            if(playerPokemon.GetDeathStatus())
            {
                cout << "\nUm... Your Pokemon is dead, man.\n";
                cout << "You attempt to feed it but it just lays there...\n";
                cout << "Please do consider healing you Pokemon.\n";
            }
            else
            {
                playerPokemon.IncrementHunger(-5);
                cout << "\nYou have fed your Pokemon!\nTheir hunger is now " << playerPokemon.GetHunger() << ".\n";
            }
        }
        // train their critter (chance to increase health or damage)
        else if(input == "train")
        {
            if(playerPokemon.GetDeathStatus())
            {
                cout << "\nUm... Your Pokemon is dead, man.\n";
                cout << "You attempt to train it but it just lays there...\n";
                cout << "Please do consider healing you Pokemon.\n";
            }
            else
            {
                if(playerPokemon.GetHunger() >= 10)
                {
                    cout << "\nSorry, your Pokemon is too hungry to train right now. Consider feeding them.\n";
                }
                else
                {
                    if(playerPokemon.GetHunger() >= 5)
                    {
                        cout << "\nYour Pokemon is starting to get hungry. Consider feeding them.\n";
                    }
                    cout << "\nTraining...\n";
                    playerPokemon.IncrementHunger(2);
                    int damageGained = rand() % 3;
                    playerPokemon.LevelDamage(damageGained);
                    int healthGained = rand() % 3;
                    playerPokemon.LevelHealth(healthGained);
                    if(damageGained > 0)
                    {
                        cout << "\nCongratulations! Your damage has been leveled up to " << playerPokemon.GetDamage();
                        if (healthGained > 0)
                        {
                            cout << ", and your health has been leveled up to " << playerPokemon.GetMaximumHealth();
                        }
                        cout << "!\n";
                    }
                    else 
                    {
                        if(healthGained > 0)
                        {
                            cout << "\nCongratulations! Your health has been leveled up to " << playerPokemon.GetMaximumHealth() << "!\n";
                        }
                        else 
                        {
                            cout << "\nSorry, your Pokemon didn't learn anything.\n";
                        }
                    }
                }
            }
        }
        // listen to their critter (display health, damage, and hunger)
        else if(input == "listen")
        {
            if(playerPokemon.GetDeathStatus())
                cout << "...\n";
            else
                playerPokemon.Hello();
        }
        else if(input == "heal")
        {
            if(playerPokemon.GetCurrentHealth() == playerPokemon.GetMaximumHealth())
                cout << "\nYour Pokemon doesn't need healed right now.\n";
            else
            {
                cout << "\nHealing your Pokemon...\n";
                playerPokemon.Heal(playerPokemon.GetMaximumHealth() - playerPokemon.GetCurrentHealth());
                cout << "\nYour Pokemon has been restored to full health!\n";
            }
        }
        // battle other critters, with options to
        else if(input == "battle")
        {
            cout << "\nTime to battle! ";
            Pokemon& opponent = opponents[rand() % opponents.size()];
            bool atLeastOneAlive = false;
            while(true)
            {
                for(Pokemon& potentialOpponent : opponents)
                {
                    if(!potentialOpponent.GetDeathStatus())
                        atLeastOneAlive = true;
                }
                if(atLeastOneAlive)
                {
                    cout << "Your opponent is " << opponent.GetName() << "!\n";
                    if(opponent.GetDeathStatus())
                    {
                        cout << "\nOh... Nevermind. That one is dead. We'll... uh... get you a new opponent.\n";
                        opponent = opponents[rand() % opponents.size()];
                    }
                    else
                    {
                        break;
                    }
                }
                else 
                {
                    cout << "\nWell, it looks like you've defeated every enemy I have for you. Congratulations. There isn't much left for you now. You'll just have to fight yourself.\n";
                    opponent = playerPokemon;
                    cout << "Your opponent is " << opponent.GetName() << "!\n";
                    break;
                }
            }
            while(true)
            {
                if(playerPokemon.GetDeathStatus())
                {
                    cout << "Um... Your Pokemon is dead, man.\n";
                    cout << opponent.GetName() << " wins by default!\n";
                    cout << "Please do consider healing you Pokemon.\n";
                    break;
                }
                if(playerPokemon.GetHunger() >= 10)
                {
                    cout << "Sorry, it looks like your Pokemon is too hungry to battle. " << opponent.GetName() << " wins by default!\n";
                    break;
                }

                //battle status
                cout << "\nYour health is at " << playerPokemon.GetCurrentHealth() << "!\n";
                cout << opponent.GetName() << "'s Health is at " << opponent.GetCurrentHealth() << "!\n";
                
                //Player's turn
                cout << "\nWhat will you do?\n(attack, heal, run away)\n";
                getline(cin, input);
                // attack
                if(input == "attack")
                {
                    if(playerPokemon.AttackOpponent(opponent))
                    {
                        //enemy died
                        cout << "\n" << opponent.GetName() << " has died! You win! Congratulations!\n";
                        break;
                    }
                }
                // heal
                else if(input == "heal")
                {
                    cout << "\nYou heal for 5 HP!\n";
                    playerPokemon.Heal(10);
                }
                // run away
                else if(input == "run" || input == "run away")
                {
                    cout << "\nYou run away, so " << opponent.GetName() << " wins by default!\n";
                    break;
                }
                else 
                {
                    cout << "\n" << playerPokemon.GetName() << " does nothing!\n";
                }
                
                //battle status
                cout << "\nYour health is at " << playerPokemon.GetCurrentHealth() << "!\n";
                cout << opponent.GetName() << "'s Health is at " << opponent.GetCurrentHealth() << "!\n";
                
                //Enemy turn
                //use random number to pick choice. Give some more weight than others
                int healChance = rand() % 10;
                if(((opponent.GetCurrentHealth() < 10 && healChance > 3) || healChance > 7) && opponent.GetCurrentHealth() != opponent.GetMaximumHealth())
                {
                    opponent.Heal(5);
                    cout << "\n" << opponent.GetName() << " has healed for 5 HP!\n";
                }
                else
                {
                    int fleeChance = rand() % 10;
                    if(fleeChance > 0)
                    {
                        if(opponent.AttackOpponent(playerPokemon))
                        {
                            cout << "\n" << playerPokemon.GetName() << " has died. " << opponent.GetName() << " wins!\n";
                            break;
                        }
                    }
                    else
                    {
                        cout << "\n" << opponent.GetName() << " has fled from battle. You win!\n";
                        break;
                    }
                }
            }
            playerPokemon.IncrementHunger(5);
            atLeastOneAlive = false;
        }
        else if(input == "rename")
        {
            cout << "\nYour Pokemon is currently named " << playerPokemon.GetName();
            cout << ".\nWhat would you like to rename it to?\n";
            getline(cin, input);
            playerPokemon.SetName(input);
            cout << "\nYour Pokemon is now named " << input << "!\n";
        }
        else if(input == "pokedex")
        {
            cout << "\nWelcome to the PokeDex!";
            while(true){
                cout << "\nWould you like to see a list of current Pokemon, add one to the list, or exit the PokeDex?\n(list, add, exit)\n";
                getline(cin, input);
                if(input == "exit")
                {
                    cout << "\nClosing the PokeDex...\n";
                    break;
                }
                else if(input == "list")
                {
                    cout << "\nHere is a list of known Pokemon.\n\n";
                    string line;
                    ifstream file("pokenames.txt");
                    if(file.is_open())
                    {
                        while(getline(file, line))
                        {
                            cout << line << endl;
                        }
                    }
                    file.close();
                }
                else if(input == "add")
                {
                    cout << "\nWhat Pokemon would you like to add to the list?\n";
                    cout << "('name', back)\n";
                    getline(cin, input);
                    if(input != "back")
                    {
                        ofstream file;
                        file.open("pokenames.txt", ios::app);
                        file << "\n" << input;
                        file.close();
                        cout << "\nAdded " << input << " to the PokeDex!\n";
                    }
                    fetchNamesFromFile();
                }
                else
                {
                    cout << "\nUnknown command.\n";
                }
            }
        }
        else if(input == "lvlMax")
        {
            playerPokemon.LevelHealth(100);
            playerPokemon.LevelDamage(100);
            cout << "\nAdded 100 levels to both stats\n";
        }
        else if(input == "quit" || input == "quit game")
        {
            break;
        }
        else
        {
            cout << "Your Pokemon doesn't know what the heck you're saying.\n";
        }
    }



    // Your program needs the following features

    // a randomized list of names must be read from a separate text file
    // setters and getters must be implemented for all class variables (class variables should be private)
    // critter class must have a constructor
    // each battle or training adds 1 to the critter's hunger.
    // if their hunger is greater than 10, they can't train or battle.
    // if their hunger is greater than 5, they'll mention it each time they train or battle
    cout << "\nThanks for playing!" << endl;
    return 0;
}