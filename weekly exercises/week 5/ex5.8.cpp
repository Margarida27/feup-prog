// ex5.8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
using namespace std;

struct EuroMillionsBet {
    vector<int> mainNumbers;
    vector<int> luckyStars;
};

bool search(vector<int> v, int value)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (value == v.at(i))
            return true;
    }
    return false;
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

void intersectionVectors(EuroMillionsBet& bet, EuroMillionsBet& win, EuroMillionsBet& match)
{
    vector<int> betNums, betStars, winNums, winStars, matchNums, matchStars;

    for (int i = 0; i < 5; i++)
    {
        betNums.push_back(bet.mainNumbers[i]);
        winNums.push_back(win.mainNumbers[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        betStars.push_back(bet.luckyStars[i]);
        winStars.push_back(win.luckyStars[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        if (search(winNums, betNums[i]))
            matchNums.push_back(betNums[i]);
    }

    for (int i = 0; i < 2; i++)
    {
        if (search(winStars, betStars[i]))
            matchStars.push_back(betStars[i]);
    }

    bubbleSortAscending(matchNums);
    bubbleSortAscending(matchStars);

    for (int i = 0; i < matchNums.size(); i++)
        match.mainNumbers.push_back(matchNums[i]);

    for (int i = 0; i < matchStars.size(); i++)
        match.luckyStars.push_back(matchStars[i]);
}

void showContent(EuroMillionsBet& match)
{
    if (match.mainNumbers.size() == 0)
        cout << "You haven't guessed any main numbers." << endl;
    else
    {
        cout << "main numbers guessed: ";

        for (int i = 0; i < match.mainNumbers.size(); i++)
            cout << match.mainNumbers[i] << " ";
        cout << endl;
    }

    if (match.luckyStars.size() == 0)
        cout << "You haven't guessed any lucky stars." << endl;
    else
    {
        cout << "lucky stars guessed: ";

        for (int i = 0; i < match.luckyStars.size(); i++)
            cout << match.luckyStars[i] << " ";
        cout << endl;
    }
}

void readBet(EuroMillionsBet& bet)
{
    int n1, n2, n3, n4, n5, s1, s2;

    cout << "main numbers: ";
    cin >> n1; cin.ignore(); cin >> n2; cin.ignore(); cin >> n3; cin.ignore(); cin >> n4; cin.ignore(); cin >> n5;
    bet.mainNumbers.push_back(n1); bet.mainNumbers.push_back(n2); bet.mainNumbers.push_back(n3); bet.mainNumbers.push_back(n4); bet.mainNumbers.push_back(n5);

    cout << "lucky stars: ";
    cin >> s1; cin.ignore(); cin >> s2;
    bet.luckyStars.push_back(s1); bet.luckyStars.push_back(s2);
}

void generateWin(EuroMillionsBet& win)
{
    for (int i = 0; i < 5; i++)
        win.mainNumbers.push_back(rand() % 51 + 1);
    for (int i = 0; i < 2; i++)
        win.luckyStars.push_back(rand() % 13 + 1);
}

int main()
{
    srand(time(NULL));
    EuroMillionsBet win, bet, match;

    generateWin(win);
    readBet(bet);
    intersectionVectors(bet, win, match);
    cout << endl;
    showContent(match);
}

