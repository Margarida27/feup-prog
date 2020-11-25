// ex4.11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int compareAscend(const void* a, const void* b)
{
    return (*(int*)a > * (int*)b); // if a > b, a change will occur
}

int compareDescend(const void* a, const void* b)
{
    return (*(int*)a < *(int*)b); // if a < b, a change will occur
}

int main()
{
    size_t nElem = 7;
    int v[] = { 20, 1, 5, 10, 10, 50, 10 };

    cout << "array ordered by ascending order: ";
    qsort(v, nElem, sizeof(int), compareAscend);
    for (int i = 0; i < nElem; i++)
        cout << v[i] << " ";

    cout << endl;

    cout << "array ordered by descending order: ";
    qsort(v, nElem, sizeof(int), compareDescend);
    for (int i = 0; i < nElem; i++)
        cout << v[i] << " ";
}
