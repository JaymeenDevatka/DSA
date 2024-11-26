#include <iostream>
using namespace std;

int interpolationSearch(int array[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    while (low <= high && value >= array[low] && value <= array[high])
    {
        if (low == high)
        {
            if (array[low] == value)
                return low;
            return -1;
        }

        int probe = low + (high - low) * (value - array[low]) / (array[high] - array[low]);

        if (array[probe] == value)
        {
            return probe;
        }

        if (array[probe] < value)
        {
            low = probe + 1;
        }
        else
        {
            high = probe - 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int array[n];

    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    int index = interpolationSearch(array, n, key);
    if (index != -1)
    {
        cout << "Index of " << key << " is: " << index << endl;
    }
    else
    {
        cout << key << " not found in the array." << endl;
    }

    return 0;
}