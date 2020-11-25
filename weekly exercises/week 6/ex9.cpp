// ex9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <algorithm> // sort() function
#include <string>
#include <vector>
using namespace std;

void readFromFile(ifstream& input, string filename, vector<string>& names)
{
	input.open(filename);
	if (input.fail())
	{
		cerr << "Failed to open the file.";
		exit(1);
	}
	while (!input.eof())
	{
		string name;
		getline(input, name);
		names.push_back(name);
	}
	input.close();
}

void removeDuplicates(vector<string>& names)
{
	vector<string> aux;
	bool duplicate = false;

	for (int i = 0; i < names.size(); i++)
	{
		for (int j = 0; j < aux.size(); j++)
			if (aux[j] == names[i])
				duplicate = true;

		if (!duplicate)
			aux.push_back(names[i]);

		duplicate = false;
	}
	names = aux;
	sort(names.begin(), names.end());
}

void writeToFile(ofstream& output, string filename, vector<string>& names)
{
	output.open(filename);
	if (output.fail())
	{
		cerr << "Failed to open the file.";
		exit(1);
	}
	for (int i = 0; i < names.size(); i++)
	{
		output << names[i] << endl;
	}
	output.close();
}

int main()
{
	ifstream input;
	ofstream output;
	string filename = "names.txt";
	vector<string> names;

	// using my own code to remove the duplicates
	readFromFile(input, filename, names);
	removeDuplicates(names);
	writeToFile(output, filename, names);

	// using unique() function to remove duplicates 
	readFromFile(input, filename, names);
	unique(names.begin(), names.end());
	sort(names.begin(), names.end());
	writeToFile(output, filename, names);
}
