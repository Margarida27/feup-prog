// ex3.8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

bool readFraction(int& numerator, int& denominator) //checks if the fraction is valid
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

void reduceFraction(int& numerator, int& denominator) //reduces fraction
{
    int gcd;
    gcd = greatestCommonDiv(numerator, denominator);
    numerator = numerator / gcd;
    denominator = denominator / gcd;
    
    cout << "reduced result: " << numerator << '/' << denominator;
}

int main()
{
    int numerator1, denominator1, numerator2, denominator2;
    int resNumerator, resDenominator;
    int numerator1copy, denominator1copy;
    int gcd;
    char separator, op;
    
    cout << "fraction 1: ";
    cin >> numerator1 >> separator >> denominator1;

    if (!readFraction(numerator1, denominator1) || separator != '/' || (numerator1 !=0 && denominator1 == 0))
    {
        numerator1 = 0;
        denominator1 = 0;
    }

    cout << "fraction 2: ";
    cin >> numerator2 >> separator >> denominator2;

    if (!readFraction(numerator1, denominator1) || separator != '/' || (numerator1 != 0 && denominator1 == 0))
    {
        numerator2 = 0;
        denominator2 = 0;
    }
    
    cout << "operation (+ | - | * | / ): ";
    cin >> op;

    numerator1copy = numerator1;
    denominator1copy = denominator1;

    switch (op)
    {
    case '+': //addition operation

        if (denominator1 == denominator2)
        {
            resNumerator = numerator1 + numerator2;
            resDenominator = denominator1;
        }
        else
        {
            denominator1 = denominator1 * denominator2;
            numerator1 = numerator1 * numerator2;
            denominator2 = denominator2 * denominator1copy;
            numerator2 = numerator2 * numerator1copy;

            resNumerator = numerator1 + numerator2;
            resDenominator = denominator1;
        }

        cout << "addition result = " << resNumerator << '/' << resDenominator << endl;
        reduceFraction(resNumerator, resDenominator);
        break;

    case '-': //subtraction operation

        if (denominator1 == denominator2)
        {
            resNumerator = numerator1 + numerator2;
            resDenominator = denominator1;
        }
        else
        {
            denominator1 = denominator1 * denominator2;
            numerator1 = numerator1 * numerator2;
            denominator2 = denominator2 * denominator1copy;
            numerator2 = numerator2 * numerator1copy;

            resNumerator = numerator1 - numerator2;
            resDenominator = denominator1;
        }

        cout << "subtraction result = " << resNumerator << '/' << resDenominator << endl;
        reduceFraction(resNumerator, resDenominator);
        break;

    case '*': //multiplication operation

        resNumerator = numerator1 * numerator2;
        resDenominator = denominator1 * denominator2;

        cout << "multiplication result = " << resNumerator << '/' << resDenominator << endl;
        reduceFraction(resNumerator, resDenominator);
        break;

    case '/': //division operation

        resNumerator = numerator1 * denominator2;
        resDenominator = denominator1 * numerator2;

        cout << "division result = " << resNumerator << '/' << resDenominator << endl;
        reduceFraction(resNumerator, resDenominator);
        break;
    }        
}
