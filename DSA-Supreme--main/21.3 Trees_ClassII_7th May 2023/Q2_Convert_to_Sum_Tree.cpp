// Convert a given binary tree into a Sum Tree, where each node’s new value is the sum of values of its left and right subtrees in the original tree.

/*
 input
        10
       /  \
      -2    6
     / \   / \
    8  -4  7  5

    output
        20
       /  \
      4    12
     / \   / \
    0   0  0  0

*/



/*
Problem:
---------
Convert a binary tree into a Sum Tree.
Each node’s value should be the sum of its left and right subtrees in the original tree.

Approach:
----------
- Use postorder traversal (Left → Right → Node).
- Recursively compute subtree sums.
- Replace each node’s value with the sum of its left and right subtrees.
- Return the total sum (old value + left sum + right sum).

Time Complexity: O(n)
Space Complexity: O(h)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int toSumTree(Node* root) {
    if (!root) return 0;

    int leftSum = toSumTree(root->left);
    int rightSum = toSumTree(root->right);

    int oldVal = root->val;
    root->val = leftSum + rightSum;

    return oldVal + root->val;
}

// Helper to print inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
          10
         /  \
        -2    6
       / \   / \
      8  -4  7  5
    */

    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    toSumTree(root);

    cout << "Inorder of Sum Tree: ";
    inorder(root);
    cout << endl;
}
