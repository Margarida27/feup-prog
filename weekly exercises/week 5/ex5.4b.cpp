// ex5.4b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include <string>
using namespace std;

int main()
{
    string s, seq;
    char c;
    int nc;

    cout << "string: "; getline(cin, s);
    cout << "character to search: "; cin >> c;
    cout << "number of consecutive characters: "; cin >> nc;

    for (int i = 1; i <= nc; i++)
        seq += c;

    if (s.find(seq) != string::npos)
        cout << "The char '" << c << "' was found " << nc << " consecutive times in '" << s << "'." << endl;
    else
        cout << "The requested sequence of characters was not found.";
}