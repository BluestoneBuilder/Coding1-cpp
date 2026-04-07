//George Smith
//Arrays, loops, and vectors

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{
    srand(time(0));

    cout << "Let's learn about arrays!\n";
    //arrays have a defined size
    //arrays can't count their contents

    cout << "Creating an array of high scores!\n";
    //declaring a new integer array with a size of 5
    int highScores[5];

    highScores[0] = 4550;   //Setting the first high score
    highScores[1] = 2215;
    highScores[4] = 11;     //Last high score at i = 4

    cout << "The first score is " << highScores[0] << ".\n";
    cout << "Here are all of the high scores:\n";

    int index = 0;
    while(index < 5)
    {
        cout << highScores[index] << endl; //can replace endl with "\n"
        index++;
    }

    cout << "Let's learn about for loops to show the scores again.\n";
    for(int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << highScores[i] << "\n";
    }

    string names[10];
    string input;
    index = 0;  //reset index var
    while(index < 10)
    {
        cout << "What name would you like to add? (Type 'done' to stop)\n";
        cin >> input;
        if(input == "done")
        {
            cout << "We are done entering names.\n";
            break;
        }
        names[index++] = input; //having ++ after name of int makes it occur after the name is set. ex: 'index++'
                                //putting ++ before would add to int before name is set. ex: '++index'
    }
    cout << "Here's your names:\n";
    for(int i = 0; i < index; i++){
        cout << i + 1 << ". " << names[i] << "\n";
    }
    string name = names[rand() % index];
    cout << "Don't get me started about " << name << ".\n";
    switch(rand() % 4)
    {
        case 0:
            cout << "I love " << name << "!\n";
            break;
        case 1:
            cout << "I like " << name << " I guess.\n";
            break;
        case 2:
            cout << "I don't like " << name << ". They kinda suck.\n";
            break;
        case 3:
            cout << "I hate " << name << " with every fiber of my being!\n";
            break;
    }

    return 0;
}