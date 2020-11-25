// ex5.7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

typedef struct {
    unsigned int year, month, day;
} Date;

void readDate(Date* d)
{
    int year, month, day;
    cout << "data (year/month/day): ";
    cin >> year; cin.ignore(); cin >> month; cin.ignore(); cin >> day;
    d->year = year;
    d->month = month;
    d->day = day;
}

void writeDate(const Date* d)
{
    cout << "Date: " << d->year << "/" << d->month << "/" << d->day << endl;;
}

int compareDates(const Date* d1, const Date* d2)
{
    if (d1->year < d2->year)
        return -1;
    else if (d1->year > d2->year)
        return 1;
    else
    {
        if (d1->month < d2->month)
            return -1;
        else if (d1->month > d2->month)
            return 1;
        else
        {
            if (d1->day < d2->day)
                return -1;
            else if (d1->day > d2->day)
                return 1;
            else
                return 0;
        }
    }
}

void sortDates(Date* d1, Date* d2)
{
    if (compareDates(d1, d2) == -1)
    {
        writeDate(d1);
        writeDate(d2);
    }
    else if (compareDates(d1, d2) == 1)
    {
        writeDate(d2);
        writeDate(d1);
    }
    else
        cout << "The dates are the same.\n";
}

int main()
{
    Date d1, d2;
    readDate(&d1); 
    readDate(&d2);
    sortDates(&d1, &d2);
}
