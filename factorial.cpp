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
    int n;
    cin >> n;

    cout << factorial(n) << endl;
    return 0;
}