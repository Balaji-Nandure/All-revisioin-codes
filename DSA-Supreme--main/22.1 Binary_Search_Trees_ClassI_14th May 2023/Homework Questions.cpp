/*
    1) Code inorder predecessor and successor in BST.

    Approach Used:
    - To find the inorder predecessor and successor of a given key in a BST, we utilize the BST property:
      * All nodes in the left subtree are less than the root.
      * All nodes in the right subtree are greater than the root.
    - We traverse the tree:
      * If the current node's value is less than the key, it could be a predecessor, so we move right.
      * If the current node's value is greater than the key, it could be a successor, so we move left.
      * If the current node's value is equal to the key:
        - The predecessor is the rightmost node in the left subtree (if exists).
        - The successor is the leftmost node in the right subtree (if exists).

    Better Alternatives:
    - Iterative approach (as below) is efficient (O(h) time, O(1) space).
    - Recursive approach is also possible but may use more stack space.
    - If multiple queries are to be answered, augmenting BST with parent pointers or using threaded BST can be considered.

    Dry Run Example:
    BST:         20
               /    \
             10      30
            /  \    /  \
           5   15  25  35
    Key = 20
    - Predecessor: 15 (max in left subtree)
    - Successor: 25 (min in right subtree)
*/

#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to find predecessor and successor
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
    pre = NULL;
    suc = NULL;
    Node* curr = root;

    // Traverse the tree to find the key and update pre/suc accordingly
    while (curr) {
        if (curr->data == key) {
            // If left subtree exists, predecessor is rightmost node of left subtree
            if (curr->left) {
                Node* temp = curr->left;
                while (temp->right)
                    temp = temp->right;
                pre = temp;
            }
            // If right subtree exists, successor is leftmost node of right subtree
            if (curr->right) {
                Node* temp = curr->right;
                while (temp->left)
                    temp = temp->left;
                suc = temp;
            }
            break;
        }
        else if (curr->data > key) {
            // Current node could be successor, move to left subtree
            suc = curr;
            curr = curr->left;
        }
        else {
            // Current node could be predecessor, move to right subtree
            pre = curr;
            curr = curr->right;
        }
    }
}

/*
Alternative Recursive Approach:
void findPreSucRec(Node* root, Node*& pre, Node*& suc, int key) {
    if (!root) return;
    if (root->data == key) {
        if (root->left) {
            Node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }
        if (root->right) {
            Node* temp = root->right;
            while (temp->left)
                temp = temp->left;
            suc = temp;
        }
    }
    else if (root->data > key) {
        suc = root;
        findPreSucRec(root->left, pre, suc, key);
    }
    else {
        pre = root;
        findPreSucRec(root->right, pre, suc, key);
    }
}
*/

// Dry Run Example:
// For key = 20 in the above BST:
// - Start at root (20): matches key.
// - Predecessor: rightmost in left subtree (15).
// - Successor: leftmost in right subtree (25).
// Output: Predecessor = 15, Successor = 25
