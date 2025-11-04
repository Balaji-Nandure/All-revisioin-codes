/*
    Approach Used:
    ----------------
    - This code implements a Binary Search Tree (BST) with insertion and level order traversal.
    - The BST is built by inserting nodes one by one, maintaining the BST property (left < root < right).
    - Level order traversal (BFS) is used to print the tree level by level.

    Better Alternatives:
    --------------------
    1. Iterative Insertion:
        - Instead of recursive insertion, we can use an iterative approach to avoid stack overflow for large trees.
        - See commented code below for iterative insertion.

    2. Level Order Traversal without NULL Markers:
        - Instead of using NULL as a level marker, we can use the size of the queue to process each level.
        - This is more efficient and avoids extra NULL pushes.
        - See commented code below for this approach.

    3. Input Handling:
        - Instead of reading until -1, we can take all input in a single line and parse it, which is more user-friendly.

    Dry Run:
    --------
    Input: 10 5 20 3 7 15 25 -1
    BST Created:
            10
           /  \
          5    20
         / \   / \
        3   7 15 25

    Level Order Output:
    10
    5 20
    3 7 15 25
*/

#include<iostream>
#include<queue>
using namespace std;

// Node class for BST
class Node{
    public:
        int data;       // Value of the node
        Node* left;     // Pointer to left child
        Node* right;    // Pointer to right child

        // Constructor to initialize node with data
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// Recursive function to insert a value into BST
Node* insertIntoBST(Node* root, int data){
    // If tree is empty, create a new node and return as root
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    // If data is less than root's data, insert in left subtree
    if(root->data > data){
        root->left = insertIntoBST(root->left, data);
    }
    // If data is greater or equal, insert in right subtree
    else{
        root->right = insertIntoBST(root->right, data);
    }
    // Return the unchanged root pointer
    return root;
}

/*
    // Iterative version of insertIntoBST (Better for large trees)
    Node* insertIntoBST(Node* root, int data){
        Node* newNode = new Node(data);
        if(root == NULL) return newNode;
        Node* curr = root;
        Node* parent = NULL;
        while(curr){
            parent = curr;
            if(data < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if(data < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
        return root;
    }
*/

// Function to take input and build BST until -1 is entered
void takeInput(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data); // Insert data into BST
        cin >> data;
    }
}

// Function to print the tree level by level (BFS)
void levelOrderTraversal(Node *root)
{
    // If tree is empty, nothing to print
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q; // Queue for BFS
    q.push(root);    // Start with root
    q.push(NULL);    // NULL marker for end of level

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // End of current level, print newline
            cout << endl;
            // If there are more nodes, add another NULL marker
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " "; // Print current node's data

            // If left child exists, push to queue
            if (temp->left)
            {
                q.push(temp->left);
            }
            // If right child exists, push to queue
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

/*
    // Better alternative: Level order traversal using queue size (no NULL markers)
    void levelOrderTraversal(Node* root) {
        if(!root) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; ++i) {
                Node* curr = q.front(); q.pop();
                cout << curr->data << " ";
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            cout << endl;
        }
    }
*/

int main(){
    Node* root = NULL; // Initialize root pointer
    cout << "Enter the data for Node (end with -1):" << endl;
    takeInput(root);   // Build BST from user input
    cout << "Level Order Traversal of BST:" << endl;
    levelOrderTraversal(root); // Print BST level by level
    return 0;
}

/*
Dry Run Example:
----------------
Input: 10 5 20 3 7 15 25 -1

Step 1: Insert 10 -> root = 10
Step 2: Insert 5  -> 5 < 10, goes to left of 10
Step 3: Insert 20 -> 20 > 10, goes to right of 10
Step 4: Insert 3  -> 3 < 10, left; 3 < 5, left of 5
Step 5: Insert 7  -> 7 < 10, left; 7 > 5, right of 5
Step 6: Insert 15 -> 15 > 10, right; 15 < 20, left of 20
Step 7: Insert 25 -> 25 > 10, right; 25 > 20, right of 20

BST Structure:
        10
       /  \
      5    20
     / \   / \
    3   7 15 25

Level Order Output:
10
5 20
3 7 15 25
*/