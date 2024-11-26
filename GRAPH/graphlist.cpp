#include <iostream>
#include <vector>

using namespace std;

void add_back(vector<int> v[], int s, int d)
{
    v[s].push_back(d);
}
int main()
{
    int v;
    cin >> v;
    vector<int> v[5];

    add_back(v, 1, 2);

    for (int i = 0; i < v; i++)
    {
        cout << "Vertex " << i << ": ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}