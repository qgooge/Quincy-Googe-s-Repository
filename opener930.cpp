#include <iostream>
using namespace std;


int main()
{
    int answer, guess;
    srand(time(0));

    answer = rand() % 10 + 1;

    cout << "Enter a number between 1 and 10: ";
    cin >> guess;

    cout << "Answer " << answer << endl; 
    cout << "Guess " << guess << endl;
}