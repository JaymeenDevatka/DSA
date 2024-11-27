#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    node *right;
    node *left;
    int data;

    node(int x)
    {
        data = x;
        right = nullptr;
        left = nullptr;
    }
};

node *insertBST(node *root, int val)
{
    if (root == nullptr)
    {
        return new node(val);
    }
    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }

    return root;
}

void recursion(node *root, int level, vector<int> &ans)
{
    if (root == nullptr)
    {
        return;
    }

    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }

    recursion(root->right, level + 1, ans);

    recursion(root->left, level + 1, ans);
}

vector<int> rightSide(node *root)
{
    vector<int> ans;
    recursion(root, 0, ans);
    return ans;
}

int main()
{
    node *root = nullptr;

    root = insertBST(root, 1);
    root = insertBST(root, 2);
    root = insertBST(root, 2);
    root = insertBST(root, 4);
    root = insertBST(root, 5);

    vector<int> rightView = rightSide(root);

    // Display the right side view
    cout << "Right Side View of the BST: ";
    for (int val : rightView)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}