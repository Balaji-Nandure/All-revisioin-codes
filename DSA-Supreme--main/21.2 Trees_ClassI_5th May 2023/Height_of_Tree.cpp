/*
    Approach:
    ---------
    This code builds a binary tree from user input (using -1 as a sentinel for NULL/leaf) and computes the height of the tree using a simple recursive approach.

    - The height of a binary tree is the number of nodes on the longest path from the root node down to the farthest leaf node.
    - The code uses recursion to compute the height of left and right subtrees, and returns the maximum of the two plus one (for the current node).

    Alternatives (with code in comments):
    -------------------------------------
    1. **Level Order Traversal (BFS) Approach** (Iterative, using queue):
        - This approach uses a queue to traverse the tree level by level and counts the number of levels.
        - Time Complexity: O(N), Space Complexity: O(N)
        - Useful for very deep trees to avoid stack overflow.

        // Iterative BFS approach for height
        #include <queue>
        int heightIterative(Node* root) {
            if (!root) return 0;
            queue<Node*> q;
            q.push(root);
            int height = 0;
            while (!q.empty()) {
                int levelSize = q.size();
                for (int i = 0; i < levelSize; ++i) {
                    Node* curr = q.front(); q.pop();
                    if (curr->left) q.push(curr->left);
                    if (curr->right) q.push(curr->right);
                }
                height++;
            }
            return height;
        }

    2. **Tail Recursion/Optimized Recursion**:
        - For very deep trees, use tail recursion or increase stack size if needed.

    3. **Morris Traversal** (for inorder, not for height directly):
        - Not directly applicable for height, but useful for traversals with O(1) space.

    4. **Memoization**:
        - If the tree is immutable and height is queried multiple times, store heights in a map.

    5. **Dry Run at the end of this file.**

    ---------------------------------------------------------------
*/

#include <iostream>
using namespace std;

// Definition of a binary tree node
class Node
{
public:
    int data;       // Value of the node
    Node *left;     // Pointer to left child
    Node *right;    // Pointer to right child

    // Constructor to initialize node with data and null children
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build a binary tree from user input (preorder, -1 for NULL)
Node *buildTree(int data)
{
    // Base Case: If data is -1, this is a NULL node (no child)
    if (data == -1)
    {
        return NULL;
    }

    // Create a new node with the given data
    Node *root = new Node(data);

    // Recursively build the left subtree
    int leftData;
    cout << "Enter the data for left child of " << data << " (-1 for NULL): ";
    cin >> leftData;
    root->left = buildTree(leftData);

    // Recursively build the right subtree
    int rightData;
    cout << "Enter the data for right child of " << data << " (-1 for NULL): ";
    cin >> rightData;
    root->right = buildTree(rightData);

    // Return the constructed subtree rooted at 'root'
    return root;
}

// Recursive function to compute the height of a binary tree
int height(Node* root){
    // Base case: If the node is NULL, height is 0
    if(root == NULL){
        return 0;
    }

    // Recursively compute the height of left subtree
    int leftHeight = height(root->left);

    // Recursively compute the height of right subtree
    int rightHeight = height(root->right);

    // Height of current node = max(leftHeight, rightHeight) + 1 (for current node)
    int ans = max(leftHeight, rightHeight) + 1;

    // Return the computed height
    return ans;
}

int main()
{
    Node *root = NULL; // Initialize root pointer
    int data;

    // Prompt user for root node data
    cout << "Enter data for root node (-1 for NULL): ";
    cin >> data;

    // Build the binary tree from user input
    root = buildTree(data);

    // Compute and print the height of the binary tree
    cout << "Height of Binary Tree = " << height(root) << endl;

    // Uncomment below to use iterative approach:
    // cout << "Height of Binary Tree (Iterative) = " << heightIterative(root) << endl;

    return 0;
}

/*
    Dry Run Example:
    ----------------
    Input (user enters):
    Enter data for root node (-1 for NULL): 1
    Enter the data for left child of 1 (-1 for NULL): 2
    Enter the data for left child of 2 (-1 for NULL): 4
    Enter the data for left child of 4 (-1 for NULL): -1
    Enter the data for right child of 4 (-1 for NULL): -1
    Enter the data for right child of 2 (-1 for NULL): 5
    Enter the data for left child of 5 (-1 for NULL): -1
    Enter the data for right child of 5 (-1 for NULL): -1
    Enter the data for right child of 1 (-1 for NULL): 3
    Enter the data for left child of 3 (-1 for NULL): -1
    Enter the data for right child of 3 (-1 for NULL): -1

    The tree:
            1
           / \
          2   3
         / \
        4   5

    height(1):
        leftHeight = height(2)
            leftHeight = height(4) = 1
            rightHeight = height(5) = 1
            => max(1,1)+1 = 2
        rightHeight = height(3) = 1
        => max(2,1)+1 = 3

    Output:
    Height of Binary Tree = 3
*/