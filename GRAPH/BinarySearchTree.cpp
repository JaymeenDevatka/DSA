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

node *insert_node_(node *&root, int key)
{
    if (root == nullptr)
    {
        return new node(key);
    }

    if (key < root->data)
    {
        root->left = insert_node_(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = insert_node_(root->right, key);
    }

    return root;
}

string search(node *&root, int key)
{
    if (root == nullptr)
    {
        return "not found";
    }

    if (root->data == key)
    {
        return "found";
    }

    if (root->data < key)
    {
        return search(root->right, key);
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
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
int main()
{
    node *root = nullptr;

    root = insert_node_(root, 20);
    root = insert_node_(root, 30);
    root = insert_node_(root, 10);

    InOrderTraversal(root);
    cout << endl;

    cout << "10 " << search(root, 10) << endl;
    cout << "15 " << search(root, 15) << endl;

    cout << "PREPARED BY 23CE023 JAYMEEN DEVATKA" << endl;

    return 0;
}