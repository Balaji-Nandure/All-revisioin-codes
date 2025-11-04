/*
    1) Convert a BST into a balanced BST.

    Approach Used:
    ---------------
    - The idea is to first store the inorder traversal of the BST in a vector.
      (Inorder traversal of BST gives sorted order of elements.)
    - Then, recursively build a balanced BST from the sorted vector by always choosing the middle element as the root.
    - This ensures the height of the tree is minimized (i.e., the tree is balanced).

    Code with Comments:
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Inorder traversal to store nodes in sorted order
void storeInorder(Node* root, vector<int>& inorder) {
    if (!root) return;
    storeInorder(root->left, inorder);      // Traverse left subtree
    inorder.push_back(root->data);          // Store current node's data
    storeInorder(root->right, inorder);     // Traverse right subtree
}

// Function to build balanced BST from sorted vector
Node* buildBalancedBST(vector<int>& inorder, int start, int end) {
    if (start > end) return NULL;           // Base case: no elements to form a node
    int mid = (start + end) / 2;            // Choose middle element for balance
    Node* root = new Node(inorder[mid]);    // Create node with middle element
    root->left = buildBalancedBST(inorder, start, mid - 1);   // Recursively build left subtree
    root->right = buildBalancedBST(inorder, mid + 1, end);    // Recursively build right subtree
    return root;                            // Return root of balanced subtree
}

// Main function to convert BST to balanced BST
Node* convertToBalancedBST(Node* root) {
    vector<int> inorder;
    storeInorder(root, inorder);            // Step 1: Get sorted order of elements
    return buildBalancedBST(inorder, 0, inorder.size() - 1);  // Step 2: Build balanced BST
}

/*
    Better Alternatives:
    --------------------
    1. If you want to avoid using extra space for the inorder vector, you can use a linked list and build the BST in O(n) time and O(1) space (excluding recursion stack).
    2. For very large trees, consider iterative inorder traversal to avoid stack overflow.
    3. If the BST is huge and cannot fit in memory, consider external memory algorithms.

    Alternative Approach (O(1) extra space, using DLL):
    ---------------------------------------------------
    // Convert BST to sorted DLL, then build balanced BST from DLL in O(n) time.
    // See: https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/

    // Example code for DLL approach (not shown here for brevity).

    Dry Run Example:
    ----------------
    Input BST:         10
                      /  \
                     8    15
                    /      \
                   7        20

    Inorder Traversal: 7 8 10 15 20

    Build Balanced BST:
    - Middle element is 10 (root)
    - Left subtree: 7 8 (mid=7, left child), 8 (right child of 7)
    - Right subtree: 15 20 (mid=15, right child), 20 (right child of 15)

    Resulting Balanced BST:
            10
           /  \
          8    15
         /      \
        7        20

    (In this case, the tree is already almost balanced, but for skewed trees, this approach will significantly reduce height.)
*/
