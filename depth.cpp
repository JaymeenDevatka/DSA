#include <iostream>
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

int depth(node *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    int ldepth = depth(root->left);
    int rdepth = depth(root->right);

    return max(ldepth, rdepth) + 1;
}

int main()
{
    node *root = nullptr;
    root = insert_node_(root, 3);
    root = insert_node_(root, 9);
    root = insert_node_(root, 20);
    root = insert_node_(root, 15);
    root = insert_node_(root, 7);

    cout << depth(root) << endl;

    return 0;
}