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

void InsertAtFront(node *&head, int val)
{
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
}

void reverse_linked_list(node **head)
{
    // if(head == NULL)
    // {
    //     return;
    // }

    // node* temp=head;
    // node* temp2 = head->next;

    // head->next=NULL;

    node *current = *head;

    node *next = NULL;
    node *pre = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }

    *head = pre;
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
    InsertAtFront(head, 10);
    InsertAtFront(head, 20);
    InsertAtFront(head, 30);

    display(head);

    reverse_linked_list(&head);

    display(head);
}