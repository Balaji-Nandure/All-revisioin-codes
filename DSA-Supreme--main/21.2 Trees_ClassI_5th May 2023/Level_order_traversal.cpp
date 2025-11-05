/*
Problem:
---------
Perform level order traversal of a binary tree.

Definition:
------------
Level order traversal (BFS): Visit nodes level by level from top to bottom, left to right.

Approach:
----------
1. Use a queue to keep track of nodes at the current level.
2. Start by pushing root into the queue.
3. While the queue is not empty:
   - Pop a node from the front of the queue.
   - Process the node (e.g., store its value).
   - Push its left and right children (if not null) into the queue.
4. Repeat until all nodes are visited.

Time Complexity: O(n)  // each node is visited once
Space Complexity: O(n) // queue can store up to n nodes in worst case
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Level Order Traversal
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;

        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(level);
    }

    return result;
}

int main() {
    /*
          1
         / \
        2   3
       / \
      4   5
    Level order:
    1
    2 3
    4 5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> levels = levelOrder(root);

    cout << "Level Order Traversal:\n";
    for (auto &lvl : levels) {
        for (int x : lvl) cout << x << " ";
        cout << "\n";
    }
}
