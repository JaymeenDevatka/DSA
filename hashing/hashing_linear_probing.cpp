#include <iostream>
#include <list>
#include <vector>
#include <utility> // For std::pair

using namespace std;


// HashTable class with both Separate Chaining and Linear Probing
class HashTable
{
private:
    int size;
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
    HashTable(int initialSize)
    {
            size = nextPrime(initialSize);
            linearTable.resize(size, {-1, -1}); // Initialize with dummy values
            isOccupied.resize(size, false);
    }

    // Insert record using Separate Chaining or Linear Probing
    void insertItem(int key, int score)
    {
        int index = hashFunction(key);

            // Linear Probing
            int i = index;
            while (isOccupied[i])
            {
                i = (i + 1) % size;
            }
            linearTable[i] = {key, score};
            isOccupied[i] = true;
    }

    // Delete a record by key using Separate Chaining or Linear Probing
    void deleteItem(int key) {
        int index = hashFunction(key);


            int i = index;
            while (isOccupied[i] && linearTable[i].first != key)
            {
                i = (i + 1) % size;
            }
            if (!isOccupied[i]) return;  // Key not found
            isOccupied[i] = false;
            linearTable[i] = {-1, -1};  // Mark as deleted

    }

    // Display the hash table for Separate Chaining or Linear Probing
    void displayHash()
    {

            // Linear Probing
            for (int i = 0; i < size; i++)
            {
                cout << "table[" << i << "]";
                if (isOccupied[i])
                {
                    cout << " --> (" << linearTable[i].first << ", " << linearTable[i].second << ")";
                }
                cout << endl;
            }
    }

};

int main() {


    // Using Linear Probing
    cout << "\nUsing Linear Probing:" << endl;
    HashTable hashTable2(6);
    hashTable2.insertItem(231, 123);
    hashTable2.insertItem(326, 432);
    hashTable2.insertItem(212, 523);
    hashTable2.insertItem(321, 43);
    hashTable2.insertItem(433, 423);
    hashTable2.insertItem(262, 111);
    hashTable2.displayHash();

    cout << "After deleting record with student ID 212:" << endl;
    hashTable2.deleteItem(212);
    hashTable2.displayHash();

    return 0;
}