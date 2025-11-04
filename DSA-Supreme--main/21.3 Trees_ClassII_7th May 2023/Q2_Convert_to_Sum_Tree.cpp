/*
    Approach Used:
    ----------------
    - The code builds a binary tree from user input using recursion.
    - Then, it converts the tree to a "sum tree" where each node contains the sum of the values of its left and right subtrees in the original tree (including its own value in this implementation).
    - The conversion is done using post-order traversal (left, right, root).

    Note: The classic "sum tree" problem usually sets each node's value to the sum of values of its left and right subtrees (excluding its own value). 
    The current implementation adds the node's own value as well. 
    Both approaches are shown below in comments.

    Better Alternatives:
    --------------------
    1. Classic Sum Tree (node's value = sum of left and right subtree, excluding its own value):
        int convertToSumTree(Node* &root){
            if(root == NULL) return 0;
            int old_val = root->data;
            root->data = convertToSumTree(root->left) + convertToSumTree(root->right);
            return root->data + old_val;
        }
    2. Iterative approach using post-order traversal with stack (for large trees to avoid stack overflow).
    3. Remove unnecessary global variables and use clear function/variable names.

    Dry Run Example:
    -----------------
    Input: 1 2 -1 -1 3 -1 -1
    Tree:
         1
        / \
       2   3

    convertToSumTree(root):
    - leftAns = convertToSumTree(2) => leftAns=0, rightAns=0, root->data=2+0+0=2, returns 2
    - rightAns = convertToSumTree(3) => leftAns=0, rightAns=0, root->data=3+0+0=3, returns 3
    - root->data = 1+2+3=6, returns 6

    Final tree:
         6
        / \
       2   3

    (If using classic sum tree, final tree would be: 5, 0, 0)
*/

#include <iostream>
#include <queue>
using namespace std;

// Node class for binary tree
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

// Function to build binary tree from user input (recursive, pre-order)
// -1 as input means no node (NULL)
Node *buildTree(int data)
{
    // Base case: if data is -1, return NULL (no node)
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

/*
    Function to convert a binary tree to a sum tree.
    Current implementation: Each node's value becomes sum of its own value + left subtree sum + right subtree sum.
    Classic sum tree: Each node's value becomes sum of left and right subtree (excluding its own value).
*/
int convertToSumTree(Node* &root){
    // Base case: if node is NULL, return 0
    if(root == NULL){
        return 0;
    }

    // Recursively convert left subtree and get its sum
    int leftAns = convertToSumTree(root->left);

    // Recursively convert right subtree and get its sum
    int rightAns = convertToSumTree(root->right);

    // Update current node's data to sum of its own value + left subtree sum + right subtree sum
    root->data = root->data + leftAns + rightAns;

    // Return the updated value (sum of subtree rooted at this node)
    return root->data;
}

/*
    // Alternative: Classic sum tree (node's value = sum of left and right subtree, excluding its own value)
    int convertToSumTree(Node* &root){
        if(root == NULL) return 0;
        int old_val = root->data;
        root->data = convertToSumTree(root->left) + convertToSumTree(root->right);
        return root->data + old_val;
    }
*/

// Utility function to print tree in level order (for debugging)
void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            Node* curr = q.front(); q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;

    // Build the binary tree from user input
    root = buildTree(data);

    // Convert the tree to sum tree (current approach: includes own value)
    convertToSumTree(root);

    // Print the tree in level order after conversion (for verification)
    cout << "Level order traversal after converting to sum tree:" << endl;
    printLevelOrder(root);

    return 0;
}

/*
    Dry Run Example:
    -----------------
    Input: 1 2 -1 -1 3 -1 -1
    Tree:
         1
        / \
       2   3

    convertToSumTree(root):
    - leftAns = convertToSumTree(2) => leftAns=0, rightAns=0, root->data=2+0+0=2, returns 2
    - rightAns = convertToSumTree(3) => leftAns=0, rightAns=0, root->data=3+0+0=3, returns 3
    - root->data = 1+2+3=6, returns 6

    Final tree (current approach):
         6
        / \
       2   3

    Final tree (classic sum tree):
         5
        / \
       0   0
*/