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

    if (root->data < key)
    {
        root->right = insert_node_(root->right, key);
    }
    else if (root->data > key)
    {
        root->left = insert_node_(root->left, key);
    }
    return root;
}

void PrintBoundryLeft(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left)
    {
        cout << root->data << " ";
        PrintBoundryLeft(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        PrintBoundryLeft(root->right);
    }
}

void PrintBoundryRight(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->right)
    {
        cout << root->data << " ";
        PrintBoundryRight(root->right);
    }
    else if (root->left)
    {
        cout << root->data << " ";
        PrintBoundryRight(root->left);
    }
}

void PrintLeaves(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    PrintLeaves(root->left);

    if (!(root->left) && !(root->right))
    {
        cout << root->data << " ";
    }

    PrintLeaves(root->right);
}

void PrintBoundry(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";

    PrintBoundryLeft(root->left);

    PrintLeaves(root->left);

    PrintLeaves(root->right);

    PrintBoundryRight(root->right);
}

int main()
{
    // node *root = nullptr;

    // root = insert_node_(root, 1);
    // insert_node_(root, 2);
    // insert_node_(root, 4);
    // insert_node_(root, 5);
    // insert_node_(root, 5);

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->right->left->left = new node(9);
    root->right->left->right = new node(10);

    PrintBoundry(root);
}