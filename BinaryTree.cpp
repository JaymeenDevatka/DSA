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
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    node *root;

    BinaryTree()
    {
        root = NULL;
    }

    void insertAtLeft(node *par, int data)
    {
        if (par == nullptr)
        {
            return;
        }
        if (par->left == nullptr)
        {
            par->left = new node(data);
        }
        else
        {
            node *newNode = new node(data);
            newNode->left = par->left;
            par->left = newNode;
        }
    }

    void deleteRight(node *par)
    {
        if (par == nullptr || par->right == NULL)
        {
            return;
        }

        delete par->right;

        par->right = nullptr;
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

    // void PreOrderTraversal(node* head)
    // {
    //     if(he)
    // }

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
};

int main()
{
    BinaryTree tree;

    tree.root = new node(1);
    tree.insertAtLeft(tree.root, 2);
    tree.root->right = new node(3);
    tree.insertAtLeft(tree.root->left, 4);
    tree.root->left->right = new node(5);

    tree.InOrderTraversal(tree.root);
    cout << endl;

    tree.PreOrderTraversal(tree.root);
    cout << endl;

    tree.PostOrderTraversal(tree.root);
    cout << endl;

    tree.deleteRight(tree.root);

    tree.InOrderTraversal(tree.root);
    cout << endl;

    tree.PreOrderTraversal(tree.root);
    cout << endl;

    tree.PostOrderTraversal(tree.root);
    cout << endl;
}