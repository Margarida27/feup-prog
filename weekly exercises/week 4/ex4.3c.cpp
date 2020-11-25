// ex4.3c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

/*
void bubbleSortAscending(vector<int>& v)
{
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                v[i] += v[i + 1];
                v[i + 1] = v[i] - v[i + 1];
                v[i] -= v[i + 1];
                swap = true;
            }
        }
    }
}

void bubbleSortDescending(vector<int>& v)
{
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] < v[i + 1])
            {
                v[i] += v[i + 1];
                v[i + 1] = v[i] - v[i + 1];
                v[i] -= v[i + 1];
                swap = true;
            }
        }
    }
}
*/

void bubbleSortAscending(vector<int>& v)
{
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                swap = true;
            }
        }
    }
}

void bubbleSortDescending(vector<int>& v)
{
    bool swap = true;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] < v[i + 1])
            {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                swap = true;
            }
        }
    }
}

void readVector(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "v[" << i << "]: " << v[i] << endl;;
    }
}

int main()
{
    vector<int> v = { 20, 1, 5, 10, 10, 50, 10 };
    bubbleSortAscending(v);
    readVector(v);
    cout << endl;
    bubbleSortDescending(v);
    readVector(v);
}