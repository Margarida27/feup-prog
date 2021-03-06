// ex2.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	double a, b, c, d, e, f, x, y;
	cout << "Consider the following system of linear equations in two variables (x e y): \n a*x + b*y = c \n d*x + e*y = f \n";
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	cout << "d: ";
	cin >> d;
	cout << "e: ";
	cin >> e;
	cout << "f: ";
	cin >> f;

	if ((a * e - b * d) == 0)
	{
		cout << "This system cannot be solved. Impossible system.";
	}
	else
	{
		x = (c * e - b * f) / (a * e - b * d);
		y = (a * f - c * d) / (a * e - b * d);
		cout << "The x solution is " << x << endl;
		cout << "The y solution is " << y << endl;
	}	
}