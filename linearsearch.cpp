#include <iostream>
using namespace std;

int LinearSearch(int array[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == key)
            return i + 1;
    }
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

    int result = LinearSearch(array, n, key);

    cout << result << endl;
}