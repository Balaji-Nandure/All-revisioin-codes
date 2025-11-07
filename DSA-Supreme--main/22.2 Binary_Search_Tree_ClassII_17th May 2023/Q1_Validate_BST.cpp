/*
APPROACH: VALIDATE IF A BINARY TREE IS A BST

A BST must satisfy for every node:
    all keys in LEFT subtree  < node->data
    all keys in RIGHT subtree > node->data
(Strict inequality if duplicates are NOT allowed)

Two standard methods:

METHOD A — RANGE CHECK (MIN/MAX):  O(n) time, O(h) stack
    - Carry a valid range [low, high] for each node.
    - For current node x:
        low < x->data < high
      Recurse:
        left  gets range [low, x->data)
        right gets range (x->data, high]
    - This directly enforces the BST rule at all depths.

METHOD B — INORDER MONOTONIC:      O(n) time, O(h) stack
    - Inorder traversal of a BST yields a strictly increasing sequence.
    - Keep 'prev' pointer/value during inorder.
    - If current <= prev at any step → NOT a BST.

Notes:
- If your BST allows duplicates:
    - Decide a convention (e.g., all duplicates in RIGHT subtree).
    - Then change strict comparisons accordingly.
*/

struct Node {
    long long data;      // use long long to reduce overflow worries
    Node *left, *right;

    Node(long long v) {
        data = v;
        left = right = nullptr;
    }
};

// -----------------------------
// METHOD A: RANGE CHECK
// -----------------------------
bool isBSTRange(Node* root, long long low, long long high) {
    // Empty subtree is valid
    if (root == nullptr) return true;

    // Enforce strict inequality (no duplicates)
    if (!(low < root->data && root->data < high)) return false;

    // Left must be in (low, root->data)
    // Right must be in (root->data, high)
    return isBSTRange(root->left, low, root->data)
        && isBSTRange(root->right, root->data, high);
}

// Convenience wrapper
bool isBST(Node* root) {
    // Use wide sentinels to avoid integer edge issues
    // For long long, use LLONG_MIN and LLONG_MAX from <climits>
    // For int, use INT_MIN and INT_MAX from <climits>
    const long long NEG_INF = LLONG_MIN;
    const long long POS_INF = LLONG_MAX;
    return isBSTRange(root, NEG_INF, POS_INF);
}

// -----------------------------
// METHOD B: INORDER MONOTONIC
// -----------------------------
bool inorderCheck(Node* root, Node*& prev) {
    if (root == nullptr) return true;

    // Left
    if (!inorderCheck(root->left, prev)) return false;

    // Current must be strictly greater than prev->data
    if (prev != nullptr && !(prev->data < root->data)) return false;

    // Update prev
    prev = root;

    // Right
    return inorderCheck(root->right, prev);
}

bool isBSTInorder(Node* root) {
    Node* prev = nullptr;
    return inorderCheck(root, prev);
}

/*
OPTIONAL TEST SNIPPET (uncomment prints if you add headers like <iostream>)

Node* makeSample() {
    // Valid BST:
    //        8
    //      /   \
    //     3     10
    //    / \      \
    //   1   6      14
    //      / \     /
    //     4   7   13

    Node* r = new Node(8);
    r->left = new Node(3);
    r->right = new Node(10);
    r->left->left = new Node(1);
    r->left->right = new Node(6);
    r->left->right->left = new Node(4);
    r->left->right->right = new Node(7);
    r->right->right = new Node(14);
    r->right->right->left = new Node(13);
    return r;
}

Node* makeBad() {
    // Not a BST because 12 is in the left subtree of 10
    //       10
    //      /  \
    //     5   15
    //    / \
    //   2  12   <-- violates BST rule
    Node* r = new Node(10);
    r->left = new Node(5);
    r->right = new Node(15);
    r->left->left = new Node(2);
    r->left->right = new Node(12);
    return r;
}

int main() {
    Node* good = makeSample();
    Node* bad = makeBad();

    // Using Method A
    // std::cout << (isBST(good) ? "GOOD is BST\n" : "GOOD is NOT BST\n");
    // std::cout << (isBST(bad)  ? "BAD is BST\n"  : "BAD is NOT BST\n");

    // Using Method B
    // std::cout << (isBSTInorder(good) ? "GOOD is BST\n" : "GOOD is NOT BST\n");
    // std::cout << (isBSTInorder(bad)  ? "BAD is BST\n"  : "BAD is NOT BST\n");

    return 0;
}
*/

// TIP:
// - If you allow duplicates on the RIGHT, change comparisons to:
//   Range method: (low <= root->data && root->data < high)
//   Inorder method: prev->data <= root->data
