//George Smith Coding 1 Spring 2026
//Our first c++ program
//Open terminal
//use "cp 'FolderName'"" to navigate to the path of the c++ file
//compile with "g++ main.cpp -o main"
//then run with "./main"

#include <iostream>     //in-out stream for sending text to the console
#include <string>       //for player name

using namespace std;    

//So we dont have to type "std::" all the time
//this is where our program starts running code
int main() 
{
    string playerName;                  //variable name written in camelCase

    //ask the player their name
    cout << "What is your name, player? ";

    //get input from player with cin
    cin >> playerName;

    cout << "Hello " << playerName << "." << endl;
    cout << "Do you like video games? ";
    string playerAnswer;
    cin >> playerAnswer;
    if(playerAnswer == "Yes")
    {
        cout << "Me too! Sick, " << playerName <<"! Let's play a game." << endl;
        cout << "You find yourself wandering through the woods. It's dark and dreary. The trees seem to close in around you on all sides. Just then, you hear a twig snap not far behind you. You look and see two glowing eyes. What do you do? (Run / Pet) ";
        cin >> playerAnswer;
        if(playerAnswer == "Run")
        {
            cout << "You try to run, but it seems to gain on you no matter how fast your legs move. You are tackled to the ground and devoured, never to be seen again." << endl;
        }
        else if(playerAnswer == "Pet")
        {
            cout << "You reach your hand out slowly. It turns out to be a dog. You pet it and decide to name it Beans. You live happily ever after with your new dog. Good job, " << playerName << "!" << endl;
        }
        else
        {
            cout << "That was not one of the options I gave you. It bites your face off and you die." << endl;
        }
    }
    else if(playerAnswer == "No")
    {
        cout << "That's a shame. I had this whole game planned out and everything, but it's whatever I guess. Goodbye, " << playerName << "." << endl;
    }
    else
    {
        cout << "It was a yes or no question, " << playerName << "." << endl;
    }

    //cout << "Hello World!" << endl;     //cout for console out
                                        //endl for end line
    return 0;
}