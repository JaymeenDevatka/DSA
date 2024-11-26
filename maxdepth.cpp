#include<iostream>
using namespace std;

class Tree
{
    public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int x)
    {
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

int depth(Tree* root)
{
    if(root == nullptr)
    {
        return 0;
    }

    int ldepth = depth(root->left);
    int rdepth = depth(root->right);

    return max(ldepth,rdepth) + 1;
}

int main()
{
    
}