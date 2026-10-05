#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int monthChoice;
    string startDay;
    int numDays = 0;
    int startCol = 0;

    // 1. Menu to select the month
    cout << "Select a month (1 - 12):" << endl;
    cout << "1. January      2. February     3. March" << endl;
    cout << "4. April        5. May          6. June" << endl;
    cout << "7. July         8. August       9. September" << endl;
    cout << "10. October     11. November    12. December" << endl;
    cout << "Enter your choice: ";
    cin >> monthChoice;

    // Determine the number of days in the chosen month
    switch (monthChoice) {
        case 1:  // January
        case 3:  // March
        case 5:  // May
        case 7:  // July
        case 8:  // August
        case 10: // October
        case 12: // December
            numDays = 31;
            break;
        case 4:  // April
        case 6:  // June
        case 9:  // September
        case 11: // November
            numDays = 30;
            break;
        case 2:  // February (default non-leap year)
            numDays = 28;
            break;
        default:
            cout << "Invalid month choice." << endl;
            return 1;
    }

    // 2. Ask for the first day of the week
    cout << "What day is the first day of the month? (Sun, Mon, Tues, Wed, Thurs, Fri, Sat): ";
    cin >> startDay;

    // Determine the starting column index (0 = Sun, 6 = Sat)
    if (startDay == "Sun") {
        startCol = 0;
    } else if (startDay == "Mon") {
        startCol = 1;
    } else if (startDay == "Tues") {
        startCol = 2;
    } else if (startDay == "Wed") {
        startCol = 3;
    } else if (startDay == "Thurs") {
        startCol = 4;
    } else if (startDay == "Fri") {
        startCol = 5;
    } else if (startDay == "Sat") {
        startCol = 6;
    } else {
        cout << "Invalid day entered." << endl;
        return 1;
    }

    // 3. Print the calendar header
    cout << endl;
    cout << setw(5) << "Sun"
         << setw(5) << "Mon"
         << setw(5) << "Tue"
         << setw(5) << "Wed"
         << setw(5) << "Thu"
         << setw(5) << "Fri"
         << setw(5) << "Sat" << endl;
    cout << "-----------------------------------" << endl;

    // 4. Print leading spaces for days before day 1
    for (int i = 0; i < startCol; i++) {
        cout << setw(5) << " ";
    }

    // 5. Print the days of the month
    int currentDayOfWeek = startCol;
    for (int day = 1; day <= numDays; day++) {
        cout << setw(5) << day;
        currentDayOfWeek++;

        // Once Saturday (column index 7) is reached, wrap to the next line
        if (currentDayOfWeek == 7) {
            cout << endl;
            currentDayOfWeek = 0;
        }
    }

    // Final newline if the last line didn't end exactly on Saturday
    if (currentDayOfWeek != 0) {
        cout << endl;
    }

    return 0;
}