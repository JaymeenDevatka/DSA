#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int FindingBurgers(vector<int> &array)
{
    int n = array.size();
    for (int i = 0; i < n; i++)
    {
        if (array[i] != 0)
        {
            int count = 0;
            int magic_number = 0;
            if (array[i] > array[i + 1])
            {
                count++;
            }

            return i;

            cout << module(i) << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int result = FindingBurgers(array);

    cout << result << endl;

    return 0;
}