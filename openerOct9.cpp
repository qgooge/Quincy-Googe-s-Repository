#include <iostream>
#include <string>

using namespace std;

int main()
{
    string suit;
    int number;

    for (int i = 1; i <= 4; i++)
    {
        number = i;

        switch (number)
        {
            case 1:
                suit = "Spades";
                break;
            case 2:
                suit = "Clubs";
                break;
            case 3:
                suit = "Diamonds";
                break;
            case 4:
                suit = "Hearts";
                break;
        }

        cout << suit << endl;
    }

    return 0;
}