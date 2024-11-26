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

void levelOrderTraversal(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *cur = q.front();
        cout << cur->data << " ";
        q.pop();

        if (cur->left != nullptr)
        {
            q.push(cur->left);
        }
        if (cur->right != nullptr)
        {
            q.push(cur->right);
        }
    }
}

int main()
{
    cout << "Inserting at left: " << endl;
    node *root = new node(10);

    insertAtLeft(root, 20);
    insertAtLeft(root, 30);
    insertAtLeft(root, 40);
    insertAtLeft(root, 50);

    cout << "No element there in right" << endl;

    deleteRight(root);
    cout << "INORDER TRAVERSAL: ";
    InOrderTraversal(root);
    cout << endl;
    cout << "PREORDER TRAVERSAL: ";
    PreOrderTraversal(root);
    cout << endl;
    cout << "POSTORDER TRAVERSAL: ";
    PostOrderTraversal(root);
    cout << endl;
    cout << "LEVELORDER TRAVERSAL: ";
    levelOrderTraversal(root);
    cout << endl;

    cout << "PREPARED BY 23CE023 JAYMEEN DEVATKA" << endl;

    return 0;
}
