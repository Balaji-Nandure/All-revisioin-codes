/*
    Approach Used:
    ----------------
    1. Build a binary tree recursively from user input. -1 means NULL node.
    2. Perform level order traversal (BFS) using a queue.
    3. Print each level on a new line (using NULL as a level marker).

    Alternatives:
    -------------
    - Instead of using NULL as a level marker, we can use the size of the queue to process each level.
    - We can also return a vector<vector<int>> for level order traversal if needed.
    - For building the tree, we can use iterative methods or take input as an array.

    See detailed alternative code and dry run at the end.
*/

#include <iostream>
#include <queue>
using namespace std;

// Node class for binary tree
class Node
{
public:
    int data;       // stores node value
    Node *left;     // pointer to left child
    Node *right;    // pointer to right child

    // Constructor to initialize node with data and set children to NULL
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build tree recursively from user input
Node *buildTree(int data)
{
    // Base case: if data is -1, this is a NULL node (no child)
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
    // Alternative: Normal Level Order Traversal (all nodes in one line)
    void levelOrderTraversal(Node* root){
        if(root == NULL) return; // If tree is empty, nothing to print

        queue<Node*>q;           // Queue for BFS
        q.push(root);            // Start with root

        while(!q.empty()){
            Node* temp = q.front(); // Get front node
            q.pop();                // Remove it from queue
            cout<<temp->data<<" ";  // Print its data

            if(temp->left) q.push(temp->left);   // Enqueue left child if exists
            if(temp->right) q.push(temp->right); // Enqueue right child if exists
        }
    }
*/

// Function to print the tree level by level (each level on new line)
void levelOrderTraversal(Node *root)
{
    // If tree is empty, nothing to print
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;      // Queue for BFS
    q.push(root);         // Start with root node
    q.push(NULL);         // NULL as marker for end of current level

    while (!q.empty())
    {
        Node *temp = q.front(); // Get front node
        q.pop();                // Remove it from queue

        if (temp == NULL)
        {
            // End of current level, print newline
            cout << endl;

            // If there are more nodes to process, add another NULL marker
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " "; // Print node data

            // Enqueue left child if exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // Enqueue right child if exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

/*
    // Better Alternative: Level Order Traversal using queue size (no NULL marker)
    // This avoids using NULL and is more efficient.
    void levelOrderTraversal(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at current level
            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front();
                q.pop();
                cout << node->data << " ";
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cout << endl; // End of current level
        }
    }
*/

/*
    // Alternative: Return level order as vector<vector<int>>
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;
            for (int i = 0; i < levelSize; ++i) {
                Node* node = q.front(); q.pop();
                level.push_back(node->data);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
*/

int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data; // Take root node data from user

    root = buildTree(data); // Build the tree recursively

    cout << "Level order traversal is as follows" << endl;
    levelOrderTraversal(root); // Print tree level by level

    return 0;
}

/*
    Dry Run Example:
    ----------------
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

    Tree built:
            1
           / \
          2   3
         / \
        4   5

    Output:
    Level order traversal is as follows
    1 
    2 3 
    4 5 

    Explanation:
    - First level: 1
    - Second level: 2 3
    - Third level: 4 5
*/

/*
    Summary:
    --------
    - Used BFS (queue) for level order traversal.
    - Used NULL marker to separate levels.
    - Provided alternative (queue size) for better efficiency.
    - Added dry run for clarity.
*/