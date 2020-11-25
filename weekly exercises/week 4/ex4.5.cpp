// ex4.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

// without auxiliar vector
void removeDuplicates(vector<int>& v)
{
    int i = 0;
    while (i < v.size())
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] == v[j])
            {
                // moves all the elements that occupy the next positions of the vector to the position before the position they occupy
                for (int k = j; k < v.size() - 1; k++)
                {
                    v[k] = v[k + 1];
                }

                // changes the size of the vector
                v.resize(v.size() - 1);
                j--;
            }
        }
        i++;
    }
}
// with auxiliar vector
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

int main()
{

}

