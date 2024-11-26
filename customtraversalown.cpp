#include<iostream>
#include<queue>
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

void RightSide(node* root)
{
    if(root == nullptr)
    {
        return;
    }

    queue<node*> q;
    q.push(root);

    while(q.empty())
    {
        int n = q.size();
        for(int i=0;i<n;i++)
        {
            node* cur = q.front();
            q.pop();

            if(i == n-1)
            {
                cout << cur->data << " ";
            }

            if(cur->left != nullptr)
            {
                q.push(cur->left);
            }

            if(cur->right != nullptr)
            {
                q.push(cur->right);
            }

        }
    }
}