#include <iostream>
using namespace std;

void array_merge(int array1[], int array2[], int n1, int n2)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (array1[j] > array1[j + 1])
            {
                int temp = array1[j];
                array1[j] = array1[j + 1];
                array1[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (array2[j] > array2[j + 1])
            {
                int temp = array2[j];
                array2[j] = array2[j + 1];
                array2[j + 1] = temp;
            }
        }
    }

    // int array[n1 + n2];

    int merged_array[n1 + n2];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (array1[i] <= array2[j])
        {
            merged_array[k++] = array1[i++];
        }
        else
        {
            merged_array[k++] = array2[j++];
        }
    } // Copy remaining elements of array1
    while (i < n1)
    {
        merged_array[k++] = array1[i++];
    }
    // Copy remaining elements of array2
    while (j < n2)
    {
        merged_array[k++] = array2[j++];
    }
    // Print the merged array
    for (int i = 0; i < n1 + n2; i++)
    {
        cout << merged_array[i] << " ";
    }
}

int main()
{
    int n1;
    cin >> n1;

    int n2;
    cin >> n2;

    int array1[n1];
    int array2[n2];

    for (int i = 0; i < n1; i++)
    {
        cin >> array1[i];
    }

    for (int i = 0; i < n2; i++)
    {
        cin >> array2[i];
    }

    array_merge(array1, array2, n1, n2);

    return 0;
}