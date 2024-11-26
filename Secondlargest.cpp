#include <iostream>
using namespace std;

int secondLargest(int arr[], int n)
{
    int first = 0, second = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[first])
        {
            second = first;
            first = i;
        }
        else if (arr[i] < arr[first])
        {
            if (second == -1 || arr[second] < arr[i])
            {
                second = i;
            }
        }
    }
    return second;
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

    cout << secondLargest(array, n) << endl;
    return 0;
}