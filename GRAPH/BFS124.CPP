#include <iostream>
#include <queue>
using namespace std;

void bfs(int start, bool matrix[][5], int v, int visit[])
{
    queue<int> q;
    visit[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 0; i < v; i++)
        {
            if (matrix[x][i] == 1 && visit[i] == 0)
            {
                q.push(i);
                visit[i] = 1;
            }
        }
    }
}

int main()
{
    int v = 5;

    int matrix[5][5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int visit[5] = {1};

    bfs(0, matrix, v, visit);
}