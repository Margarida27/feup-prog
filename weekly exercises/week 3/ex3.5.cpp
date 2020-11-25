// ex3.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int greatestCommonDiv(int a, int b)
{
    if (b == 0)
        return a;
    return greatestCommonDiv(b, (a % b));
}

int main()
{
    int a, b, gcd;
    cout << "number 1: "; cin >> a;
    cout << "number 2: "; cin >> b;
    cout << "greatest common divisor: " << greatestCommonDiv(a, b);
}