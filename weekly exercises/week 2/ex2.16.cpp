// ex2.16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ios>
#include <climits>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

bool validOperation(char& operation) //checks if is a valid operation
{
    if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^')
        return true;
    else
    {
        cin.clear(); //clears error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //clears input buffer
        return false;
    }
}

bool validYorN(char& anotherOperation)
{
    if (anotherOperation == 'N' || anotherOperation == 'n' || anotherOperation == 'Y' || anotherOperation == 'y')
        return true;
    else
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}

bool validOption(string& option)
{
    if (option == "M" || option == "M+" || option == "M-" || option == "MR" || option == "MC" || option == "E" || option == "m" || option == "m+" || option == "m-" || option == "mr" || option == "mc" || option == "e")
        return true;
    else
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
}

double calculateResult(double& operand1, char& operation, double& operand2)
{
    double result;

   switch (operation)
    {
    case '+':
        result = operand1 + operand2;
        break;
    case '-':
        result = operand1 - operand2;
        break;
    case '*':
        result = operand1 * operand2;
        break;
    case '/':
        result = operand1 / operand2;
        break;
    case '^':
        result = pow(operand1, operand2);
        break;
    }
    return result;
}

int main()
{
    const unsigned int RESULT_PRECISION = 3;
    double operand1, operand2, result;
    char operation, anotherOperation;
    string option;
    bool memoryCleared = false; 
    double memory = 0;
    
    do
    {
        do 
        {
            cout << "Insert operation (x op y):\n";
            cin >> operand1 >> operation >> operand2;
            if (cin.peek() != '\n')
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (validOperation(operation) == false);

        result = calculateResult(operand1, operation, operand2);
        cout << "Result (" << operand1 << " " << operation << " " << operand2 << "): " 
            << fixed << setprecision(RESULT_PRECISION) << result << endl << endl;

        do
        {
            cout << "Y|y: Compute another operation\n"
                << "N|n: More options\n";
            cin >> anotherOperation;
            cout << endl;
        } while (validYorN(anotherOperation) == false);
        
        while (anotherOperation == 'N' || anotherOperation == 'n')
        {
            do
            {
                cout << "M|m: save current value on the memory\n"
                    << "MR|mr: show the content of the memory\n"
                    << "M+|m+: add current value to the memory\n"
                    << "M-|m-: subtract current value to the memory"
                    << "MC|mc: clear memory\n"
                    << "E|e: exit calculator\n\n";

                cout << "What do you want to do next? ";
                cin >> option;
                cout << endl;
            } while (validOption(option) == false);
            

            if (option == "M" || option == "m") //updates memory with the current value
            {
                memory = result;
                cout << "Memory sucessfully updated.\n\n";
                memoryCleared = false;
                do
                {
                    cout << "Y|y: Compute another operation\n"
                        << "N|n: More options\n";
                    cin >> anotherOperation;
                    cout << endl;
                } while (validYorN(anotherOperation) == false);
            }
            else if (option == "MR" || option == "mr") //shows content of the memory
            {
                if (memoryCleared == false) //if there is any information available
                {
                    cout << "Memory: ";
                    cout << memory << endl << endl;
                    do
                    {
                        cout << "Y|y: Compute another operation\n"
                            << "N|n: More options\n";
                        cin >> anotherOperation;
                        cout << endl;
                    } while (validYorN(anotherOperation) == false);
                }
                else //otherwise the following message will be shown
                {
                    cout << "You have cleared all memory. There is not any information available to display.\n\n";
                    do
                    {
                        cout << "Y|y: Compute another operation\n"
                            << "N|n: More options\n";
                        cin >> anotherOperation;
                        cout << endl;
                    } while (validYorN(anotherOperation) == false);
                }
            }
            else if (option == "M+" || option == "m+") //adds current value to the memory
            {
                memory += result;
                memoryCleared = false;
                cout << "Memory sucessfully updated.\n"
                    << "Current value has been added to the memory.\n\n";
                do
                {
                    cout << "Y|y: Compute another operation\n"
                        << "N|n: More options\n";
                    cin >> anotherOperation;
                    cout << endl;
                } while (validYorN(anotherOperation) == false);
            }
            else if (option == "M-" || option == "m-") //subtracts current value to the memory
            {
                memory -= result;
                memoryCleared = false;
                cout << "Memory sucessfully updated.\n"
                    << "Current value has been subtract to the memory.\n\n";
                do
                {
                    cout << "Y|y: Compute another operation\n"
                        << "N|n: More options\n";
                    cin >> anotherOperation;
                    cout << endl;
                } while (validYorN(anotherOperation) == false);
            }
            else if (option == "MC" || option == "mc") //clears the memory
            {
                memoryCleared = true;
                cout << "You have cleared the memory. Memory is now empty.\n\n";
                do
                {
                    cout << "Y|y: Compute another operation\n"
                        << "N|n: More options\n";
                    cin >> anotherOperation;
                    cout << endl;
                } while (validYorN(anotherOperation) == false);
            }
            else if (option == "E" || option == "e") //exits the program
            {
                cout << "Exiting the calculator...\n";
                return 0;
            }
        }
    } while (anotherOperation == 'y' || anotherOperation == 'Y');
}