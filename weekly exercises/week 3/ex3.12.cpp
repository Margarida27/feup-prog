// ex3.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

//the area of a circle, given its radius
double area(double& radius)
{
    const double PI = 3.14159265;

    return PI * pow(radius, 2);
}

//the area of a triangle, given its 3 vertices
double area(int& x1, int& y1, int& x2, int& y2, int& x3, int& y3)
{
    double a, b, c, s;

    a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
    s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

//the area of a rectangle, given 2 opposite vertices
double area(int& x1, int& y1, int& x2, int& y2)
{
    return (fabs(x1 - x2) * fabs(y1 - y2));
}

int main()
{
    //the functions above are overloaded
}