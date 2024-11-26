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

node *insert_node_(node *&root, int x)
{
    if (root == nullptr)
    {
        return new node(x);
    }

    if (root->data < x)
    {
        root->right = insert_node_(root->right, x);
    }
    else if (root->data > x)
    {
        root->left = insert_node_(root->left, x);
    }

    return root;
}

int search_node(node *&root, int x, int level)
{
    if (root == nullptr)
    {
        return -1;
    }

    if (root->data == x)
    {
        return level;
    }

    if (root->data < x)
    {
        return search_node(root->right, x, level + 1);
    }
    else
    {
        return search_node(root->left, x, level + 1);
    }
}

int main()
{
    node *root = nullptr;
    root = insert_node_(root, 10);
    root = insert_node_(root, -2);
    root = insert_node_(root, 5);
    root = insert_node_(root, 50);

    int n;
    int level = 0;
    cin >> n;

    cout << search_node(root, n, level) << endl;

    return 0;
}