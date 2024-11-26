#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    // node* pre;
    // node* cur;

    node(int x)
    {
        data = x;
        next = NULL;
        // pre=NULL;
        // cur=NULL;
    }
};

node *reverse_linked_list(node *&head)
{
    node *pre = NULL;

    node *cur = head;
    node *nextptr;

    while (cur != NULL)
    {
        nextptr = cur->next;
        cur->next = pre;

        pre = cur;
        cur = nextptr;
    }

    return pre;
}

void Insert_at_front(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

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
int main()
{
    node *head = NULL;
    Insert_at_front(head, 10);
    Insert_at_front(head, 20);
    Insert_at_front(head, 30);
    display(head);

    node *newHead = reverse_linked_list(head);

    display(newHead);
}