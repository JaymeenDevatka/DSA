#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *pre;

    node(int x)
    {
        data = x;
        next = NULL;
        pre = NULL;
    }
};

void insert_at_front(node *&head, int value)
{
    node *newNode = new node(value);
    newNode->next = head;
    // newNode->pre = NULL;
    head = newNode;
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
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    node *Lastnode = temp->next;
    temp->next = NULL;

    delete Lastnode;
}

node *delete_all_node(node *&head)
{
    node *temp = head;
    while (head != NULL)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }

    return head;
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

    insert_at_front(head, 10);
    insert_at_front(head, 20);
    insert_at_front(head, 30);

    display(head);

    // delete_at_front(head);

    // display(head);

    // delete_at_last(head);

    // display(head);

    delete_all_node(head);

    display(head);

    return 0;
}