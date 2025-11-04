/*
    Approach Used:
    ----------------
    - The code implements a Binary Search Tree (BST) with insertion and search functionalities.
    - Nodes are inserted such that for any node, all elements in the left subtree are less, and all in the right are greater.
    - Searching leverages the BST property to efficiently find a target value.
    - Input is taken until -1 is entered.
    - The code checks if the value 1000 exists in the BST.

    Better Alternatives:
    --------------------
    1. Iterative search instead of recursive (to avoid stack overflow for skewed trees).
    2. Iterative insertion (for the same reason).
    3. Level order traversal for debugging/visualization.
    4. Use of smart pointers for memory management (advanced).
    5. Self-balancing BSTs (like AVL/Red-Black) for guaranteed O(log n) operations.

    See detailed alternative code and dry run at the end.
*/

#include<iostream>
#include<queue>
using namespace std;

// Node class for BST
class Node{
    public:
        int data;       // Value of the node
        Node* left;     // Pointer to left child
        Node* right;    // Pointer to right child
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

// Function to take input and build BST until -1 is entered
void takeInput(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Recursive function to search for a target value in BST
bool findNode(Node* root, int target){
    // If root is NULL, target not found
    if(root == NULL)
        return false;
    // If current node matches target, return true
    if(root->data == target)
        return true;
    // If target is less, search in left subtree
    else if(root->data > target){
        return findNode(root->left, target);
    }
    // If target is greater, search in right subtree
    else{
        return findNode(root->right, target);
    }
}

int main(){
    Node* root = NULL; // Initialize root pointer
    cout << "Enter the data for Node (end with -1):" << endl;
    takeInput(root);   // Build BST from user input

    // Search for value 1000 in BST
    if(findNode(root, 1000)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    return 0;
}

/*
    -------------------------------
    Alternative: Iterative Search
    -------------------------------
    // This avoids recursion and is more stack-safe for large/skewed trees.
    bool findNodeIterative(Node* root, int target){
        while(root != NULL){
            if(root->data == target)
                return true;
            else if(root->data > target)
                root = root->left;
            else
                root = root->right;
        }
        return false;
    }

    -------------------------------
    Alternative: Iterative Insertion
    -------------------------------
    Node* insertIntoBSTIterative(Node* root, int data){
        Node* newNode = new Node(data);
        if(root == NULL)
            return newNode;
        Node* parent = NULL;
        Node* curr = root;
        while(curr != NULL){
            parent = curr;
            if(data < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if(data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
        return root;
    }

    -------------------------------
    Dry Run Example
    -------------------------------
    Input: 5 3 7 2 4 6 8 -1

    BST Structure:
            5
           / \
          3   7
         / \ / \
        2  4 6  8

    Search for 1000:
    - 1000 > 5 -> right to 7
    - 1000 > 7 -> right to 8
    - 1000 > 8 -> right to NULL
    - NULL reached, return false ("Not found")

    Search for 4:
    - 4 < 5 -> left to 3
    - 4 > 3 -> right to 4
    - 4 == 4 -> found ("Found")
*/