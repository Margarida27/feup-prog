// ex2.2a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int max = INT_MIN, min = INT_MAX;
	int n;
	
	for (int i = 1; i <= 3; i++)
	{
		cout << "no." << i << ": ";
		cin >> n;
		
		if (n > max) //largest number
			max = n;
		if (n < min) //smallest number
			min = n;
	}
	cout << "Largest number: " << max << endl;
	cout << "Smallest number: " << min << endl;
}

