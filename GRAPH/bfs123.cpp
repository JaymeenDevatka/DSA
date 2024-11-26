#include <iostream>
#include <queue>
using namespace std;

void bfs(int start, int matrix[][7], int visit[], int v)
{
    queue<int> q;
    visit[start] = 1;
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
    int v = 7;

    int matrix[7][7];

    for (int i = 1; i <= 7; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int visit[7] = {0};

    bfs(0, matrix, visit, v);

    return 0;
}