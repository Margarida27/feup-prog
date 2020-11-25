// ex4.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

// reads v[] from keyboard
void readVector(vector<int>& v, size_t nElem) 
{
    int n;
    for (int i = 0; i < nElem; i++)
    {
        cout << "index " << i << ": ";
        cin >> n;
        v.push_back(n);
    }
}

// outputs content of v[]
void showContent(vector<int>& v, size_t nElem) 
{
    cout << "content of the array: ";

    for (int i = 0; i < nElem; i++)
    {
        cout << v.at(i) << "  ";
    }
}

// searches the nElem elements of v[], between indexes pos1 and pos2, inclusive, for the first occurrence of value
size_t findValueInVector(const vector<int>& v, int value, size_t pos1, size_t pos2)
{
    for (size_t i = pos1; i <= pos2; i++)
    {
        if (value == v.at(i))
            return 1;
    }
    return -1;
}

// if there are multiple occurrences of value in v[], returns the indexes of those occurrences through index[]
void findMultValuesInVector(const vector<int>& v, int value, size_t pos1, size_t pos2, vector<size_t>& index)
{
    for (size_t i = pos1; i <= pos2; i++)
    {
        if (value == v.at(i))
            index.push_back(i);
    }
}

int main()
{

}