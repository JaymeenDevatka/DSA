#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n == 1 && n == 0)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % 2 == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
int main()
{
    int n;
    cin >> n;

    if (isPrime(n))
    {
        cout << "Prime number" << endl;
    }
    else
    {
        cout << "Not Prime number" << endl;
    }

    return 0;
}