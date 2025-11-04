/*
    Approach Used:
    ----------------
    - The code builds a binary tree using recursive input from the user.
    - It then performs a preorder traversal (Root, Left, Right) of the tree and prints the node values.
    - The tree is built recursively: for each node, the user is prompted for left and right child data.
    - If the user enters -1, it means the child is NULL (leaf node).
    - Preorder traversal is also implemented recursively.

    Better Alternatives:
    --------------------
    1. **Iterative Preorder Traversal**: Can be done using a stack to avoid recursion.
    2. **Level Order Input**: Build the tree using level order input (using a queue) for better usability.
    3. **Input as Array**: Build the tree from an array representation (like Leetcode style).
    4. **Error Handling**: Add input validation and error handling.
    5. **Memory Management**: Add a destructor to free memory.

    Example of Iterative Preorder Traversal (Alternative Approach):
    ---------------------------------------------------------------
    // void iterativePreOrder(Node* root) {
    //     if (!root) return;
    //     stack<Node*> st;
    //     st.push(root);
    //     while (!st.empty()) {
    //         Node* curr = st.top();
    //         st.pop();
    //         cout << curr->data << " ";
    //         if (curr->right) st.push(curr->right);
    //         if (curr->left) st.push(curr->left);
    //     }
    // }

    Example of Level Order Build (Alternative Approach):
    ----------------------------------------------------
    // Node* buildTreeLevelOrder() {
    //     int data;
    //     cout << "Enter root data: ";
    //     cin >> data;
    //     if (data == -1) return NULL;
    //     Node* root = new Node(data);
    //     queue<Node*> q;
    //     q.push(root);
    //     while (!q.empty()) {
    //         Node* curr = q.front(); q.pop();
    //         int leftData, rightData;
    //         cout << "Enter left child of " << curr->data << ": ";
    //         cin >> leftData;
    //         if (leftData != -1) {
    //             curr->left = new Node(leftData);
    //             q.push(curr->left);
    //         }
    //         cout << "Enter right child of " << curr->data << ": ";
    //         cin >> rightData;
    //         if (rightData != -1) {
    //             curr->right = new Node(rightData);
    //             q.push(curr->right);
    //         }
    //     }
    //     return root;
    // }

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

    Tree:
        1
       / \
      2   3

    Output:
    1 2 3

*/

#include <iostream>
using namespace std;

// Node class represents a single node in the binary tree
class Node
{
public:
    int data;       // stores the value of the node
    Node *left;     // pointer to the left child
    Node *right;    // pointer to the right child

    // Constructor to initialize node with data and set children to NULL
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build the binary tree recursively using user input
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

// Function to perform preorder traversal (Root, Left, Right) recursively
void preOrderTraversal(Node* root){
    // Base Case: If node is NULL, return (end of branch)
    if(root == NULL){
        return;
    }
    // Visit the root node (print its data)
    cout<<root->data<<" ";
    // Traverse the left subtree
    preOrderTraversal(root->left);
    // Traverse the right subtree
    preOrderTraversal(root->right);
}

int main()
{
    Node *root; // pointer to the root of the tree
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    // Build the tree using recursive input
    root = buildTree(data);
    // Print the preorder traversal of the tree
    cout << "Preorder Traversal: ";
    preOrderTraversal(root);
    cout << endl;
    return 0;
}

/*
Dry Run Example:
----------------
Suppose user input is:
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

Tree constructed:
    1
   / \
  2   3

Preorder Traversal Output:
Preorder Traversal: 1 2 3

Explanation:
- Visit 1 (root)
- Go left: visit 2
- 2 has no children, return
- Go right from 1: visit 3
- 3 has no children, return
*/