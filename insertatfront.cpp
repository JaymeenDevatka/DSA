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

void insert_at_front(node *&head, int value)
{
    node *temp = head;
    if (head == NULL)
    {
        head = temp;
    }

    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

void insert_at_last(node *&head, int value)
{
    node *temp = head;
    node *newNode = new node(value);
    if (head == NULL)
    {
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insert_at_any_point(node* &head,int value)
{
    node* newNode = new node(x);
    if(head == NULL)
    {
        return;
    }
    node* temp=head;

    while(temp != NULL && temp->data != value)
    {
        temp=temp->next;
    }

    if(temp == NULL)
    {
        delete newNode;
        return;
    }

    newNode->next =temp->next;
    temp->next=newNode;

}

void delete_at_front(node *&head)
{
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
    insert_at_front(head, 40);
    insert_at_front(head, 50);

    display(head);

    insert_at_last(head, 0);

    display(head);

    delete_at_front(head);

    display(head);

    delete_at_last(head);

    display(head);

    insert_at_any_point(head,4);

    display(head);

    return 0;
}