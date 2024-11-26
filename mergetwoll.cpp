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
void insert_at_front(node *&head, int x)
{
    node *newNode = new node(x);
    newNode->next = head;
    head = newNode;
}

node *Merge_two_ll(node *&h1, node *&h2)
{
    node *temp1 = h1;
    // display(h1);
    while (temp1->next != nullptr)
    {
        cout << temp1->data << "->";
        temp1 = temp1->next;
    }

    node *temp2 = h2;
    temp1->next = h2;

}

int main()
{
    node *h1 = nullptr;
    node *h2 = nullptr;

    insert_at_front(h1, 30);
    insert_at_front(h1, 20);
    insert_at_front(h1, 10);

    display(h1);

    insert_at_front(h2, 60);
    insert_at_front(h2, 50);
    insert_at_front(h2, 40);

    display(h2);

    node *final1 = Merge_two_ll(h1, h2);

    display(final1);

    return 0;
}