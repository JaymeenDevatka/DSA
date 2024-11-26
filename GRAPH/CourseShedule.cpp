#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> &vis, vector<int> adj[])
{
    if (vis[node] == 1)
        return true;

    if (vis[node] == 0)
    {
        vis[node] = 1;

        for (auto adjacentNode : adj[node])
        {
            if (dfs(adjacentNode, vis, adj))
            {
                return true;
            }
        }
    }

    vis[node] = 2;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    if (numCourses == 1 || prerequisites.size() == 0)
        return true;

    vector<int> adj[numCourses];
    for (int i = 0; i < prerequisites.size(); i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    vector<int> vis(numCourses, 0);
    for (int i = 0; i < numCourses; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, adj))
                return false;
        }
    }

    return true;
}

int main()
{
    int numCourses;
    cin >> numCourses;

    int numPrerequisites;
    cin >> numPrerequisites;

    vector<vector<int>> prerequisites(numPrerequisites, vector<int>(2));
    for (int i = 0; i < numPrerequisites; i++)
    {
        cin >> prerequisites[i][0] >> prerequisites[i][1];
    }

    if (canFinish(numCourses, prerequisites))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}