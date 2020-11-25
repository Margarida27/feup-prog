// ex5.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include <string>
using namespace std;

bool sequenceSearch(const string& s, int nc, char c)
{
    bool found;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            found = true;
            for (int j = i; j <= nc; j++)
            {
                if (s[j] != c)
                    found = false;
            }
        }
    }
    return found;
}

int main()
{
    string s;
    char c;
    int nc;

    cout << "string: "; getline(cin, s);
    cout << "character to search: "; cin >> c;
    cout << "number of consecutive characters: "; cin >> nc;

    if (sequenceSearch(s, nc, c))
        cout << "The char '" << c << "' was found " << nc << " consecutive times in '" << s << "'." << endl;
    else
        "The requested sequence of characters was not found.";
}