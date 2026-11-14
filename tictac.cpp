
#include <iostream>

using namespace std;

// Function prototype
void printBoard(char board[][3]);

int main()
{
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row;
    int column;
    char player = 'X';

    // Print the starting board
    printBoard(board);

    // Ask the user where to go
    cout << "\nEnter row (0-2): ";
    cin >> row;

    cout << "Enter column (0-2): ";
    cin >> column;

    // Place the player's character
    board[row][column] = player;

    // Print the updated board
    cout << "\nUpdated Board:" << endl;
    printBoard(board);

    return 0;
}

// Prints the board
void printBoard(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << " " << board[i][0] << " | ";
        cout << board[i][1] << " | ";
        cout << board[i][2] << endl;

        if (i < 2)
        {
            cout << "---|---|---" << endl;
        }
    }
}
