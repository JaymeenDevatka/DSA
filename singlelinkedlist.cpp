#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void InsertAtFront(node *&head, int val)
{
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
}
void InsertAtTail(node *&head, int val)
{
    node *New = new node(val);
    if (head == NULL)
    {
        head = New;
        cout << "Linked list is null";
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = New;
}

// void DeleteAtFirst(node *head, int n)
// {
//     if (head == NULL)
//     {
//         cout << "Linked list is empty";
//         return;
//     }

//     node *todelete = head;
//     head = head->next;
//     delete todelete;
// }

// void DeleteAtLast(node *head,int n)
// {
//     if(head == NULL)
//     {
//         cout << "Linked list is empty";
//         return;
//     }

//     if(head->next == NULL)
//     {
//         delete head;
//         head = NULL;
//         return;
//     }
// }
// void display() const

// {
//     node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << "->";
//         temp = temp->next;
//     }
//     cout << endl;
// }