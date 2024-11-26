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

void RightView(node *root)
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
            node *cur = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << cur->data << " ";
            }

            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }

            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
        }
    }
}

int main()
{
    node *root = new node(1);
    root->right = new node(3);

    root->left = new node(2);

    root->left->left = new node(4);

    root->left->right = new node(5);

    RightView(root);

    return 0;
}