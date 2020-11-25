// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int& n)
{
	bool prime = true;

	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (i == 1 || i == n)
				continue;
			else
				prime = false;
		}
	}
	return prime;
}

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		if (isPrime(i) == true)
			cout << i << endl;
	}
}
