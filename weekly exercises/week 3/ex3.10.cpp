// ex3.10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

unsigned long long factorialIte(unsigned int& n) //a) iterative version of factorial function 
{
    int f = 1;
    for (unsigned int i = n; i >= 2; i--)
        f = f * i;
    return f;
}

unsigned long long factorialRec(unsigned int& n) //b) recursive version of factorial function
{
    if (n == 0 || n == 1)
        return 1;
    else
        return (n * factorialRec(n - 1));
}

int main()
{
    
}
