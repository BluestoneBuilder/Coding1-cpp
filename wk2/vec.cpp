//George Smith
//Vectors, iterators, and algorithms
//g++ vec.cpp -o vec && ./vec
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout << "Let's learn about vectors!\n";

    int chapter = 0;
    cout << "What program would you like to run?\n";
    cout << "Press 1 for Vectors.\n";
    cout << "Press 2 for push_back() and pop_back().\n";
    cout << "Press 3 for algorithms.\n";

    cin >> chapter;
    if(chapter == 1)
    {
        cout << "You have selected Vectors.\n\n";
        //collection initializer
        vector<string> names = {"George", "Brian", "otherDude", "pipo"};
        cout << "There are " << names.size() << " names in the vector.\n";
        cout << "Here are your names:\n";
        for(int i = 0; i < names.size(); i++)
        {
            cout << i + 1 << ". " << names[i] << endl;
        }                                               //iterator that points to specific spot in vector
        cout << "The first name in the vector is " << *(names.begin()) << ".\n";

        //Iterator. Points to an element in a vector;
        vector<string>::iterator iter;
        iter = names.begin() + 2;

        //dereference iter with *
        //
        cout << "Iter is pointing at " << *iter << ".\n";
    }
    else if(chapter == 2)
    {
        cout << "Let's use push_back() and pop_back().\n";
        vector<string> favMovies;
        while(favMovies.size() < 3)
        {
            cout << "Please add a favorite movie: ";
            string input;
            cin >> input;

            favMovies.push_back(input);
        }
        cout << "Here are your favorite movies:\n";
        for(vector<string>::iterator iter = favMovies.begin(); iter != favMovies.end(); iter++)
        {
            cout << *iter << endl;
        }
    }
    else if(chapter == 3)
    {
        vector<string> friends;
        friends.push_back("Bobbert");
        friends.push_back("Pipo");
        friends.push_back("Jonathaniel");
        friends.push_back("Gableer");

        cout << "Here are your friends:\n";
        for(int i = 0; i < friends.size(); i++)
        {
            cout << friends[i] << ".\n";
        }
        cout << "Please choose a friend to visit:\n";
        vector<string>::iterator chosenFriend = friends.begin();
        string input;
        cin >> input;

        //use an algorithm to find a friend
        chosenFriend = find(friends.begin(), friends.end(), input);
        if(chosenFriend != friends.end())
        {
            cout << "Let's talk to " << *chosenFriend << " today!\n";
        }
        else 
        {
            cout << "I couldn't find " << input << " in your friends list.\n";
        }
        cout << "Let's give " << *chosenFriend << " a nickname!\n";
        cin >> input;
        *chosenFriend = input;
        cout << "Their nickname is now " << *chosenFriend << ".\n";
    }
    else 
    {
        cout << "Chapter " << chapter << " isn't one of the options.\n";
    }
    return 0;
}