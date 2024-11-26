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

void delete_at_last(node *&head, int value)
{
    node *temp = head;
    if (head == NULL)
    {
        // head=temp;
        // delete temp;
        return;
    }

    if (head->data == value)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node *prev = NULL;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;

    // Delete the node
    delete temp;
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

void insert_at_front(node *&head, int value)
{
    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

int main()
{
    node *head = NULL;

    insert_at_front(head, 10);
    insert_at_front(head, 20);
    insert_at_front(head, 30);

    display(head);

    delete_at_last(head, 30);

    display(head);

    return 0;
}