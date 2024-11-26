#include <iostream>
using namespace std;

class node
{
public:
    int x;
    node *next;

    node(int n)
    {
        x = n;
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

void delete_at_front(node *&head)
{
    node *temp = head;
    head = head->next;
    delete temp;
}

void delete_at_last(node *&head)
{
    node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = nullptr;
}
void display(node *&head)
{
    // node *temp = head;
    // while (temp != nullptr)
    // {
    //     cout << temp->x << "->";
    //     temp = temp->next;
    // }

    // cout << "NULL" << endl;

    if (head == nullptr)
    {
        return;
    }

    cout << head->x << " ";

    // cout << endl;
    display(head->next);
}

int main()
{
    node *head = nullptr;

    insert_at_last(head, 10);
    insert_at_last(head, 20);
    insert_at_last(head, 30);

    display(head);
}