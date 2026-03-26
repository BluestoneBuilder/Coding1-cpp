//George Smith Coding 1 Spring 2026
//Our first c++ program
//compile in terminal with "g++ main.cpp -o main"
//then run with "./main"
//use "cp 'FolderName'"" to navigate to the path of the c++ file

#include <iostream>     //in-out stream for sending text to the console
#include <string>       //for player name

using namespace std;    

//So we dont have to type "std::"" all the time
//this is where our program starts running code
int main() 
{
    string playerName;                  //variable name written in camelCase

    //ask the player their name
    cout << "What is your name, player? ";

    //get input from player with cin
    cin >> playerName;

    cout << "Hello " << playerName << "." << endl;

    //cout << "Hello World!" << endl;     //cout for console out
                                        //endl for end line
    return 0;
}