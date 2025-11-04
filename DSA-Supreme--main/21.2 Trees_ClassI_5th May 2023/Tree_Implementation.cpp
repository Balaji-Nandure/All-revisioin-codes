/*
    Approach Used:
    ----------------
    - The code implements a binary tree using a recursive approach.
    - The tree is built by taking user input for each node and its left/right children.
    - The value -1 is used as a sentinel to indicate the absence of a child (i.e., a NULL pointer).
    - The buildTree function is called recursively to construct the left and right subtrees.

    Better Alternatives:
    --------------------
    1. **Level Order (Iterative) Construction**:
        - Instead of recursive input, we can use a queue to build the tree level by level.
        - This is more user-friendly and avoids deep recursion.
        - See commented code at the end for this approach.

    2. **Input from Array or String**:
        - For automated testing, input can be taken from an array or string (preorder with -1 as NULL).
        - This avoids manual input and is useful for coding platforms.

    3. **Error Handling**:
        - Add input validation to handle invalid or non-integer input.

    4. **Memory Management**:
        - Add a function to delete/free the tree to avoid memory leaks.

    Dry Run Example:
    -----------------
    Input:
        Enter data for root node
        1
        Enter the data for left child of 1
        2
        Enter the data for left child of 2
        -1
        Enter the data for right child of 2
        -1
        Enter the data for right child of 1
        3
        Enter the data for left child of 3
        -1
        Enter the data for right child of 3
        -1

    Output: (Tree Structure)
            1
           / \
          2   3

*/

#include <iostream>
using namespace std;

// Node class represents a single node in the binary tree
class Node
{
public:
    int data;       // Stores the value of the node
    Node *left;     // Pointer to the left child
    Node *right;    // Pointer to the right child

    // Constructor to initialize node with data and set children to NULL
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Recursive function to build the binary tree from user input
Node *buildTree(int data)
{
    // Base Case: If data is -1, this position is NULL (no node)
    if (data == -1)
    {
        return NULL;
    }

    // Create a new node with the given data
    Node *root = new Node(data);

    // Input for left child
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    // Recursively build the left subtree
    root->left = buildTree(leftData);

    // Input for right child
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    // Recursively build the right subtree
    root->right = buildTree(rightData);

    // Return the constructed subtree rooted at 'root'
    return root;
}

int main()
{
    Node *root; // Pointer to the root of the tree
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    // Build the tree starting from the root
    root = buildTree(data);

    // (Optional) You can add code here to traverse or print the tree

    // (Optional) Free memory by deleting the tree (not implemented here)

    return 0;
}

/*
    -------------------------------
    Alternative: Level Order Build
    -------------------------------
    // #include <queue>
    // Node* buildTreeLevelOrder() {
    //     int data;
    //     cout << "Enter data for root node" << endl;
    //     cin >> data;
    //     if (data == -1) return NULL;
    //     Node* root = new Node(data);
    //     queue<Node*> q;
    //     q.push(root);
    //     while (!q.empty()) {
    //         Node* curr = q.front(); q.pop();
    //         int leftData, rightData;
    //         cout << "Enter left child of " << curr->data << endl;
    //         cin >> leftData;
    //         if (leftData != -1) {
    //             curr->left = new Node(leftData);
    //             q.push(curr->left);
    //         }
    //         cout << "Enter right child of " << curr->data << endl;
    //         cin >> rightData;
    //         if (rightData != -1) {
    //             curr->right = new Node(rightData);
    //             q.push(curr->right);
    //         }
    //     }
    //     return root;
    // }
*/

/*
    Dry Run:
    --------
    Input:
        Enter data for root node
        1
        Enter the data for left child of 1
        2
        Enter the data for left child of 2
        -1
        Enter the data for right child of 2
        -1
        Enter the data for right child of 1
        3
        Enter the data for left child of 3
        -1
        Enter the data for right child of 3
        -1

    Steps:
    - root = 1
    - left child of 1 = 2
        - left child of 2 = -1 (NULL)
        - right child of 2 = -1 (NULL)
    - right child of 1 = 3
        - left child of 3 = -1 (NULL)
        - right child of 3 = -1 (NULL)

    Final Tree:
            1
           / \
          2   3
*/