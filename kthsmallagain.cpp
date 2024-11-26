#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int count;

    node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
        count = 1;
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

node *kthsmllest(node *root, int x)
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
        return kthsmllest(root->left, x);
    }

    else if (count < x)
    {
        return kthsmllest(root->right, x - count);
    }
}

int main()
{
    node *root = nullptr;

    int keys[] = {5, 3, 6, 2, 4, 1};

    for (int i = 1; i <= 6; i++)
    {
        root = insert_node_(root, i);
    }

    int x;
    cout << "Enter Element: ";
    cin >> x;
    node *result = kthsmllest(root, x);

    cout << "Kth Smallest element is: " << result->data << endl;
    return 0;
}