/*
    Approach Used:
    --------------
    - The code constructs a binary tree from user input using recursion.
    - It then prints the left view of the binary tree using a recursive DFS (preorder) approach.
    - The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.
    - For each level, the first node encountered (from the left) is included in the left view.

    Steps:
    1. Build the tree recursively from user input.
    2. Traverse the tree in preorder (root, left, right), keeping track of the current level.
    3. For each level, if it's the first time visiting that level, add the node's data to the answer.
    4. Print the left view.

    Better Alternatives:
    --------------------
    1. **Level Order Traversal (BFS) Approach:**
       - Use a queue to traverse the tree level by level.
       - For each level, print the first node (leftmost node).
       - This approach is iterative and uses a queue, which may be more intuitive for some.
       - See code in the comment block below.

    2. **Iterative DFS with Stack:**
       - Use a stack to simulate preorder traversal.
       - Track the level and store the first node at each level.

    3. **Space Optimization:**
       - Instead of storing the entire left view in a vector, print directly during traversal if only output is needed.

    4. **Right View:**
       - The same logic can be used for the right view by traversing right before left.

    Dry Run Example is provided at the end of the code.

    ---------------------------------------------------------------
    // Alternative: Left View using Level Order Traversal (BFS)
    /*
    void leftViewBFS(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                Node* curr = q.front(); q.pop();
                if (i == 0) cout << curr->data << " "; // First node at this level
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
    }
    */
    ---------------------------------------------------------------
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node class for binary tree node
class Node {
public:
    int data;           // Data stored in the node
    Node *left;         // Pointer to left child
    Node *right;        // Pointer to right child

    // Constructor to initialize node with data
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build the binary tree recursively from user input
Node* buildTree(int data) {
    // Base case: -1 indicates a NULL node (no child)
    if (data == -1) {
        return NULL;
    }
    // Create a new node with the given data
    Node* root = new Node(data);

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

// Function to print the tree level-wise (for debugging/visualization)
void levelOrderTraversal(Node *root) {
    // If the tree is empty, return
    if (root == NULL) {
        return;
    }
    queue<Node *> q;        // Queue for level order traversal
    q.push(root);           // Push root node
    q.push(NULL);           // Level marker

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of current level
            cout << endl;
            // If there are more nodes, add level marker for next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " "; // Print current node's data

            // Enqueue left child if exists
            if (temp->left) {
                q.push(temp->left);
            }
            // Enqueue right child if exists
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Recursive function to compute the left view of the binary tree
void printLeftView(Node* root, vector<int>& ans, int level) {
    // Base case: if node is NULL, return
    if (root == NULL) {
        return;
    }
    // If this is the first node at this level, add it to the answer
    if (level == ans.size()) {
        ans.push_back(root->data);
    }
    // Recurse for left subtree first (to ensure leftmost node is visited first)
    printLeftView(root->left, ans, level + 1);
    // Then recurse for right subtree
    printLeftView(root->right, ans, level + 1);
}

int main() {
    // Build the tree from user input (root data is 10 for initial call)
    Node* root = buildTree(10);

    // Optional: Print the tree level-wise for visualization
    // cout << "Level Order Traversal of Tree:" << endl;
    // levelOrderTraversal(root);

    // Vector to store the left view nodes
    vector<int> ans;
    // Compute the left view starting from root at level 0
    printLeftView(root, ans, 0);

    // Print the left view
    cout << "Left View of the Tree: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
    Dry Run Example:
    ----------------
    Suppose the user input is as follows (for buildTree(10)):
    10
    / \
   20  30
   /     \
  40      50

    Input sequence (user enters):
    buildTree(10)
    Enter the data for left child of 10
    20
    Enter the data for left child of 20
    40
    Enter the data for left child of 40
    -1
    Enter the data for right child of 40
    -1
    Enter the data for right child of 20
    -1
    Enter the data for right child of 10
    30
    Enter the data for left child of 30
    -1
    Enter the data for right child of 30
    50
    Enter the data for left child of 50
    -1
    Enter the data for right child of 50
    -1

    The tree looks like:
            10
           /  \
         20    30
        /        \
      40         50

    Left View Traversal:
    - Level 0: 10 (first node at level 0)
    - Level 1: 20 (first node at level 1)
    - Level 2: 40 (first node at level 2)
    So, output: 10 20 40

    (If 30 had a left child, it would only appear in the left view if 20 didn't exist at that level.)
*/

/*
    Alternative: Left View using Level Order Traversal (BFS)
    --------------------------------------------------------
    void leftViewBFS(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                Node* curr = q.front(); q.pop();
                if (i == 0) cout << curr->data << " "; // First node at this level
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
    }
*/