#include <iostream>

// Definition of a node in the linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to merge two sorted linked lists
Node *mergeSortedLists(Node *l1, Node *l2)
{
    // Create a dummy node to simplify the merge logic
    Node dummy(0);
    Node *tail = &dummy;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining nodes from l1 or l2
    if (l1 != nullptr)
    {
        tail->next = l1;
    }
    else
    {
        tail->next = l2;
    }

    return dummy.next;
}

// Function to print a linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to append a node to the end of the list
void append(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a linked list and free memory
void deleteList(Node *&head)
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *l1 = nullptr;
    Node *l2 = nullptr;

    // Creating first sorted list: 1 -> 3 -> 5
    append(l1, 1);
    append(l1, 3);
    append(l1, 5);

    // Creating second sorted list: 2 -> 4 -> 6
    append(l2, 2);
    append(l2, 4);
    append(l2, 6);

    // Merging the two sorted lists
    Node *mergedList = mergeSortedLists(l1, l2);

    // Printing the merged list
    std::cout << "Merged List: ";
    printList(mergedList);

    // Clean up memory
    deleteList(mergedList);

    return 0;
}
