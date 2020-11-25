// ex4.12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <new>
using namespace std;

void readArray(int* a, size_t nElem)
{
    for (int i = 0; i < nElem; i++)
    {
        cout << "index " << i << ": ";
        cin >> *(a+i);
    }
}

int findValueInArray(const int* a, size_t nElem, int value, size_t pos1, size_t pos2)
{
    for (size_t i = pos1; i <= pos2; i++)
    {
        if (value == *(a + i))
            return 1;
    }
    return -1;
}

size_t findMultValuesInArray(const int* a, size_t nElem, int value, size_t pos1, size_t pos2, size_t* index)
{
    size_t counter = 0;

    for (size_t i = pos1; i <= pos2; i++)
    {
        if (value == a[i])
        {
            index = new size_t[counter + 1]; // as counter increases and there's the need of adding new elements to array index, new memory is dynamically allocated
            index[counter] = i;
            counter += 1;
        }
    }
    return counter;
}

int main()
{
    size_t nElem;
    int* a;
    size_t* index;
    int value, pos1, pos2;

    cout << "number of elements of the array: ";
    cin >> nElem;
    a = new int[nElem]; // dynamic allocation for an array of nElem elements indicated by the user
    pos1 = 0;
    pos2 = nElem - 1;
    cout << "value to search: ";
    cin >> value;

    readArray(a, nElem);

    if (findValueInArray(a, nElem, value, pos1, pos2) == 1)
        cout << "The value " << value << " was found on the array." << endl;
    else
        cout << "The value " << value << " was not found on the array." << endl;

    index = new size_t[1]; // dynamic allocation of 1 elem for array index so it can be called by the function
    cout << "The value searched was found " << findMultValuesInArray(a, nElem, value, pos1, pos2, index) << " times on the array.";

    delete[] a;
    delete[] index;
}
