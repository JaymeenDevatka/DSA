#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int matrix[][100], vector<bool> &visit, int V)
{
    visit[node] = true;
    cout << node << " ";

    for (int i = 0; i < V; ++i)
    {
        if (matrix[node][i] == 1 && !visit[i])
        {
            dfs(i, matrix, visit, V);
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

    cout << "Prepared by 23CE023 Jaymeen Devatka" << endl;

    return 0;
}