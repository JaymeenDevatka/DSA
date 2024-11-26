#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

node *insert_node_(node *root, int key)
{
    if (root == nullptr)
    {
        return new node(key);
    }

    if (key > root->data)
    {
        root->right = insert_node_(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = insert_node_(root->left, key);
    }

    return root;
}

void rightsideview(node *root)
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

            if (cur->left)
            {
                q.push(cur->left);
            }

            if (cur->right)
            {
                q.push(cur->right);
            }
        }
    }
}

int main()
{
    node *root = nullptr;
    root = insert_node_(root, 1);
    root = insert_node_(root, 3);
    root = insert_node_(root, 2);
    root = insert_node_(root, 4);
    root = insert_node_(root, 5);

    rightsideview(root);

    return 0;
}