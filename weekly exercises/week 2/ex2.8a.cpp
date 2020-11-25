// 2.8a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.141592
using namespace std;

int main()
{
    const int RESULT_PRECISION = 6;
    float rad;
    
    cout << "ang\t" << "sin\t" << "cos\t" << "tan\n";
    
    for (int i = 0; i <= 90; i += 15)
    {
        rad = (i * PI) / 180;

        if (i != 90)
            cout << fixed << setprecision(RESULT_PRECISION) << i << "\t" << sin(rad) << "\t" << cos(rad) << "\t" << tan(rad) << endl;
        else
            cout << fixed << setprecision(RESULT_PRECISION) << i << "\t" << sin(rad) << "\t" << cos(rad) << "\t" << "infinite\n";
    }
}

