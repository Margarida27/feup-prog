// ex3.11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int greatestCommonDiv(int a, int b)
{
    if(b == 0)
        return a;
    return greatestCommonDiv(b, (a % b));
}   

int main()
{
    int n1, n2;
    cout << "insert two numbers (n1,n2): ";
    cin >> n1; cin.ignore(); cin >> n2;
    cout << "the greatest common divisor of " << n1 << " and " << n2 << " is " << greatestCommonDiv(n1, n2) << ".\n";
}
