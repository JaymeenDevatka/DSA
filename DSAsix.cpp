#include <iostream>
#include <algorithm>
using namespace std;

int count(int array[], int n, int target)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] >= target)
            ans++;
    }

    return ans;
}

int SpecialArray(int array[], int n)
{
    sort(array, array + n);
    int left = 0;
    int right = n;

    while (left <= right)
    {
        int mid = left + ((right - left) / 2);
        int ans = count(array, n, mid);

        if (ans == mid)
            return ans;

        else if (ans > mid)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
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

    int result = SpecialArray(array, n);

    cout << result << endl;
}