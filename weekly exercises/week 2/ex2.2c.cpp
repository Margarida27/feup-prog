// ex2.2c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    unsigned int l1, l2, l3, max;

    cout << "Insert 3 positive numbers: "; cin >> l1 >> l2 >> l3;

    if (l1 > l2&& l1 > l3)
    {
        max = l1;
        if (l2 + l3 >= l1)
            cout << "The numbers can represent the length of the 3 sides of a triangle.";
        else
            cout << "The numbers cannot represent the length of the 3 sides of a triangle!";
    }
    else if (l2 > l1&& l2 > l3)
    {
        max = l2;
        if (l1 + l3 >= l2)
            cout << "The numbers can represent the length of the 3 sides of a triangle.";
        else
            cout << "The numbers cannot represent the length of the 3 sides of a triangle!";
    }
    else
    {
        max = l3;
        if (l1 + l2 >= l3)
            cout << "The numbers can represent the length of the 3 sides of a triangle.";
        else
            cout << "The numbers cannot represent the length of the 3 sides of a triangle!";
    }
}
