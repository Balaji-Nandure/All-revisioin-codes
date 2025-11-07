// approach is to use the properties of bst to find the lca
// if both nodes are smaller than the current node, then the lca is in the left subtree
// if both nodes are greater than the current node, then the lca is in the right subtree
// if one node is smaller and the other is greater, then the current node is the lca or
// one of the nodes is the current node, then the current node is the lca


// RECURSIVE LCA (BST)
// tc o(h) sc o(h)
Node* lcaBST(Node* root, int p, int q) {
    if (root == nullptr) return nullptr;

    // If both targets are smaller, go left
    if (p < root->data && q < root->data)
        return lcaBST(root->left, p, q);

    // If both targets are greater, go right
    if (p > root->data && q > root->data)
        return lcaBST(root->right, p, q);

    // Split point (or one equals root) → current is LCA
    return root;
}

// ITERATIVE LCA (BST) — O(1) extra space
// tc o(h) sc o(1)
Node* lcaBSTIter(Node* root, int p, int q) {
    Node* cur = root;
    while (cur != nullptr) {
        if (p < cur->data && q < cur->data) {
            cur = cur->left;
        } else if (p > cur->data && q > cur->data) {
            cur = cur->right;
        } else {
            return cur; // split point or equals
        }
    }
    return nullptr; // not found (if one/both keys absent)
}