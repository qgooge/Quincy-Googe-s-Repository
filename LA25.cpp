#include <iostream>
using namespace std;

int main()
{
    int num1;
    int num2;
    char choice;

    cout << "Enter the first integer: ";
    cin >> num1;

    cout << "Enter the second integer: ";
    cin >> num2;

    cout << endl;
    cout << "Choose an operation:" << endl;
    cout << "a. Addition" << endl;
    cout << "b. Subtraction" << endl;
    cout << "c. Multiplication" << endl;
    cout << "d. Division" << endl;
    cout << "e. Remainder" << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 'a')
    {
        cout << "Result: " << num1 + num2 << endl;
    }
    else if (choice == 'b')
    {
        cout << "Result: " << num1 - num2 << endl;
    }
    else if (choice == 'c')
    {
        cout << "Result: " << num1 * num2 << endl;
    }
    else if (choice == 'd')
    {
        cout << "Result: " << num1 / num2 << endl;
    }
    else if (choice == 'e')
    {
        cout << "Result: " << num1 % num2 << endl;
    }

    return 0;
}