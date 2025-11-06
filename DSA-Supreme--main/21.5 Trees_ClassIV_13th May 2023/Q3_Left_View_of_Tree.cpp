/*
Problem:
---------
Print the left view of a binary tree.
The left view contains all nodes that are visible when the tree is viewed from the left side.

Approach:
----------
Use Level Order Traversal (BFS):
1. Traverse the tree level by level.
2. For each level, record the **first node** (leftmost) in that level.
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

vector<int> leftView(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            // first node of this level
            if (i == 0)
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

     Left view: [1, 2, 4, 7]
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    vector<int> ans = leftView(root);
    cout << "Left View: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}
