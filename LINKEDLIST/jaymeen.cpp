#include <iostream>
using namespace std;

int sum(int array[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + array[i];
    }

    return sum;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int n = sizeof(array) / sizeof(array[0]);

    cout << sum(array, n) << endl;
}