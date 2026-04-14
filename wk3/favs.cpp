//George Smith
//create a list of favorites
//g++ favs.cpp -o favs && ./favs
//ctrl+C to quit loop

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<string> favs;
    while(true){
        cout << "\nWhat would you like to do?\n";
        cout << "'add', 'edit', 'remove', 'show', or 'quit'.\n";

        string input;
        getline(cin, input);


        if(input == "test")
        {
            cout << "use getline for number with stoi(input):\n";
            cout << "What's your favorite number?\n";
            getline(cin, input);
            int favNum = stoi(input);

            if(favNum > 3)
            {
                cout << "Okay, man. Your favorite number is bigger than mine. Show off.\n";
            }
        }
        else if(input == "quit")
        {
            cout << "\nThanks for playing!\n";
            break;
        }
        else if(input == "add")
        {
            cout << "\nWhat game would you like to add to your favorites?\n";
            getline(cin, input);
            favs.push_back(input);
            cout << "\nAdded '" << input << "'\n";
        }
        else if(input == "show")
        {
            sort(favs.begin(), favs.end());
            if(favs.size() == 0)
            {
                cout << "\nYou don't have any favorites right now. Consider using the 'add' function\n";
            }
            else
            {
                cout << "\nHere are your current favorite games.\n";
                for(int i = 0; i < favs.size(); i++)
                {
                    cout << i + 1 << ". " << favs[i] << endl;
                }
            }
        }
        else if(input == "edit")
        {
            if(favs.size() == 0)
            {
                cout << "\nYou don't have any favorites right now. Consider using the 'add' function\n";
            }
            else
            {
                cout << "\nWhich of your favorites would you like to edit?\n";
                getline(cin, input);
                vector<string>::iterator favToEdit = favs.begin();
                favToEdit = find(favs.begin(), favs.end(), input);
                if(favToEdit != favs.end())
                {
                    cout << "\nWhat would you like to change '" << *favToEdit << "' to?\n";\
                    getline(cin, input);
                    cout << "\n'" << *favToEdit << "' has been changed to '" << input << "'.\n";
                    *favToEdit = input;
                }
                else
                {
                    cout << "\nI couldn't find that game in your favorites\n";
                }
            }
        }
        else if(input == "remove")
        {
            if(favs.size() == 0)
            {
                cout << "\nYou don't have any favorites right now. Consider using the 'add' function\n";
            }
            else
            {
                cout << "\nWhat game would you like to remove from your favorites?\n";
                getline(cin, input);
                vector<string>::iterator favToRemove = favs.begin();
                favToRemove = find(favs.begin(), favs.end(), input);
                if(favToRemove != favs.end())
                {
                    cout << "\nRemoved '" << *favToRemove << "'.\n";
                    favs.erase(favToRemove);
                }
                else
                {
                    cout << "\nI couldn't find that game in your favorites\n";
                }
            }
        }
        else
        {
            cout << "\nUnrecognized input.\n";
        }
    }
}