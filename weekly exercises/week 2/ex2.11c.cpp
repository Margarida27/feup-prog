// ex2.11c.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    unsigned double x;

    cout << "Number of terms to calculate: "; cin >> n;

    cout << "Insert a real positive value for variable x: "; cin >> x;


    for (int i = 0; i <= n - 1; i++)
    {
        sum += pow(-1, i) * (pow(x, i) / factorial(i));
    }

    cout << "The sum of the first " << n
        << " terms of the series giving the value of e^-x is " << sum << ".\n";
}
