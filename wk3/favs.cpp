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
        cout << "What would you like to do?\n";
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
            cout << "Thanks for playing!\n";
            break;
        }
        else if(input == "add")
        {
            cout << "What game would you like to add to your favorites?\n";
            getline(cin, input);
            favs.push_back(input);
        }
        else if(input == "show")
        {
            sort(favs.begin(), favs.end());
            if(favs.size() == 0)
            {
                cout << "You don't have any favorites right now. Consider using the 'add' function\n";
            }
            else
            {
                cout << "Here are your current favorite games.\n";
                for(int i = 0; i < favs.size(); i++)
                {
                    cout << i + 1 << ". " << favs[i] << endl;
                }
            }
        }
        else if(input == "edit")
        {
            cout << "Which of your favorites would you like to edit?\n";
            getline(cin, input);
            vector<string>::iterator favToEdit = favs.begin();
            favToEdit = find(favs.begin(), favs.end(), input);
            if(favToEdit != favs.end())
            {
                cout << "What would you like to change '" << *favToEdit << "' to?\n";\
                getline(cin, input);
                cout << "'" << *favToEdit << "' has been changed to '" << input << "'.\n";
                *favToEdit = input;
            }
            else
            {
                cout << "I couldn't find that game in your favorites\n";
            }
        }
        else if(input == "remove")
        {
            cout << "What game would you like to remove from your favorites?\n";
            getline(cin, input);
            vector<string>::iterator favToRemove = favs.begin();
            favToRemove = find(favs.begin(), favs.end(), input);
            if(favToRemove != favs.end())
            {
                cout << "Removed '" << *favToRemove << "'.\n";
                favs.erase(favToRemove);
            }
            else
            {
                cout << "I couldn't find that game in your favorites\n";
            }
        }
        else
        {
            cout << "Unrecognized input.\n";
        }
    }
}