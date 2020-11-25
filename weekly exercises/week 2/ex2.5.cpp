// ex2.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, c;
    cout << "Insert the coefficients (A B C): "; 
    cin >> a >> b >> c;

    if (pow(b, 2) - 4 * a * c < 0)
        cout << "The equation has two complex roots: " 
        << -b / (2 * a) << "+" << (sqrt((pow(b, 2) - 4 * a * c) * -1)) / (2 * a) << "i and "
        << -b / (2 * a) << "-" << (sqrt((pow(b, 2) - 4 * a * c) * -1)) / (2 * a) << "i" << endl;

    else if (pow(b, 2) - 4 * a * c == 0)
        cout << "The equation has one root: "
        << (- b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << endl;

    else if (pow(b, 2) - 4 * a * c > 0)
        cout << "The equation has two real roots: " 
        << (- b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << " and "
        << (- b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) << endl;
}