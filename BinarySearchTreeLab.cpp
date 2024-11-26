#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int x)
    {
        data = x;
        right = nullptr;
        left = nullptr;
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

void InOrderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    InOrderTraversal(root->left);
    InOrderTraversal(root->right);
}
node *search_node(node *root, int key)
{
    if (root == nullptr || root->data == key)
    {
        return root;
    }

    if (root->data < key)
    {
        return search_node(root->right, key);
    }
    else
    {
        return search_node(root->left, key);
    }

    return nullptr;
}

int main()
{
    node *root = nullptr;

    root = insert_node_(root, 4);
    insert_node_(root, 2);
    insert_node_(root, 7);
    insert_node_(root, 1);
    insert_node_(root, 3);

    cout << "InOrder Traversal: " << endl;
    InOrderTraversal(root);
    cout << endl;
    int key;
    cout << "Enter key: ";
    cin >> key;

    node *search_element = search_node(root, key);

    if (search_element)
    {
        cout << "Tree element " << key << " found." << endl;
        InOrderTraversal(search_element);
    }
    else
    {
        cout << "Tree element " << key << " not found." << endl;
    }

    return 0;
}