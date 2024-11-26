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
            q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
        }
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    levelOrderTraversal(root);
}
