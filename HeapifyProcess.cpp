#include <iostream>
using namespace std;

void Heapify(int array[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
    {
        largest = left;
    }

    if (right < n && array[right] > array[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(array[i], array[largest]);

        Heapify(array, n, largest);
    }
}

void BuildHeap(int array[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Heapify(array, n, i);
    }
}

int main()
{
    int array[] = {4, 10, 3, 5, 1};

    // int i = 0;
    int n = sizeof(array) / sizeof(array[0]);
    BuildHeap(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}