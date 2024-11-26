#include <iostream>
#include <algorithm> // Include algorithm for reverse
using namespace std;

bool is_palindrome(int array[], int n)
{
    // Create a copy of the original array
    int array2[n];
    for (int i = 0; i < n; i++)
    {
        array2[i] = array[i];
    }

    // Reverse the original array
    reverse(array, array + n);

    // Compare the reversed array with the copy
    for (int i = 0; i < n; i++)
    {
        if (array[i] != array2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int array[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    if (is_palindrome(array, n))
    {
        cout << "The array is a palindrome." << endl;
    }
    else
    {
        cout << "The array is not a palindrome." << endl;
    }

    return 0;
}
