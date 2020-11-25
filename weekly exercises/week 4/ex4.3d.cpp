// ex4.3d.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void bubbleSortAscending(vector<int>& v)
{
    for (int j = 0; j < v.size(); j++)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
}

void bubbleSortDescending(vector<int>& v)
{
    for (int j = 0; j < v.size(); j++)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] < v[i + 1])
            {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
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

bool validInput(char& sortMethod)
{
    if (cin.fail() || (sortMethod != 'a' && sortMethod != 'd'))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

int main()
{
    vector<int> v = { 1, 5, 3, 8, 9, 2, 10 };
    char sortMethod;
    cout << "a - ascending order\n"
        << "d - descending order\n";
    do
    {
        cout << "choose the sort method: ";
        cin >> sortMethod;
    } while (!validInput(sortMethod));

    switch (sortMethod)
    {
    case 'a':
        bubbleSortAscending(v);
        readVector(v);
        break;
    case 'd':
        bubbleSortDescending(v);
        readVector(v);
        break;       
    }    
}