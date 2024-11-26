#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;
    int count;

    node(int x)
    {
        data = x;
        right = nullptr;
        left = nullptr;
        count = 1;
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

node *kthSmallest(node *root, int x)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    int count = root->count;

    if (count == x)
    {
        return root;
    }
    else if (count > x)
    {
        return kthSmallest(root->left, x);
    }
    else
    {
        return kthSmallest(root->right, x - count);
    }
}

int main()
{
    node *root = nullptr;

    int keys[] = {3, 1, 4, 2};

    for (int i = 1; i <= 4; i++)
    {
        root = insert_node_(root, i);
    }

    int x;
    cout << "Enter Element: ";
    cin >> x;
    node *result = kthSmallest(root, x);

    cout << "Kth Smallest element is: " << result->data << endl;
    return 0;
}