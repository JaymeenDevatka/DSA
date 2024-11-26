#include <iostream>
using namespace std;

int LinearSearch(int n, int array[], int key)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }

    return -1;
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

    int key;
    cin >> key;
    cout << LinearSearch(n, array, key);
}