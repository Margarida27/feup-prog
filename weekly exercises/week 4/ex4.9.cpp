// ex4.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int x = 1, y = 2; 
    int &ref_x = x, &ref_y = y; 
    ref_x = ref_y; 
    cout << "x = " << x << "; y = " << y << endl; 
    cout << "ref_x = " << ref_x << "; ref_y = " << ref_y << endl;
    /* output
    x = 2; y = 2
    ref_x = 2; ref_y = 2
    */

    int x = 1, y = 2; 
    int *ptr_x = &x, *ptr_y = &y; 
    ptr_x = ptr_y; 
    cout << "x = " << x << "; y = " << y << endl; 
    cout << "ptr_x = " << ptr_x << "; ptr_y = " << ptr_y << endl; 
    cout << "*ptr_x = " << *ptr_x << "; *ptr_y = " << *ptr_y << endl;
    /* output
    x = 1; y = 2
    ptr_x = 00EFFE5C; ptr_y = 00EFFE5C
    *ptr_x = 2; *ptr_y = 2
    */
}
