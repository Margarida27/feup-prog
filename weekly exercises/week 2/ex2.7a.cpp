// ex2.7a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	bool isPrime = true;

	cout << "insert a number to determine if it is prime: "; cin >> n;
	
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (i == 1 || i == n) 
				continue;
			else 
				isPrime = false;
		}
	}

	if (isPrime == true)
		cout << n << " is prime.";
	else
		cout << n << " is not prime.";
}
