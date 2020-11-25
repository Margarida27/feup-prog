// ex2.9a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	unsigned int num, numCopy, digit, reverse = 0;

	cout << "A palindrome is a word, number, phrase, or other sequence of characters which reads the same backward as forward.\n";
	cout << "Insert a number: "; cin >> n;

	num = numCopy;

	do
	{
		digit = num % 10;
		reverse = (reverse * 10) + digit;
		num = num / 10;
	} while (num != 0);

	if (reverse == numCopy)
		cout << 'The number is a palindrome.';
	else
		cout << "The number is not a palindrome."
}