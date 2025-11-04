/*
    Approach Used:
    ----------------
    - The code builds a binary tree from user input using recursion.
    - It then performs an inorder traversal (Left, Node, Right) recursively.
    - The tree is built such that entering -1 means the current child is NULL (leaf node).
    - The code is interactive: it prompts the user for each node's left and right child.

    Better Alternatives:
    --------------------
    1. **Level Order Build (Iterative):**
        - Instead of recursive input, use a queue to build the tree level by level.
        - This is more user-friendly for large trees and avoids deep recursion.
        - See commented code at the end for this approach.

    2. **Iterative Inorder Traversal:**
        - Use a stack to avoid recursion for inorder traversal.
        - Useful for very deep trees to avoid stack overflow.
        - See commented code at the end for this approach.

    3. **Input as Array:**
        - Accept the tree as an array (like heap representation) for easier automated testing.

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

    Tree built:
            1
           / \
          2   3

    Output (Inorder): 2 1 3

*/

// Include necessary header
#include <iostream>
using namespace std;

// Node class represents each node in the binary tree
class Node
{
public:
    int data;       // Data stored in the node
    Node *left;     // Pointer to left child
    Node *right;    // Pointer to right child

    // Constructor to initialize node with data and set children to NULL
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build the binary tree recursively from user input
Node *buildTree(int data)
{
    // Base Case: If data is -1, this position is a NULL node (no child)
    if (data == -1)
    {
        return NULL;
    }

    // Create a new node with the given data
    Node *root = new Node(data);

    // Recursively build the left subtree
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);

    // Recursively build the right subtree
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);

    // Return the constructed subtree rooted at 'root'
    return root;
}

// Function to perform inorder traversal (Left, Node, Right) recursively
void inorderTraversal(Node* root){
    // Base Case: If node is NULL, do nothing
    if(root == NULL){
        return;
    }
    // Traverse left subtree
    inorderTraversal(root->left);

    // Visit current node (print data)
    cout<<root->data<<" ";

    // Traverse right subtree
    inorderTraversal(root->right);
}

int main()
{
    Node *root; // Pointer to root node
    int data;

    // Prompt user for root node data
    cout << "Enter data for root node" << endl;
    cin >> data;

    // Build the tree recursively
    root = buildTree(data);

    // Print inorder traversal of the tree
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

/*
-------------------------------
Better Alternative Approaches:
-------------------------------

1. Iterative Inorder Traversal (using stack):

#include <stack>
void inorderIterative(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

2. Level Order Build (using queue):

#include <queue>
Node* buildTreeLevelOrder() {
    int data;
    cout << "Enter data for root node: ";
    cin >> data;
    if (data == -1) return NULL;
    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        int leftData, rightData;
        cout << "Enter left child of " << curr->data << ": ";
        cin >> leftData;
        if (leftData != -1) {
            curr->left = new Node(leftData);
            q.push(curr->left);
        }
        cout << "Enter right child of " << curr->data << ": ";
        cin >> rightData;
        if (rightData != -1) {
            curr->right = new Node(rightData);
            q.push(curr->right);
        }
    }
    return root;
}

-------------------------------
Dry Run Example:
-------------------------------
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

Tree Structure:
        1
       / \
      2   3

Inorder Traversal Steps:
    - Traverse left of 1 -> Node 2
    - Traverse left of 2 -> NULL (return)
    - Print 2
    - Traverse right of 2 -> NULL (return)
    - Print 1
    - Traverse right of 1 -> Node 3
    - Traverse left of 3 -> NULL (return)
    - Print 3
    - Traverse right of 3 -> NULL (return)

Output:
    Inorder Traversal: 2 1 3

*/