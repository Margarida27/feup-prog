// ex3.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
    int x1, x2, x3, y1, y2, y3;
    double a, b, c, s, area;

    cout << "point 1 (x1,y1): ";
    cin.ignore(); cin >> x1; cin.ignore(); cin >> y1; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "point 2 (x2,y2): ";
    cin.ignore(); cin >> x2; cin.ignore(); cin >> y2; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "point 3 (x3,y3): ";
    cin.ignore(); cin >> x3; cin.ignore(); cin >> y3; cin.ignore();

    a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    s = (a + b + c) / 2;

    area = sqrt(s * (s - a) * (s - b) * (s - c));

    cout << "area: " << area;
}