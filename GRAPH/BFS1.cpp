#include <iostream>
#include <queue>
using namespace std;

void bfs(int start, int matrix[][5], bool visit[], int v)
{
    queue<int> q;
    visit[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 0; i < v; ++i)
        {
            if (matrix[x][i] == 1 && visit[i] == 0)
            {
                q.push(i);    // Push it into the queue
                visit[i] = 1; // Mark it as visited
            }
        }
    }
}

int main()
{
    int v = 5; // Fixed number of vertices

    // Adjacency matrix to store graph edges
    int matrix[5][5];

    // Input adjacency matrix values
    cout << "Enter the adjacency matrix (5x5):" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Initialize visited array to false (0)
    bool visit[5] = {0};

    // Perform BFS starting from node 0
    cout << "BFS Traversal starting from node 0: ";
    bfs(0, matrix, visit, v);

    cout << endl;

    cout << "Prepared By 23CE023 Jaymeen Devatka" << endl;

    return 0;
}