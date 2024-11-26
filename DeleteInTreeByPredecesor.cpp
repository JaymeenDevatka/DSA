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

node *findMin(node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}
void InOrderTraversal(node *head)
{
    if (head == nullptr)
    {
        return;
    }

    InOrderTraversal(head->left);
    cout << head->data << " ";
    InOrderTraversal(head->right);
}

node *delete_node(node *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (key < root->data)
    {
        root->left = delete_node(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete_node(root->right, key);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        else if (root->left == nullptr)
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

        else
        {
            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
    }

    return root;
}

int main()
{
    node *root = new node(9);
    root->left = new node(5);
    root->right = new node(10);

    root->left->left = new node(0);
    root->left->right = new node(6);

    root->right->right = new node(11);

    root->left->left->left = new node(-1);
    root->left->left->right = new node(1);

    root->left->left->right->right = new node(2);
    cout << "Before:";
    InOrderTraversal(root);
    root = delete_node(root, 0);
    cout << endl;
    cout << "After: ";
    InOrderTraversal(root);

    return 0;
}