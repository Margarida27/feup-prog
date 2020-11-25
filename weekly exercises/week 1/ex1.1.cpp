// TP_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	cout << "Character to be converted to ASCII: ";
	char c; 
		cin >> c;
		cout << "The ASCII of " << c << " is " << int(c);
}