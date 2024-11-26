#include <iostream>
using namespace std;

int GetMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}

void CountingSort(int array[], int n, int place)
{
    //  int i;
    int output[n + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < n; i++)
    {
        // to sort the array element.
        if (((array[i] / place) % 10) > max)
        {
            max = array[i];
        }
    }

    int count[max + 1];

    for (int i = 0; i < max; i++)
    {
        count[i] = 0;
    }

    // calculate the count of element
    for (int i = 0; i < n; i++)
    {
        count[(array[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        array[i] = output[i];
    }
}

void RadixSort(int array[], int n)
{
    int max = GetMax(array, n);
    for (int i = 1; max / i > 0; i = i * 10)
    {
        CountingSort(array, n, i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
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

    RadixSort(array, n);

    return 0;
}