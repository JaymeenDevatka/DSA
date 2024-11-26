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

node *middle_of_linkedlist(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        head = slow;
    }

    return slow;
}

int main()
{
    node *head = NULL;
    insert_at_front(head, 10);
    insert_at_front(head, 20);
    insert_at_front(head, 30);
    insert_at_front(head, 40);
    insert_at_front(head, 50);
    insert_at_front(head, 60);
    insert_at_front(head, 70);
    insert_at_front(head, 80);
    insert_at_front(head, 90);
    insert_at_front(head, 100);
    insert_at_front(head, 110);

    display(head);

    // cout << middle_of_linkedlist(head) << endl;

    node *n = middle_of_linkedlist(head);
    // display(head);

    cout << n->data << " ";
}