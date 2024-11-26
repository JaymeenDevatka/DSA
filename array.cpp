#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {
            if (array[i] > array[i + 1])
            {
                swap(array[i], array[i + 1]);
            }
        }
        else
        {
            if (array[i] < array[i + 1])
            {
                swap(array[i], array[i + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}