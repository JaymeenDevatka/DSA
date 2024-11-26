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

int depth_of_tree(node *&root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int ldepth = depth_of_tree(root->left);
    int rdepth = depth_of_tree(root->right);

    return max(ldepth, rdepth) + 1;
}

int main()
{
    node *root = new node(100);

    root->right = new node(10);
    root->left = new node(20);
    root->right->left = new node(5);
    root->left->right = new node(2);

    cout << depth_of_tree(root) << endl;

    return 0;
}