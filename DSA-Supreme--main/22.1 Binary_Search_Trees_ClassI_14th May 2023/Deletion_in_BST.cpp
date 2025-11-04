/*
    Approach Used:
    ----------------
    - This code implements a Binary Search Tree (BST) with insertion, level order traversal, and deletion operations.
    - The deletion operation handles all three cases: deleting a leaf node, a node with one child, and a node with two children (using inorder predecessor).
    - The code is modular, with separate functions for each operation.

    Better Alternatives:
    --------------------
    1. For deletion, instead of using the inorder predecessor (max in left subtree), we can also use the inorder successor (min in right subtree).
    2. For insertion, an iterative approach can be used to avoid recursion stack overhead.
    3. For level order traversal, we can use a vector of vectors to return the result instead of printing directly.
    4. For deletion, we should free the memory of the deleted node to avoid memory leaks (especially in C++).

    Alternative Deletion using Inorder Successor:
    ---------------------------------------------
    // int findMin(Node* root) {
    //     Node* temp = root;
    //     while (temp && temp->left != NULL) {
    //         temp = temp->left;
    //     }
    //     return temp ? temp->data : -1;
    // }
    // Node* deleteNodeInBST(Node* root, int target) {
    //     if (!root) return root;
    //     if (root->data == target) {
    //         if (!root->left && !root->right) {
    //             delete root;
    //             return NULL;
    //         } else if (!root->left) {
    //             Node* temp = root->right;
    //             delete root;
    //             return temp;
    //         } else if (!root->right) {
    //             Node* temp = root->left;
    //             delete root;
    //             return temp;
    //         } else {
    //             int inorderSucc = findMin(root->right);
    //             root->data = inorderSucc;
    //             root->right = deleteNodeInBST(root->right, inorderSucc);
    //         }
    //     } else if (root->data < target) {
    //         root->right = deleteNodeInBST(root->right, target);
    //     } else {
    //         root->left = deleteNodeInBST(root->left, target);
    //     }
    //     return root;
    // }

    Dry Run Example:
    -----------------
    Input: 50 30 70 20 40 60 80 -1
    Delete: 50
    BST before deletion (level order):
    50
    30 70
    20 40 60 80

    After deleting 50 (root with two children, replaced by 40):
    40
    30 70
    20 60 80

    Each step is explained in comments below.
*/

#include <iostream>
#include <queue>
using namespace std;

// Node class for BST
class Node
{
public:
    int data;       // Value of the node
    Node *left;     // Pointer to left child
    Node *right;    // Pointer to right child

    // Constructor to initialize node with data
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Recursive function to insert a value into BST
Node *insertIntoBST(Node *root, int data)
{
    // If tree is empty, create a new node and return as root
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    // If data is less than root, insert into left subtree
    if (root->data > data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    // If data is greater or equal, insert into right subtree
    else
    {
        root->right = insertIntoBST(root->right, data);
    }
    return root; // Return the unchanged root pointer
}

// Function to take input from user and build BST
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    // Keep reading until -1 is entered
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Function to print the BST level by level (BFS)
void levelOrderTraversal(Node *root)
{
    // If tree is empty, nothing to print
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q; // Queue for BFS
    q.push(root);    // Start with root
    q.push(NULL);    // Level marker

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // End of current level
            cout << endl;
            // If more nodes are present, add level marker for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " "; // Print current node

            // If left child exists, add to queue
            if (temp->left)
            {
                q.push(temp->left);
            }
            // If right child exists, add to queue
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Function to find a node with given target value in BST
Node *findNode(Node *root, int target)
{
    // Base case: not found
    if (root == NULL)
        return NULL;
    // If current node matches target, return it
    if (root->data == target)
        return root;
    // If target is less, search in left subtree
    else if (root->data > target)
    {
        return findNode(root->left, target);
    }
    // If target is greater, search in right subtree
    else
    {
        return findNode(root->right, target);
    }
}

// Function to find maximum value in a BST (rightmost node)
int findMax(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
        return -1; // Tree is empty
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp->data;
}

// Function to delete a node with given target value from BST
Node *deleteNodeInBST(Node *root, int target)
{
    // Base case: tree is empty
    if (root == NULL)
    {
        return root;
    }

    if (root->data == target)
    {
        // Case 1: Node is a leaf (no children)
        if (root->left == NULL && root->right == NULL)
        {
            delete root; // Free memory
            return NULL;
        }
        // Case 2: Node has only right child
        else if (root->left == NULL && root->right != NULL)
        {
            Node *child = root->right;
            delete root; // Free memory
            return child;
        }
        // Case 3: Node has only left child
        else if (root->left != NULL && root->right == NULL)
        {
            Node *child = root->left;
            delete root; // Free memory
            return child;
        }
        // Case 4: Node has two children
        else
        {
            // Find inorder predecessor (max in left subtree)
            int inorderPred = findMax(root->left);
            root->data = inorderPred; // Replace data
            // Recursively delete the predecessor node
            root->left = deleteNodeInBST(root->left, inorderPred);
            return root;
        }
    }
    else if (root->data < target)
    {
        // Target is greater, search in right subtree
        root->right = deleteNodeInBST(root->right, target);
    }
    else
    {
        // Target is smaller, search in left subtree
        root->left = deleteNodeInBST(root->left, target);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the data for Node (end with -1):" << endl;
    takeInput(root); // Build BST from user input

    cout << "Enter value to delete: ";
    int delVal;
    cin >> delVal;

    // Delete the node with value delVal
    root = deleteNodeInBST(root, delVal);

    cout << "Level Order Traversal after deletion:" << endl;
    levelOrderTraversal(root);

    return 0;
}

/*
    Dry Run Example:
    -----------------
    Input: 50 30 70 20 40 60 80 -1
    Delete: 50

    BST before deletion (level order):
    50
    30 70
    20 40 60 80

    Deletion Steps:
    - 50 has two children.
    - Find inorder predecessor: max in left subtree (40).
    - Replace 50 with 40.
    - Delete 40 from left subtree.

    BST after deletion:
    40
    30 70
    20 60 80

    Output:
    Enter the data for Node (end with -1):
    50 30 70 20 40 60 80 -1
    Enter value to delete: 50
    Level Order Traversal after deletion:
    40 
    30 70 
    20 60 80 
*/