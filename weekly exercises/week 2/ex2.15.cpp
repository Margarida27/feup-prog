// ex2.15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL)); 

    int n1, n2, answer;
    float time;

    n1 = 2 + rand() % 10;
    n2 = 2 + rand() % 10;

    cout << "What is the result of multiplying the numbers " << n1 << " and " << n2 << "?";

    time = clock(); 

    cin >> answer;

    time = clock() - time;
    time = float(time) / CLOCKS_PER_SEC;
    
    if (n1 * n2 == answer)
    {
        if (time < 5)
            cout << "Good! You took " << time << " seconds to answer.";
        else if (time >= 5 && time <= 10)
            cout << "Satisfactory. You took " << time << " seconds to answer.";
        else
            cout << "Insufficient. You took " << time;
    }
    else
        cout << "Very bad! You answered incorrectly.";    
}