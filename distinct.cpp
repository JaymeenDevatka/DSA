#include <iostream>
using namespace std;

int SumOfDistinct(int array[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        bool distinct = true;
        for (int j = 0; j < i; j++)
        {
            if (array[i] == array[j])
            {
                distinct = false;
                break;
            }
        }
        if (distinct)
        {
            sum += array[i];
        }
    }
    return sum;
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

    int result = SumOfDistinct(array, n);
    cout << result << endl;

    return 0;
}
