// ex2.13a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int length, n, sum = 0, sumStandardDev = 0, largest = INT_MIN, smallest = INT_MAX;
    double mean, standardDev;

    cout << "length of the sequence: ";
    cin >> length;

    for (int i = 1; i <= length; i++)
    {
        cout << "number: ";
        cin >> n;
        sum += n;
        sumStandardDev += pow(n, 2);
        
        if (n < smallest)
            smallest = n;
        
        if (n > largest)
            largest = n;
    }
    
    mean = (float)sum / length;

    standardDev = pow(((float)sumStandardDev / length) - pow(((float)sum / length), 2), 0.5);

    cout << "sum: " << sum << endl
        << "mean: " << mean << endl
        << "standard deviation: " << standardDev << endl
        << "largest: " << largest << endl
        << "smallest: " << smallest << endl;   
}
