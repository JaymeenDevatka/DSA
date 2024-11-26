#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int x)
    {
        data = x;
        next = nullptr;
    }
};
void insert_at_last(node *&head, int x)
{
    node *temp = head;
    node *newNode = new node(x);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}
// void insert_at_front(node *&head, int x)
// {
//     node *newNode = new node(x);
//     newNode->next = head;
//     head = newNode;
// }
void display(node *&head)
{
    node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

node *merge_sorted_ll(node *&h1, node *&h2)
{
    if (h1 == nullptr)
    {
        return h2;
    }

    if (h2 == nullptr)
    {
        return h1;
    }

    node *dummy = new node(0);
    node *temp = dummy;

    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->data > h2->data)
        {
            temp->next = h2;
            h2 = h2->next;
        }
        else if (h1->data < h2->data)
        {
            temp->next = h1;
            h1 = h1->next;
        }

        temp = temp->next;
    }

    if (h1 != nullptr)
    {
        temp->next = h1;
    }

    if (h2 != nullptr)
    {
        temp->next = h2;
    }

    return dummy->next;
}
int main()
{
    node *h1 = nullptr;
    node *h2 = nullptr;
    insert_at_last(h1, 1);
    insert_at_last(h1, 3);
    insert_at_last(h1, 6);

    display(h1);
    insert_at_last(h2, 4);
    insert_at_last(h2, 5);
    insert_at_last(h2, 7);
    display(h2);

    node *merge = merge_sorted_ll(h1, h2);

    display(merge);
    return 0;
}