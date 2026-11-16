
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int SIZE = 5;

    char answers[SIZE] = {'A', 'D', 'B', 'B', 'C'};
    char studentAns[SIZE];

    int correctAns = 0;
    int incorrectAns = 0;

    // Get student's answers
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter answer for question " << i + 1 << ": ";
        cin >> studentAns[i];
    }

    // Check student's answers
    cout << endl;

    for (int i = 0; i < SIZE; i++)
    {
        if (studentAns[i] != answers[i])
        {
            incorrectAns++;
            cout << "Question " << i + 1 << " was incorrect." << endl;
        }
        else
        {
            correctAns++;
        }
    }

    // Display results
    cout << endl;

    if (correctAns >= 4)
    {
        cout << "The student passed the exam!" << endl;
    }
    else
    {
        cout << "The student failed the exam." << endl;
    }

    cout << "Correct answers: " << correctAns << endl;
    cout << "Incorrect answers: " << incorrectAns << endl;

    return 0;
}
