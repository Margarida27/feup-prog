// ex2.11b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

double factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return (n * factorial(n - 1));
}

int main()
{
    int n;
    double sum = 0;

    cout << "Number of terms to calculate: "; cin >> n;

    for (int i = 0; i <= n - 1; i++)
    {
        sum += 1 / factorial(i);
    }

    cout << "The sum of the first " << n
        << " terms of the series giving the value of the mathematical constant e is " << sum << ".\n";
}