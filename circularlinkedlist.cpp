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
        next = NULL;
    }
};

void InsertAtHead(node *&head, int value)
{
    node *newNode = new node(value);

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}
void insert_at_tail(node *&head, int value)
{
    node *newNode = new node(value);
    node *temp = head;

    if (head == NULL)
    {
        InsertAtHead(head, value);
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void display(node *&head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);

    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;

    insert_at_tail(head, 10);
    insert_at_tail(head, 20);
    insert_at_tail(head, 30);
    insert_at_tail(head, 40);
    insert_at_tail(head, 50);

    display(head);

    InsertAtHead(head, 60);

    display(head);

    return 0;
}