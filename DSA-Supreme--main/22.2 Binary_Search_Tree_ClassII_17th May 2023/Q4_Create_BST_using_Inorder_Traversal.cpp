/*
APPROACH: CONSTRUCT A BST FROM ITS INORDER TRAVERSAL

Given inorder[] of a BST → the array is already sorted.
To build BST:
- Choose middle element as root (to keep tree height minimal).
- Recursively build left subtree from left half.
- Recursively build right subtree from right half.

This constructs a height-balanced BST.

Example:
Inorder = [1, 3, 4, 6, 7, 8, 9]

             6
          /      \
        3          8
      /   \      /   \
     1     4    7     9
*/

struct Node {
    int data;
    Node *left, *right;
    Node(int v) { data = v; left = right = nullptr; }
};

Node* buildBSTFromInorder(int inorder[], int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* root = new Node(inorder[mid]);

    root->left = buildBSTFromInorder(inorder, start, mid - 1);
    root->right = buildBSTFromInorder(inorder, mid + 1, end);

    return root;
}

// MAIN FOR TESTING
int main() {

    int arr[] = {1, 3, 4, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* root = buildBSTFromInorder(arr, 0, n - 1);

    // inorderPrint(root); // would print sorted again

    return 0;
}
