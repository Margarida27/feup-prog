// ex5.9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Address{
    string street;
    int door;
    string city;
};

struct Person {
    string name;
    int age;
    char gender;
    Address addr;
};

int main()
{
    size_t max;
    string cityFilter;
    vector<Person> data;

    cout << "size of the data set: "; cin >> max; 
    cin.ignore(1000, '\n'); 
    cout << endl;

    while (max != 0)
    {
        Person p;
        cout << "name: "; getline(cin,p.name);
        cout << "age: "; cin >> p.age; 
        cin.ignore(1000, '\n');
        cout << "gender (m|f): "; cin >> p.gender; 
        cin.ignore(1000, '\n');
        cout << "street: "; getline(cin, p.addr.street);
        cout << "door: "; cin >> p.addr.door; 
        cin.ignore(1000, '\n');
        cout << "city: "; getline(cin, p.addr.city); 
        cout << endl;

        data.push_back(p);

        max--;
    }

    cout << "city filter: "; getline(cin, cityFilter);
    cout << endl;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i].addr.city == cityFilter)
            cout << data[i].name << ", "
            << data[i].age << " years, "
            << data[i].addr.street << ", "
            << data[i].addr.door << ", "
            << data[i].addr.city << endl << endl;
    }
}
