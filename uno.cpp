#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    int n;

    cin >> n;

    int x1;
    cin >> x1;

    int array1[x1];
    for (int i = 0; i < x1; i++)
    {
        cin >> array1[i];
    }

    int x2;
    cin >> x2;

    int array2[x2];
    for (int i = 0; i < x2; i++)
    {
        cin >> array2[i];
    }

    int x3;
    cin >> x3;

    int array3[x3];
    for (int i = 0; i < x3; i++)
    {
        cin >> array3[i];
    }

    unordered_set<int> set1, set2, set3;
    int count1 = 0, count2 = 0, count3 = 0;

    for (int i = 0; i < x1; i++)
    {
        if (set1.find(array1[i]) != set1.end())
        {
            count1++;
        }
        else
        {
            set1.insert(array1[i]);
        }
    }
    cout << count1 << endl;

    for (int i = 0; i < x2; i++)
    {
        if (set2.find(array2[i]) != set2.end())
        {
            count2++;
        }
        else
        {
            set2.insert(array2[i]);
        }
    }
    cout << count2 << endl;

    for (int i = 0; i < x3; i++)
    {
        if (set3.find(array3[i]) != set3.end())
        {
            count3++;
        }
        else
        {
            set3.insert(array3[i]);
        }
    }
    cout << count3 << endl;

    return 0;
}