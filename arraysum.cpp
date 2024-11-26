#include <iostream>
using namespace std;

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};

    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        if (array[i] % 2 == 0)
        {
            sum = sum + array[i];
        }
    }

    cout << sum << endl;

    return 0;
}