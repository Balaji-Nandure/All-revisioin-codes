/*
Approach Used:
---------------
- The code implements a Binary Search Tree (BST) and provides functions to insert nodes, and to find the minimum and maximum values in the BST.
- The minimum value in a BST is found by traversing to the leftmost node, and the maximum by traversing to the rightmost node.
- Input is taken until -1 is entered, and each value is inserted into the BST.

Better Alternatives:
--------------------
1. Iterative insertion can be used instead of recursion to avoid stack overflow for skewed trees.
2. For finding min/max, recursive approach can also be used.
3. Error handling for empty input can be improved.
4. Use nullptr instead of NULL (C++11 onwards).
5. Use smart pointers for better memory management (not shown here for simplicity).

Alternative code for finding min recursively:
---------------------------------------------
int findMinRecursive(Node* root) {
    if (root == nullptr) return -1;
    if (root->left == nullptr) return root->data;
    return findMinRecursive(root->left);
}

Alternative code for insertion (iterative):
-------------------------------------------
Node* insertIntoBSTIterative(Node* root, int data) {
    Node* newNode = new Node(data);
    if (!root) return newNode;
    Node* curr = root;
    Node* parent = nullptr;
    while (curr) {
        parent = curr;
        if (data < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;
    return root;
}
*/

// Include necessary headers
#include<iostream>
#include<queue>
using namespace std;

// Node class for BST
class Node{
    public:
        int data;           // Value of the node
        Node* left;         // Pointer to left child
        Node* right;        // Pointer to right child

        // Constructor to initialize node with data and null children
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// Recursive function to insert a value into BST
Node* insertIntoBST(Node* root, int data){
    // If tree is empty, create a new node and return as root
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    // If data is less than root's data, insert into left subtree
    if(root->data > data){
        root->left = insertIntoBST(root->left, data);
    }
    // If data is greater or equal, insert into right subtree
    else{
        root->right = insertIntoBST(root->right, data);
    }
    // Return the unchanged root pointer
    return root;
}

// Function to take input from user and build BST
void takeInput(Node* &root){
    int data;
    cin >> data; // Read first data
    while(data != -1){ // Continue until -1 is entered
        root = insertIntoBST(root, data); // Insert data into BST
        cin >> data; // Read next data
    }
}

// Function to find minimum value in BST (leftmost node)
int findMin(Node* root){
    Node* temp = root;
    if(temp == NULL)
        return -1; // Return -1 if tree is empty
    // Traverse to the leftmost node
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data; // Return data of leftmost node
}

// Function to find maximum value in BST (rightmost node)
int findMax(Node* root){
    Node* temp = root;
    if(temp == NULL)
        return -1; // Return -1 if tree is empty
    // Traverse to the rightmost node
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data; // Return data of rightmost node
}

int main(){
    Node* root = NULL; // Initialize root of BST as NULL

    cout << "Enter the data for Node (enter -1 to stop):" << endl;
    takeInput(root); // Build BST from user input

    int minValue = findMin(root); // Find minimum value in BST
    cout << "Minimum value = " << minValue << endl;

    int maxValue = findMax(root); // Find maximum value in BST
    cout << "Maximum value = " << maxValue << endl;

    return 0;
}

/*
Dry Run Example:
----------------
Input: 5 3 7 2 4 8 -1

Step-by-step BST construction:
1. Insert 5: root = 5
2. Insert 3: 3 < 5, go left -> root->left = 3
3. Insert 7: 7 > 5, go right -> root->right = 7
4. Insert 2: 2 < 5, go left; 2 < 3, go left -> root->left->left = 2
5. Insert 4: 4 < 5, go left; 4 > 3, go right -> root->left->right = 4
6. Insert 8: 8 > 5, go right; 8 > 7, go right -> root->right->right = 8

BST Structure:
        5
       / \
      3   7
     / \   \
    2   4   8

findMin: Traverse left from 5 -> 3 -> 2 (leftmost), so min = 2
findMax: Traverse right from 5 -> 7 -> 8 (rightmost), so max = 8

Output:
Minimum value = 2
Maximum value = 8
*/