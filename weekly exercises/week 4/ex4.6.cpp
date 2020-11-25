// ex4.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int> v, int value)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (value == v.at(i))
            return true;
    }
    return false;
}

void removeDuplicates(vector<int>& v)
{
    vector<int> aux;
    bool duplicate = false;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < aux.size(); j++)
            if (aux.at(j) == v.at(i))
                duplicate = true;

        if (!duplicate)
            aux.push_back(v.at(i));

        duplicate = false;
    }
    v = aux;
}

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

void unionVectors(const vector<int>& v1, const vector<int>& v2, vector<int>& v3)
{
    for (int i = 0; i < v1.size(); i++)
        v3.push_back(v1.at(i));

    for (int i = 0; i < v2.size(); i++)
        v3.push_back(v2.at(i));
}

void intersectionVectors(const vector<int>& v1, const vector<int>& v2, vector<int>& v3)
{
    for (int i = 0; i < v1.size(); i++)
    {
        if (search(v2, v1.at(i)))
            v3.push_back(v1.at(i));
    }
}

void showContent(vector<int>& v)
{
    cout << "content of the array: " << endl;;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }
}

int main()
{
    vector<int> v1, v2, v3;
    v1 = { 20, 1, 5, 10, 10, 50, 10 };
    v2 = { 50, 20, 3, 15, 50 };

    /*
    unionVectors(v1, v2, v3);
    removeDuplicates(v3);
    bubbleSortAscending(v3);
    showContent(v3);
    */

    /*
    intersectionVectors(v1, v2, v3);
    removeDuplicates(v3);
    bubbleSortAscending(v3);
    showContent(v3);
    */
}
