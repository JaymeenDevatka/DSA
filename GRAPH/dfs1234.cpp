#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, int matrix[][7], vector<int> &ans, int v)
{
    ans[start] = 1;
    cout << start << " ";

    for (int i = 0; i < v; i++)
    {
        if (matrix[start][i] == 1 && !ans[i])
        {
            dfs(i, matrix, ans, v);
        }
    }
}
int main()
{
    int v = 7;

    int matrix[7][7];

    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> ans(v, false);

    dfs(0, matrix, ans, v);
}