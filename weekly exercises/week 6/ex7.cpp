// ex7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T max(vector<T>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    return v[v.size() - 1];
}

template <typename T>
T min(vector<T>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    return v[0];
}

int main()
{
    vector<int> v = { 2, 5, 0, 12, 7, 34, 128, -1 };
    cout << "maximum value: " << max<int>(v);
    cout << endl;
    cout << "minimum value: " << min<int>(v);
}
