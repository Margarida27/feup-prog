// ex5.10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Polygon {
    int nVertices;
    vector<Point> vertices;
};

int main()
{
    Polygon plgn;
    int sum = 0;
    double area;

    cout << "number of vertices of the polygon: ";
    cin >> plgn.nVertices;
    cout << endl;

    for (int i = 1; i <= plgn.nVertices; i++)
    {
        Point p;
        cout << "vertice " << i << endl;
        cout << "x coordinate: "; cin >> p.x;
        cout << "y coordinate: "; cin >> p.y;
        cout << endl;
        plgn.vertices.push_back(p);
    }

    for (int i = 0; i < plgn.vertices.size(); i++)
    {
        int x1 = plgn.vertices[i].x;
        int x2 = plgn.vertices[(i + 1) % plgn.nVertices].x;
        int y1 = plgn.vertices[i].y;
        int y2 = plgn.vertices[(i + 1) % plgn.nVertices].y;

        sum += (x1 * y2 - y1 * x2);
    }

    area = sum / 2;
    if (area < 0)
        area = area * -1;

    cout << "area of the polygon: " << area << endl;
}
