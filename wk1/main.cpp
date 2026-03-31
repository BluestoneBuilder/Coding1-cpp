//George Smith, Coding 1, Spring 2026
//Using VS Codium and its integrated terminal
//to learn about variables and logic

//Open terminal
//use "cp path/to/folder" to navigate to the path of the c++ file
//"cd GitHub/Coding1-cpp/wk1" for this script
//compile with "g++ main.cpp -o main"
//then run with "./main"

#include <iostream>
using namespace std;

int main() {
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

    if(playAgain){
        cout << "Let's play a game!\n";

        //game will go here
    }

    return 0;
} //end of main()