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

void PrintBoundaryLeft(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left)
    {
        cout << root->data << " ";
        PrintBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        PrintBoundaryLeft(root->right);
    }
}

void PrintBoundaryRight(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->right)
    {
        cout << root->data << " ";
        PrintBoundaryRight(root->right);
    }
    else if (root->left)
    {
        cout << root->data << " ";
        PrintBoundaryRight(root->left);
    }
}

void PrintBoundary(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";

    PrintBoundaryLeft(root->left);

    PrintLeaves(root->left);
    PrintLeaves(root->right);

    PrintBoundaryRight(root->right);
}

int main()
{
    node *root = new node(20);
    root->left = new node(8);
    root->right = new node(22);
    root->left->left = new node(4);
    root->left->right = new node(12);
    root->right->right = new node(25);

    root->left->right->left = new node(10);
    root->left->right->right = new node(14);

    PrintBoundary(root);
}