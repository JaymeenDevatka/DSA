#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Circular Linked List class
class CircularLinkedList
{
private:
    Node *last; // Pointer to the last node

public:
    CircularLinkedList()
    {
        last = nullptr;
    }

    // Function to add a node at the end
    void insertAtEnd(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;

        if (last == nullptr)
        { // If the list is empty
            newNode->next = newNode;
            last = newNode;
        }
        else
        {
            newNode->next = last->next; // Point new node to the first node
            last->next = newNode;       // Last node's next points to the new node
            last = newNode;             // Update the last pointer
        }
    }

    // Function to add a node at the beginning
    void insertAtBeginning(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;

        if (last == nullptr)
        { // If the list is empty
            newNode->next = newNode;
            last = newNode;
        }
        else
        {
            newNode->next = last->next;
            last->next = newNode; // Update the last node's next to the new node
        }
    }

    // Function to display the list
    void displayList()
    {
        if (last == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = last->next; // Start from the first node

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next); // Loop until we reach the first node again

        cout << endl;
    }

    // Function to delete a node
    void deleteNode(int key)
    {
        if (last == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        // If the list contains only one node
        if (last == last->next && last->data == key)
        {
            delete last;    
            last = nullptr;
            return;
        }

        Node *temp = last->next; // Pointer to the first node
        Node *prev = last;

        // Search for the node to be deleted
        do
        {
            if (temp->data == key)
            {
                if (temp == last)
                {
                    last = prev; // Update last if the node to be deleted is the last node
                }
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next); // Loop until we come back to the first node

        cout << "Node with value " << key << " not found." << endl;
    }
};

int main()
{
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.insertAtBeginning(5);

    cout << "Circular Linked List: ";
    cll.displayList();

    cll.deleteNode(20);
    cout << "After deletion of 20: ";
    cll.displayList();

    return 0;
}
