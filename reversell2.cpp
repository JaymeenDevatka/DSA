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

void reverse_linked_list(node *&head)
{
    node *pre = NULL;
    node *cur = head;
    node *next = NULL;

    while (cur != NULL)
    {
        next = cur->next; // Save next node
        cur->next = pre;  // Reverse current node's pointer
        pre = cur;        // Move pointers one position ahead
        cur = next;       // Move to the next node in the list
    }

    head = pre; // Update head to the new first node
}

void insert_at_front(node *&head, int val)
{
    node *newNode = new node(val);
    newNode->next = head;
    head = newNode;
}

int main()
{
    node *head = NULL;
    insert_at_front(head, 10);
    insert_at_front(head, 20);
    insert_at_front(head, 30);

    cout << "Original List: ";
    display(head);

    reverse_linked_list(head);

    cout << "Reversed List: ";
    display(head);

    return 0;
}
