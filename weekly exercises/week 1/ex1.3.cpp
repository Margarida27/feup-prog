// TP1_ex3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#define PI 3.141592
using namespace std;

int main()
{
	double ro;
	double radius;
	cout << "mass of the material of which the sphere is made (Kg/m**3): ";
	cin >> ro;
	cout << "radius of the sphere (m): ";
	cin >> radius;
	double mass = (4 / 3) * ro * PI * pow(radius, 3);
	cout << "the mass of the sphere, in Kg, is " << mass;
}