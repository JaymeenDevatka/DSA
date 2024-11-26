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
        right = nullptr;
        left = nullptr;
    }
};

void levelOrderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<node *> q;

    q.push(root);

    while (!q.empty())
    {
        node *cur = q.front();

        cout << cur->data << " ";
        q.pop();

        if (cur->left != nullptr)
        {
            levelOrderTraversal(root->left);
        }
        else if (cur->right != nullptr)
        {
            levelOrderTraversal(root->right);
        }
    }
}