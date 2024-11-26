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

int depth(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int lheight = depth(root->left);
    int rheight = depth(root->right);

    return max(lheight, rheight) + 1;
}

int main()
{
    node *root = new node(1);
    root->right = new node(3);

    root->left = new node(2);

    root->left->left = new node(4);

    root->left->right = new node(5);

    cout << depth(root) << endl;
}