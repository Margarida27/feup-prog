// ex4.7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

// using arrays - 4.7 a)
void localMax(const int a[][5], int NE, bool all)
{
    int currVal;
    bool valid;

    for (int i = !all; i < NE - !all; ++i)
    {
        for (int j = !all; j < NE - !all; ++j)
        {
            currVal = a[i][j];
            valid = true;

            for (int si = -1; si < 2; ++si)
            {
                for (int sj = -1; sj < 2; ++sj)
                {
                    if (0 <= si + i && si + i < NE && 0 <= sj + j && sj + j < NE && a[si + i][sj + j] > currVal)
                        valid = false;
                }
            }
            if (valid)
                cout << currVal << " ";
        }
    }
}


// using vectors - 4.7 b)
void localMax(vector<vector<int>> v, bool all)
{
    int currVal;
    bool valid;

    for (int i = !all; i < v.size() - !all; ++i)
    {
        for (int j = !all; j < v.size() - !all; ++j)
        {
            currVal = v.at(i).at(j);
            valid = true;

            for (int si = -1; si < 2; ++si)
            {
                for (int sj = -1; sj < 2; ++sj)
                {
                    if (0 <= si + i && si + i < v.size() && 0 <= sj + j && sj + j < v.size() && v.at(si + i).at(sj + j) > currVal)
                        valid = false;
                }
            }
            if (valid)
                cout << currVal << " ";
        }
    }
}


int main()
{
    // using arrays - 4.7 a)
    const int NE = 5;
    int a[NE][NE] = { { 7, 3, 4, 1, 3 }, { 2, 9, 6, 2, 1 }, { 1, 3, 5, 1, 4 }, { 6, 5, 2, 7, 5 }, { 4, 2, 1, 3, 6 } };
    char answer;
    bool all;

    cout << "Do you want to consider that any element of the matrix can be a local maximum, regardless of the number of neighbors it has? (y or n) ";
    cin >> answer;
    if (answer == 'y') all = true; else if (answer == 'n') all = false;
    cout << "Local maximas: ";
    localMax(a, NE, all);

    // using vectors - 4.7 b)
    vector<vector<int>> v = { { 7, 3, 4, 1, 3 }, { 2, 9, 6, 2, 1 }, { 1, 3, 5, 1, 4 }, { 6, 5, 2, 7, 5 }, { 4, 2, 1, 3, 6 } };
    char answer;
    bool all;

    cout << "Do you want to consider that any element of the matrix can be a local maximum, regardless of the number of neighbors it has? (y or n) ";
    cin >> answer;
    if (answer == 'y') all = true; else if (answer == 'n') all = false;
    cout << "Local maximas: ";
    localMax(v, all); 
}