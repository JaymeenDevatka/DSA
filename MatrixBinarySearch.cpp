#include <iostream>
using namespace std;

int main()
{
    int m = 3;
    int n = 3;

    int array[m][n];

    // Input elements into the array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) // Corrected: j < n
        {
            cin >> array[i][j];
        }
    }

    int target;
    cout << "Target: ";
    cin >> target;

    // Search for the target in the array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) // Corrected: j < n
        {
            if (array[i][j] == target)
            {
                cout << "Target found at: (" << i << "," << j << ")" << endl;
            }
            else
            {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    return 0;
}
