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

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void delete_from_front(node *&head)
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;
    head = head->next;
    delete temp;
}

void delete_from_last(node *&head)
{
    if (head == NULL)
    {
        return;
    }

    node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}
void delete_all_node(node *&head)
{

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

    // insert_at_front(head, 10);
    // insert_at_front(head, 20);
    // insert_at_front(head, 30);

    insert_at_last(head, 10);
    insert_at_last(head, 20);
    insert_at_last(head, 30);
    insert_at_last(head, 40);
    insert_at_last(head, 50);
    insert_at_last(head, 60);

    delete_from_front(head);

    // delete_from_last(head);

    display(head);

    delete_all_node(head);

    display(head);

    return 0;
}