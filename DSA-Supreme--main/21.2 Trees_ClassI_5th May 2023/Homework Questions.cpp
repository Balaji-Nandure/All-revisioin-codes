/*
    1) Binary Tree Implementation + Level Order Traversal

    Approach:
    ---------
    - Build a binary tree from user input (using -1 as sentinel for NULL/leaf).
    - Perform Level Order Traversal (Breadth-First Search) using a queue.
    - Print nodes level by level.

    Key Points:
    -----------
    - Level order traversal visits nodes level by level from left to right.
    - Uses a queue to keep track of nodes at each level.

    Alternatives (with code in comments):
    -------------------------------------
    1. **Recursive Level Order Traversal**:
        - Use a helper function to print nodes at each level recursively.
        - Less efficient due to repeated traversals for each level.
        - See code in comments below.

    2. **Zigzag/Spiral Level Order Traversal**:
        - Use two stacks or a deque to alternate direction at each level.

    3. **Level Order with Level Separation**:
        - Print each level on a new line (see code in comments).

    4. **DFS Traversals**:
        - Preorder, Inorder, Postorder (not shown here).

    ---------------------------------------------------------------
*/

#include <iostream>
#include <queue>
using namespace std;

// Node class for binary tree
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data; // store node value
        left = NULL;       // initialize left child
        right = NULL;      // initialize right child
    }
};

// Function to build tree from user input (preorder, -1 for NULL)
Node* buildTree() {
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;
    if (data == -1) {
        // -1 means no node here
        return NULL;
    }
    Node* root = new Node(data); // create new node
    // Recursively build left and right subtrees
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();
    cout << "Enter right child of " << data << endl;
    root->right = buildTree();
    return root;
}

// Level Order Traversal (BFS) using queue
void levelOrderTraversal(Node* root) {
    if (!root) return; // empty tree
    queue<Node*> q;    // queue for BFS
    q.push(root);      // start with root
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " "; // print current node
        if (curr->left) q.push(curr->left);   // enqueue left child if exists
        if (curr->right) q.push(curr->right); // enqueue right child if exists
    }
    cout << endl;
}

/*
    // Alternative 1: Recursive Level Order Traversal
    int height(Node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void printLevel(Node* root, int level) {
        if (!root) return;
        if (level == 1) cout << root->data << " ";
        else {
            printLevel(root->left, level-1);
            printLevel(root->right, level-1);
        }
    }
    void levelOrderRecursive(Node* root) {
        int h = height(root);
        for (int i = 1; i <= h; ++i) {
            printLevel(root, i);
        }
    }

    // Alternative 2: Level Order with Level Separation
    void levelOrderWithLevels(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                Node* curr = q.front(); q.pop();
                cout << curr->data << " ";
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            cout << endl; // new line after each level
        }
    }
*/

int main() {
    // Build tree from user input
    Node* root = buildTree();

    // Print level order traversal
    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);

    // Uncomment below to see level order with levels separated
    // cout << "Level Order (with levels):" << endl;
    // levelOrderWithLevels(root);

    return 0;
}

/*
    Dry Run Example:
    ----------------
    Input:
        Enter data (-1 for NULL): 1
        Enter left child of 1
        Enter data (-1 for NULL): 2
        Enter left child of 2
        Enter data (-1 for NULL): 4
        Enter left child of 4
        Enter data (-1 for NULL): -1
        Enter right child of 4
        Enter data (-1 for NULL): -1
        Enter right child of 2
        Enter data (-1 for NULL): 5
        Enter left child of 5
        Enter data (-1 for NULL): -1
        Enter right child of 5
        Enter data (-1 for NULL): -1
        Enter right child of 1
        Enter data (-1 for NULL): 3
        Enter left child of 3
        Enter data (-1 for NULL): -1
        Enter right child of 3
        Enter data (-1 for NULL): -1

    Tree Structure:
            1
           / \
          2   3
         / \
        4   5

    Output:
        Level Order Traversal: 1 2 3 4 5

    (If using levelOrderWithLevels, output would be:)
        1
        2 3
        4 5
*/
