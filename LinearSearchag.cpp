#include <iostream>
#include <unordered_map>
using namespace std;

void countOccurrences(int array[], int n)
{
    unordered_map<int, int> occurrenceMap;

    // Count occurrences of each element
    for (int i = 0; i < n; i++)
    {
        occurrenceMap[array[i]]++;
    }

    // Print each element and its occurrence
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " occurs " << occurrenceMap[array[i]] << " times." << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int array[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    countOccurrences(array, n);

    return 0;
}