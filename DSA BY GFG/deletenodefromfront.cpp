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

void delete_at_front(node *&head)
{
    node *temp = head;
    head = head->next;
    delete temp;
}

void delete_at_end(node *&head)
{

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
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

void delete_node_at_any_point(node *&head, int value)
{
    if (head == NULL)
    {
        return;
    }

    if(head->next == NULL)
    {
        delete head;
        head=NULL;
        return;
    }

    node *temp = head;

    while (temp->next != NULL && temp->next->data != value)
    {
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
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

    // delete_at_front(head);

    // delete_at_end(head);

    // display(head);

    delete_node_at_any_point(head, 10);

    display(head);

    return 0;
}