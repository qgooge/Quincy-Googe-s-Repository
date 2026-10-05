#include <iostream>
using namespace std;

int main()
{
    int correctPIN = 2265;
    int pin;
    int attempts = 0;
    int maxAttempts = 3;

    do
    {
        cout << "Enter your 4-digit PIN: ";
        cin >> pin;

        attempts++;

        if (pin == correctPIN)
        {
            cout << "Access Granted!" << endl;
            break;
        }
        else if (attempts == maxAttempts)
        {
            cout << "Account Locked! Too many failed attempts." << endl;
        }

    } while (attempts < maxAttempts);

    return 0;
}