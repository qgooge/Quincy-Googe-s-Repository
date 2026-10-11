#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream infile("nums.txt");

    int number;
    int sum = 0;
    int count = 0;
    double average;

    while (infile >> number)
    {
        cout << number << endl;
        sum = sum + number;
        count++;
    }

    average = static_cast<double>(sum) / count;

    cout << fixed << setprecision(2);
    cout << "Average: " << average << endl;

    infile.close();

    return 0;
}