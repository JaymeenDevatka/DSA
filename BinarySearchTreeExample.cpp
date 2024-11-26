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

node *insert_node(node *root, int x)
{
    if (root == nullptr)
    {
        return new node(x); // Return a new node when the root is nullptr.
    }
    else
    {
        if (x < root->data)
        {
            root->left = insert_node(root->left, x); // Insert in the left subtree.
        }
        else if (x > root->data)
        {
            root->right = insert_node(root->right, x); // Insert in the right subtree.
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

void PreOrderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout << root->data << " ";
}

int calcHeight(node *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    int lheight = calcHeight(root->left);
    int rheight = calcHeight(root->right);

    return max(lheight, rheight) + 1;
}

void PrintLeaves(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    PrintLeaves(root->left);

    if (!(root->left) && !(root->right))
    {
        cout << root->data << " ";
    }

    PrintLeaves(root->right);
}

void PrintBoundaryLeft(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->left)
    {
        cout << root->data << " ";
        PrintBoundaryLeft(root->left);
    }
    else if (root->right)
    {
        cout << root->data << " ";
        PrintBoundaryLeft(root->right);
    }
}

void PrintBoundaryRight(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->right)
    {
        cout << root->data << " ";
        PrintBoundaryRight(root->right);
    }
    else if (root->left)
    {
        cout << root->data << " ";
        PrintBoundaryRight(root->left);
    }
}

void PrintBoundary(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";

    PrintBoundaryLeft(root->left);

    PrintLeaves(root->left);
    PrintLeaves(root->right);

    PrintBoundaryRight(root->right);
}

int main()
{
    node *root = nullptr;

    root = insert_node(root, 3);
    root = insert_node(root, 9);
    root = insert_node(root, 20);
    // root = insert_node(root, NULL);
    // root = insert_node(root, NULL);
    root = insert_node(root, 15);
    root = insert_node(root, 7);
    // root = insert_node(root, 1);
    // root = insert_node(root, 2);

    InOrderTraversal(root);
    cout << endl;
    PostOrderTraversal(root);
    cout << endl;
    PreOrderTraversal(root);
    cout << endl;
  
    root = delete_node(root, 9);
    InOrderTraversal(root);

    cout << endl;
    cout << "Height of a Tree: " << endl;
    cout << calcHeight(root) << endl;

    cout << "Boundry of Tree: " << endl;
    PrintBoundary(root);
    return 0;
}