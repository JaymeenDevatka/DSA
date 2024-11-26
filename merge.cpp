#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;                               

    node(int n)
    {
        data = n;
        next = NULL;
    }
};

node *mergeRecursive(node *&head1, node *&head2)
{

    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }

    return result;
}

int main()
{
    // Create first linked list: 1 -> 3 -> 5
    node *head1 = new node(1);
    head1->next = new node(3);
    head1->next->next = new node(5);

    // Create second linked list: 2 -> 4 -> 6
    node *head2 = new node(2);
    head2->next = new node(4);
    head2->next->next = new node(6);

    // Merge the two linked lists
    node *mergedHead = mergeRecursive(head1, head2);

    // Print the merged linked list
    while (mergedHead != NULL)
    {
        cout << mergedHead->data << " ";
        mergedHead = mergedHead->next;
    }

    return 0;
}