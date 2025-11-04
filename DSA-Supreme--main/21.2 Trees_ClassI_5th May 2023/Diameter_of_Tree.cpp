/*

    Approach: 
    -----------
    The code builds a binary tree from user input (using -1 as a sentinel for NULL/leaf) and computes the diameter of the tree.
    The diameter of a binary tree is the length (number of nodes/edges) of the longest path between any two nodes in the tree.
    This path may or may not pass through the root.

    The code uses a naive recursive approach:
    - For each node, it computes:
        1. The diameter in the left subtree.
        2. The diameter in the right subtree.
        3. The path passing through the root (height of left + height of right).
    - The answer is the maximum of these three.

    Time Complexity: O(N^2) due to repeated height calculations.

    -----------------
    Better Alternative (Optimal Approach):
    -----------------
    We can compute the diameter and height in a single traversal using post-order recursion.
    This reduces the time complexity to O(N).

    // Optimal Approach Code (commented for reference):

    /*
    int diameterOpt(Node* root, int& diameter) {
        if (!root) return 0;
        int lh = diameterOpt(root->left, diameter);
        int rh = diameterOpt(root->right, diameter);
        diameter = max(diameter, lh + rh); // update diameter if needed
        return 1 + max(lh, rh); // return height
    }
    // Usage:
    int diameter = 0;
    diameterOpt(root, diameter);
    cout << "Diameter: " << diameter << endl;
    */

    -----------------
    Dry Run Example:
    -----------------
    Input:
        Enter data for root node
        1
        Enter the data for left child of 1
        2
        Enter the data for left child of 2
        4
        Enter the data for left child of 4
        -1
        Enter the data for right child of 4
        -1
        Enter the data for right child of 2
        5
        Enter the data for left child of 5
        -1
        Enter the data for right child of 5
        -1
        Enter the data for right child of 1
        3
        Enter the data for left child of 3
        -1
        Enter the data for right child of 3
        -1

    Tree:
            1
           / \
          2   3
         / \
        4   5

    Diameter: 3 (Path: 4-2-1-3 or 5-2-1-3)

*/

#include <iostream>
using namespace std;

// Node class for binary tree
class Node
{
public:
    int data;       // value of the node
    Node *left;     // pointer to left child
    Node *right;    // pointer to right child

    // Constructor to initialize node with data and null children
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build binary tree from user input (preorder, -1 for NULL)
Node *buildTree(int data)
{
    // Base Case: -1 means no node (NULL)
    if (data == -1)
    {
        return NULL;
    }

    // Create the root node with given data
    Node *root = new Node(data);

    // Recursively build left subtree
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);

    // Recursively build right subtree
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);

    // Return constructed subtree root
    return root;
}

// Function to compute height of a binary tree rooted at 'root'
int height(Node* root){
    // Base case: empty tree has height 0
    if(root == NULL){
        return 0;
    }
    // Recursively compute left and right subtree heights
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Height is max of left/right subtree + 1 (for current node)
    int ans = max(leftHeight, rightHeight) + 1;
    return ans;
}

// Naive O(N^2) function to compute diameter of binary tree
int diameterBinaryTree(Node* root){
    // Base case: empty tree has diameter 0
    if(root == NULL){
        return 0;
    }
    // Compute diameter in left subtree
    int op1 = diameterBinaryTree(root->left);

    // Compute diameter in right subtree
    int op2 = diameterBinaryTree(root->right);

    // Compute diameter passing through root (left height + right height)
    int op3 = height(root->left) + height(root->right);

    // Return the maximum of the three options
    int ans = max(op1, max(op2, op3));
    return ans;
}

/*
    // Optimal O(N) approach: Compute diameter and height in one traversal
    int diameterOpt(Node* root, int& diameter) {
        if (!root) return 0;
        int lh = diameterOpt(root->left, diameter);
        int rh = diameterOpt(root->right, diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
*/

int main()
{
    Node *root;
    int data;

    // Prompt user for root node data
    cout << "Enter data for root node" << endl;
    cin >> data;

    // Build the binary tree from user input
    root = buildTree(data);

    // Compute and print the diameter using naive approach
    int dia = diameterBinaryTree(root);
    cout << "Diameter of the tree (naive O(N^2) approach): " << dia << endl;

    // Uncomment below for optimal approach
    /*
    int diameter = 0;
    diameterOpt(root, diameter);
    cout << "Diameter of the tree (optimal O(N) approach): " << diameter << endl;
    */

    return 0;
}

/*
    Dry Run Example:
    -----------------
    Input:
        Enter data for root node
        1
        Enter the data for left child of 1
        2
        Enter the data for left child of 2
        4
        Enter the data for left child of 4
        -1
        Enter the data for right child of 4
        -1
        Enter the data for right child of 2
        5
        Enter the data for left child of 5
        -1
        Enter the data for right child of 5
        -1
        Enter the data for right child of 1
        3
        Enter the data for left child of 3
        -1
        Enter the data for right child of 3
        -1

    Tree:
            1
           / \
          2   3
         / \
        4   5

    Diameter: 3 (Path: 4-2-1-3 or 5-2-1-3)
*/
