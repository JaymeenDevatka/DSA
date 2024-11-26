#include <iostream>
#include <list>
#include <vector>
#include <utility> // For std::pair

using namespace std;

// Node structure for linked list used in separate chaining
struct Node
{
    int key;
    int score;
    Node *next;
    Node(int k, int s)
    {
        key = k;
        score = s;
        next = nullptr;
    }
};

// HashTable class with both Separate Chaining and Linear Probing
class HashTable
{
private:
    int size;
    vector<Node *> table; // Table for Separate Chaining

    // Helper function to find next prime greater than size
    bool isPrime(int num)
    {
        if (num <= 1)
            return false;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }

    int nextPrime(int num)
    {
        while (!isPrime(num))
            num++;
        return num;
    }

    // Hash function using modulo operation
    int hashFunction(int key)
    {
        return key % size;
    }

public:
    // Constructor to initialize hash table size
    HashTable(int initialSize)
    {
        size = nextPrime(initialSize);
        table.resize(size, nullptr);
    }

    // Insert record using Separate Chaining or Linear Probing
    void insertItem(int key, int score, bool useLinearProbing = false)
    {
        int index = hashFunction(key);

        // Separate Chaining
        Node *newNode = new Node(key, score);
        if (!table[index])
        {
            table[index] = newNode;
        }
        else
        {
            Node *temp = table[index];
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Delete a record by key using Separate Chaining or Linear Probing
    void deleteItem(int key, bool useLinearProbing = false)
    {
        int index = hashFunction(key);

        // Separate Chaining
        Node *temp = table[index];
        Node *prev = nullptr;
        while (temp != nullptr && temp->key != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr)
            return; // Key not found
        if (prev == nullptr)
        {
            table[index] = temp->next; // Delete the first node
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
    }

    // Display the hash table for Separate Chaining or Linear Probing
    void displayHash(bool useLinearProbing = false)
    {

        // Separate Chaining
        for (int i = 0; i < size; i++)
        {
            cout << "table[" << i << "]";
            Node *temp = table[i];
            while (temp != nullptr)
            {
                cout << " --> (" << temp->key << ", " << temp->score << ")";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    // Using Separate Chaining
    cout << "Using Separate Chaining:" << endl;
    HashTable hashTable1(6);
    hashTable1.insertItem(231, 123);
    hashTable1.insertItem(326, 432);
    hashTable1.insertItem(212, 523);
    hashTable1.insertItem(321, 43);
    hashTable1.insertItem(433, 423);
    hashTable1.insertItem(262, 111);
    hashTable1.displayHash();

    cout << "After deleting record with student ID 212:" << endl;
    hashTable1.deleteItem(212);
    hashTable1.displayHash();

    return 0;
}