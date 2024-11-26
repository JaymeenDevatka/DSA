#include <iostream>
using namespace std;

int largest(int array[], int n)
{
    int largest = array[9];
    for (int i = 0; i < n; i++)
    {
        if (array[i] > largest)
        {
            largest = array[i];
        }
    }

    return largest;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 50, 100};

    int n = sizeof(array) / sizeof(array[0]);

    cout << largest(array, n) << endl;
}