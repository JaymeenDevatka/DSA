#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    vector<vector<int>> adjList;

public:
    Graph(int nodes)
    {
        adjList.resize(nodes);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void bfs(int start)
    {
        vector<bool> visited(adjList.size(), false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal starting from node " << start << ": ";
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    int nodes;
    cout << "Enter number of nodes in the graph: ";
    cin >> nodes;

    Graph graph(nodes);
    int choice;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Edge\n";
        cout << "2. Perform BFS Traversal from Node 0\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int u, v;
            cout << "Enter edge (u, v) to add (0 <= u, v < " << nodes << "): ";
            cin >> u >> v;
            if (u >= 0 && u < nodes && v >= 0 && v < nodes)
            {
                graph.addEdge(u, v);
                cout << "Edge added from " << u << " to " << v << ".\n";
            }
            else
            {
                cout << "Invalid nodes! Please enter valid nodes within range.\n";
            }
            break;
        }
        case 2:
            graph.bfs(0);
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Please select again.\n";
        }
    } while (choice != 3);

    return 0;
}