#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int x)
    {
        data = x;
        right = nullptr;
        left = nullptr;
    }
};

void RightSideView(node *root)
{

    if (root == nullptr)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            node *temp = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << temp->data << " ";
            }

            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }

            else if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
}