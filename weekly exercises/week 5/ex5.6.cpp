// ex5.6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

bool readFraction(Fraction& fraction) //checks if the fraction is valid
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

int greatestCommonDiv(int a, int b) //auxiliar function to the reduceFraction() function, finds greatest common divisor
{
    if (b == 0)
        return a;
    return greatestCommonDiv(b, (a % b));
}

void reduceFraction(Fraction& fraction) //reduces fraction
{
    int gcd;
    gcd = greatestCommonDiv(fraction.numerator, fraction.denominator);
    fraction.numerator = fraction.numerator / gcd;
    fraction.denominator = fraction.denominator / gcd;

    if (fraction.denominator == 1)
        cout << "reduced result: " << fraction.numerator;
    else
        cout << "reduced result: " << fraction.numerator << '/' << fraction.denominator;
}

int main()
{
    Fraction f1, f2, copy, res;

    char separator, op;
    int gcd;

    cout << "fraction 1: ";
    cin >> f1.numerator >> separator >> f1.denominator;

    if (!readFraction(f1) || separator != '/')
    {
        f1.numerator = 0;
        f1.denominator = 0;
    }

    cout << "fraction 2: ";
    cin >> f2.numerator >> separator >> f2.denominator;

    if (!readFraction(f2) || separator != '/')
    {
        f2.numerator = 0;
        f2.denominator = 0;
    }

    cout << "operation (+ | - | * | / ): ";
    cin >> op;

    copy.numerator = f1.numerator;
    copy.denominator = f1.denominator;

    switch (op)
    {
    case '+': //addition operation

        if (f1.denominator == f2.denominator)
        {
            res.numerator = f1.numerator + f2.numerator;
            res.denominator = f1.denominator;
        }
        else
        {
            f1.numerator = f1.numerator * f2.denominator;
            f2.numerator = f2.numerator * f1.denominator;
            res.numerator = f1.numerator + f2.numerator;
            res.denominator = f1.denominator * f2.denominator;
        }

        cout << "addition result = " << res.numerator << '/' << res.denominator << endl;
        reduceFraction(res);
        break;

    case '-': //subtraction operation

        if (f1.denominator == f2.denominator)
        {
            res.numerator = f1.numerator - f2.numerator;
            res.denominator = f1.denominator;
        }
        else
        {
            f1.numerator = f1.numerator * f2.denominator;
            f2.numerator = f2.numerator * f1.denominator;
            res.numerator = f1.numerator - f2.numerator;
            res.denominator = f1.denominator * f2.denominator;
        }

        cout << "addition result = " << res.numerator << '/' << res.denominator << endl;
        reduceFraction(res);
        break;

    case '*': //multiplication operation

        res.numerator = f1.numerator * f2.numerator;
        res.denominator = f1.denominator * f2.denominator;

        cout << "multiplication result = " << res.numerator << '/' << res.denominator << endl;
        reduceFraction(res);
        break;

    case '/': //division operation

        res.numerator = f1.numerator * f2.denominator;
        res.denominator = f1.denominator * f2.numerator;

        cout << "division result = " << res.numerator << '/' << res.denominator << endl;
        reduceFraction(res);
        break;
    }
}