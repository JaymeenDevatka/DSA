#include <iostream>
using namespace std;

void CanPair(int array[], int n, int key)
{
    if (n % 2 == 1)
    {
        cout << "-1";
        return;
    }

    int count = 0;
    int vis[n];

    for (int i = 0; i < n; i++)
    {
        vis[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((array[i] + array[j]) % key == 0 && vis[i] == -1 && vis[j] == -1)
            {
                count++;
                vis[i] = 1;
                vis[j] = 1;
            }
        }
    }

    if (count != n / 2)
    {
        cout << "-1";
    }
    else
    {
        int vis[n];

        for (int i = 0; i < n; i++)
        {
            vis[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((array[i] + array[j]) % key == 0 && vis[i] == -1 && vis[j] == -1)
                {
                    cout << "(" << array[i] << "," << array[j] << ")\n";
                }
            }
        }
    }
}

int main()
{
    int array[] = {2, 9, 4, 1, 3, 5};
    int n = sizeof(array) / sizeof(array[0]);

    int key = 6;
    CanPair(array, n, key);

    return 0;
}