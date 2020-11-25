// ex2.10.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	int num, divisor = 2;

	cout << "Number: "; cin >> num;

	while (isPrime(num) == false)
	{
		if (num % divisor == 0)
		{
			num = num / divisor;
			cout << divisor << "x";
		}
		else
		{
			do
				divisor += 1;
			while (isPrime(divisor) == false);
		}
	}	
	cout << num;
}