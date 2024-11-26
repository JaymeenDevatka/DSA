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
    node *temp = head;
    node *newNode = new node(x);

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

void delete_from_front(node *&head)
{
    if (head == nullptr)
    {
        return;
    }

    node *temp = head;
    head = head->next;
    delete temp;
}

void delete_from_last(node *&head)
{
    node *temp = head;

    if (head == nullptr)
    {
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = temp->next->next;
}
void print_data(node *&head)
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
    // insert_at_front(head, 50);

    insert_at_last(head, 10);
    insert_at_last(head, 20);
    insert_at_last(head, 30);
    insert_at_last(head, 40);
    insert_at_last(head, 50);

    print_data(head);

    // delete_from_front(head);

    delete_from_last(head);

    delete_from_last(head);

    delete_from_last(head);

    delete_from_last(head);

    delete_from_last(head);

    delete_from_last(head);

    delete_from_last(head);

    print_data(head);

    return 0;
}