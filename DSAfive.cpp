#include <iostream>
using namespace std;

int binarySearch(int array[], int n, int key)
{
    int left = 0;
    int right = n;
    while (left <= right)
    {
        int mid = left + ((right - left) / 2);

        if (array[mid] == key)
        {
            return mid;
        }

        else if (array[mid] > key)
        {
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int key;
    cin >> key;

    cout << binarySearch(array, n, key) << endl;
}