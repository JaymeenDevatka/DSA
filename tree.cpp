#include <iostream>
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

node *insert(node *&root, int x)
{
    if (root == nullptr)
    {
        return new node(x);
    }

    if (root->data < x)
    {
        root->right = insert(root->right, x);
    }

    else if (root->data > x)
    {
        root->left = insert(root->left, x);
    }

    return root;
}

int depth(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int ldepth = depth(root->left);
    int rdepth = depth(root->right);

    return max(ldepth, rdepth) + 1;
}

void InOrderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

int main()
{
    node *root = nullptr;

    root = insert(root, 10);
    root = insert(root, 2);
    root = insert(root, 9);
    root = insert(root, -3);
    root = insert(root, 7);

    InOrderTraversal(root);

    cout << endl;

    cout << depth(root) << endl;

    return 0;
}