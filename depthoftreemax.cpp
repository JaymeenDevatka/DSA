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

node *insert_node_(node *root, int value)
{
    if (root == nullptr)
    {
        return new node(value);
    }

    if (value > root->data)
    {
        root->right = insert_node_(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = insert_node_(root->left, value);
    }

    return root;
}
int depth(node *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    int ldepth = depth(root->left);
    int rdepth = depth(root->right);

    return max(rdepth, ldepth) + 1;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    cout << depth(root) << endl;
}