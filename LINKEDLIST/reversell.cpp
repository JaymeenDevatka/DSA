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
        next = nullptr;
    }
};

void insert_at_front(node *&head, int x)
{
    node *newNode = new node(x);
    newNode->next = head;
    head = newNode;
}
void display(node *&head)
{
    node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
node *reverse_ll(node *&head)
{
    node *cur = head;
    node *pre = nullptr;
    node *next = nullptr;

    while (cur != nullptr)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    head = pre;
    return head;
}
int main()
{
    node *head = nullptr;
    insert_at_front(head, 10);
    insert_at_front(head, 20);
    insert_at_front(head, 30);

    display(head);

    node *rev = reverse_ll(head);

    display(rev);

    return 0;
}