// ex2.11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    double sum = 0;

    cout << "Number of terms to calculate: "; cin >> n;

    for (int i = 0; i <= n - 1; i++)
    {
        sum += 4 * (pow(-1, i) / (2 * i + 1));
    }

    cout << "The sum of the first " << n 
        << " terms of the series giving the value of the mathematical constant PI is " << sum << ".\n";
}
