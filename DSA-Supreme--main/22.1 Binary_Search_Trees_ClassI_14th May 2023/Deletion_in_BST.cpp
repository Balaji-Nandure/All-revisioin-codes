/*
APPROACH: DELETE A NODE FROM BST

We follow BST rules while deleting a node:

Case 1: Node has NO CHILD (Leaf)
    → Delete it, return NULL.

Case 2: Node has ONE CHILD
    → Replace the node with its only child and delete the node.

Case 3: Node has TWO CHILDREN
    → Find the INORDER SUCCESSOR (smallest node in right subtree),
      copy its value into the current node,
      and then delete the inorder successor.

Steps:
1) Search the value.
2) Based on children count, apply one of the above cases.
3) Return updated root.
*/

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Insert a value into BST
Node* insert(Node* root, int value) {
    if (root == nullptr) 
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Find minimum value node (used to find inorder successor)
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// find maximum value node (used to find inorder predecessor)
Node* findMax(Node* root) {
    while (root->right != nullptr)
        root = root->right;
    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int value) {

    if (root == nullptr) 
        return root;

    // Search for node
    if (value < root->data)
        root->left = deleteNode(root->left, value);

    else if (value > root->data)
        root->right = deleteNode(root->right, value);

    else {
        // Node found

        // Case 1: No child
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        Node* temp = findMin(root->right); // Inorder successor
        root->data = temp->data;          // Copy value
        root->right = deleteNode(root->right, temp->data); // Remove successor
    }

    return root;
}

// Inorder traversal to view BST
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// findnodeinbst
bool findNodeInBST(Node* root, int target) {
    if (root == nullptr) return false;
    if (root->data == target) return true;
    if (target < root->data) return findNodeInBST(root->left, target);
    return findNodeInBST(root->right, target);
}


// MAIN FUNCTION WITH TESTING
int main() {

    Node* root = nullptr;

    // Build BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Before deletion
    // cout << "Inorder before deletion: ";
    inorder(root);

    // Delete examples
    root = deleteNode(root, 20); // leaf node
    root = deleteNode(root, 30); // one-child node
    root = deleteNode(root, 50); // two-children case

    // After deletion
    // cout << "\nInorder after deletion: ";
    inorder(root);

    return 0;
}
