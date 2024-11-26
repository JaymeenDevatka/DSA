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

void reverse_linked_list(node **head)
{
    node *pre = NULL;
    node *cur = *head;
    node *next;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = pre;

        pre = cur;
        cur = next;
    }

    *head = pre;
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

    reverse_linked_list(&head);

    display(head);

    return 0;
}