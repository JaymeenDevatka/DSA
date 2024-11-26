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

node *insert_node_(node *root, int value)
{
    if (root == nullptr)
    {
        return new node(value); // Create a new node if the root is null
    }

    // Insert node to the right if value is greater than root's data
    if (root->data < value)
    {
        root->right = insert_node_(root->right, value);
    }
    // Insert node to the left if value is smaller than root's data
    else if (root->data > value)
    {
        root->left = insert_node_(root->left, value);
    }

    return root; // Return the modified root
}

node *min_value(node *root)
{
    node *cur = root;

    while (cur && cur->left != nullptr)
    {
        cur = cur->left;
    }

    return cur;
}

node *delete_node(node *root, int value)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (value > root->data)
    {
        root->right = delete_node(root->right, value);
    }
    else if (value < root->data)
    {
        root->left = delete_node(root->left, value);
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

        node *temp = min_value(root->right);

        root->data = temp->data;

        root->right = delete_node(root->right, temp->data);
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

int main()
{
    node *root = new node(10);

    root = insert_node_(root, 20);
    root = insert_node_(root, 5);
    root = insert_node_(root, 15);
    root = insert_node_(root, 3);
    root = insert_node_(root, 7);
    root = insert_node_(root, 13);
    root = insert_node_(root, 18);

    InOrderTraversal(root);

    cout << endl;
    root = delete_node(root, 20);

    InOrderTraversal(root);
    cout << endl;
}