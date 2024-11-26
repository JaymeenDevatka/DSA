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

    cout << calcHeight(root) << endl;
}