#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string foodName;
    char itemChoice;
    char sizeChoice;
    char tipChoice;
    int itemQuantity;
    bool isMember;

    double unitPrice = 0.0;
    double subtotal;
    double discount = 0.0;

    // Display the menu
    cout << "Coffee Shop Menu\n";
    cout << "--------------------------------------------------\n";

    cout << left << setw(22) << "Item"
         << setw(12) << "Small"
         << setw(12) << "Medium"
         << setw(12) << "Large" << endl;

    cout << left << setw(22) << "A. Caffe Latte"
         << setw(12) << "$4.75"
         << setw(12) << "$5.50"
         << setw(12) << "$6.25" << endl;

    cout << left << setw(22) << "B. Cold Brew"
         << setw(12) << "$4.50"
         << setw(12) << "$5.25"
         << setw(12) << "$5.95" << endl;

    cout << left << setw(22) << "C. Chai Tea Latte"
         << setw(12) << "$4.50"
         << setw(12) << "$5.25"
         << setw(12) << "$5.75" << endl;

    cout << left << setw(22) << "D. Hot Drip Coffee"
         << setw(12) << "$2.95"
         << setw(12) << "$3.50"
         << setw(12) << "$3.95" << endl;

    cout << "--------------------------------------------------\n";

    // Ask the user to select an item
    cout << "What item would you like? ";
    cin >> itemChoice;

    // Select the food
    if (itemChoice == 'A')
    {
        foodName = "Caffe Latte";
    }
    else if (itemChoice == 'B')
    {
        foodName = "Cold Brew";
    }
    else if (itemChoice == 'C')
    {
        foodName = "Chai Tea Latte";
    }
    else if (itemChoice == 'D')
    {
        foodName = "Hot Drip Coffee";
    }

    // Ask the user to select a size
    cout << "What size? (S = Small, M = Medium, L = Large): ";
    cin >> sizeChoice;

    // Select the price
    switch (sizeChoice)
    {
        case 'S':
            if (itemChoice == 'A')
                unitPrice = 4.75;
            else if (itemChoice == 'B')
                unitPrice = 4.50;
            else if (itemChoice == 'C')
                unitPrice = 4.50;
            else if (itemChoice == 'D')
                unitPrice = 2.95;
            break;

        case 'M':
            if (itemChoice == 'A')
                unitPrice = 5.50;
            else if (itemChoice == 'B')
                unitPrice = 5.25;
            else if (itemChoice == 'C')
                unitPrice = 5.25;
            else if (itemChoice == 'D')
                unitPrice = 3.50;
            break;

        case 'L':
            if (itemChoice == 'A')
                unitPrice = 6.25;
            else if (itemChoice == 'B')
                unitPrice = 5.95;
            else if (itemChoice == 'C')
                unitPrice = 5.75;
            else if (itemChoice == 'D')
                unitPrice = 3.95;
            break;
    }

    // Display the order
    cout << "\nYour Order\n";
    cout << "-------------------------\n";
    cout << "Item: " << foodName << endl;
    cout << "Size: " << sizeChoice << endl;

    cout << fixed << setprecision(2);
    cout << "Cost: $" << unitPrice << endl;

    // Ask for quantity
    cout << "\nEnter item quantity: ";
    cin >> itemQuantity;

    // Ask about membership
    cout << "Are you a member? (1 = yes, 0 = no): ";
    cin >> isMember;

    // Calculate subtotal
    subtotal = itemQuantity * unitPrice;

    // Members get a 10 percent discount
    if (isMember)
    {
        discount = subtotal * 0.10;
    }

    // Calculate the discounted subtotal
    double discountedSubtotal = subtotal - discount;

    // Calculate taxes
    double arkansasTax = discountedSubtotal * 0.065;
    double faulknerTax = discountedSubtotal * 0.005;
    double conwayTax = discountedSubtotal * 0.02125;

    double totalTax = arkansasTax + faulknerTax + conwayTax;

    // Display the receipt
    cout << "\nReceipt\n";
    cout << "--------------------------------------------------\n";

    cout << left << setw(20) << "Item:" << foodName << endl;
    cout << left << setw(20) << "Quantity:" << itemQuantity << endl;
    cout << left << setw(20) << "Unit Price:" << "$" << unitPrice << endl;
    cout << left << setw(20) << "Subtotal:" << "$" << subtotal << endl;
    cout << left << setw(20) << "Discount:" << "$" << discount << endl;

    // Display taxes
    cout << "\nTaxes\n";
    cout << "--------------------------------------------------\n";

    cout << left << setw(30) << "Arkansas State Tax (6.5%)"
         << "$" << arkansasTax << endl;

    cout << left << setw(30) << "Faulkner County Tax (0.5%)"
         << "$" << faulknerTax << endl;

    cout << left << setw(30) << "Conway Municipal Tax (2.125%)"
         << "$" << conwayTax << endl;

    cout << left << setw(30) << "Total Tax"
         << "$" << totalTax << endl;

    // Display tip menu
    cout << "\nTip Selection\n";
    cout << "-------------------------\n";
    cout << "A. 15%\n";
    cout << "B. 20%\n";
    cout << "C. 25%\n";
    cout << "D. Other Amount\n";

    cout << "What tip do you choose? ";
    cin >> tipChoice;

    double tip = 0.0;

    // Calculate tip
    if (tipChoice == 'A')
    {
        tip = discountedSubtotal * 0.15;
    }
    else if (tipChoice == 'B')
    {
        tip = discountedSubtotal * 0.20;
    }
    else if (tipChoice == 'C')
    {
        tip = discountedSubtotal * 0.25;
    }
    else if (tipChoice == 'D')
    {
        cout << "How much would you like to tip? $";
        cin >> tip;
    }

    // Calculate final total
    double total = discountedSubtotal + totalTax + tip;

    // Display final total
    cout << "\nFinal Receipt\n";
    cout << "--------------------------------------------------\n";

    cout << left << setw(20) << "Item:" << foodName << endl;
    cout << left << setw(20) << "Quantity:" << itemQuantity << endl;
    cout << left << setw(20) << "Unit Price:" << "$" << unitPrice << endl;
    cout << left << setw(20) << "Subtotal:" << "$" << subtotal << endl;
    cout << left << setw(20) << "Discount:" << "$" << discount << endl;
    cout << left << setw(20) << "Total Tax:" << "$" << totalTax << endl;
    cout << left << setw(20) << "Tip:" << "$" << tip << endl;
    cout << left << setw(20) << "Total:" << "$" << total << endl;

    return 0;
}