#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
    }
};

void InsertatFirst(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void InsertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    InsertatFirst(head, 1);
    InsertatFirst(head, 2);
    InsertatFirst(head, 3);

    display(head);

    InsertAtTail(head, 4);
    display(head);
}