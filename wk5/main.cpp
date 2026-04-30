//George Smith Coding 1
//
//g++ main.cpp -o main && ./main

#include <iostream>
#include <string>
using namespace std;

//classes are custom variable types that have their own variables and functions.

//constructors
//getters and setters (privacy)
//instances
//inheritance (not today)

//my new variable type
class robot
{
private:
    string name;
    int charge;
    int boredom;
public:
    //constructor that sets up a class
    //must be same name as class
    robot(string givenName, int givenCharge, int givenBoredom)
    {
        name = givenName;
        charge = givenCharge;
        boredom = givenBoredom;
        status();
    }
    //overload constructor
    robot()
    {
        name = "bot";
        charge = 10;
        boredom = 0;
    }

    void status()
    {
        cout << "My name is " << name << ", my charge is " << charge << ".\n\n";

        cout << "I am ";
        if(boredom < 5)
        {
            cout << "happy";
        }
        else if(boredom < 10)
        {
            cout << "bored";
        }
        else if(boredom < 15)
        {
            cout << "frustrated";
        }
        else 
        {
            cout << "ENRAGED";
        }
        cout << ".\n\n";
    }
    void newDay()
    {
        boredom += 2;
    }
    void play()
    {
        boredom -= 1;
    }
    void setName(string givenName)
    {
        if(givenName.size() <= 5)
        {
            name = givenName;
        }
        else
        {
            cout << "Error. Name is too long.\n";
        }
    }
    void setCharge(int givenCharge)
    {
        //clamping
        if(givenCharge < 0)
        {
            charge = 0;
        }
        else if(givenCharge > 100)
        {
            charge = 100;
        }
        else 
        {
            charge = givenCharge;
        }
    }
    void setBoredom(int givenBoredom)
    {
        //clamping
        if(givenBoredom < 0)
        {
            boredom = 0;
        }
        else if(givenBoredom > 100)
        {
            boredom = 100;
        }
        else 
        {
            boredom = givenBoredom;
        }
    }
    string getName()
    {
        return name;
    }
    int getCharge()
    {
        return charge;
    }
    int getBoredom()
    {
        return boredom;
    }
    void changeChargeBy(int amount)
    {
        charge += amount;
    }
};  //Don't forget the semicolon

int main()
{
    cout << "Let's build some classes!\n\n";

    robot artoo("R2-D2", 97, 0);
    // artoo.name = "R2-D2";
    // artoo.charge = 97;
    // artoo.boredom = 0;

    robot threepio;
    threepio.setName("C-3P0");
    threepio.setCharge(3);
    threepio.setBoredom(10);
    threepio.status();


    cout << artoo.getName() << " notices that " << threepio.getName();
    cout << " doesn't have much battery left. Let's fix that!\n\n";

    cout << "Transfering power...\n\n";
    while(threepio.getCharge() < 15)
    {
        artoo.changeChargeBy(-1);
        threepio.changeChargeBy(1);
    }

    cout << threepio.getName() << "'s charge is now " << threepio.getCharge() << ".\n";
    cout << artoo.getName() << "'s charge is now " << artoo.getCharge() << ".\n";

    string input = "";
    int turns = 0;

    while(true)
    {
        while(turns < 3)
        {
            cout << "What would you like to do?\n";
            getline(cin, input);

            if(input == "play")
            {
                cout << "\nLet's play with " << artoo.getName() << "!\n";
                artoo.play();
            }
            else if(input == "status")
            {
                artoo.status();
            }
            else if(input == "wait")
            {
                turns = 2;
            }
            turns++;
        }
        turns = 0;
        cout << "Do you want to keep playing?\n";
        getline(cin, input);

        if(input == "no")
        {
            break;
        }
        artoo.newDay();
    }

    return 0;
}