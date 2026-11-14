
#include <iostream>

using namespace std;

// Function prototypes
void showIntroduction();
int getPlayerChoice(int numChoices);
void handleWoods();
void handleRiver();
void handleCabin();
void handleMountain();
void handleEnding();

int main()
{
    showIntroduction();

    handleWoods();

    return 0;
}

// Shows the beginning of the game
void showIntroduction()
{
    cout << "Welcome to Lost in the Woods!" << endl;
    cout << "You are walking through the woods and suddenly get lost." << endl;
    cout << "You need to find your way back home." << endl;
}

// Gets the player's choice
int getPlayerChoice(int numChoices)
{
    int choice;

    cout << "\nEnter your choice: ";
    cin >> choice;

    while (choice < 1 || choice > numChoices)
    {
        cout << "Invalid choice. Try again: ";
        cin >> choice;
    }

    return choice;
}

// Starting location
void handleWoods()
{
    cout << "\nYou are standing in the middle of the woods." << endl;
    cout << "1. Follow a river." << endl;
    cout << "2. Walk towards a mountain." << endl;

    int choice = getPlayerChoice(2);

    if (choice == 1)
    {
        handleRiver();
    }
    else
    {
        handleMountain();
    }
}

// River path
void handleRiver()
{
    cout << "\nYou follow the river and find an old cabin." << endl;
    cout << "1. Go inside the cabin." << endl;
    cout << "2. Keep walking along the river." << endl;

    int choice = getPlayerChoice(2);

    if (choice == 1)
    {
        handleCabin();
    }
    else
    {
        handleEnding();
    }
}

// Mountain path
void handleMountain()
{
    cout << "\nYou reach the top of the mountain." << endl;
    cout << "1. Follow a trail down." << endl;
    cout << "2. Look inside a nearby cave." << endl;

    int choice = getPlayerChoice(2);

    if (choice == 1)
    {
        handleEnding();
    }
    else
    {
        handleCabin();
    }
}

// Cabin ending
void handleCabin()
{
    cout << "\nYou enter the cabin and find a phone." << endl;
    cout << "You call for help and someone comes to get you." << endl;
    cout << "You made it home safely. You Win!" << endl;
}

// Other ending
void handleEnding()
{
    cout << "\nYou keep walking but the sun starts going down." << endl;
    cout << "You cannot find your way out of the woods." << endl;
    cout << "Game Over!" << endl;
}
