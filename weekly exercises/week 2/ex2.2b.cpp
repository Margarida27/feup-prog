// ex2.2b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n1, n2, n3, max, min, med;

	cout << "no.1: "; cin >> n1;
	cout << "no.2: "; cin >> n2;
	cout << "no.3: "; cin >> n3;

	//maximum number
	if (n1 > n2&& n1 > n3)
		max = n1;
	else if (n2 > n1&& n2 > n3)
		max = n2;
	else
		max = n3;

	//minimum number
	if (n1 < n2 && n1 < n3)
		min = n1;
	else if (n2 < n1 && n2 < n3)
		min = n2;
	else
		min = n3;

	//medium number
	if (n1 != max && n1 != min)
		med = n1;
	else if (n2 != max && n2 != min)
		med = n2;
	else
		med = n3;

	cout << "Numbers by descending order: " << max << " " << med << " " << min << endl;
	cout << "Numbers by ascending order: " << min << " " << med << " " << max << endl;
}
