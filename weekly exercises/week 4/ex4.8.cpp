// ex4.8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
using namespace std;

bool leapYear(int& year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

int daysOfMonth(int& year, int& month)
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
        if (leapYear(year))
            return 29;
        else
            return 28;
}

void generate(vector<vector<int>>& pluv)
{
    int year = 2020;
    int pluvInfo;
    vector<int> byMonth;

    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= daysOfMonth(year, i); j++)
        {
            pluvInfo = rand() % 221;
            byMonth.push_back(pluvInfo);
        }
        pluv.push_back(byMonth);
        byMonth.clear();
    }

    for (int i = 0; i < 12; i++)
    {
        cout << "month: " << i+1 << " -> ";

        for (int j = 0; j < pluv[i].size(); j++)
        {
            cout << setfill('0') << setw(3) << pluv[i][j] << "  ";
        }

        cout << endl << endl;;
    }
}

void averageMonthly(vector<vector<int>>& pluv, vector<int>& avMonthly_vector, int& avMonthly)
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < pluv[i].size(); j++)
        {
            avMonthly += pluv[i][j];
        }
        avMonthly = avMonthly / pluv[i].size();
        avMonthly_vector.push_back(avMonthly);
        avMonthly = 0;
    }
    
    cout << "Monthly average pluviosity: " << endl;
    for (int i = 0; i < 12; i++)
    {
        cout << i + 1 << ": " << avMonthly_vector[i] << endl;
    }
}

void averageDaily(vector<vector<int>>& pluv, vector<int>& avMonthly_vector, int& avDaily)
{
    for (int i = 0; i < avMonthly_vector.size(); i++)
    {
        avDaily += avMonthly_vector[i];
    }
    avDaily = avDaily / 12;

    cout << "Daily average pluviosity: " << endl << avDaily << endl;
}

void maxMonthly(vector<vector<int>>& pluv, vector<int>& maxPluv, int& max)
{
    int day; 

    cout << "Maximum monthly pluviosity: " << endl;

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < pluv[i].size(); j++)
        {
            if (pluv[i][j] > max)
            {
                max = pluv[i][j];
                day = j + 1;
            }
        }
        maxPluv.push_back(max);

        cout << "month: " << i+1 << " / day: " << day << " / pluviosity: " << max;
    }
}

void aboveAv(vector<vector<int>>& pluv, vector<int>& avMonthly_vector)
{
    cout << "Above the average daily pluviosity: " << endl;

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < pluv[i].size(); j++)
        {
            if (pluv[i][j] > avMonthly_vector[i])
                cout << j + 1 << "/" << i + 1 << "/2020 -> pluviosity: " << pluv[i][j] << endl;
        }
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));
    int avMonthly = 0;
    int avDaily = 0;
    int max = 0;
    vector<vector<int>> pluv;
    vector<int> avMonthly_vector;
    vector<int> maxPluv;

    generate(pluv);
    cout << endl;
    averageMonthly(pluv, avMonthly_vector, avMonthly);
    cout << endl;
    averageDaily(pluv, avMonthly_vector, avDaily);
    cout << endl;
    aboveAv(pluv, avMonthly_vector);
    cout << endl;
    maxMonthly(pluv, maxPluv, max);
}
