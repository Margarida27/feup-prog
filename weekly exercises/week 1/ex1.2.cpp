// TP1_ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#define PI 3.141592
using namespace std;

int main()
{
	double ro;
	double radius;
	double mass;

	cout << "mass of the material of which the sphere is made: ";
	cin >> ro;
	cout << "radius of the sphere: ";
	cin >> radius;

	mass = (4/3)*ro*PI*(radius**3);
	cout << "the mass of the sphere is " << mass;
}
