#include <iostream>
using namespace std;

void BubbleSort(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
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

    BubbleSort(array, n);
    // SelectionSort(array,n);
    // InsertionSort(array,n);

    return 0;
}