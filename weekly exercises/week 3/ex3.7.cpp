// ex3.7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits>
using namespace std;

bool readInt(int& x)
{
    if (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

int main()
{
    int n;
    cout << "Input an integer: ";
    cin >> n; 
    if (readInt(n))
        cout << n;
    else
        cout << "You have entered an invalid input.";
}