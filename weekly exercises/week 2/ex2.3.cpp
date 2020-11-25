// ex2.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a, b, sum;

    cout << "a: "; cin >> a;
    cout << "b: "; cin >> b;

    sum = a + b;

    if (sum > INT_MAX)
        cout << "sum overflow \n";
    else if (sum < INT_MIN)
        cout << "sum underflow \n";
    else
        cout << "sum = " << sum << endl;

}