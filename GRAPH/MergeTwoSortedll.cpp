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

// Insert at the front of the list
void insert_at_front(node *&head, int x)
{
    node *newNode = new node(x);
    newNode->next = head;
    head = newNode;
}

// Merge two sorted linked lists
node *Sorted_linked_list(node *h1, node *h2)
{
    // Base cases: if either list is empty, return the other
    if (h1 == nullptr)
        return h2;
    if (h2 == nullptr)
        return h1;

    node *result = nullptr;

    // Compare values and recursively merge the remaining lists
    if (h1->data < h2->data)
    {
        result = h1;
        result->next = Sorted_linked_list(h1->next, h2);
    }
    else
    {
        result = h2;
        result->next = Sorted_linked_list(h1, h2->next);
    }

    return result;
}

// Display the linked list
void display(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *h1 = nullptr;
    node *h2 = nullptr;

    // Create sorted list 1 (1 -> 2 -> 3)
    insert_at_front(h1, 4);
    insert_at_front(h1, 2);
    insert_at_front(h1, 1);

    // Create sorted list 2 (5 -> 6 -> 8)
    insert_at_front(h2, 4);
    insert_at_front(h2, 3);
    insert_at_front(h2, 1);

    // Display both lists
    cout << "List 1: ";
    display(h1);
    cout << "List 2: ";
    display(h2);

    // Merge both sorted lists
    node *merged_list = Sorted_linked_list(h1, h2);

    // Display the merged sorted list
    cout << "Merged Sorted List: ";
    display(merged_list);

    return 0;
}
