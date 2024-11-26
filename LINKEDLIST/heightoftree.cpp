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

node *insert_in_bst(node *&root, int x)
{
    if (root == nullptr)
    {
        return new node(x);
    }
    else
    {
        if (root->data > x)
        {
            root->left = insert_in_bst(root->left, x);
        }
        else if (root->data < x)
        {
            root->right = insert_in_bst(root->right, x);
        }
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

node *delete_node(node *root, int x)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (x < root->data)
    {
        root->left = delete_node(root->left, x);
    }
    else if (x > root->data)
    {
        root->right = delete_node(root->right, x);
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

    return root;
}

void InorderTraversal(node *&root)
{
    if (root == nullptr)
    {
        return;
    }

    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}
int height_of_a_tree(node *&root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int lheight = height_of_a_tree(root->left);

    int rheight = height_of_a_tree(root->right);

    return max(lheight, rheight) + 1;
}

int main()
{
    // node *root = nullptr;

    node *last = nullptr;

    last = insert_in_bst(last, 50);
    last = insert_in_bst(last, 5);
    last = insert_in_bst(last, 4);
    last = insert_in_bst(last, 7);
    last = insert_in_bst(last, 60);
    last = insert_in_bst(last, 70);

    InorderTraversal(last);

    cout << endl;

    cout << height_of_a_tree(last) << endl;
}