// ex13a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>  
#include <vector>
#include <set>
using namespace std;

struct Bet 
{
    vector<int> numbers;
    vector<int> stars;
};

void generateBet(Bet& b)
{
    for (int i = 1; i <= 50; i++)
        b.numbers.push_back(i);

    random_shuffle(begin(b.numbers), end(b.numbers));
    b.numbers.erase(begin(b.numbers) + 5, end(b.numbers));

    for (int j = 1; j <= 12; j++)
        b.stars.push_back(j);

    random_shuffle(begin(b.stars), end(b.stars));
    b.stars.erase(begin(b.stars) + 2, end(b.stars));
}

void showMatches(vector<Bet>& bets, Bet& win, int n)
{
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        vector<int> matchNumbers, matchStars;

        cout << "----- bet no. " << i+1 << " -----" << endl;

        sort(begin(bets[i].numbers), end(bets[i].numbers));
        sort(begin(win.numbers), end(win.numbers));
        set_intersection(begin(bets[i].numbers), end(bets[i].numbers), begin(win.numbers), end(win.numbers), back_inserter(matchNumbers));

        cout << "matching numbers: ";
        if (matchNumbers.size() == 0)
            cout << "none";
        else
        {
            for (vector<int>::const_iterator i = begin(matchNumbers); i != end(matchNumbers); i++)
                cout << *i << " ";
        }
        
        cout << endl;

        sort(begin(bets[i].stars), end(bets[i].stars));
        sort(begin(win.stars), end(win.stars));
        set_intersection(begin(bets[i].stars), end(bets[i].stars), begin(win.stars), end(win.stars), back_inserter(matchStars));

        cout << "matching stars: ";
        if (matchStars.size() == 0)
            cout << "none";
        else
        {
            for (vector<int>::const_iterator j = begin(matchStars); j != end(matchStars); j++)
                cout << *j << " ";
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

    cout << "How many bets? "; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        Bet bet;
        generateBet(bet);
        bets.push_back(bet);
    }
    showMatches(bets,win,n);
}
