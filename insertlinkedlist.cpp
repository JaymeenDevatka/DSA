#include <iostream>
using namespace std;

void Rearrange(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        else
        {
            if (array[i] < array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        int array[n];
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }

        Rearrange(array, n);
        printArray(array, n);
    }

    return 0;
}