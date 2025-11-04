/*
    Approach Used: 
    --------------
    - The code constructs a binary tree from user input (using -1 as a marker for NULL/leaf nodes).
    - It then prints the boundary traversal of the binary tree in anti-clockwise direction.
    - Boundary traversal includes:
        1. Root node (if not NULL)
        2. Left boundary (excluding leaf nodes)
        3. All leaf nodes (from left to right)
        4. Right boundary (excluding leaf nodes, printed in bottom-up order)

    Why this approach:
    ------------------
    - We avoid duplicating leaf nodes by printing them separately.
    - Left and right boundaries are handled recursively, with right boundary printed after recursion to ensure bottom-up order.

    Better Alternatives:
    --------------------
    1. **Iterative Approach using Stack/Queue:**
        - Use a queue for level order traversal to collect boundary nodes.
        - Use a stack for right boundary to reverse the order.
        - This can be more efficient for very large trees (avoids deep recursion).
    2. **Single Pass DFS:**
        - Traverse the tree once, marking nodes as left boundary, right boundary, or leaf, and collect accordingly.
        - This can be more optimal in terms of traversal, but logic is more complex.

    // Alternative Iterative Approach (Pseudocode):
    /*
    void boundaryTraversalIterative(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        // Print left boundary (excluding leaves)
        Node* curr = root->left;
        while (curr) {
            if (curr->left || curr->right) cout << curr->data << " ";
            curr = curr->left ? curr->left : curr->right;
        }
        // Print all leaves
        printLeaves(root);
        // Print right boundary (excluding leaves, bottom-up)
        stack<int> s;
        curr = root->right;
        while (curr) {
            if (curr->left || curr->right) s.push(curr->data);
            curr = curr->right ? curr->right : curr->left;
        }
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
    */

    Dry Run Example:
    ----------------
    Input (preorder, -1 for NULL): 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
    Tree:
            1
           / \
          2   3
         / \   \
        4   5   6

    Boundary Traversal: 1 2 4 5 6 3

    Explanation:
    - Root: 1
    - Left boundary: 2
    - Leaf nodes: 4 5 6
    - Right boundary (bottom-up): 3

*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

// Node class for binary tree
class Node {
public:
    int data;           // Value of the node
    Node *left;         // Pointer to left child
    Node *right;        // Pointer to right child

    // Constructor to initialize node with data
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build tree recursively from user input
Node* buildTree(int data) {
    // Base case: -1 means no node (leaf's child)
    if (data == -1) {
        return NULL;
    }
    // Create the root node with given data
    Node* root = new Node(data);

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

    return root;
}

// Print the left boundary excluding leaf nodes
void printLeftBoundary(Node* root) {
    // Base case: if node is NULL, return
    if (root == NULL) return;

    // If node is not a leaf, print it
    if (root->left != NULL || root->right != NULL)
        cout << root->data << " ";

    // Prefer left child, else right child
    if (root->left)
        printLeftBoundary(root->left);
    else if (root->right)
        printLeftBoundary(root->right);
    // If leaf node, do nothing (handled in printLeaves)
}

// Print all leaf nodes (from left to right)
void printLeaves(Node* root) {
    if (root == NULL) return;

    // If node is a leaf, print it
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return;
    }
    // Recurse for left and right subtrees
    printLeaves(root->left);
    printLeaves(root->right);
}

// Print the right boundary excluding leaf nodes (bottom-up)
void printRightBoundary(Node* root) {
    if (root == NULL) return;

    // Prefer right child, else left child
    if (root->right)
        printRightBoundary(root->right);
    else if (root->left)
        printRightBoundary(root->left);

    // If node is not a leaf, print it after recursion (to get bottom-up order)
    if (root->left != NULL || root->right != NULL)
        cout << root->data << " ";
}

// Function to print the boundary traversal of the tree
void boundaryTraversal(Node* root) {
    if (root == NULL) return;

    // Print root node (always part of boundary)
    cout << root->data << " ";

    // Print left boundary (excluding root and leaves)
    if (root->left)
        printLeftBoundary(root->left);

    // Print all leaf nodes (from left to right)
    // (Leaves from left and right subtrees, but not root if it's a leaf)
    if (root->left || root->right)
        printLeaves(root);

    // Print right boundary (excluding root and leaves, in bottom-up order)
    if (root->right)
        printRightBoundary(root->right);
}

// Example input for dry run: 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
int main() {
    // Build tree from user input (root data first)
    Node* root = buildTree(10);

    // Print boundary traversal
    cout << "Boundary Traversal: ";
    boundaryTraversal(root);
    cout << endl;

    return 0;
}

/*
Dry Run Example:
----------------
Input (preorder, -1 for NULL): 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

Tree:
        1
       / \
      2   3
     / \   \
    4   5   6

Step-by-step:
- Root: 1
- Left boundary: 2
- Leaf nodes: 4 5 6
- Right boundary (bottom-up): 3

Output:
Boundary Traversal: 1 2 4 5 6 3
*/