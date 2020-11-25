// ex5.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include <string>
#include <vector>
using namespace std;

string normalizeName(const string& name)
{
    string normal, sub1, sub2;
    vector<string> toRemove;
    int i = 0, pos;

    while (i < name.length())
    {
        while (name.at(i) == ' ') // removes multiple spaces at position of the name
            i++;
        while (name.at(i) != ' ') 
        {
            normal += toupper(name.at(i));
            i++;
            if (i == name.length())
                break;
        }
        normal += ' '; // adds a space between two words since it was removed previously
    }

    if (normal.at(name.length() - 1) == ' ') // removes the space added unnecessarily to the string in the last iteration
        normal.pop_back();

    toRemove = { " DE ", " DO ", " DA ", " DOS ", " DAS ", " E " };

    for (int i = 0; i < toRemove.size(); i++)
    {
        pos = normal.find(toRemove[i]);
        if (pos != string::npos)
        {
            sub1 = normal.substr(0, pos);
            sub2 = normal.substr(pos + toRemove[i].length() - 1);
            normal = sub1 + sub2;
        }
    }

    return normal;
}

int main()
{
    string name = "Maria da Felicidade dos Reis e Passos Dias de Aguiar"; //must return "MARIA FELICIDADE REIS PASSOS DIAS AGUIAR"
    cout << normalizeName(name);
}