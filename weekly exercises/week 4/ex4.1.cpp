// ex4.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// reads a[] from keyboard
void readArray(int a[], size_t nElem)
{
    for (int i = 0; i < nElem; i++)
    {
        cout << "index " << i << ": ";
        cin >> a[i];
    }
}

// outputs content of a[]
void showContent(int a[], size_t nElem)
{
    cout << "content of the array: ";

    for (int i = 0; i < nElem; i++)
    {
        cout << a[i] << "  ";
    }
}

// searches the nElem elements of a[], between indexes pos1 and pos2, inclusive, for the first occurrence of value
int findValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2)
{
    for (size_t i = pos1; i <= pos2; i++)
    {
        if (value == a[i])
            return 1;
    }
    return -1;
}

// if there are multiple occurrences of value in a[], returns the indexes of those occurrences through index[]
size_t findMultValuesInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[])
{
    size_t currentIx = 0;

    for (size_t i = pos1; i <= pos2; i++)
    {
        if (value == a[i])
        {
            index[currentIx] = i;
            currentIx += 1;
        }
    }
    return currentIx;
}

int main()
{

}