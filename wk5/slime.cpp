//George Smith Coding 1
//class inheritance and header files
//g++ slime.cpp -o slime && ./slime

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

//global vector of names any function can use
vector<string> slimeNames = {"Tombow", "Cheryl", "Escobar", "Inigo", "Franz"};

class baseSlime
{
public:
    string name;
    int health;
    int damage;

    baseSlime()
    {
        name = slimeNames[rand() % slimeNames.size()] + " Slime";
        health = rand() % 5 + 5;
        damage = rand() % 6 + 3;
    }
    baseSlime(string setName, int setHealth, int setDamage)
    {
        name = setName;
        health = setHealth;
        damage = setDamage;
    }

    void hello()
    {
        cout << "My name is " << name << ".\nI have " << health << " health and " << damage << " damage.\n\n";
    }

    bool attack(baseSlime& opponent)
    {
        opponent.health -= damage;
        cout << "Ooh! " << name;
        switch (rand() % 4) 
        {
            case 0:
                cout << " punches ";
                break;
            case 1:
                cout << " kicks ";
                break;
            case 2:
                cout << " stabs ";
                break;
            case 3:
                cout << " blasts ";
                break;
        }
        cout << opponent.name << " for " << damage << " damage!\n\n";
        if(opponent.health <= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    srand(time(0));
    cout << "Let's make some slimes fight!\n\n";

    baseSlime ricky("Richard Slime", 10, 4);
    
    baseSlime beth("Elizabeth Slime", 12, 5);

    baseSlime randomSlime;
    
    ricky.hello();
    beth.hello();
    randomSlime.hello();

    cout << "Creating our glob of slimes...\n\n";
    vector<baseSlime> glob(6);

    // for(int i = 0; i < glob.size(); i++)
    // {
    //     glob[i].hello();
    // }
    for(baseSlime slime : glob)
    {
        slime.hello();
    }

    cout << "Let's have Ricky and Beth fight!\n";
    baseSlime temp, temp2;
    baseSlime& fighterA = temp;
    baseSlime& fighterB = temp2;

    if(rand() % 2 == 0)
    {
        cout << "Ricky goes first!\n\n";
        fighterA = ricky;
        fighterB = beth;
    }
    else 
    {
        cout << "Beth goes first!\n\n";
        fighterA = beth;
        fighterB = ricky;
    }
    while(fighterA.health > 0 && fighterB.health > 0)
    {
        if(fighterA.attack(fighterB))
        {
            cout << fighterB.name << " has been defeated!\n";
        }
        else
        {
            if(fighterB.attack(fighterA))
            {
                cout << fighterA.name << " is freaking dead!\n";
            }
        }
    }

    return 0;
}