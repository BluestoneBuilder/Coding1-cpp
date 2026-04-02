//George Smith, Coding 1, Sring 2026
//Switch, random numbers, and while loops

//You task... create the rest of the code to say "Random Numbers!"
//Then run the program.

//Open terminal
//use "cp path/to/folder" to navigate to the path of the c++ file
//"cd GitHub/Coding1-cpp/wk1" for this script
//compile with "g++ rand.cpp -o rand"
//then run with "./rand"

#include <iostream>
//#include <random> //for random numbers
//rand function seems to be included in the compiler
#include <ctime> //for seeding the random numbers
using namespace std;

int main() 
{
    srand(time(0)); //seed the random number generator with the current time
    cout << "Random Numbers!\n\n";

    cout << "Our first random number is " << rand() << ".\n";
    
    cout << "Here are 10 random numbers.\n";
    int counter = 0;
    while (counter++ < 10)
    {
        cout << (rand() % 10) + 1 << endl; //modulus opperator (%) divides random number by 10 and outputs remainder
                                     //This will give us a random number 0-9, so we add 1
    }

    //guess the number game
    
    //computer picks number between 1 and 10 (inclusive)
    int theNumber = (rand() % 10) + 1;
    //player guesses
    int guess = -1;
    do{
        cout << "What is your guess?\n";
        cin >> guess;
        //computer evaluates guess, outputs 
            //correct
            if(theNumber == guess)
            {
                cout << "You guessed it!\n";
                
            }
            //too high
            else if(guess > theNumber)
            {
                cout << "That guess is too high!\n";
            }
            //too low
            else if(guess < theNumber)
            {
                cout << "That guess is too low!\n";
            }
        //output answer
        //let player guess again if incorrect
    } while(guess != theNumber);
    return 0;
}