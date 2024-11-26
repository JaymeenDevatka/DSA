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

    if (root->data > value)
    {
        root->left = insert_node_(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = insert_node_(root->right, value);
    }

    return root;
}
node *minvalue_node(node *root)
{
    node *temp = root;
    while (temp && temp->left != nullptr)
    {
        temp = temp->left;
    }

    return temp;
}

node *delete_node(node *root, int value)
{
    if (root == nullptr)
    {
        return;
    }
    if (value < root->data)
    {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete_node(root->right, value);
    }
    else
    {
        if (root->left == nullptr)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        node *temp = minvalue_node(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
    }
}
