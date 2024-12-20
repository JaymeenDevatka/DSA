#include <iostream>
using namespace std;

const int MAX = 100;
int m, n;
// This function does Binary search for x in i-th
// row. It does the search from mat[i][j_low] to
// mat[i][j_high]
void binarySearch(int mat[][10], int i, int j_low, int j_high, int x)
{
    while (j_low <= j_high)
    {
        int j_mid = (j_low + j_high) / 2;

        // Element found
        if (mat[i][j_mid] == x)
        {
            cout << "(" << i << ","
                 << j_mid << ")";
            return;
        }

        else if (mat[i][j_mid] > x)
            j_high = j_mid - 1;

        else
            j_low = j_mid + 1;
    }

    // element not found
    cout << "-1";
}

// Function to perform binary search on the mid
// values of row to get the desired pair of rows
// where the element can be found
void sortedMatrixSearch(int mat[][10], int n,
                        int m, int x)
{
    // Single row matrix
    if (n == 1)
    {
        binarySearch(mat, 0, 0, m - 1, x);
        return;
    }

    // Do binary search in middle column.
    // Condition to terminate the loop when the
    // 2 desired rows are found
    int i_low = 0;
    int i_high = n - 1;
    int j_mid = m / 2;
    while ((i_low + 1) < i_high)
    {
        int i_mid = (i_low + i_high) / 2;

        // element found
        if (mat[i_mid][j_mid] == x)
        {
            cout << "(" << i_mid << ","
                 << j_mid << ")";
            return;
        }

        else if (mat[i_mid][j_mid] > x)
            i_high = i_mid;

        else
            i_low = i_mid;
    }

    // If element is present on the mid of the
    // two rows
    if (mat[i_low][j_mid] == x)
        cout << "(" << i_low << ","
             << j_mid << ")";
    else if (mat[i_low + 1][j_mid] == x)
        cout << "(" << (i_low + 1)
             << "," << j_mid << ")";

    // search element on 1st half of 1st row
    else if (x <= mat[i_low][j_mid - 1])
        binarySearch(mat, i_low, 0, j_mid - 1, x);

    // Search element on 2nd half of 1st row
    else if (x >= mat[i_low][j_mid + 1] &&
             x <= mat[i_low][m - 1])
        binarySearch(mat, i_low, j_mid + 1, m - 1, x);

    // Search element on 1st half of 2nd row
    else if (x <= mat[i_low + 1][j_mid - 1])
        binarySearch(mat, i_low + 1, 0, j_mid - 1, x);

    // search element on 2nd half of 2nd row
    else
        binarySearch(mat, i_low + 1, j_mid + 1, m - 1, x);
}

// Driver program to test above
int main()
{
    int x = 8;
    cin >> n >> m;
    int mat[10][10];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    cin >> x;
    sortedMatrixSearch(mat, n, m, x);
    return 0;
}