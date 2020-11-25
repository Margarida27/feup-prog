// ex4.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& v, int value)
{
    int first = 0;
    int last = v.size() - 1;
    int middle;
    bool found = false;

    do
    {
        middle = (first + last) / 2;
        if (v[middle] == value)
            found = true;
        else if (value < v[middle])
            last = middle - 1;
        else if (value > v[middle])
            first = middle + 1;
    } while (!found && first <= last);

    if (found)
        return middle;
    else
        return -1;
}

int main()
{
    vector<int> v = { 2,5,9,10,16,20,23,27,39,71,100 };
    int value = 71;
    int returnValue = binarySearch(v, value);
    if (returnValue == -1)
        cout << "The value doesn't exist on the vector.\n";
    else
        cout << "The value " << value << " is on index no. " << returnValue << ".\n";
}
