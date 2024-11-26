#include <iostream>
#include <queue>
using namespace std;

void bfs(int start, int matrix[][10], bool visited[], int v)
{
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 0; i < v; i++)
        {
            if (matrix[x][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
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

    bool visited[10] = {0};

    bfs(0, matrix, visited, v);

    return 0;
}