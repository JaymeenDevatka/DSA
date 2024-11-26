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

void insert_at_first(node *&head, int value)
{
    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

node *update_linked_list(node *&head, int oldvalue, int newvalue)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == oldvalue)
        {
            temp->data = newvalue;
            break;
        }

        temp = temp->next;
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

    insert_at_first(head, 10);
    insert_at_first(head, 20);
    insert_at_first(head, 30);

    display(head);

    node *X = update_linked_list(head, 20, 40);

    display(X);

    return 0;
}