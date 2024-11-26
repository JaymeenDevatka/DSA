#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

// Function to check if bomb j can be triggered by bomb i
bool can_trigger(const vector<int> &bomb_i, const vector<int> &bomb_j)
{
    int x1 = bomb_i[0], y1 = bomb_i[1], r1 = bomb_i[2];
    int x2 = bomb_j[0], y2 = bomb_j[1];
    // Calculate Euclidean distance and check if bomb j is within radius of bomb i
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) <= r1;
}

// DFS function to detonate bombs
int dfs(const vector<vector<int>> &graph, int node, set<int> &visited)
{
    visited.insert(node);
    int count = 1;

    for (int neighbor : graph[node])
    {
        if (visited.find(neighbor) == visited.end())
        {
            count += dfs(graph, neighbor, visited);
        }
    }
    return count;
}

// Main function to find maximum bombs detonated
int max_bombs_detonated(const vector<vector<int>> &bombs)
{
    int n = bombs.size();
    vector<vector<int>> graph(n);

    // Build graph based on triggering condition
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && can_trigger(bombs[i], bombs[j]))
            {
                graph[i].push_back(j);
            }
        }
    }

    // Calculate max bombs detonated using DFS
    int max_detonations = 0;
    for (int i = 0; i < n; i++)
    {
        set<int> visited;
        max_detonations = max(max_detonations, dfs(graph, i, visited));
    }

    return max_detonations;
}

int main()
{
    // Example bomb list where each bomb is represented as {x, y, radius}
    vector<vector<int>> bombs = {{2, 1, 3}, {6, 1, 4}, {9, 2, 1}};

    cout << "Maximum bombs detonated: " << max_bombs_detonated(bombs) << endl;

    return 0;
}