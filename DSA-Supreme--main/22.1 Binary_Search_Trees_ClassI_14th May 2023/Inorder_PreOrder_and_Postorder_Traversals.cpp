/*
    Approach Used:
    ----------------
    - This code builds a Binary Search Tree (BST) from user input and demonstrates three types of depth-first traversals (inorder, preorder, postorder) and a breadth-first traversal (level order).
    - The BST is constructed by inserting nodes such that for any node, all values in the left subtree are less, and all values in the right subtree are greater.
    - Traversals are implemented recursively (DFS) and using a queue for level order (BFS).

    Better Alternatives:
    --------------------
    1. **Iterative Traversals**: For large trees, recursion can cause stack overflow. Iterative traversals using stack/queue are safer.
    2. **Balanced BST**: The current approach may create skewed trees for sorted input. Using self-balancing BSTs (like AVL/Red-Black) ensures O(log n) operations.
    3. **Input Handling**: Instead of reading until -1, reading all input at once or from a file is more robust.
    4. **Memory Management**: No destructor is provided; for large trees, consider freeing memory.

    Example of Iterative Inorder Traversal (Alternative):
    -----------------------------------------------------
    // Iterative Inorder Traversal using stack
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

        // Constructor to initialize node with data and null children
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
    // If data is less than root, insert into left subtree
    if(root->data > data){
        root->left = insertIntoBST(root->left, data);
    }
    // If data is greater or equal, insert into right subtree
    else{
        root->right = insertIntoBST(root->right, data);
    }
    // Return the unchanged root pointer
    return root;
}

// Function to take input from user and build BST
void takeInput(Node* &root){
    int data;
    cin >> data; // Read first value
    while(data != -1){ // Sentinel value -1 to stop input
        root = insertIntoBST(root, data); // Insert into BST
        cin >> data; // Read next value
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
    q.push(NULL);    // Level marker

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // End of current level
            cout << endl;
            // If more nodes exist, add level marker for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " "; // Print current node

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

// Recursive Inorder Traversal: Left, Node, Right
void inorderTraversal(Node* root){
    if(root == NULL){
        return; // Base case: empty subtree
    }
    inorderTraversal(root->left);   // Visit left subtree
    cout << root->data << " ";      // Visit node
    inorderTraversal(root->right);  // Visit right subtree
}

// Recursive Postorder Traversal: Left, Right, Node
void postOrderTraversal(Node* root){
    if(root == NULL){
        return; // Base case: empty subtree
    }
    postOrderTraversal(root->left);   // Visit left subtree
    postOrderTraversal(root->right);  // Visit right subtree
    cout << root->data << " ";        // Visit node
}

// Recursive Preorder Traversal: Node, Left, Right
void preOrderTraversal(Node* root){
    if(root == NULL){
        return; // Base case: empty subtree
    }
    cout << root->data << " ";        // Visit node
    preOrderTraversal(root->left);    // Visit left subtree
    preOrderTraversal(root->right);   // Visit right subtree
}

int main(){
    Node* root = NULL; // Initialize root pointer

    cout << "Enter the data for Node (end with -1):" << endl;
    takeInput(root); // Build BST from user input

    cout << endl << "Level order traversal:" << endl;
    levelOrderTraversal(root); // Print tree level by level

    cout << "Inorder Traversal:" << endl;
    inorderTraversal(root); // Print inorder (should be sorted for BST)
    cout << endl;

    cout << "Postorder Traversal:" << endl;
    postOrderTraversal(root); // Print postorder
    cout << endl;

    cout << "Preorder Traversal:" << endl;
    preOrderTraversal(root); // Print preorder
    cout << endl;

    return 0;
}

/*
    Dry Run Example:
    -----------------
    Input: 10 5 20 3 7 15 25 -1

    BST Structure:
            10
           /  \
          5    20
         / \   / \
        3   7 15 25

    Level Order Traversal:
    10
    5 20
    3 7 15 25

    Inorder Traversal (LNR): 3 5 7 10 15 20 25
    Postorder Traversal (LRN): 3 7 5 15 25 20 10
    Preorder Traversal (NLR): 10 5 3 7 20 15 25

    Alternative Approach (Iterative Inorder):
    -----------------------------------------
    // See code at the top of this file for iterative inorder traversal.
*/