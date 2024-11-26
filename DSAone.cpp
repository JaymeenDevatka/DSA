#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool pairing(int x[], int y, int z)
{
    int counter = 0;
    int pair[y];

    if (y % 2 == 1)
    {
        return false;
    }

    else if (y % 2 == 0)
    {
        int vis[y], k = 0;

        for (int i = 0; i < y; i++)
        {
            vis[i] = -1;
        }

        for (int i = 0; i < y; i++)
        {
            for (int j = 1; j < y; j++)
            {
                if ((x[i] + x[j]) % z == 0 && vis[i] == -1 && vis[j] == -1 && k < y && i != j)
                {
                    pair[k] = x[i];
                    pair[k + 1] = x[j];

                    vis[i] = 1;
                    vis[j] = 1;

                    k = k + 2;
                    counter++;
                    break;
                }
            }
        }
    }

    if (counter == (y / 2))
    {
        for (int i = 0; i < y;)
        {
            cout << "(" << pair[i] << "," << pair[i + 1] << ")" << endl;
            i = i + 2;
        }
        return true;
    }

    else if (counter != y / 2)
    {
        return false;
    }

    return false;
}

int main()
{

    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

    if (!pairing(arr, n, k))
    {
        cout << "-1";
    }
    return 0;
}