#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

void insert_at_front(node *&head, int x)
{
    node *newNode = new node(x);
    // node *temp = head;
    newNode->next = head;
    newNode->prev = NULL;

    head = newNode;
}

void insert_at_last(node *&head, int x)
{
    node *newNode = new node(x);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void delete_at_front(node *&head)
{
    if (head == nullptr)
    {
        return;
    }

    node *temp = head;

    head = head->next;

    delete temp;
}

void delete_at_last(node *&head)
{
    if (head == nullptr)
    {
        return;
    }

    node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = nullptr;
}
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

int main()
{
    node *head = nullptr;
    // insert_at_front(head, 10);
    // insert_at_front(head, 20);
    // insert_at_front(head, 30);
    // insert_at_front(head, 40);

    // display(head);

    insert_at_last(head, 10);
    insert_at_last(head, 20);
    insert_at_last(head, 30);
    insert_at_last(head, 40);

    display(head);

    delete_at_front(head);

    display(head);

    delete_at_last(head);

    display(head);
    return 0;
}