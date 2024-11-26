#include <iostream>
using namespace std;

class node
{
public:
    int info;
    node *next;
    node *prev;

    node(int x)
    {
        info = x;
        next = NULL;
        prev = NULL;
    }

    node *insert_node_beginning(int n, node *lhead, node *&rhead)
    {
        int x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (lhead == NULL)
            {
                lhead = new node(x);
                rhead = lhead;
            }
            else
            {
                node *temp = new node(x);
                temp->next = lhead;
                lhead->prev = temp;
                lhead = temp;
            }
        }
        return lhead;
    }

    node *delete_last(node *rhead)
    {
        if (rhead == NULL)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            node *temp = rhead;
            rhead = rhead->prev;
            if (rhead != NULL)
            {
                rhead->next = NULL;
            }
            delete temp;
        }
        return rhead;
    }

    node *delete_all_nodes(node *lhead)
    {
        while (lhead != NULL)
        {
            node *temp = lhead;
            lhead = lhead->next;
            delete temp;
        }
        return NULL;
    }

    void display(node *lhead)
    {
        node *trav = lhead;
        if (trav == NULL)
        {
            cout << "Linked list is empty" << endl;
            return;
        }
        else
        {
            while (trav != NULL)
            {
                cout << trav->info << " -> ";
                trav = trav->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    node *lhead = NULL;
    node *rhead = NULL;
    int n;
    cout << "Enter how many nodes you want to enter: ";
    cin >> n;
    lhead = lhead->insert_node_beginning(n, lhead, rhead);
    lhead->display(lhead);

    rhead = rhead->delete_last(rhead);
    lhead->display(lhead);

    lhead = lhead->delete_all_nodes(lhead);
    lhead->display(lhead);

    return 0;
}