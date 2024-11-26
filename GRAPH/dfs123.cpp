#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, int matrix[][100], vector<bool> &visit, int v)
{
    visit[start] = true;
    cout << start << " ";

    for (int i = 0; i < v; i++)
    {
        if (matrix[start][i] == 1 && !visit[i])
        {
            dfs(i, matrix, visit, v);
        }
    }
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int matrix[100][100];

    cout << "Enter the adjacency matrix (" << V << "x" << V << "):" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<bool> visit(V, false);

    cout << "DFS Traversal starting from node 0: ";
    dfs(0, matrix, visit, V);

    cout << endl;

    return 0;
}