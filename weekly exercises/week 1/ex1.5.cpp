// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int h1, m1, s1;
    int h2, m2, s2;
    int d, h, m, s;

    cout << "Time1 (h:m:s) ? "; 
    cin >> h1 >> m1 >> s1;
    cout << "Time2 (h:m:s) ? "; 
    cin >> h2 >> m2 >> s2;

    s = (s1 + s2) % 60;
    m = (m1 + m2 + ((s1 + s2) / 60)) % 60;
    h = (h1 + h2 + ((m1 + m2) / 60)) % 24;
    d = (h1 + h2) / 24;

    cout << "Time1 + Time2 = days: " << d << " | hours: " << h << " | minutes: " << m << " | seconds: " << s;

}