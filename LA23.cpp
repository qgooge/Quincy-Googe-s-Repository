#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    int dice3 = rand() % 6 + 1;

    cout << "Dice 1: " << dice1 << endl;
    cout << "Dice 2: " << dice2 << endl;
    cout << "Dice 3: " << dice3 << endl;

    return 0;
}