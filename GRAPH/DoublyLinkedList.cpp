#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

void insert_at_front(node *&head, int x)
{
    node *newNode = new node(x);
    newNode->next = head;
    //  if (head != NULL)
    //     head->prev = newNode;
    newNode->prev = nullptr;
    head = newNode;
}

void insert_at_last(node *&head, int x)
{

    node *newNode = new node(x);
    if (head == nullptr)
    {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    // newNode->prev = head;
    newNode->next = nullptr;

    node *temp = head;
    while (temp->next != nullptr)
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

    node *last = temp->next;
    temp->next = nullptr;
    delete last;
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

    insert_at_last(head, 10);
    insert_at_last(head, 20);
    insert_at_last(head, 30);

    display(head);

    // delete_at_front(head);

    delete_at_last(head);

    display(head);

    return 0;
}