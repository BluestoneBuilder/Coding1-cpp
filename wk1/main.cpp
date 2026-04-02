//George Smith, Coding 1, Spring 2026
//Using VS Codium and its integrated terminal
//to learn about variables and logic

//Open terminal
//use "cp path/to/folder" to navigate to the path of the c++ file
//"cd GitHub/Coding1-cpp/wk1" for this script
//compile with "g++ main.cpp -o main"
//then run with "./main"

#include <iostream>

#include <ctime> //for seeding the random number generator
using namespace std;

int main() {
    srand(time(0)); //seeding the rng
    //"\n" makes a new line
    cout << "\n\nAll about variables and logic!\n\n\n";

    //declaring a variable means it exists
    //defining a variable means giving it a value
    //set to -1 so you know whether or not it's been changed
    int playerAge = -1;
    string playerName = "Goobert";
    float playerHeight = 1.8f; //In meters //if you don't add "f" the float precision extends to 22 decimal places, "double precision"
    bool playAgain = true;
    if(playerAge == -1)
    {
        cout << "How old are you?\n";
        cin >> playerAge;

        if(playerAge < 13)
        {
            cout << "Sorry, this game is too grown up for you.\n\n";
            return 0;
        }
        else
        {
            cout << "Wow! That's old!\n\n";
        }
    }//end of playerAge
    if(playerName == "Goobert")
    {
        cout << "Is your name Goobert?\n(yes/no) ";
        string input;
        cin >> input;
        if(input == "yes")
        {
            cout << "Convenient! Welcome, " << playerName << "!\n\n";
        }
        else
        {
            cout << "What is your name, player?\n";
            cin >> playerName;
            if(playerName == "Goobert")
            {
                cout << "You... you just said it's not Goobert? Why would you... nevermind. Welcome, Goobert.\n";
            }
            else 
            {
                if(playerName.length() > 6)
                {
                    cout << "Wow! That's a long name, " << playerName << "!\n";
                }
                else
                {
                    cout << "Nice! Easy name. Welcome, " << playerName << "!\n";
                }
            }
        }
        
    }//end of playerName

    //if name and age is developer
    //unlock godmode
    bool godMode = false;
    if(playerAge == 19 && playerName == "George")
    {
        cout << "\n*Hello, developer. Debug mode enabled.*\n\n";
        godMode = true;
    }
    bool firstTry = true;
    int firstTryCounter = 0;
    bool cheating = false;
    do{
        cout << "\nLet's play a game!\n";
        cout << "I'm thinking of a number between 1 and 10.\n";

        int theNumber = (rand() % 10) + 1;
        //player guesses
        int guess = -1;
        do{
            if(godMode)
            {
                cout << "\n*The number is " << theNumber << ".*\n\n";
            }
            cout << "What is your guess?\n";
            cin >> guess;
            //computer evaluates guess, outputs 
                //correct
                if(theNumber == guess)
                {
                    cout << "You guessed it!\n";
                    if(firstTry)
                    {
                        firstTryCounter++;
                        if(firstTryCounter == 1)
                        {
                            cout << "First try! Impressive. You're not cheating, are you?\n(yes/no)";
                            string input;
                            cin >> input;
                            if(input == "yes")
                            {
                                cout << "Aww. Dude, come on. I worked really hard on this game. Not cool.\n";
                                cheating = true;
                            }
                            else if(input == "no")
                            {
                                cout << "Hmm... okay, I trust you. That's good to hear.\n";
                            }
                            else
                            {
                                cout << "I don't know what that means, but I'm just going to assume you weren't\n";
                            }
                        }
                        else if(firstTryCounter == 2)
                        {
                            if(cheating)
                            {
                                cout << "Okay, dude. It's not cool if I know you're cheating.\n";
                            }
                            else 
                            {
                                cout << "Two in a row! That's awesome, " << playerName << "! But I've got my eye on you.\n";
                            }
                        }
                        else if(firstTryCounter == 3)
                        {
                            if(cheating)
                            {
                                cout << "This can't possibly be fun for you.\n";
                            }
                            else 
                            {
                                cout << "Okay, well now I know you've got to be cheating.\n";
                                cheating = true;
                            }
                        }
                        else
                        {
                            cout << "I'm disappointed in you, " << playerName << ".\n";
                        }
                    }
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
            firstTry = false;
        } while(guess != theNumber);
        firstTry = true;
        cout << "Would you like to play again?\n(yes/no) ";
        string input;
        cin >> input;
        if(input != "yes")
        {
            playAgain = false;
        }
    } while(playAgain);
    cout << "\nGoodbye, " << playerName << "!" << endl;
    return 0;
} //end of main()