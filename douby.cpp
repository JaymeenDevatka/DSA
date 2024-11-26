#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void InsertAtHead(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void Insert_At_Tail(node *&head, int val)
{
    if (head == NULL)
    {
        InsertAtHead(head, val);
        return;
    }
    node *newNode = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
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

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return; // List is empty
    }
    node *todelete = head;
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    delete todelete;
}

void deletion(node *&head, int pos)
{
    if (head == NULL) // Check if list is empty
    {
        return;
    }

    if (pos == 0)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    int count = 0;

    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) // Position is out of range
    {
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int main()
{
    node *head = NULL;
    Insert_At_Tail(head, 1);
    Insert_At_Tail(head, 2);
    Insert_At_Tail(head, 3);
    Insert_At_Tail(head, 4);
    Insert_At_Tail(head, 5);

    cout << "Initial list: ";
    display(head);

    InsertAtHead(head, 6);
    cout << "List after inserting at head: ";
    display(head);

    deletion(head, 2); // Deletes node at position 2
    cout << "List after deleting node at position 2: ";
    display(head);

    // Uncomment to delete head
    // deletion(head, 0);
    // cout << "List after deleting head: ";
    // display(head);

    return 0;
}
