#include <iostream>
using namespace std;

pair<int, int> BinarySearch(int array[][100], int row, int col, int key)
{
    int top = 0;
    int bottom = row - 1;
    int ind = -1;

    // Find the correct row
    while (top <= bottom)
    {
        int mid = top + (bottom - top) / 2;
        if (array[mid][0] <= key && array[mid][col - 1] >= key)
        {
            ind = mid;
            break;
        }
        else if (array[mid][0] > key)
        {
            bottom = mid - 1;
        }
        else
        {
            top = mid + 1;
        }
    }

    if (ind == -1)
    {
        return {-1, -1};
    }

    // Binary search in the found row
    int left = 0;
    int right = col - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (array[ind][mid] == key)
        {
            return {ind, mid};
        }
        else if (array[ind][mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return {-1, -1};
}

int main()
{
    int row, col;
    cin >> row >> col;
    int array[100][100];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> array[i][j];
        }
    }

    int key;
    cin >> key;

    pair<int, int> result = BinarySearch(array, row, col, key);
    if (result.first == -1)
    {
        cout << "(-1,-1)" << endl;
    }
    else
    {
        cout << "(" << result.first << "," << result.second << ")" << endl;
    }

    return 0;
}
