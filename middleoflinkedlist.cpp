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

void insert_at_front(node *&head, int val)
{
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
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

int Middle_of_linked_list(node *&head)
{
    if (head == NULL)
    {
        return -1;
    }

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
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

    int x = Middle_of_linked_list(head);

    cout << x << endl;
}