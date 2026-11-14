
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function prototypes
string getAnimalName();
void linearSearch(const vector<string>& animals, string animal);
void binarySearch(const vector<string>& animals, string animal);

int main()
{
    vector<string> animals;
    ifstream fin("animalsFIXED.txt");

    string animal;

    // Read animals from the file
    if (!fin)
    {
        cout << "Could not open file." << endl;
        return 1;
    }

    while (getline(fin, animal))
    {
        animals.push_back(animal);
    }

    fin.close();

    cout << "Animals loaded: " << animals.size() << endl;

    // Get animal name
    string searchAnimal = getAnimalName();

    // Search using linear search
    linearSearch(animals, searchAnimal);

    // Search using binary search
    binarySearch(animals, searchAnimal);

    return 0;
}

// Gets an animal name
string getAnimalName()
{
    string animal;

    cout << "\nEnter an animal name: ";
    getline(cin, animal);

    return animal;
}

// Linear search
void linearSearch(const vector<string>& animals, string animal)
{
    int comparisons = 0;

    for (int i = 0; i < animals.size(); i++)
    {
        comparisons++;

        if (animals[i] == animal)
        {
            cout << "\nI found " << animal;
            cout << " with a linear search at position " << i + 1;
            cout << " after " << comparisons << " tries." << endl;

            return;
        }
    }

    cout << "\nI could not find " << animal;
    cout << ". I tried " << comparisons << " animals." << endl;
}

// Binary search
void binarySearch(const vector<string>& animals, string animal)
{
    int first = 0;
    int last = animals.size() - 1;
    int middle;
    int comparisons = 0;

    while (first <= last)
    {
        middle = (first + last) / 2;

        comparisons++;

        if (animals[middle] == animal)
        {
            cout << "\nI found " << animal;
            cout << " with a binary search at position " << middle + 1;
            cout << " after " << comparisons << " tries." << endl;

            return;
        }
        else if (animal < animals[middle])
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }

    cout << "\nI could not find " << animal;
    cout << " with a binary search. I tried ";
    cout << comparisons << " animals." << endl;
}

