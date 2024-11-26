#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Function to perform counting sort
void countingSort(vector<int> &arr)
{
    int n = arr.size();

    // Find the maximum element in the array
    int maxVal = *max_element(arr.begin(), arr.end());

    // Create a count array to store the frequency of each element
    vector<int> count(maxVal + 1, 0);

    // Store the count of each element in count array
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Modify the count array to store the cumulative count
    for (int i = 1; i <= maxVal; i++)
    {
        count[i] += count[i - 1];
    }

    // Create an output array to store the sorted elements
    vector<int> output(n);

    // Build the output array by placing elements at their correct positions
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    countingSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}