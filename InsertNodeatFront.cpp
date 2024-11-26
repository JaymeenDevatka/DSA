#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void InsertNodeFront(node* &head)
{
    node* temp = new node(45);
    temp->next = head;
    

}

int main()
{
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
}