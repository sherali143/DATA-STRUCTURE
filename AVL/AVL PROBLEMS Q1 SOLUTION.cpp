#include <iostream>   
#include <cmath>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return max(height(node->left), height(node->right)) + 1;
    }

    bool isBalanced(Node* node) {
        if (node == NULL) {
            return true;
        }
        int left_height = height(node->left);
        int right_height = height(node->right);
        if (abs(left_height - right_height) > 1) {
            return false;
        }
        return isBalanced(node->left) && isBalanced(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int val) {
        Node* node = new Node(val);
        if (root == NULL) {
            root = node;
        }
        else {
            Node* curr = root;
            while (true) {
                if (val < curr->val) {
                    if (curr->left == NULL) {
                        curr->left = node;
                        break;
                    }
                    else {
                        curr = curr->left;
                    }
                }
                else {
                    if (curr->right == NULL) {
                        curr->right = node;
                        break;
                    }
                    else {
                        curr = curr->right;
                    }
                }
            }
        }
    }

    bool isAVL() {
        return isBalanced(root);
    }
};
int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(8);
    tree.insert(15);
    tree.insert(25);
    if (tree.isAVL()) {
        cout << "The tree is AVL." << endl;
    }
    else {
        cout << "The tree is not AVL." << endl;
    }

    return 0;
}
