// ex3.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
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

int dayOfWeek(int& year, int& month, int& day)
{
    int ds; //day of week
    int s; //two first digits of the year
    int a; //two last digits of the year
    int c; //month code

    a = year % 100; 
    s = year / 100; 

    switch (month) 
    {
    case 1: if (leapYear(year)) c = 6; else c = 0; break;
    case 2: if (leapYear(year)) c = 2; else c = 3; break;
    case 3: c = 3; break;
    case 4: c = 6; break;
    case 5: c = 1; break;
    case 6: c = 4; break;
    case 7: c = 6; break;
    case 8: c = 2; break;
    case 9: c = 5; break;
    case 10: c = 0; break;
    case 11: c = 3; break;
    case 12: c = 5; break;
    }

    ds = (((5 * a) / 4) + c + day - 2 * (s % 4) + 7) % 7; //day of week

    return ds;
}

void calendar(int& year, int& month)
{
    string week[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    int dm = daysOfMonth(year, month); //days of the month
    int day = 1; //day of the month (starts with the 1st day)
    int weekDay; //correspondent day of the week for day
    string m;
    bool firstWeek = true;

    switch (month)
    {
    case 1: m = "January"; break;
    case 2: m = "February"; break;
    case 3: m = "March"; break;
    case 4: m = "April"; break;
    case 5: m = "May"; break;
    case 6: m = "June"; break;
    case 7: m = "July"; break;
    case 8: m = "August"; break;
    case 9: m = "September"; break;
    case 10: m = "October"; break;
    case 11: m = "November"; break;
    case 12: m = "December"; break;
    }

    cout << "====================================================\n";
    cout << "Calendar: " << m << " / " << year << "\n\n";

    for (int i = 0; i < 7; i++) //days of the week
    {
        cout << week[i] << "\t";
    }
    cout << endl;

    while (day <= dm)
    {
        weekDay = dayOfWeek(year, month, day) - 1;

        if (weekDay < 0)
            weekDay += 7;

        for (int i = weekDay; i < 7; i++)
        {
            if (firstWeek) //since it is not every time a month starts at sunday, this condition will be used to adjust the days of the first week 
            {
                for (int j = 0; j < weekDay; j++)
                {
                    cout << "\t";
                }
                firstWeek = false;
            }
          
            if (day <= dm)
            {
                cout << day << "\t";
                day += 1;
            } 
        }
        cout << endl << endl;
    }
    cout << "====================================================\n\n";
}

int main()
{
    int year, month;
    cout << "year: "; cin >> year;

    /*
    cout << "month: "; cin >> month;
    calendar(year, month);
    */

    for (int month = 1; month <= 12; month++)
    {
        calendar(year, month);
    }    
}