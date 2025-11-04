/*
    Approach Used:
    ----------------
    - The code builds a binary tree from user input using recursion.
    - It then performs a postorder traversal (Left, Right, Node) recursively.
    - The tree is built such that entering -1 means the current child is NULL (leaf node).
    - The traversal prints the nodes in postorder.

    Better Alternatives:
    --------------------
    1. **Iterative Postorder Traversal**: Can be done using two stacks or a single stack with a visited flag.
    2. **Level Order Input**: Instead of recursive input, use a queue for level order input for better usability.
    3. **Use nullptr instead of NULL**: Modern C++ recommends nullptr.
    4. **Avoid Global cin/cout in Functions**: Pass input as parameters or use a helper for better testability.

    Example of Iterative Postorder Traversal (commented):
    ------------------------------------------------------
    // void postOrderIterative(Node* root) {
    //     if (!root) return;
    //     stack<Node*> s1, s2;
    //     s1.push(root);
    //     while (!s1.empty()) {
    //         Node* curr = s1.top(); s1.pop();
    //         s2.push(curr);
    //         if (curr->left) s1.push(curr->left);
    //         if (curr->right) s1.push(curr->right);
    //     }
    //     while (!s2.empty()) {
    //         cout << s2.top()->data << " ";
    //         s2.pop();
    //     }
    // }

    Dry Run Example:
    -----------------
    Input: 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
    Tree:
            1
           / \
          2   3
         / \   \
        4   5   6
    Postorder Output: 4 5 2 6 3 1

*/

#include <iostream>
using namespace std;

// Node class represents each node in the binary tree
class Node
{
public:
    int data;       // Data stored in the node
    Node *left;     // Pointer to left child
    Node *right;    // Pointer to right child

    // Constructor to initialize node with data and null children
    Node(int data)
    {
        this->data = data;
        left = nullptr;   // Use nullptr instead of NULL for modern C++
        right = nullptr;
    }
};

// Function to build the binary tree recursively from user input
Node *buildTree(int data)
{
    // Base Case: If data is -1, this position is a leaf (no node)
    if (data == -1)
    {
        return nullptr;
    }

    // Create a new node with the given data
    Node *root = new Node(data);

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

// Function to perform postorder traversal (Left, Right, Node)
void postOrderTraversal(Node* root){
    // Base case: If node is null, do nothing
    if(root == nullptr){
        return;
    }
    // Traverse left subtree
    postOrderTraversal(root->left);
    // Traverse right subtree
    postOrderTraversal(root->right);
    // Process current node (print data)
    cout << root->data << " ";
}

int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    // Build the tree from user input
    root = buildTree(data);

    cout << "Postorder Traversal: ";
    // Perform postorder traversal and print nodes
    postOrderTraversal(root);

    cout << endl;
    return 0;
}

/*
    Alternative: Iterative Postorder Traversal (using two stacks)
    -------------------------------------------------------------
    #include <stack>
    void postOrderIterative(Node* root) {
        if (!root) return;
        stack<Node*> s1, s2;
        s1.push(root);
        while (!s1.empty()) {
            Node* curr = s1.top(); s1.pop();
            s2.push(curr);
            if (curr->left) s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }
        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }

    // To use, call postOrderIterative(root); in main.

    Dry Run:
    --------
    Input: 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

    Step-by-step:
    - buildTree(1): root=1
        - left: buildTree(2)
            - left: buildTree(4)
                - left: buildTree(-1) => NULL
                - right: buildTree(-1) => NULL
            - right: buildTree(5)
                - left: buildTree(-1) => NULL
                - right: buildTree(-1) => NULL
        - right: buildTree(3)
            - left: buildTree(-1) => NULL
            - right: buildTree(6)
                - left: buildTree(-1) => NULL
                - right: buildTree(-1) => NULL

    Postorder Traversal:
    - postOrderTraversal(1)
        - postOrderTraversal(2)
            - postOrderTraversal(4) => print 4
            - postOrderTraversal(5) => print 5
            - print 2
        - postOrderTraversal(3)
            - postOrderTraversal(6) => print 6
            - print 3
        - print 1

    Output: 4 5 2 6 3 1
*/