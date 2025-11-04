#include<iostream>
#include<queue>
#include<climits>
using namespace std;

/*
    Approach Used in the Code:
    --------------------------
    The code checks if a given binary tree is a Max-Heap or not.
    - It recursively checks for each node:
        1. If the left and right subtrees are heaps.
        2. If the current node's value is greater than its children's values.
    - It returns a pair: (isHeap, maxValueInSubtree).
    - The function is called for the root node.

    Limitations:
    ------------
    - This code only checks the heap property (parent > children) but does NOT check if the tree is a Complete Binary Tree (CBT), which is also required for a valid heap.
    - So, this code only partially checks if a tree is a heap.

    Better Alternative Approach:
    ---------------------------
    1. Check if the tree is a Complete Binary Tree (CBT).
    2. Check if the tree satisfies the heap property (parent >= children).
    Both conditions must be true for a tree to be a heap.

    See detailed alternative approach and code at the end of this file.
*/

// Node class for binary tree
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

/*
    Function: solve
    ---------------
    Checks if the subtree rooted at 'root' satisfies the max-heap property.
    Returns a pair:
        - first: true if subtree is heap, false otherwise
        - second: value of current node (used for comparison)
*/
pair<bool,int>solve(Node* root){
    // Base Case: If node is NULL, it's a valid heap (empty tree)
    if(root == NULL){
        pair<bool,int>p = make_pair(true,INT_MIN);
        return p;
    }
    // Leaf Node: A single node is always a heap
    if(root->left == NULL && root->right == NULL){
        pair<bool,int>p = make_pair(true,root->data);
        return p;
    }
    // Recursively check left and right subtrees
    pair<bool,int> leftAns = solve(root->left);
    pair<bool,int> rightAns = solve(root->right);

    // Check heap property: 
    // 1. Both left and right subtrees are heaps
    // 2. Current node's data is greater than both children's data
    if(leftAns.first && rightAns.first && 
       (root->left == NULL || root->data >= leftAns.second) && 
       (root->right == NULL || root->data >= rightAns.second)){
        pair<bool,int>p = make_pair(true,root->data);
        return p;
    }
    else{
        pair<bool,int>p = make_pair(false,root->data);
        return p;
    }
}

int main(){
    /*
        // Example usage:
        Node* root = new Node(10);
        root->left = new Node(9);
        root->right = new Node(8);
        root->left->left = new Node(7);
        root->left->right = new Node(6);
        root->right->left = new Node(5);

        pair<bool,int> result = solve(root);
        if(result.first)
            cout << "Heap property is satisfied (but CBT not checked!)" << endl;
        else
            cout << "Heap property is NOT satisfied" << endl;
    */
    return 0;
}

/*
    -------------------------------
    Better Alternative Approach:
    -------------------------------
    // 1. Check if the tree is a Complete Binary Tree (CBT)
    // 2. Check if the tree satisfies the heap property

    // Function to count total nodes
    int countNodes(Node* root) {
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Function to check if tree is CBT
    bool isCBT(Node* root, int index, int totalNodes) {
        if(!root) return true;
        if(index >= totalNodes) return false;
        return isCBT(root->left, 2*index+1, totalNodes) && isCBT(root->right, 2*index+2, totalNodes);
    }

    // Function to check heap property
    bool isMaxHeap(Node* root) {
        // Leaf node
        if(!root->left && !root->right) return true;
        // Only left child
        if(root->left && !root->right)
            return (root->data >= root->left->data) && isMaxHeap(root->left);
        // Both children
        if(root->left && root->right)
            return (root->data >= root->left->data) && (root->data >= root->right->data) &&
                   isMaxHeap(root->left) && isMaxHeap(root->right);
        // Only right child (invalid for CBT)
        return false;
    }

    // Main function to check if tree is heap
    bool isHeap(Node* root) {
        int totalNodes = countNodes(root);
        return isCBT(root, 0, totalNodes) && isMaxHeap(root);
    }

    // Usage:
    // if(isHeap(root)) cout << "Tree is a Heap" << endl;
    // else cout << "Tree is NOT a Heap" << endl;

    -------------------------------------------------
    Dry Run Example:
    -------------------------------------------------
    Tree:
            10
           /  \
          9    8
         / \  /
        7  6 5

    - countNodes(root) = 6
    - isCBT(root, 0, 6): returns true (all indices < 6)
    - isMaxHeap(root): returns true (all parent >= children)
    => isHeap(root) = true

    If you remove node 5 (right child of 8), isCBT will return false (not complete).
*/