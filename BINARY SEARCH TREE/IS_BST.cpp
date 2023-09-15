#include <bits/stdc++.h>
using namespace std;
 
 
// IS BINARY SEACH TREE


/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node* newNode(int data)
{
    struct node* node
        = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
int maxValue(struct node* node)
{
    if (node == NULL) {
        return INT16_MIN;
    }
    int value = node->data;
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);
 
    return max(value, max(leftMax, rightMax));
}
 
int minValue(struct node* node)
{
    if (node == NULL) {
        return INT16_MAX;
    }
    int value = node->data;
    int leftMax = minValue(node->left);
    int rightMax = minValue(node->right);
 
    return min(value, min(leftMax, rightMax));
}
 
/* Returns true if a binary tree is a binary search tree */
int isBST(struct node* node)
{
    if (node == NULL)
        return 1;
 
    /* false if the max of the left is > than us */
    if (node->left != NULL
        && maxValue(node->left) > node->data)
        return 0;
 
    /* false if the min of the right is <= than us */
    if (node->right != NULL
        && minValue(node->right) < node->data)
        return 0;
 
    /* false if, recursively, the left or right is not a BST
     */
    if (!isBST(node->left) || !isBST(node->right))
        return 0;
 
    /* passing all that, it's a BST */
    return 1;
}
 
/* Driver code*/
int main()
{
    struct node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    // root->right->left = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
 
    // Function call
    if (isBST(root))
        printf("Is BST");
    else
        printf("Not a BST");
 
    return 0;
}




// BINARY TREE TO BST



#include <iostream>
using namespace std;
 
/* A binary tree node structure */
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
/* A helper function that stores inorder
   traversal of a tree rooted with node */
void storeInorder(struct node* node, int inorder[], int* index_ptr)
{
    // Base Case
    if (node == NULL)
        return;
 
    /* first store the left subtree */
    storeInorder(node->left, inorder, index_ptr);
 
    /* Copy the root's data */
    inorder[*index_ptr] = node->data;
    (*index_ptr)++; // increase index for next entry
 
    /* finally store the right subtree */
    storeInorder(node->right, inorder, index_ptr);
}
 
/* A helper function to count nodes in a Binary Tree */
int countNodes(struct node* root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
 
// Following function is needed for library function qsort()
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
 
/* A helper function that copies contents of arr[]
   to Binary Tree. This function basically does Inorder
   traversal of Binary Tree and one by one copy arr[]
   elements to Binary Tree nodes */
void arrayToBST(int* arr, struct node* root, int* index_ptr)
{
    // Base Case
    if (root == NULL)
        return;
 
    /* first update the left subtree */
    arrayToBST(arr, root->left, index_ptr);
 
    /* Now update root's data and increment index */
    root->data = arr[*index_ptr];
    (*index_ptr)++;
 
    /* finally update the right subtree */
    arrayToBST(arr, root->right, index_ptr);
}
 
// This function converts a given Binary Tree to BST
void binaryTreeToBST(struct node* root)
{
    // base case: tree is empty
    if (root == NULL)
        return;
 
    /* Count the number of nodes in Binary Tree so that
    we know the size of temporary array to be created */
    int n = countNodes(root);
 
    // Create a temp array arr[] and store inorder
    // traversal of tree in arr[]
    int* arr = new int[n];
    int i = 0;
    storeInorder(root, arr, &i);
 
    // Sort the array using library function for quick sort
    qsort(arr, n, sizeof(arr[0]), compare);
 
    // Copy array elements back to Binary Tree
    i = 0;
    arrayToBST(arr, root, &i);
 
    // delete dynamically allocated memory to
    // avoid memory leak
    delete[] arr;
}
 
/* Utility function to create a new Binary Tree node */
struct node* newNode(int data)
{
    struct node* temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
 
/* Utility function to print inorder
   traversal of Binary Tree */
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
 
    /* first recur on left child */
    printInorder(node->left);
 
    /* then print the data of node */
    cout <<" "<< node->data;
 
    /* now recur on right child */
    printInorder(node->right);
}
 
/* Driver function to test above functions */
int main()
{
    struct node* root = NULL;
 
    /* Constructing tree given in the above figure
        10
        / \
        30 15
    /     \
    20     5 */
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
 
    // convert Binary Tree to BST
    binaryTreeToBST(root);
 
    cout <<"Following is Inorder Traversal of the converted BST:" << endl ;
    printInorder(root);
 
    return 0;
}


// CONVERT BINARY SEARCH TREE TO MINIMUM HEAP


#include <bits/stdc++.h>
using namespace std;
 
// Structure of a node of BST
struct Node {
 
    int data;
    Node *left, *right;
};
 
/* Helper function that allocates a new node
   with the given data and NULL left and right
   pointers. */
struct Node* getNode(int data)
{
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
// function prototype for preorder traversal
// of the given tree
void preorderTraversal(Node*);
 
// function for the inorder traversal of the tree
// so as to store the node values in 'arr' in
// sorted order
void inorderTraversal(Node* root, vector<int>& arr)
{
    if (root == NULL)
        return;
 
    // first recur on left subtree
    inorderTraversal(root->left, arr);
 
    // then copy the data of the node
    arr.push_back(root->data);
 
    // now recur for right subtree
    inorderTraversal(root->right, arr);
}
 
// function to convert the given BST to MIN HEAP
// performs preorder traversal of the tree
void BSTToMinHeap(Node* root, vector<int> arr, int* i)
{
    if (root == NULL)
        return;
 
    // first copy data at index 'i' of 'arr' to
    // the node
    root->data = arr[++*i];
 
    // then recur on left subtree
    BSTToMinHeap(root->left, arr, i);
 
    // now recur on right subtree
    BSTToMinHeap(root->right, arr, i);
}
 
// utility function to convert the given BST to
// MIN HEAP
void convertToMinHeapUtil(Node* root)
{
    // vector to store the data of all the
    // nodes of the BST
    vector<int> arr;
    int i = -1;
 
    // inorder traversal to populate 'arr'
    inorderTraversal(root, arr);
 
    // BST to MIN HEAP conversion
    BSTToMinHeap(root, arr, &i);
}
 
// function for the preorder traversal of the tree
void preorderTraversal(Node* root)
{
    if (!root)
        return;
 
    // first print the root's data
    cout << root->data << " ";
 
    // then recur on left subtree
    preorderTraversal(root->left);
 
    // now recur on right subtree
    preorderTraversal(root->right);
}
 
// Driver program to test above
int main()
{
    // BST formation
    struct Node* root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
 
    // Function call
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
 
    return 0;
}





//  TWO BINARY TREE IDENTICAL



#include <iostream>
using namespace std;
 
// BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
 
// Utility function to create a new Node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)
        malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
}
 
// Function to perform inorder traversal
void inorder(Node* root)
{
    if (root == NULL)
        return;
 
    inorder(root->left);
 
    cout << root->data << " ";
 
    inorder(root->right);
}
 
// Function to check if two BSTs
// are identical
int isIdentical(Node* root1, Node* root2)
{
    // Check if both the trees are empty
    if (root1 == NULL && root2 == NULL)
        return 1;
    // If any one of the tree is non-empty
    // and other is empty, return false
    else if (root1 == NULL || root2 == NULL)
        return 0;
    else { // Check if current data of both trees equal
        // and recursively check for left and right subtrees
        if (root1->data == root2->data && isIdentical(root1->left, root2->left)
            && isIdentical(root1->right, root2->right))
            return 1;
        else
            return 0;
    }
}
 
// Driver code
int main()
{
    struct Node* root1 = newNode(5);
    struct Node* root2 = newNode(5);
    root1->left = newNode(3);
    root1->right = newNode(8);
    root1->left->left = newNode(2);
    root1->left->right = newNode(4);
 
    root2->left = newNode(3);
    root2->right = newNode(8);
    root2->left->left = newNode(2);
    root2->left->right = newNode(4);
 
    if (isIdentical(root1, root2))
        cout << "Both BSTs are identical";
    else
        cout << "BSTs are not identical";
 
    return 0;
}




// 

