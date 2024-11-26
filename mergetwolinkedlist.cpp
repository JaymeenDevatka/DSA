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

node *mergelinkedlist(node *l1, node *l2)
{
    if (l1 == NULL)
        return l2;

    if (l2 == NULL)
        return l1;

    node *ptr = l1;
    if (l1->data > l2->data)
    {
        ptr = l2;
        l2 = l2->next;
    }
    else
    {
        l1 = l1->next;
    }
    node *cur = ptr;

    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }

        cur = cur->next;
    }

    if (!l1)
    {
        cur->next = l2;
    }
    else
    {
        cur->next = l1;
    }

    return ptr;
}

void printList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n1;
    int n2;
    cin >> n1;
    if (n1 <= 0)
    {
        return 1;
    }

    node *head1 = NULL;
    node *temp1 = NULL;

    for (int i = 0; i < n1; ++i)
    {
        int value;
        cin >> value;

        if (head1 == NULL)
        {
            head1 = new node(value);
            temp1 = head1;
        }
        else
        {
            temp1->next = new node(value);
            temp1 = temp1->next;
        }
    }
    cin >> n2;
    if (n2 <= 0)
    {
        return 1;
    }
    node *head2 = NULL;
    for (int i = 0; i < n2; i++)
    {

        int value;
        cin >> value;
        node *newNode = new node(value);
        if (head2 == NULL)
        {
            head2 = newNode;
        }
        else
        {
            node *temp2 = head2;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            temp2->next = newNode;
        }
    }

    node *mergedList = mergelinkedlist(head1, head2);

    printList(mergedList);

    return 0;
}