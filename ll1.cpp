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

void delete_at_last(node *&head)
{
    node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = nullptr;
}

void delete_all_node(node *&head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        node *next = temp->next;
        delete temp;
        temp = next;
    }

    head = nullptr;
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

    insert_at_front(head, 30);
    insert_at_front(head, 20);
    insert_at_front(head, 10);

    display(head);

    // delete_at_last(head);.

    delete_all_node(head);

    display(head);
}