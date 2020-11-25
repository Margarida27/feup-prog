// ex3.14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

double integrateTR(double f(double), double a, double b, int n)
{ 
    double x1, x2, y1, y2; //limits of the sub-interval
    double h; //width of the sub-interval
    double totalArea = 0; //integral aproximation

    h = (b - a) / n;

    for (int i = 1; i <= n; i++)
    {
        totalArea += ((h / 2) * (f(a + (i - 1) * h) + f(a + i * h)));
    }
    return totalArea;

    /*
    double x1, x2, y1, y2; 
    double dx; 
    double area; //area of the sub-interval
    double totalArea = 0; 

    dx = (b - a) / n;
    x1 = a;
    x2 = x1 + dx;

    for (int i = 1; i <= n; i++)
    {
        y1 = f(x1);
        y2 = f(x2);
        area = dx * (y1 + y2) / 2;
        totalArea = totalArea + area;
        x1 = x1 + dx;
        x2 = x2 + dx;
    }
    return totalArea;
    */   
}

double g(double x)
{
    return pow(x, 2);
}

double h(double x)
{
    return sqrt(4 - pow(x, 2));
}

int main()
{
    cout << integrateTR(g, 0, 10, 50) << endl
        << integrateTR(h, -2, 2, 50) << endl;
}
