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

class CircularLL
{
public:
    node *head;

    CircularLL()
    {
        head = nullptr;
    }

    void Insert_Data(int x)
    {
        node *newNode = new node(x);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    void printlist()
    {
        if (head == nullptr)
        {
            return;
        }

        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    CircularLL ll;
    ll.Insert_Data(10);
    ll.Insert_Data(20);
    ll.Insert_Data(30);
    ll.Insert_Data(40);
    ll.Insert_Data(50);

    ll.printlist();

    return 0;
}