#include <iostream>
using namespace std;

int search(int array[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == k)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int key;
    int n;
    cin >> n;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cin >> key;

    int result = search(array, n, key);
    if (result != -1)
    {
        cout << result << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}