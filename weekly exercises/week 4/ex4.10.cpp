// ex4.10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int values[] = { 2, 3, 5, 7, 11, 13 }; 
    int *p = values + 1;                      // outputs: 
    cout << values[1] << endl;                // 3
    cout << values + 1 << endl;               // 0053FCC0
    cout << *p << endl;                       // 3
    cout << *(values + 3) << endl;            // 7
    cout << p + 1 << endl;                    // 0053FCC4
    cout << p[1] << endl;                     // 5
    cout << p - values << endl;               // 1
}
