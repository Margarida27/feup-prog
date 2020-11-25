// ex12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>  
#include <vector>
#include <set>
using namespace std;

// a) using two STL vectors to represent the "main numbers" and the "star numbers"
void EuroMillions_v1()
{
    vector<int> mainNumbers;
    vector<int> luckyStars;

    for (int i = 1; i <= 50; i++)
        mainNumbers.push_back(i);

    random_shuffle(mainNumbers.begin(), mainNumbers.end());
    mainNumbers.erase(mainNumbers.begin() + 5, mainNumbers.end());

    for (int j = 1; j <= 12; j++)
        luckyStars.push_back(j);

    random_shuffle(luckyStars.begin(), luckyStars.end());
    luckyStars.erase(luckyStars.begin() + 2, luckyStars.end());

    cout << "main numbers: ";
    for (int i = 0; i < 5; i++)
        cout << mainNumbers[i] << ' ';

    cout << "\nlucky stars: ";
    for (int j = 0; j < 2; j++)
        cout << luckyStars[j] << ' ';
}

// b) Use two STL sets to represent the "main numbers" and the "star numbers"
void EuroMillions_v2()
{
    set<int> mainNumbers;
    set<int> luckyStars;
    srand(time(NULL));

    while (mainNumbers.size() != 5)
    {
        int n = 1 + rand() % 51;
        mainNumbers.insert(n);
    }

    while (luckyStars.size() != 2)
    {
        int n = 1 + rand() % 13;
        luckyStars.insert(n);
    }

    cout << "main numbers: ";
    for (auto i = mainNumbers.begin(); i != mainNumbers.end(); i++)
        cout << *i << ' ';

    cout << "\nlucky stars: ";
    for (auto j = luckyStars.begin(); j != luckyStars.end(); j++)
        cout << *j << ' ';
}

int main()
{
    EuroMillions_v1();
    cout << endl << endl;
    EuroMillions_v2();
}