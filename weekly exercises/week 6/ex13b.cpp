// ex13b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>  
#include <vector>
#include <set>
using namespace std;

struct Bet 
{
    set<int> numbers;
    set<int> stars;
};

void generateBet(Bet& b)
{
    while (b.numbers.size() != 5)
    {
        int n = 1 + rand() % 51;
        b.numbers.insert(n);
    }

    while (b.stars.size() != 2)
    {
        int n = 1 + rand() % 13;
        b.stars.insert(n);
    }
}

void showMatches(vector<Bet>& bets, Bet& win, int n)
{
    set<int> matchNumbers, matchStars;
    set<int>::iterator itNums, itWinNums, itStars, itWinStars;

    cout << endl;
    cout << "win numbers: ";
    for (itWinNums = begin(win.numbers); itWinNums != end(win.numbers); itWinNums++)
        cout << *itWinNums << ' ';
    cout << endl << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "---------- bet no. " << i + 1 << " ----------" << endl;

        cout << "bet numbers: ";
        for (itNums = begin(bets[i].numbers); itNums != end(bets[i].numbers); itNums++)
            cout << *itNums << ' ';
        cout << endl;

        for (itNums = begin(bets[i].numbers); itNums != end(bets[i].numbers); itNums++)
        {
            for (itWinNums = begin(win.numbers); itWinNums != end(win.numbers); itWinNums++)
            {
                if (*itNums == *itWinNums)
                    matchNumbers.insert(*itNums);
            }
        }

        for (itStars = begin(bets[i].stars); itStars != end(bets[i].stars); itStars++)
        {
            for (itWinStars = begin(win.stars); itWinStars != end(win.stars); itWinStars++)
            {
                if (*itStars == *itWinStars)
                    matchStars.insert(*itStars);
            }
        }

        cout << "matching numbers: ";
        if (matchNumbers.empty())
            cout << "none";
        else
        {
            for (set<int>::iterator i = begin(matchNumbers); i != end(matchNumbers); i++)
                cout << *i << ' ';
        }
        cout << endl;

        cout << "matching stars: ";
        if (matchStars.empty())
            cout << "none";
        else
        {
            for (set<int>::iterator j = begin(matchStars); j != end(matchStars); j++)
                cout << *j << ' ';
        }
        cout << endl << endl;
    }
}

int main()
{
    int n;
    vector<Bet> bets;
    Bet win;
    generateBet(win);
    srand(time(NULL));

    cout << "How many bets? "; cin >> n;

    for (int i = 1; i <= n; i++)
    {
        Bet bet;
        generateBet(bet);
        bets.push_back(bet);
    }

    showMatches(bets, win, n);
}