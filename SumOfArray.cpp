#include <iostream>
using namespace std;

void SumOfArray(int array[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + array[i];
    }

    cout << sum << endl;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(array) / sizeof(array[0]);

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> array[i];
    // }

    SumOfArray(array, n);

    return 0;
}