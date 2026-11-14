
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

// Function prototypes
bool readSongs(string fileName, string songs[][2], int &count);
void printSongs(const string songs[][2], int count);
int linearSearchForSong(const string songs[][2], int size, string grail, int &comparisons);
void swap(string line1[], string line2[]);
void selectionSort(string songs[][2], int size);
void bubbleSort(string songs[][2], int size);
int binarySearchForSong(const string songs[][2], int size, string grail, int &comparisons);

int main()
{
    static string songs[120450][2];
    static string selectionSongs[120450][2];
    static string bubbleSongs[120450][2];

    int count = 0;

    // Read the songs file
    if (readSongs("spotify_songs_tab_artists.dat", songs, count))
    {
        cout << "Songs loaded: " << count << endl;
    }
    else
    {
        cout << "Could not open file." << endl;
        return 1;
    }

    // Linear search
    string grail;

    cout << "\nEnter a song to search for: ";
    getline(cin, grail);

    int comparisons = 0;

    auto start = chrono::steady_clock::now();

    int found = linearSearchForSong(songs, count, grail, comparisons);

    auto end = chrono::steady_clock::now();

    chrono::duration<double> time = end - start;

    cout << "\nLinear Search Results" << endl;
    cout << "Song position: " << found << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Time: " << time.count() << " seconds" << endl;

    // Copy songs for sorting
    for (int i = 0; i < count; i++)
    {
        selectionSongs[i][0] = songs[i][0];
        selectionSongs[i][1] = songs[i][1];

        bubbleSongs[i][0] = songs[i][0];
        bubbleSongs[i][1] = songs[i][1];
    }

    // Selection sort
    cout << "\nStarting Selection Sort..." << endl;

    start = chrono::steady_clock::now();

    selectionSort(selectionSongs, count);

    end = chrono::steady_clock::now();

    time = end - start;

    cout << "Selection Sort Time: " << time.count() << " seconds" << endl;

    cout << "\nFirst 100 Songs After Selection Sort:" << endl;
    printSongs(selectionSongs, 100);

    // Bubble sort
    cout << "\nStarting Bubble Sort..." << endl;

    start = chrono::steady_clock::now();

    bubbleSort(bubbleSongs, count);

    end = chrono::steady_clock::now();

    time = end - start;

    cout << "Bubble Sort Time: " << time.count() << " seconds" << endl;

    cout << "\nFirst 100 Songs After Bubble Sort:" << endl;
    printSongs(bubbleSongs, 100);

    // Binary search
    comparisons = 0;

    start = chrono::steady_clock::now();

    found = binarySearchForSong(selectionSongs, count, grail, comparisons);

    end = chrono::steady_clock::now();

    time = end - start;

    cout << "\nBinary Search Results" << endl;
    cout << "Song position: " << found << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Time: " << time.count() << " seconds" << endl;

    return 0;
}

// Reads the songs from the file
bool readSongs(string fileName, string songs[][2], int &count)
{
    ifstream fin(fileName);

    if (!fin)
    {
        return false;
    }

    string line;

    // Skip the first line
    getline(fin, line);

    count = 0;

    while (getline(fin, songs[count][0], '\t'))
    {
        if (!getline(fin, songs[count][1]))
        {
            break;
        }

        count++;

        if (count >= 120450)
        {
            break;
        }
    }

    fin.close();

    return true;
}

// Prints the songs
void printSongs(const string songs[][2], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << songs[i][0] << " - " << songs[i][1] << endl;
    }
}

// Searches for a song one at a time
int linearSearchForSong(const string songs[][2], int size, string grail, int &comparisons)
{
    comparisons = 0;

    for (int i = 0; i < size; i++)
    {
        comparisons++;

        if (songs[i][0] == grail)
        {
            return i;
        }
    }

    return -1;
}

// Swaps two songs and their artists
void swap(string line1[], string line2[])
{
    string temp;

    temp = line1[0];
    line1[0] = line2[0];
    line2[0] = temp;

    temp = line1[1];
    line1[1] = line2[1];
    line2[1] = temp;
}

// Sorts the songs using selection sort
void selectionSort(string songs[][2], int size)
{
    int min;

    for (int i = 0; i < size - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (songs[j][0] < songs[min][0])
            {
                min = j;
            }
        }

        if (min != i)
        {
            swap(songs[i], songs[min]);
        }
    }
}

// Sorts the songs using bubble sort
void bubbleSort(string songs[][2], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (songs[j][0] > songs[j + 1][0])
            {
                swap(songs[j], songs[j + 1]);
            }
        }
    }
}

// Searches for a song using binary search
int binarySearchForSong(const string songs[][2], int size, string grail, int &comparisons)
{
    int first = 0;
    int last = size - 1;
    int middle;

    comparisons = 0;

    while (first <= last)
    {
        middle = (first + last) / 2;

        comparisons++;

        if (songs[middle][0] == grail)
        {
            return middle;
        }
        else if (grail < songs[middle][0])
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }

    return -1;
}

