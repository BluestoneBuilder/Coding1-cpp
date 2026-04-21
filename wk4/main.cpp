//George Smith Coding 1
//Writing to and reading from files
//g++ main.cpp -o main && ./main

#include <iostream>
//file stream. Include istream and ostream
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//new function
//return type = void, name = writeFile(input, path)
void writeFile(string input, bool append = false, string path = "save.txt")
{
    ofstream file;
    if(append)
    {
        file.open(path, ios::app);
        file << "\n" << input;
    }
    else
    {
        file.open(path);
        file << input;
    }
    file.close();
}
//for vectors               & to reference instead of copy
void writeFile(vector<string>& vec, string path = "vector.txt")
{
    ofstream file(path);
    for(int i = 0; i < vec.size(); i++)
    {
        file << vec[i] << endl;
    }
    file.close();
}
void readFile(string path = "save.txt")
{
    string line;
    ifstream file(path);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            cout << line << endl;
        }
    }
    else
    {
        cout << "File not found.\n";
    }
    file.close();
}
//for vectors
void readFile(vector<string>& vec, string path = "vector.txt")
{
    vec.clear();    //Be sure vector is empty
    string line;
    ifstream file(path);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            vec.push_back(line);
        }
    }
    file.close();
}
int main()
{
    cout << "Let's do some file opperations!\n\n";

    writeFile("Here is some text.");
    writeFile("This is the second line.", true);
    readFile();

    cout << "\n";
    vector<string> names = {"Harry", "Hermione", "Ron"};

    //this line goes under read file and for statement
    writeFile(names, "names.txt");
    readFile(names, "names.txt");
    for(int i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }
    //writeFile(names, "names.txt");

    return 0;
}