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

void insert_at_front(node *&head, int x)
{
    node *newNode = new node(x);

    newNode->next = head;

    head = newNode;
}

void insert_at_last(node *&head, int x)
{
    node *newNode = new node(x);

    node *temp = head;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void remove_from_front(node *&head)
{

    if (head == nullptr)
    {
        return;
    }

    node *temp = head;
    head = head->next;
    delete temp;
}

void remove_from_last(node *&head)
{
    node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = nullptr;
}

void remove_all_nodes(node *&head)
{
    if (head == nullptr)
    {
        return;
    }

    while (head != nullptr)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }
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

    // insert_at_front(head,10);
    // insert_at_front(head,20);
    // insert_at_front(head,30);

    insert_at_last(head, 10);
    insert_at_last(head, 20);
    insert_at_last(head, 30);

    display(head);

    // remove_from_front(head);

    // remove_from_last(head);

    remove_all_nodes(head);

    display(head);
}