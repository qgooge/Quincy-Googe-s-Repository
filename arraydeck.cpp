
#include <iostream>
#include <string>

using namespace std;

// Global deck array
string deck[52];

// Function prototypes
string getSuitName(int suitNum);
string getRankName(int rankNum);
void rankTester();
void initializeDeck();
void deckTester();

int main()
{
    rankTester();

    cout << endl;

    deckTester();

    return 0;
}

// Gets the suit name
string getSuitName(int suitNum)
{
    string suits[4] = {"Spades", "Clubs", "Diamonds", "Hearts"};

    return suits[suitNum];
}

// Gets the rank name
string getRankName(int rankNum)
{
    string ranks[13] = {
        "Ace", "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "Jack", "Queen", "King"
    };

    return ranks[rankNum];
}

// Prints all the ranks
void rankTester()
{
    for (int i = 0; i < 13; i++)
    {
        cout << getRankName(i) << endl;
    }
}

// Creates the deck of cards
void initializeDeck()
{
    int count = 0;

    for (int suit = 0; suit < 4; suit++)
    {
        for (int rank = 0; rank < 13; rank++)
        {
            deck[count] = getRankName(rank) + " of " + getSuitName(suit);

            count++;
        }
    }
}

// Prints all the cards
void deckTester()
{
    initializeDeck();

    for (int i = 0; i < 52; i++)
    {
        cout << deck[i] << endl;
    }
}
