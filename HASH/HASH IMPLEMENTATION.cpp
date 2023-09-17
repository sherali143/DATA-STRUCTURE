// NAME: SHERALI
// ROLL NO: P21-8024


#include <iostream>
using namespace std;

const int hash_Size = 10;

class Node {
public:
    int key;
    int value;
    Node* next;
    Node(int k, int v){
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable {
private:
    Node* table[hash_Size];
public:
    HashTable() {
        for (int i = 0; i < hash_Size; i++) {
            table[i] = nullptr;
        }
    }

    int hash(int key) {
        return key % hash_Size;
    }

    void insert(int value) {
        int key = hash(value);
        Node* node = new Node(key, value);
        if (table[key] == nullptr) {
            table[key] = node;
        } else {
            Node* curr = table[key];
            while (curr->next != nullptr
            ) {
                curr = curr->next;
            }
            curr->next = node;
        }
    }

    bool remove(int key) {
        int index = hash(key);
        Node* curr = table[index];
        Node* prev = nullptr;
        while (curr != nullptr) {
            if (curr->key == key) {
                if (prev == nullptr) {
                    table[index] = curr->next;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    int search(int value) {
        for (int i = 0; i < hash_Size; i++) {
            Node* curr = table[i];
            while (curr != nullptr) {
                if (curr->value == value) {
                    return curr->key;
                }
                curr = curr->next;
            }
        }
        return -1;
    }
    bool searchByKey(int k){
        int ind = hash(k);
        Node* curr = table[ind];
        while (curr != NULL){
            if(curr->key == k){
                return true;
            }
            else{
                return false;
            }
            curr = curr->next;
        }
    }
    
};

int main() {
    HashTable ht;
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    cout << ht.searchByKey(1) << endl;
    cout << ht.search(10) << endl; 
    cout << ht.search(20) << endl; 
    cout << ht.search(25) << endl; 

    ht.remove(20);

    cout << ht.search(15) << endl; 
    cout << ht.searchByKey(1);

}
