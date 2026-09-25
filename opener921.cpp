#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num1;
    int num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << endl;
    cout << "-----------------------------" << endl;
    cout << setw(20) << left << "Operation" << "Result" << endl;
    cout << "-----------------------------" << endl;

    cout << setw(20) << left << "Sum" 
         << (num1 + num2) << endl;

    cout << setw(20) << left << "Difference" 
         << (num1 - num2) << endl;

    cout << setw(20) << left << "Product" 
         << (num1 * num2) << endl;

    cout << setw(20) << left << "Quotient" 
         << (num1 / static_cast<double>(num2)) << endl;

    cout << setw(20) << left << "Remainder" 
         << (num1 % num2) << endl;

    cout << "-----------------------------" << endl;

    return 0;
}