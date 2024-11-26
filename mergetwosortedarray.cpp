#include <iostream>
using namespace std;

void MergeTwoSortedArray(int n1, int n2, int array1[], int array2[], int mergedarray[])
{
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and merge them
    while (i < n1 && j < n2)
    {
        if (array1[i] <= array2[j])
        {
            mergedarray[k++] = array1[i++];
        }
        else
        {
            mergedarray[k++] = array2[j++];
        }
    }

    // Copy remaining elements of array1, if any
    while (i < n1)
    {
        mergedarray[k++] = array1[i++];
    }

    // Copy remaining elements of array2, if any
    while (j < n2)
    {
        mergedarray[k++] = array2[j++];
    }
}

int main()
{
    int n1, n2;

    // Input size and elements of the first array
    cin >> n1;
    int array1[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> array1[i];
    }

    // Input size and elements of the second array
    cin >> n2;
    int array2[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> array2[i];
    }

    // Create an array to hold the merged result
    int mergedarray[n1 + n2];

    // Merge the two arrays
    MergeTwoSortedArray(n1, n2, array1, array2, mergedarray);

    // Output the merged array
    for (int i = 0; i < n1 + n2; i++)
    {
        cout << mergedarray[i] << " ";
    }
    cout << endl;

    return 0;
}