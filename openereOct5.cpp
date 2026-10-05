#include <iostream>
using namespace std;
int main()

#include <iostream>

using namespace std;

int main() {
    char answer;

    // Prompt the user for input
    cout << "Are you leaving town this weekend? (Y/N): ";
    cin >> answer;

    // Error-checking loop
    while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') {
        cout << "Invalid input. Please enter Y or N: ";
        cin >> answer;
    }

    // Final message
    cout << "Have a great weekend!" << endl;

    return 0;
}