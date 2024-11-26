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

node *insert_tree(node *&root, int x)
{
    if (root == nullptr)
    {
        return new node(x);
    }

    if (root->data < x)
    {
        root->right = insert_tree(root->right, x);
    }
    else if (root->data > x)
    {
        root->left = insert_tree(root->left, x);
    }

    return root;
}

node *search_key(node *&root, int key)
{
    if (root == nullptr || root->data == key)
    {
        return root;
    }

    // if (root->data == key)
    // {
    //     return true;
    // }
    if (root->data < key)
    {
        return search_key(root->right, key);
    }

    return search_key(root->left, key);
}

void InOrderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

node *kthsmallest(node *&root, int x)
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
        return kthsmallest(root->left, x);
    }
    else
    {
        return kthsmallest(root->right, x - count);
    }
}
int main()
{
    node *root = nullptr;

    root = insert_tree(root, 5);
    insert_tree(root, 3);
    insert_tree(root, 6);
    insert_tree(root, 2);
    insert_tree(root, 4);
    insert_tree(root, 1);
    // insert_tree(root, 3);

    // InOrderTraversal(root);

    // cout << endl;

    // cout << "Enter a key: ";

    // int key;
    // cin >> key;

    // node *final = search_key(root, key);

    // if (final != nullptr)
    // {
    //     InOrderTraversal(final);
    // }
    // else
    // {
    //     cout << "GoodBye" << endl;
    // }

    node *kth = kthsmallest(root, 3);

    cout << kth->count << endl;
}