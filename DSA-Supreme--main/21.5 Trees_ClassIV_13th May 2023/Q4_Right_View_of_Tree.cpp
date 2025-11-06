/*
Problem:
---------
Print the right view of a binary tree.
The right view contains all nodes visible when the tree is viewed from the right side.

Approach:
----------
Use Level Order Traversal (BFS):
1. Traverse the tree level by level.
2. For each level, record the **last node** (rightmost) in that level.
3. Push children into the queue for the next level.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<int> rightView(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            // last node of this level
            if (i == n - 1)
                result.push_back(curr->val);

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    return result;
}

int main() {
    /*
             1
           /   \
          2     3
           \   / \
            4 5   6
                 / \
                7   8

     Right view: [1, 3, 6, 8]
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    vector<int> ans = rightView(root);
    cout << "Right View: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}
