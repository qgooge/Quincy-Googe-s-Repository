#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

int main()
{
    // Variables for customer and items
    string customerName;
    string foodName;

    string food1, food2, food3, food4;
    double food1Sm, food1Med, food1Lg;
    double food2Sm, food2Med, food2Lg;
    double food3Sm, food3Med, food3Lg;
    double food4Sm, food4Med, food4Lg;

    char itemChoice;
    char sizeChoice;
    char tipChoice;
    char anotherCustomer;

    int itemQuantity;
    bool isMember;

    double unitPrice = 0.0;
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

    // Starting inventory count
    int food1Start = 50;
    int food2Start = 50;
    int food3Start = 50;
    int food4Start = 50;

    int food1Sold = 0;
    int food2Sold = 0;
    int food3Sold = 0;
    int food4Sold = 0;

    // Read menu from file
    ifstream menu_fin("menu.txt");

    if (!menu_fin)
    {
        cout << "Error: Could not open menu.txt" << endl;
        return 1;
    }

    getline(menu_fin, food1);
    menu_fin >> food1Sm >> food1Med >> food1Lg;
    menu_fin.ignore(1000, '\n');

    getline(menu_fin, food2);
    menu_fin >> food2Sm >> food2Med >> food2Lg;
    menu_fin.ignore(1000, '\n');

    getline(menu_fin, food3);
    menu_fin >> food3Sm >> food3Med >> food3Lg;
    menu_fin.ignore(1000, '\n');

    getline(menu_fin, food4);
    menu_fin >> food4Sm >> food4Med >> food4Lg;

    menu_fin.close();

    // Loop for customers
    do
    {
        subtotal = 0.0;
        discount = 0.0;
        totalTax = 0.0;
        tip = 0.0;
        total = 0.0;

        cout << "\nEnter customer name: ";
        cin >> customerName;

        // Show menu
        cout << fixed << setprecision(2);
        cout << "\nCoffee Shop Menu\n";
        cout << "--------------------------------------------------\n";
        cout << left << setw(22) << "Item"
             << setw(10) << "Small"
             << setw(10) << "Medium"
             << setw(10) << "Large" << endl;

        cout << left << setw(22) << ("A. " + food1)
             << setw(10) << food1Sm << setw(10) << food1Med << setw(10) << food1Lg << endl;
        cout << left << setw(22) << ("B. " + food2)
             << setw(10) << food2Sm << setw(10) << food2Med << setw(10) << food2Lg << endl;
        cout << left << setw(22) << ("C. " + food3)
             << setw(10) << food3Sm << setw(10) << food3Med << setw(10) << food3Lg << endl;
        cout << left << setw(22) << ("D. " + food4)
             << setw(10) << food4Sm << setw(10) << food4Med << setw(10) << food4Lg << endl;
        cout << left << setw(22) << "E. Checkout" << endl;
        cout << "--------------------------------------------------\n";

        // Open receipt file
        ofstream receipt_fout("receipt.txt", ios::app);
        receipt_fout << fixed << setprecision(2);

        receipt_fout << "\nFinal Receipt\n";
        receipt_fout << "--------------------------------------------------\n";
        receipt_fout << "Customer: " << customerName << "\n";
        receipt_fout << "\nItems\n";
        receipt_fout << "--------------------------------------------------\n";

        // Loop to pick items
        do
        {
            cout << "\nWhat item would you like (A-D, or E to checkout)? ";
            cin >> itemChoice;
            itemChoice = toupper(itemChoice);

            while (itemChoice != 'A' && itemChoice != 'B' &&
                   itemChoice != 'C' && itemChoice != 'D' &&
                   itemChoice != 'E')
            {
                cout << "Invalid choice. Please enter A, B, C, D, or E: ";
                cin >> itemChoice;
                itemChoice = toupper(itemChoice);
            }

            if (itemChoice == 'E')
            {
                break;
            }

            // Set item name
            if (itemChoice == 'A')
                foodName = food1;
            else if (itemChoice == 'B')
                foodName = food2;
            else if (itemChoice == 'C')
                foodName = food3;
            else if (itemChoice == 'D')
                foodName = food4;

            // Pick size
            cout << "What size? (S = Small, M = Medium, L = Large): ";
            cin >> sizeChoice;
            sizeChoice = toupper(sizeChoice);

            while (sizeChoice != 'S' && sizeChoice != 'M' && sizeChoice != 'L')
            {
                cout << "Invalid size. Please enter S, M, or L: ";
                cin >> sizeChoice;
                sizeChoice = toupper(sizeChoice);
            }

            // Set price based on size
            if (sizeChoice == 'S')
            {
                if (itemChoice == 'A') unitPrice = food1Sm;
                else if (itemChoice == 'B') unitPrice = food2Sm;
                else if (itemChoice == 'C') unitPrice = food3Sm;
                else unitPrice = food4Sm;
            }
            else if (sizeChoice == 'M')
            {
                if (itemChoice == 'A') unitPrice = food1Med;
                else if (itemChoice == 'B') unitPrice = food2Med;
                else if (itemChoice == 'C') unitPrice = food3Med;
                else unitPrice = food4Med;
            }
            else if (sizeChoice == 'L')
            {
                if (itemChoice == 'A') unitPrice = food1Lg;
                else if (itemChoice == 'B') unitPrice = food2Lg;
                else if (itemChoice == 'C') unitPrice = food3Lg;
                else unitPrice = food4Lg;
            }

            // Get quantity and add to subtotal
            cout << "Enter item quantity: ";
            cin >> itemQuantity;

            double itemSubtotal = itemQuantity * unitPrice;
            subtotal += itemSubtotal;

            // Track items sold
            if (itemChoice == 'A') food1Sold += itemQuantity;
            else if (itemChoice == 'B') food2Sold += itemQuantity;
            else if (itemChoice == 'C') food3Sold += itemQuantity;
            else if (itemChoice == 'D') food4Sold += itemQuantity;

            // Write item to receipt file
            receipt_fout << foodName << "  Size: " << sizeChoice
                         << "  Qty: " << itemQuantity
                         << "  $" << itemSubtotal << "\n";

        } while (itemChoice != 'E');

        // Member discount
        cout << "\nAre you a member? (1 = yes, 0 = no): ";
        cin >> isMember;

        if (isMember)
        {
            discount = subtotal * 0.10;
        }

        discountedSubtotal = subtotal - discount;

        // Taxes
        arkansasTax = discountedSubtotal * 0.065;
        faulknerTax = discountedSubtotal * 0.005;
        conwayTax = discountedSubtotal * 0.02125;
        totalTax = arkansasTax + faulknerTax + conwayTax;

        // Tip
        cout << "\nTip Selection\n";
        cout << "-------------------------\n";
        cout << "A. 15%\nB. 20%\nC. 25%\nD. Other Amount\n";
        cout << "What tip do you choose? ";
        cin >> tipChoice;
        tipChoice = toupper(tipChoice);

        if (tipChoice == 'A')
            tip = discountedSubtotal * 0.15;
        else if (tipChoice == 'B')
            tip = discountedSubtotal * 0.20;
        else if (tipChoice == 'C')
            tip = discountedSubtotal * 0.25;
        else if (tipChoice == 'D')
        {
            cout << "How much would you like to tip? $";
            cin >> tip;
        }

        // Totals and loyalty points
        total = discountedSubtotal + totalTax + tip;
        grandTotalSales += total;
        totalCustomers++;

        int loyaltyPoints = total / 3;

        // Print receipt to screen
        cout << "\nFinal Receipt\n";
        cout << "--------------------------------------------------\n";
        cout << "Customer: " << customerName << endl;
        cout << "Subtotal: $" << subtotal << endl;
        cout << "Discount: $" << discount << endl;
        cout << "\nTaxes\n";
        cout << "--------------------------------------------------\n";
        cout << left << setw(30) << "Arkansas State Tax (6.5%)" << "$" << arkansasTax << endl;
        cout << left << setw(30) << "Faulkner County Tax (0.5%)" << "$" << faulknerTax << endl;
        cout << left << setw(30) << "Conway Municipal Tax (2.125%)" << "$" << conwayTax << endl;
        cout << left << setw(30) << "Total Tax" << "$" << totalTax << endl;
        cout << "\nTip:   $" << tip << endl;
        cout << "Total: $" << total << endl;
        cout << "\nLoyalty Points: ";
        for (int i = 0; i < loyaltyPoints; i++)
        {
            cout << "*";
        }
        cout << " (" << loyaltyPoints << ")\n";
        cout << "--------------------------------------------------\n";

        // Print totals to receipt file
        receipt_fout << "\nSubtotal: $" << subtotal << "\n";
        receipt_fout << "Discount: $" << discount << "\n";
        receipt_fout << "\nTaxes\n";
        receipt_fout << "--------------------------------------------------\n";
        receipt_fout << left << setw(30) << "Arkansas State Tax (6.5%)" << "$" << arkansasTax << "\n";
        receipt_fout << left << setw(30) << "Faulkner County Tax (0.5%)" << "$" << faulknerTax << "\n";
        receipt_fout << left << setw(30) << "Conway Municipal Tax (2.125%)" << "$" << conwayTax << "\n";
        receipt_fout << left << setw(30) << "Total Tax" << "$" << totalTax << "\n";
        receipt_fout << "\nTip:   $" << tip << "\n";
        receipt_fout << "Total: $" << total << "\n";
        receipt_fout << "\nLoyalty Points: ";
        for (int i = 0; i < loyaltyPoints; i++)
        {
            receipt_fout << "*";
        }
        receipt_fout << " (" << loyaltyPoints << ")\n";
        receipt_fout << "--------------------------------------------------\n\n";

        receipt_fout.close();

        // Check for next customer
        cout << "\nIs there another customer? (Y/N): ";
        cin >> anotherCustomer;
        anotherCustomer = toupper(anotherCustomer);

    } while (anotherCustomer == 'Y');

    // Daily summary
    cout << "\nDaily Summary\n";
    cout << "--------------------------------------------------\n";
    cout << "Total Customers: " << totalCustomers << endl;
    cout << "Total Sales: $" << grandTotalSales << endl;
    cout << "--------------------------------------------------\n";

    // Write inventory to file and screen
    ofstream inventory_fout("inventory.txt");

    cout << "\nDaily Inventory\n";
    cout << left << setw(22) << "Item" << setw(10) << "Start" << setw(10) << "Change" << setw(10) << "End" << endl;

    inventory_fout << "Daily Inventory\n";
    inventory_fout << left << setw(22) << "Item" << setw(10) << "Start" << setw(10) << "Change" << setw(10) << "End" << endl;

    // Item 1
    cout << left << setw(22) << food1 << setw(10) << food1Start << setw(10) << -food1Sold << setw(10) << food1Start - food1Sold << endl;
    inventory_fout << left << setw(22) << food1 << setw(10) << food1Start << setw(10) << -food1Sold << setw(10) << food1Start - food1Sold << endl;

    // Item 2
    cout << left << setw(22) << food2 << setw(10) << food2Start << setw(10) << -food2Sold << setw(10) << food2Start - food2Sold << endl;
    inventory_fout << left << setw(22) << food2 << setw(10) << food2Start << setw(10) << -food2Sold << setw(10) << food2Start - food2Sold << endl;

    // Item 3
    cout << left << setw(22) << food3 << setw(10) << food3Start << setw(10) << -food3Sold << setw(10) << food3Start - food3Sold << endl;
    inventory_fout << left << setw(22) << food3 << setw(10) << food3Start << setw(10) << -food3Sold << setw(10) << food3Start - food3Sold << endl;

    // Item 4
    cout << left << setw(22) << food4 << setw(10) << food4Start << setw(10) << -food4Sold << setw(10) << food4Start - food4Sold << endl;
    inventory_fout << left << setw(22) << food4 << setw(10) << food4Start << setw(10) << -food4Sold << setw(10) << food4Start - food4Sold << endl;

    inventory_fout.close();

    return 0;
}