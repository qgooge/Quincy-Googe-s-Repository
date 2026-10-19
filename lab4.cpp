
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

// Reads the menu and prices from menu.txt.
bool readMenu(string &food1, string &food2, string &food3, string &food4,
              double &food1Sm, double &food1Med, double &food1Lg,
              double &food2Sm, double &food2Med, double &food2Lg,
              double &food3Sm, double &food3Med, double &food3Lg,
              double &food4Sm, double &food4Med, double &food4Lg)
{
    ifstream menu_fin("menu.txt");

    if (!menu_fin)
    {
        cout << "Error: Could not open menu.txt" << endl;
        return false;
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
    return true;
}

// Displays the coffee shop menu.
void displayMenu(string food1, string food2, string food3, string food4,
                 double food1Sm, double food1Med, double food1Lg,
                 double food2Sm, double food2Med, double food2Lg,
                 double food3Sm, double food3Med, double food3Lg,
                 double food4Sm, double food4Med, double food4Lg)
{
    cout << fixed << setprecision(2);
    cout << "\nCoffee Shop Menu\n";
    cout << "--------------------------------------------------\n";
    cout << left << setw(22) << "Item"
         << setw(10) << "Small" << setw(10) << "Medium"
         << setw(10) << "Large" << endl;

    cout << left << setw(22) << ("A. " + food1)
         << setw(10) << food1Sm << setw(10) << food1Med
         << setw(10) << food1Lg << endl;

    cout << left << setw(22) << ("B. " + food2)
         << setw(10) << food2Sm << setw(10) << food2Med
         << setw(10) << food2Lg << endl;

    cout << left << setw(22) << ("C. " + food3)
         << setw(10) << food3Sm << setw(10) << food3Med
         << setw(10) << food3Lg << endl;

    cout << left << setw(22) << ("D. " + food4)
         << setw(10) << food4Sm << setw(10) << food4Med
         << setw(10) << food4Lg << endl;

    cout << left << setw(22) << "E. Checkout" << endl;
    cout << "--------------------------------------------------\n";
}

// Gets the customer's item choice.
char getChoice()
{
    char itemChoice;

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

    return itemChoice;
}

// Gets the customer's size choice.
char getSize()
{
    char sizeChoice;

    cout << "What size? (S = Small, M = Medium, L = Large): ";
    cin >> sizeChoice;
    sizeChoice = toupper(sizeChoice);

    while (sizeChoice != 'S' && sizeChoice != 'M' &&
           sizeChoice != 'L')
    {
        cout << "Invalid size. Please enter S, M, or L: ";
        cin >> sizeChoice;
        sizeChoice = toupper(sizeChoice);
    }

    return sizeChoice;
}

// Returns the name of the selected food item.
string getFoodName(char itemChoice, string food1, string food2,
                   string food3, string food4)
{
    if (itemChoice == 'A')
        return food1;
    else if (itemChoice == 'B')
        return food2;
    else if (itemChoice == 'C')
        return food3;
    else
        return food4;
}

// Returns the price for the selected item and size.
double getPrice(char itemChoice, char sizeChoice,
                double food1Sm, double food1Med, double food1Lg,
                double food2Sm, double food2Med, double food2Lg,
                double food3Sm, double food3Med, double food3Lg,
                double food4Sm, double food4Med, double food4Lg)
{
    if (itemChoice == 'A')
    {
        if (sizeChoice == 'S') return food1Sm;
        else if (sizeChoice == 'M') return food1Med;
        else return food1Lg;
    }
    else if (itemChoice == 'B')
    {
        if (sizeChoice == 'S') return food2Sm;
        else if (sizeChoice == 'M') return food2Med;
        else return food2Lg;
    }
    else if (itemChoice == 'C')
    {
        if (sizeChoice == 'S') return food3Sm;
        else if (sizeChoice == 'M') return food3Med;
        else return food3Lg;
    }
    else
    {
        if (sizeChoice == 'S') return food4Sm;
        else if (sizeChoice == 'M') return food4Med;
        else return food4Lg;
    }
}

// Takes the customer's order and returns the subtotal.
double takeOrder(string food1, string food2, string food3, string food4,
                 double food1Sm, double food1Med, double food1Lg,
                 double food2Sm, double food2Med, double food2Lg,
                 double food3Sm, double food3Med, double food3Lg,
                 double food4Sm, double food4Med, double food4Lg,
                 int &food1Sold, int &food2Sold,
                 int &food3Sold, int &food4Sold,
                 ofstream &receipt_fout)
{
    double subtotal = 0.0;
    char itemChoice;
    char sizeChoice;
    string foodName;
    int itemQuantity;
    double unitPrice;
    double itemSubtotal;

    do
    {
        itemChoice = getChoice();

        if (itemChoice != 'E')
        {
            foodName = getFoodName(itemChoice, food1, food2,
                                   food3, food4);

            sizeChoice = getSize();

            unitPrice = getPrice(itemChoice, sizeChoice,
                                 food1Sm, food1Med, food1Lg,
                                 food2Sm, food2Med, food2Lg,
                                 food3Sm, food3Med, food3Lg,
                                 food4Sm, food4Med, food4Lg);

            cout << "Enter item quantity: ";
            cin >> itemQuantity;

            itemSubtotal = itemQuantity * unitPrice;
            subtotal += itemSubtotal;

            if (itemChoice == 'A')
                food1Sold += itemQuantity;
            else if (itemChoice == 'B')
                food2Sold += itemQuantity;
            else if (itemChoice == 'C')
                food3Sold += itemQuantity;
            else
                food4Sold += itemQuantity;

            receipt_fout << foodName << "  Size: " << sizeChoice
                         << "  Qty: " << itemQuantity
                         << "  $" << itemSubtotal << "\n";
        }

    } while (itemChoice != 'E');

    return subtotal;
}

// Calculates the member discount and taxes.
void calculateReceipt(double subtotal, bool isMember,
                      double &discount, double &discountedSubtotal,
                      double &arkansasTax, double &faulknerTax,
                      double &conwayTax, double &totalTax)
{
    discount = 0.0;

    if (isMember)
        discount = subtotal * 0.10;

    discountedSubtotal = subtotal - discount;

    arkansasTax = discountedSubtotal * 0.065;
    faulknerTax = discountedSubtotal * 0.005;
    conwayTax = discountedSubtotal * 0.02125;

    totalTax = arkansasTax + faulknerTax + conwayTax;
}

// Gets the customer's tip and returns the tip amount.
double getTip(double discountedSubtotal)
{
    char tipChoice;
    double tip = 0.0;

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

    return tip;
}

// Prints the customer's receipt to the screen and file.
void printReceipt(string customerName, double subtotal,
                  double discount, double arkansasTax,
                  double faulknerTax, double conwayTax,
                  double totalTax, double tip, double total,
                  ofstream &receipt_fout)
{
    int loyaltyPoints = total / 3;

    cout << "\nFinal Receipt\n";
    cout << "--------------------------------------------------\n";
    cout << "Customer: " << customerName << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Discount: $" << discount << endl;

    cout << "\nTaxes\n";
    cout << "--------------------------------------------------\n";
    cout << left << setw(30) << "Arkansas State Tax (6.5%)"
         << "$" << arkansasTax << endl;
    cout << left << setw(30) << "Faulkner County Tax (0.5%)"
         << "$" << faulknerTax << endl;
    cout << left << setw(30) << "Conway Municipal Tax (2.125%)"
         << "$" << conwayTax << endl;
    cout << left << setw(30) << "Total Tax" << "$" << totalTax << endl;

    cout << "\nTip:   $" << tip << endl;
    cout << "Total: $" << total << endl;
    cout << "\nLoyalty Points: ";

    for (int i = 0; i < loyaltyPoints; i++)
        cout << "*";

    cout << " (" << loyaltyPoints << ")\n";
    cout << "--------------------------------------------------\n";

    receipt_fout << "\nSubtotal: $" << subtotal << "\n";
    receipt_fout << "Discount: $" << discount << "\n";
    receipt_fout << "\nTaxes\n";
    receipt_fout << "--------------------------------------------------\n";

    receipt_fout << left << setw(30) << "Arkansas State Tax (6.5%)"
                 << "$" << arkansasTax << "\n";
    receipt_fout << left << setw(30) << "Faulkner County Tax (0.5%)"
                 << "$" << faulknerTax << "\n";
    receipt_fout << left << setw(30) << "Conway Municipal Tax (2.125%)"
                 << "$" << conwayTax << "\n";
    receipt_fout << left << setw(30) << "Total Tax" << "$" << totalTax << "\n";

    receipt_fout << "\nTip:   $" << tip << "\n";
    receipt_fout << "Total: $" << total << "\n";
    receipt_fout << "\nLoyalty Points: ";

    for (int i = 0; i < loyaltyPoints; i++)
        receipt_fout << "*";

    receipt_fout << " (" << loyaltyPoints << ")\n";
    receipt_fout << "--------------------------------------------------\n\n";
}

// Prints the daily inventory to the screen and inventory.txt.
void printInventory(string food1, string food2,
                    string food3, string food4,
                    int food1Start, int food2Start,
                    int food3Start, int food4Start,
                    int food1Sold, int food2Sold,
                    int food3Sold, int food4Sold)
{
    ofstream inventory_fout("inventory.txt");

    cout << "\nDaily Inventory\n";
    cout << left << setw(22) << "Item"
         << setw(10) << "Start"
         << setw(10) << "Change"
         << setw(10) << "End" << endl;

    inventory_fout << "Daily Inventory\n";
    inventory_fout << left << setw(22) << "Item"
                   << setw(10) << "Start"
                   << setw(10) << "Change"
                   << setw(10) << "End" << endl;

    cout << left << setw(22) << food1 << setw(10) << food1Start
         << setw(10) << -food1Sold
         << setw(10) << food1Start - food1Sold << endl;

    inventory_fout << left << setw(22) << food1
                   << setw(10) << food1Start
                   << setw(10) << -food1Sold
                   << setw(10) << food1Start - food1Sold << endl;

    cout << left << setw(22) << food2 << setw(10) << food2Start
         << setw(10) << -food2Sold
         << setw(10) << food2Start - food2Sold << endl;

    inventory_fout << left << setw(22) << food2
                   << setw(10) << food2Start
                   << setw(10) << -food2Sold
                   << setw(10) << food2Start - food2Sold << endl;

    cout << left << setw(22) << food3 << setw(10) << food3Start
         << setw(10) << -food3Sold
         << setw(10) << food3Start - food3Sold << endl;

    inventory_fout << left << setw(22) << food3
                   << setw(10) << food3Start
                   << setw(10) << -food3Sold
                   << setw(10) << food3Start - food3Sold << endl;

    cout << left << setw(22) << food4 << setw(10) << food4Start
         << setw(10) << -food4Sold
         << setw(10) << food4Start - food4Sold << endl;

    inventory_fout << left << setw(22) << food4
                   << setw(10) << food4Start
                   << setw(10) << -food4Sold
                   << setw(10) << food4Start - food4Sold << endl;

    inventory_fout.close();
}

int main()
{
    string customerName;
    string food1, food2, food3, food4;

    double food1Sm, food1Med, food1Lg;
    double food2Sm, food2Med, food2Lg;
    double food3Sm, food3Med, food3Lg;
    double food4Sm, food4Med, food4Lg;

    int food1Start = 50;
    int food2Start = 50;
    int food3Start = 50;
    int food4Start = 50;

    int food1Sold = 0;
    int food2Sold = 0;
    int food3Sold = 0;
    int food4Sold = 0;

    double grandTotalSales = 0.0;
    int totalCustomers = 0;
    char anotherCustomer;

    if (!readMenu(food1, food2, food3, food4,
                  food1Sm, food1Med, food1Lg,
                  food2Sm, food2Med, food2Lg,
                  food3Sm, food3Med, food3Lg,
                  food4Sm, food4Med, food4Lg))
    {
        return 1;
    }

    cout << fixed << setprecision(2);

    // Repeats the order process for each customer.
    do
    {
        double subtotal = 0.0;
        double discount = 0.0;
        double discountedSubtotal = 0.0;
        double arkansasTax = 0.0;
        double faulknerTax = 0.0;
        double conwayTax = 0.0;
        double totalTax = 0.0;
        double tip = 0.0;
        double total = 0.0;
        bool isMember;

        cout << "\nEnter customer name: ";
        cin >> customerName;

        displayMenu(food1, food2, food3, food4,
                    food1Sm, food1Med, food1Lg,
                    food2Sm, food2Med, food2Lg,
                    food3Sm, food3Med, food3Lg,
                    food4Sm, food4Med, food4Lg);

        ofstream receipt_fout("receipt.txt", ios::app);
        receipt_fout << fixed << setprecision(2);

        receipt_fout << "\nFinal Receipt\n";
        receipt_fout << "--------------------------------------------------\n";
        receipt_fout << "Customer: " << customerName << "\n";
        receipt_fout << "\nItems\n";
        receipt_fout << "--------------------------------------------------\n";

        subtotal = takeOrder(food1, food2, food3, food4,
                             food1Sm, food1Med, food1Lg,
                             food2Sm, food2Med, food2Lg,
                             food3Sm, food3Med, food3Lg,
                             food4Sm, food4Med, food4Lg,
                             food1Sold, food2Sold,
                             food3Sold, food4Sold,
                             receipt_fout);

        cout << "\nAre you a member? (1 = yes, 0 = no): ";
        cin >> isMember;

        calculateReceipt(subtotal, isMember, discount,
                         discountedSubtotal, arkansasTax,
                         faulknerTax, conwayTax, totalTax);

        tip = getTip(discountedSubtotal);

        total = discountedSubtotal + totalTax + tip;
        grandTotalSales += total;
        totalCustomers++;

        printReceipt(customerName, subtotal, discount,
                     arkansasTax, faulknerTax, conwayTax,
                     totalTax, tip, total, receipt_fout);

        receipt_fout.close();

        cout << "\nIs there another customer? (Y/N): ";
        cin >> anotherCustomer;
        anotherCustomer = toupper(anotherCustomer);

    } while (anotherCustomer == 'Y');

    // Displays the daily sales summary.
    cout << "\nDaily Summary\n";
    cout << "--------------------------------------------------\n";
    cout << "Total Customers: " << totalCustomers << endl;
    cout << "Total Sales: $" << grandTotalSales << endl;
    cout << "--------------------------------------------------\n";

    printInventory(food1, food2, food3, food4,
                   food1Start, food2Start, food3Start, food4Start,
                   food1Sold, food2Sold, food3Sold, food4Sold);

    return 0;
}
