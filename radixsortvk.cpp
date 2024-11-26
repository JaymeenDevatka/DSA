#include <iostream>
using namespace std;

void radixSort(int arr[], int n)
{
    int div = 1;
    int num = 3;

    int bucket[10][n];
    int buck[10];

    for (int p = 0; p < num; p++)
    {
        for (int k = 0; k < 10; k++)
        {
            buck[k] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            int l = (arr[i] / div) % 10;
            bucket[l][buck[l]++] = arr[i];
        }

        int index = 0;
        for (int k = 0; k < 10; k++)
        {
            for (int j = 0; j < buck[k]; j++)
            {
                arr[index++] = bucket[k][j];
            }
        }

        div = div * 10;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    radixSort(arr, n);

    return 0;
}