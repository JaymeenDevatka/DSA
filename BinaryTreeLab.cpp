#include <iostream>
#include <queue>
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

node *insert(node *root, int key)
{
    if (root == nullptr)
    {
        return new node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }

    return root;
}

node *minValueNode(node *root)
{
    node *current = root;

    // Loop down to find the leftmost leaf
    while (current && current->left != nullptr)
    {
        current = current->left;
    }

    return current;
}
node *delete_node(node *root, int value)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (value < root->data)
    {
        root->left = delete_node(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = delete_node(root->right, value);
    }
    else
    {
        // Node with only one child or no child
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

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        node *temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = delete_node(root->right, temp->data);
    }
    return root;
}

// Helper function to find the node with the minimum value

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

void PreOrderTraversal(node *head)
{
    if (head == nullptr)
    {
        return;
    }

    cout << head->data << " ";
    PreOrderTraversal(head->left);
    PreOrderTraversal(head->right);
}

void PostOrderTraversal(node *head)
{
    if (head == nullptr)
    {
        return;
    }

    PostOrderTraversal(head->left);

    PostOrderTraversal(head->right);
    cout << head->data << " ";
}
void levelOrderTraversal(node *root)
{
    if (root == nullptr)
        return;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}
int main()
{
    // BinaryTree tree;
    node *root = new node(9);
    root->left = new node(5);
    root->right = new node(10);

    root->left->left = new node(0);
    root->left->right = new node(6);

    root->right->right = new node(11);

    root->left->left->left = new node(-1);
    root->left->left->right = new node(1);

    root->left->left->right->right = new node(2);

    InOrderTraversal(root);
    cout << endl;
    PostOrderTraversal(root);
    cout << endl;
    PreOrderTraversal(root);
    cout << endl;

    root = delete_node(root, 0);

    InOrderTraversal(root);
    return 0;
}