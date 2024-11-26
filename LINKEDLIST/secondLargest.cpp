#include <iostream>
using namespace std;

int secondLargest(int array[], int n)
{
    int largest = 0;
    int secondLargest = -1;
    for (int i = 1; i < n; i++)
    {
        if (array[i] > array[largest])
        {
            largest = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (array[i] != array[largest])
        {
            if (secondLargest == -1)
            {
                secondLargest = i;
            }
            else if (array[i] > array[secondLargest])
            {
                secondLargest = i;
            }
        }
    }

    return secondLargest;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = sizeof(array) / sizeof(array[0]);

    cout << secondLargest(array, n) << endl;
}