// ex5.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include <string>
using namespace std;

char encryptChar(char c, int key)
{
    if (97 <= int(c) <= 122) //a-z
    {
        if (int(c) + key > 122)
            return char((int(c) + key - 97) % 26 + 97);
    }
    else if (65 <= int(c) <= 90) //A-Z
    {
        if (int(c) + key > 90)
            return char((int(c) + key - 65) % 26 + 65);
    }
}

string encryptString(string s, int key)
{
    string cipher;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
            cipher += ' ';
        else
            cipher += encryptChar(s[i], key);
    }
    return cipher;
}

int main()
{
    string s; 
    int key;

    cout << "string to cipher: "; 
    getline(cin, s);
    cout << "key: "; cin >> key;

    cout << encryptString(s, key);
}