// ex5.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <istream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

void bubbleSortAscending(vector<string>& v)
{
    for (int j = 0; j < v.size(); j++)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                string temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
}

void bubbleSortDescending(vector<string>& v)
{
    for (int j = 0; j < v.size(); j++)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] < v[i + 1])
            {
                string temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
}

void addElems(vector<string>& v, size_t MAX_SIZE)
{
    for (size_t i = 0; i < MAX_SIZE; i++)
    {
        string name;
        cout << "name: ";
        getline(cin, name);
        v.push_back(name);
    }
}

void bubbleSort(vector<string>& v, char order)
{
    if (order == 'a')
        bubbleSortAscending(v);
    else
        bubbleSortDescending(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << "v[" << i << "]: " << v[i] << endl;;
    }
}

int main()
{
    size_t MAX_SIZE = 10;
    char order;
    vector<string> v;

    cout << "order (a | d): "; 
    cin >> order;

    cin.ignore(1000, '\n'); //because in the next function is used a getline()

    addElems(v, MAX_SIZE);
    bubbleSort(v, order);
}