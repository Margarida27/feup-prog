// ex2.13b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int length = 0, n, sum = 0, sumStandardDev = 0, largest = INT_MIN, smallest = INT_MAX;
    double mean, standardDev;

    do
    {
        cout << "number: ";
        cin >> n;

        length += 1;
        sum += n;
        sumStandardDev += pow(n, 2);

        if (n < smallest && n != 0)
            smallest = n;

        if (n > largest)
            largest = n;

    } while (n != 0);

    mean = (float)sum / (length - 1);

    standardDev = pow(((float)sumStandardDev / (length - 1)) - pow(((float)sum / (length - 1)), 2), 0.5);

    cout << "length of the sequence: " << length - 1 << endl
        << "sum: " << sum << endl
        << "mean: " << mean << endl
        << "standard deviation: " << standardDev << endl
        << "largest: " << largest << endl
        << "smallest: " << smallest << endl;
}
