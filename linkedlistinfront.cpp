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
    while (temp->next != nullptr)
    {
        // cout << temp->data << "->";
        temp = temp->next;
    }

    node *newNode = new node(x);

    temp->next = newNode;
    newNode->next = nullptr;
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

    // temp = temp->next;
}

void delete_at_last(node *&head)
{
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
    node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    // temp->next->next = temp->next;

    delete temp->next;
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

    insert_at_front(head, 10);
    insert_at_front(head, 20);
    insert_at_front(head, 30);

    display(head);

    insert_at_last(head, 40);
    insert_at_last(head, 50);

    display(head);

    delete_at_front(head);

    display(head);

    delete_at_last(head);

    display(head);
    return 0;
}