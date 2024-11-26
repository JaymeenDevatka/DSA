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

void reverse_linkde_list(node **head)
{
    node*  prev = NULL;
    node* current=v*head;
    node* next = NULL;

    while(current->next != NULL)
    {
        next = current->next;
        current->next=prev;
        current=next;
        prev=current;
    }

    *head = prev;
}
void display()
{
    node* temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    node* head = new node(45)
}