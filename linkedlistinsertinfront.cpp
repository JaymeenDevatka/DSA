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

void insert_at_front(node *&head, int y)
{
    // if (head == NULL)
    // {
    //     return;
    // }

    node *newNode = new node(y);
    newNode->next = head;
    head = newNode;
}

void insert_at_last(node *&head, int y)
{
    node *newNode = new node(y);
    if (head == NULL)
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
    // newNode->next = NULL;
}

void delete_at_front(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    head = head->next;
    delete temp;
}

void delete_at_last(node *&head)
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

    delete temp->next;
    temp->next = NULL;
}

void delete_all_node(node *&head)
{
    // if (head == NULL)
    // {
    //     return;
    // }

    node *temp = head;
    node *newNode;
    while (temp != NULL)
    {
        node *newNode = temp->next;
        delete temp;
        temp = newNode;
    }

    head = NULL;
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
    display(head);

    // delete_at_front(head);
    // display(head);

    // delete_at_front(head);
    // display(head);

    // delete_at_front(head);
    // display(head);

    // delete_at_last(head);
    // display(head);

    // delete_at_last(head);
    // display(head);

    // delete_at_last(head);
    // display(head);

    delete_all_node(head);
    display(head);

    return 0;
}