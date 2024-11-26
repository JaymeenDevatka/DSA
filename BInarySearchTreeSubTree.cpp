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

    if (root->data < value)
    {
        root->right = insert_node_(root->right, value);
    }
    else if (root->data > value)
    {
        root->left = insert_node_(root->left, value);
    }

    return root;
}

node *search(node *root, int value)
{
    if (root == NULL || root->data == value) // Fixed here
    {
        return root;
    }

    if (root->data < value)
    {
        return search(root->right, value);
    }
    else if (root->data > value)
    {
        return search(root->left, value);
    }

    return nullptr; // Optional: in case all conditions fail (although won't happen in this case)
}

int main()
{
    node *root = new node(4);
    root = insert_node_(root, 2);
    root = insert_node_(root, 1);
    root = insert_node_(root, 3);
    root = insert_node_(root, 7);

    int n;
    cin >> n;

    node *result = search(root, n);

    if (result != nullptr)
    {
        cout << result->data << " ";
    }
    else
    {
        cout << "NULL" << endl;
    }
}