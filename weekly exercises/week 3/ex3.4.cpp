// ex3.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

double round(double& x, unsigned int& n)
{
    return floor(x * pow(10, n) + 0.5) / pow(10, n);
}

int main()
{
    double x;
    unsigned int n; 

    cout << "number: "; cin >> x;
    cout << "decimal places: "; cin >> n;
    cout << round(x, n) << endl;
}