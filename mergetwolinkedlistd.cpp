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

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertattail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

node *mergelinkedlist(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *dummyNode = new node(-1);
    node *p3 = dummyNode;

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

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    node *newHead = dummyNode->next;
    delete dummyNode;
    return newHead;
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int array1[] = {1, 4, 5, 7};
    int array2[] = {2, 3, 6};

    for (int i = 0; i < 4; i++)
    {
        insertattail(head1, array1[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        insertattail(head2, array2[i]);
    }

    node *newHead = mergelinkedlist(head1, head2);
    printList(newHead);
    return 0;
}