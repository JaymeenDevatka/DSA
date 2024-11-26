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
    Node* next;
    Node(int k, int s) : key(k), score(s), next(nullptr)
    {
    }
};

// HashTable class with both Separate Chaining and Linear Probing
class HashTable {
private:
    int size;
    vector<Node*> table;  // Table for Separate Chaining
    vector<pair<int, int>> linearTable;  // Table for Linear Probing
    vector<bool> isOccupied;  // Occupied flag for Linear Probing

    // Helper function to find next prime greater than size
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int nextPrime(int num) {
        while (!isPrime(num)) num++;
        return num;
    }

    // Hash function using modulo operation
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor to initialize hash table size
    HashTable(int initialSize, bool useLinearProbing = false) {
        size = nextPrime(initialSize);
        if (useLinearProbing) {
            linearTable.resize(size, {-1, -1}); // Initialize with dummy values
            isOccupied.resize(size, false);
        } else {
            table.resize(size, nullptr);
        }
    }

    // Insert record using Separate Chaining or Linear Probing
    void insertItem(int key, int score, bool useLinearProbing = false) {
        int index = hashFunction(key);
        if (!useLinearProbing) {
            // Separate Chaining
            Node* newNode = new Node(key, score);
            if (!table[index]) {
                table[index] = newNode;
            } else {
                Node* temp = table[index];
                while (temp->next) temp = temp->next;
                temp->next = newNode;
            }
        } else {
            // Linear Probing
            int i = index;
            while (isOccupied[i]) {
                i = (i + 1) % size;
            }
            linearTable[i] = {key, score};
            isOccupied[i] = true;
        }
    }

    // Delete a record by key using Separate Chaining or Linear Probing
    void deleteItem(int key, bool useLinearProbing = false) {
        int index = hashFunction(key);
        if (!useLinearProbing) {
            // Separate Chaining
            Node* temp = table[index];
            Node* prev = nullptr;
            while (temp != nullptr && temp->key != key) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == nullptr) return; // Key not found
            if (prev == nullptr) {
                table[index] = temp->next;  // Delete the first node
            } else {
                prev->next = temp->next;
            }
            delete temp;
        } else {
            // Linear Probing
            int i = index;
            while (isOccupied[i] && linearTable[i].first != key) {
                i = (i + 1) % size;
            }
            if (!isOccupied[i]) return;  // Key not found
            isOccupied[i] = false;
            linearTable[i] = {-1, -1};  // Mark as deleted
        }
    }

    // Display the hash table for Separate Chaining or Linear Probing
    void displayHash(bool useLinearProbing = false) {
        if (!useLinearProbing) {
            // Separate Chaining
            for (int i = 0; i < size; i++) {
                cout << "table[" << i << "]";
                Node* temp = table[i];
                while (temp != nullptr) {
                    cout << " --> (" << temp->key << ", " << temp->score << ")";
                    temp = temp->next;
                }
                cout << endl;
            }
        } else {
            // Linear Probing
            for (int i = 0; i < size; i++) {
                cout << "table[" << i << "]";
                if (isOccupied[i]) {
                    cout << " --> (" << linearTable[i].first << ", " << linearTable[i].second << ")";
                }
                cout << endl;
            }
        }
    }
};

int main() {
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

    // Using Linear Probing
    cout << "\nUsing Linear Probing:" << endl;
    HashTable hashTable2(6, true);
    hashTable2.insertItem(231, 123, true);
    hashTable2.insertItem(326, 432, true);
    hashTable2.insertItem(212, 523, true);
    hashTable2.insertItem(321, 43, true);
    hashTable2.insertItem(433, 423, true);
    hashTable2.insertItem(262, 111, true);
    hashTable2.displayHash(true);

    cout << "After deleting record with student ID 212:" << endl;
    hashTable2.deleteItem(212, true);
    hashTable2.displayHash(true);

    return 0;
}
