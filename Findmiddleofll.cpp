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

int middleNode(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main()
{
    node *h1 = nullptr;

    insert_at_front(h1, 30);
    insert_at_front(h1, 20);
    insert_at_front(h1, 10);

    display(h1);

    int final1 = middleNode(h1);
    cout << final1 << endl;
}