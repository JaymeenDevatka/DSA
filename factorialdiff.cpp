#include <iostream>
using namespace std;

int factorial(int n)
{
    int sum = 1;
    if (n == 0 || n == 1)
    {
        return 1;
    }

    for (int i = 1; i <= n; i++)
    {
        sum = sum * i;
    }

    return sum;
}
int main()
{
    int array[] = {1, -2, 3, -4, 5, -6, 7, -8};

    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        if (array[i] > 0)
        {
            sum = sum + factorial(array[i]);
        }
        else
        {
            sum = sum + array[i];
        }
    }

    cout << sum << endl;
    return 0;
}