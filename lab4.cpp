#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
   
    string foodName;
    string cashierNotes;
    char itemCode;
    int itemQuantity;
    double unitPrice;
    bool isMember;

    // Get the food information
    cout << "Enter food name: ";
    getline(cin, foodName);

    cout << "Enter item code: ";
    cin >> itemCode;

    cout << "Enter item quantity: ";
    cin >> itemQuantity;

    cout << "Enter unit price: ";
    cin >> unitPrice;

    // Get the membership status
    cout << "Are you a member? (1 = yes, 0 = no): ";
    cin >> isMember;


    cin.ignore();


    cout << "Enter cashier notes: ";
    getline(cin, cashierNotes);

    // Calculate the original price
    double subtotal = itemQuantity * unitPrice;

    // Members get a 10 percent discount
    double discount = 0.0;

    if (isMember)
    {
        discount = subtotal * 0.10;
    }

    // Subtract the discount before calculating tax
    double discountedSubtotal = subtotal - discount;

    // Calculate the tax
    double tax = discountedSubtotal * 0.0825;

    // Calculate the final price
    double total = discountedSubtotal + tax;

    // the receipt
    cout << "\nReceipt\n";
    cout << "--------------------------------\n";

    cout << left << setw(15) << "Food:" << foodName << endl;
    cout << left << setw(15) << "Item Code:" << itemCode << endl;
    cout << left << setw(15) << "Quantity:" << itemQuantity << endl;

    cout << left << setw(15) << "Price:"
         << right << fixed << setprecision(2)
         << "$" << unitPrice << endl;

    cout << left << setw(15) << "Member:" << isMember << endl;

    cout << left << setw(15) << "Subtotal:"
         << right << "$" << subtotal << endl;

    cout << left << setw(15) << "Discount:"
         << right << "$" << discount << endl;

    cout << left << setw(15) << "Tax:"
         << right << "$" << tax << endl;

    cout << left << setw(15) << "Total:"
         << right << "$" << total << endl;

    cout << left << setw(15) << "Notes:"
         << cashierNotes << endl;

    // the inventory audit table
    cout << "\nInventory Audit\n";
    cout << "----------------------------------------\n";

    cout << left
         << setw(15) << "Item Code"
         << setw(25) << "Food"
         << setw(10) << "Quantity"
         << right << setw(10) << "Price"
         << endl;

    //  the item information in the table
    cout << left
         << setw(15) << itemCode
         << setw(25) << foodName
         << setw(10) << itemQuantity
         << right << setw(10) << fixed << setprecision(2)
         << unitPrice
         << endl;

    return 0;
}