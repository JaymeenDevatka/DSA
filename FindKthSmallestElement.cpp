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

void InOrderTraversal(node *root, int &k, int &result)
{
    if (root == nullptr)
    {
        return;
    }

    InOrderTraversal(root->left, k, result);

    k--;

    if (k == 0)
    {
        result = root->data;
        return;
    }

    InOrderTraversal(root->right, k, result);
}

int KthSmallest(node *root, int k)
{
    int result = -1;
    InOrderTraversal(root, k, result);
    return result;
}

int main()
{
    node *root = nullptr;

    root = insert_node_(root, 3);
    root = insert_node_(root, 1);
    root = insert_node_(root, 4);
    root = insert_node_(root, 2);
    // root = insert_node_(root, 4);
    // root = insert_node_(root, 1);

    int k = 1;

    int result = KthSmallest(root, k);
    if (result != -1)
    {
        cout << result << endl;
    }
    else
    {
        cout << "NULL" << endl;
    }

    return 0;
}