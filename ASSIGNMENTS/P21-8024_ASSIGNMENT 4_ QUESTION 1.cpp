// NAME : SHERALI
// ROLL NO : P21-8024
// ASSIGNMENT NO 4



#include <iostream>

using namespace std;

class HashTable
{
private:
    int tableSize;
    int rangeStart;
    int rangeEnd;
    int *table;

public:
    HashTable(int size, int start, int end)
    {
        tableSize = size;
        rangeStart = start;
        rangeEnd = end;
        table = new int[tableSize];
        for (int i = 0; i < tableSize; ++i)
        {
            table[i] = -1;
        }
    }

    int hashFunction(int key)
    {
        return key % tableSize;
    }

    void insert(int key)
    {
        if (key < rangeStart || key > rangeEnd)
        {
            cout << "Number " << key << " is outside the range." << endl;
            return;
        }

        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index] != -1)
        {
            index = (index + 1) % tableSize;
            if (index == originalIndex)
            {
                cout << "Hash table is full." << endl;
                return;
            }
        }

        table[index] = key;

        if (isTable70PercentFull())
        {
            rehash();
        }
    }

    bool isTable70PercentFull()
    {
        int count = 0;
        for (int i = 0; i < tableSize; ++i)
        {
            if (table[i] != -1)
            {
                count++;
            }
        }
        return count >= 0.7 * tableSize;
    }

    void rehash()
    {
        int newSize = tableSize * 2;
        int *newTable = new int[newSize];
        for (int i = 0; i < newSize; ++i)
        {
            newTable[i] = -1;
        }

        for (int i = 0; i < tableSize; ++i)
        {
            if (table[i] != -1)
            {
                int newIndex = hashFunction(table[i]);
                while (newTable[newIndex] != -1)
                {
                    newIndex = (newIndex + 1) % newSize;
                }
                newTable[newIndex] = table[i];
            }
        }

        delete[] table;
        tableSize = newSize;
        table = newTable;
        cout << "Rehashing completed. Table size is now " << tableSize << endl;
    }

    bool search(int key)
    {
        if (key < rangeStart || key > rangeEnd)
        {
            cout << "Number " << key << " is outside the range." << endl;
            return false;
        }

        int index = hashFunction(key);
        int originalIndex = index;

        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                cout << "Number " << key << " found at index " << index << endl;
                return true;
            }
            index = (index + 1) % tableSize;
            if (index == originalIndex)
            {
                cout << "Number " << key << " not found." << endl;
                return false;
            }
        }

        cout << "Number " << key << " not found." << endl;
        return false;
    }
};

int main()
{
    
    HashTable myHashTable(10, 0, 99);

    
    myHashTable.insert(5);
    myHashTable.insert(15);
    myHashTable.insert(7);
    myHashTable.insert(12);

    
    myHashTable.search(5);
    myHashTable.search(15);
    myHashTable.search(7);
    myHashTable.search(12);
    myHashTable.search(20); 
    
    return 0;
}
