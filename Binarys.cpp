#include <iostream>
using namespace std;

int BinarySearch(int array[], int n, int key)
{

    int left = 1;
    int right = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] == key)
        {
            return mid;
        }
        else if (array[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    int array[n];

    for (int i = 1; i <= n; i++)
    {
        cin >> array[i];
    }

    int key;
    cin >> key;
    cout << "Index of " << key << " is: " << BinarySearch(array, n, key) << endl;

    return 0;
}