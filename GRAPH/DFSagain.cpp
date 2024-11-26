#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, int matix[][10], vector<bool> &visit, int v)
{
    visit[node] = true;

    cout << node << " ";
    for (int i = 0; i < v; i++)
    {
        if (matix[node][i] == 1 && !visit[i])
        {
            dfs(i, matix, visit, v);
        }
    }
}

int main()
{
    int v;
    cin >> v;

    int matrix[10][10];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<bool> visit(v, false);

    dfs(0, matrix, visit, v);

    return 0;
}