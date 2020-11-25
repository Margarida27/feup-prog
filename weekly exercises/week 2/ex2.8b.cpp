// ex2.8b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.141592
using namespace std;

int main()
{
    const int RESULT_PRECISION = 3;
    float l; //lower limit
    float u; //upper limit
    float delta; //increment
    float rad; //angle in radians

    cout << "lower limit: "; cin >> l;
    cout << "upper limit: "; cin >> u;
    cout << "increment: "; cin >> delta; 

    cout << "ang\t" << "sin\t" << "cos\t" << "tan\n";

    for (float i = l; i <= u; i += delta)
    {
        rad = (i * PI) / 180;

        if (i != 90)
            cout << fixed << setprecision(RESULT_PRECISION) << i << "\t" << sin(rad) << "\t" << cos(rad) << "\t" << tan(rad) << endl;
        else
            cout << fixed << setprecision(RESULT_PRECISION) << i << "\t" << sin(rad) << "\t" << cos(rad) << "\t" << "infinite\n";
    }
}