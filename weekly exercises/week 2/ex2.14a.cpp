// ex2.14a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, nMaxIter;
    double rq = 1, rqn, delta, dif; 

    cout << "number: "; cin >> n;
    cout << "delta: "; cin >> delta;
    cout << "maximum number of iterations: "; cin >> nMaxIter;

    while (fabs(sqrt(n) - rq) > delta && nMaxIter > 0)
    {
        rqn = (rq + n / rq) / 2;
        dif = pow(rqn, 2) - rqn;
        rq = rqn;
        nMaxIter -= 1;
    }
    cout << "Heron of Alexandria's algorithm square root of " << n << ": " << rq << endl;
}
