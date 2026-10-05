#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string customerName;
    string foodName;
    string orderDetails;

    char itemChoice;
    char sizeChoice;
    char tipChoice;
    char anotherCustomer;

    int itemQuantity;
    bool isMember;

    double unitPrice;
    double subtotal;
    double discount;
    double discountedSubtotal;
    double arkansasTax;
    double faulknerTax;
    double conwayTax;
    double totalTax;
    double tip;
    double total;

    double grandTotalSales = 0.0;
    int totalCustomers = 0;

    // Loop for multiple customers
    do
    {
        orderDetails = "";
        subtotal = 0.0;
        discount = 0.0;
        totalTax = 0.0;
        tip = 0.0;
        total = 0.0;

        cout << "\nEnter customer name: ";
        cin >> customerName;

        // Display the menu
        cout << "\nCoffee Shop Menu\n";
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

        cout << left << setw(22) << "E. Checkout" << endl;

        cout << "--------------------------------------------------\n";

        // Loop for multiple items
        do
        {
            cout << "\nWhat item would you like? ";
            cin >> itemChoice;

            // Make sure the menu choice is valid
            while (itemChoice != 'A' && itemChoice != 'B' &&
                   itemChoice != 'C' && itemChoice != 'D' &&
                   itemChoice != 'E')
            {
                cout << "Invalid choice. Please enter A, B, C, D, or E: ";
                cin >> itemChoice;
            }

            // Checkout
            if (itemChoice == 'E')
            {
                break;
            }

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

            // Make sure the size is valid
            while (sizeChoice != 'S' && sizeChoice != 'M' && sizeChoice != 'L')
            {
                cout << "Invalid size. Please enter S, M, or L: ";
                cin >> sizeChoice;
            }

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

            // Ask for quantity
            cout << "Enter item quantity: ";
            cin >> itemQuantity;

            // Calculate the item subtotal
            double itemSubtotal = itemQuantity * unitPrice;

            // Add item to the order
            orderDetails += foodName + "  ";
            orderDetails += "Size: " + string(1, sizeChoice) + "  ";
            orderDetails += "Qty: " + to_string(itemQuantity) + "  ";
            orderDetails += "$" + to_string(itemSubtotal) + "\n";

            // Add item to total subtotal
            subtotal += itemSubtotal;

        } while (itemChoice != 'E');

        // Ask about membership
        cout << "\nAre you a member? (1 = yes, 0 = no): ";
        cin >> isMember;

        // Members get a 10 percent discount
        if (isMember)
        {
            discount = subtotal * 0.10;
        }

        // Calculate the discounted subtotal
        discountedSubtotal = subtotal - discount;

        // Calculate taxes
        arkansasTax = discountedSubtotal * 0.065;
        faulknerTax = discountedSubtotal * 0.005;
        conwayTax = discountedSubtotal * 0.02125;

        totalTax = arkansasTax + faulknerTax + conwayTax;

        // Display tip menu
        cout << "\nTip Selection\n";
        cout << "-------------------------\n";
        cout << "A. 15%\n";
        cout << "B. 20%\n";
        cout << "C. 25%\n";
        cout << "D. Other Amount\n";

        cout << "What tip do you choose? ";
        cin >> tipChoice;

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
        total = discountedSubtotal + totalTax + tip;

        // Add to grand total
        grandTotalSales += total;
        totalCustomers++;

        // Calculate loyalty points
        int loyaltyPoints = total / 3;

        // Display receipt
        cout << fixed << setprecision(2);

        cout << "\nFinal Receipt\n";
        cout << "--------------------------------------------------\n";

        cout << "Customer: " << customerName << endl;

        cout << "\nItems\n";
        cout << "--------------------------------------------------\n";
        cout << orderDetails;

        cout << "\nSubtotal: $" << subtotal << endl;
        cout << "Discount: $" << discount << endl;

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

        cout << "\nTip: $" << tip << endl;
        cout << "Total: $" << total << endl;

        // Display loyalty points
        cout << "\nLoyalty Points: ";

        for (int i = 0; i < loyaltyPoints; i++)
        {
            cout << "*";
        }

        cout << " (" << loyaltyPoints << ")" << endl;

        cout << "--------------------------------------------------\n";

        // Ask if there is another customer
        cout << "\nIs there another customer? (Y/N): ";
        cin >> anotherCustomer;

    } while (anotherCustomer == 'Y');

    // Display daily totals
    cout << "\nEnd of Day Report\n";
    cout << "--------------------------------------------------\n";
    cout << "Total Customers: " << totalCustomers << endl;
    cout << fixed << setprecision(2);
    cout << "Total Sales: $" << grandTotalSales << endl;

    return 0;
}