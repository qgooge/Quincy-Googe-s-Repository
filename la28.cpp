#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int monthChoice;
    string startDay;
    int numDays = 0;
    int startCol = 0;

    // Pick month
    cout << "Select a month (1 - 12):" << endl;
    cout << "1. January      2. February     3. March" << endl;
    cout << "4. April        5. May          6. June" << endl;
    cout << "7. July         8. August       9. September" << endl;
    cout << "10. October     11. November    12. December" << endl;
    cout << "Enter your choice: ";
    cin >> monthChoice;

    // Get number of days
    switch (monthChoice) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            numDays = 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            numDays = 30;
            break;

        case 2:
            numDays = 28;
            break;

        default:
            cout << "Invalid month choice." << endl;
            return 1;
    }

    // Get first day
    cout << "What day is the first day of the month? (Sun, Mon, Tues, Wed, Thurs, Fri, Sat): ";
    cin >> startDay;

    // Find starting spot
    if (startDay == "Sun") {
        startCol = 0;
    }
    else if (startDay == "Mon") {
        startCol = 1;
    }
    else if (startDay == "Tues") {
        startCol = 2;
    }
    else if (startDay == "Wed") {
        startCol = 3;
    }
    else if (startDay == "Thurs") {
        startCol = 4;
    }
    else if (startDay == "Fri") {
        startCol = 5;
    }
    else if (startDay == "Sat") {
        startCol = 6;
    }
    else {
        cout << "Invalid day entered." << endl;
        return 1;
    }

    // Print calendar
    cout << endl;
    cout << setw(5) << "Sun"
         << setw(5) << "Mon"
         << setw(5) << "Tue"
         << setw(5) << "Wed"
         << setw(5) << "Thu"
         << setw(5) << "Fri"
         << setw(5) << "Sat" << endl;

    cout << "-----------------------------------" << endl;

    // Print spaces
    for (int i = 0; i < startCol; i++) {
        cout << setw(5) << " ";
    }

    // Print days
    int currentDayOfWeek = startCol;

    for (int day = 1; day <= numDays; day++) {
        cout << setw(5) << day;
        currentDayOfWeek++;

        if (currentDayOfWeek == 7) {
            cout << endl;
            currentDayOfWeek = 0;
        }
    }

    return 0;
}