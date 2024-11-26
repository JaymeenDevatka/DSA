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

void insert_at_front(node *&head, int value)
{
    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
}

int lengthOfLinkedList(node *head)
{
    node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }

    return length;
}

int InterSectionPoint(node *&h1, node *&h2)
{
    int l1 = lengthOfLinkedList(h1);
    int l2 = lengthOfLinkedList(h2);

    int d = 0;
    node *ptr1;
    node *ptr2;

    if (l1 > l2)
    {
        d = l1 - l2; // pointer 1 point to big linked list
        ptr1 = h1;
        ptr2 = h2;
    }

    else
    {
        d = l2 - l1; // pointer 1 point to big linked list
        ptr1 = h2;
        ptr2 = h1;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }

        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    insert_at_front(head1, 1);
    insert_at_front(head1, 2);
    insert_at_front(head1, 3);
    insert_at_front(head1, 4);
    insert_at_front(head1, 5);

    display(head1);

    insert_at_front(head2, 9);
    insert_at_front(head2, 10);

    head2->next->next = head1->next->next;

    display(head2);

    cout << "InterSection Point: ";
    cout << InterSectionPoint(head1, head2) << endl;

    return 0;
}