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

node *MergeTwoLinkedlists(node *h1, node *h2)
{
    node *p1 = h1;
    node *p2 = h2;
    node *dummy = new node(-1); // Dummy node to simplify merging
    node *p3 = dummy;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    // Append remaining nodes from p1 or p2
    if (p1 != NULL)
    {
        p3->next = p1;
    }
    else
    {
        p3->next = p2;
    }

    node *mergedHead = dummy->next;
    delete dummy; // Clean up the dummy node
    return mergedHead;
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

int main()
{
    node *h1 = NULL;
    node *h2 = NULL;

    // Insert nodes in descending order to create lists in ascending order
    insert_at_front(h1, 4);
    insert_at_front(h1, 2);
    insert_at_front(h1, 1);

    cout << "First Linked List: ";
    display(h1);

    insert_at_front(h2, 4);
    insert_at_front(h2, 3);
    insert_at_front(h2, 1);

    cout << "Second Linked List: ";
    display(h2);

    node *mergedHead = MergeTwoLinkedlists(h1, h2);

    cout << "Merged Linked List: ";
    display(mergedHead);

    return 0;
}