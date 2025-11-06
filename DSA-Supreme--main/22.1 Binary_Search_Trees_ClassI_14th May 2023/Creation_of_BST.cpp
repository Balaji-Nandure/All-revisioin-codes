/*
Approach:
- We create a Binary Search Tree (BST) where, for every node, all values in the left
  subtree are strictly smaller than the node’s value and all values in the right subtree
  are greater than or equal to the node’s value (duplicates go to the right).
- Define a Node structure and a recursive insert function that places each new key
  in its correct position by comparing with the current node and moving left/right.
- Build the BST by reading integers from standard input until a sentinel (-1) is seen.
- Verify construction by printing traversals:
  - Inorder: sorted order of inserted values
  - Preorder, Postorder: structural checks
  - Level-order: breadth-first view (levels on separate lines)

Complexity:
- Insertion per key takes O(h), where h is the tree height. In the worst case (degenerated),
  h = O(n); on average (random insertion), h ≈ O(log n). Space is O(h) for recursion.
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    explicit Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

Node* insertIntoBST(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }
    if (key < root->value) {
        root->left = insertIntoBST(root->left, key);
    } else {
        root->right = insertIntoBST(root->right, key);
    }
    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

void levelOrder(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = static_cast<int>(q.size());
        for (int i = 0; i < levelSize; ++i) {
            Node* current = q.front();
            q.pop();
            cout << current->value << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << "\n";
    }
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = nullptr;

    cout << "Enter values to insert into BST (-1 to stop): ";
    int x;
    while (cin >> x && x != -1) {
        root = insertIntoBST(root, x);
    }

    cout << "\nInorder   : ";
    inorder(root);
    cout << "\nPreorder  : ";
    preorder(root);
    cout << "\nPostorder : ";
    postorder(root);
    cout << "\nLevel-order:\n";
    levelOrder(root);

    freeTree(root);
    return 0;
}


