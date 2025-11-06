/*
Problem:
---------
Given the root of a binary tree and an integer targetSum,
return all root-to-leaf paths where the sum of the node values equals targetSum.

Approach:
----------
Use Backtracking (DFS):
1. Maintain a vector<int> `path` to store the current path.
2. Subtract the current node’s value from `targetSum`.
3. If it’s a leaf node and targetSum == 0 → add current path to answer.
4. Recurse left and right.
5. Backtrack — remove the last node before returning.

Time Complexity: O(n)
Space Complexity: O(h)  // recursion + path storage
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Depth-first search to find all root-to-leaf paths with sum == targetSum
    // path keeps the current nodes, ans saves results
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if (!root) return; // Base case: if node is null, nothing to do

        path.push_back(root->val); // Add current node to path
                                  // This extends the temporary path for recursion

        // Check if current node is a leaf (no children)
        // Also check if the path sum matches targetSum exactly here
        if (!root->left && !root->right && targetSum == root->val)
            ans.push_back(path); // Valid path found: store a copy in ans
                                // Only push when both conditions met

        // Recur left, subtract current node's value from sum
        // Traverse left child for possible paths
        dfs(root->left, targetSum - root->val, path, ans);

        // Recur right, again track reduced sum for path
        // Traverse right child to explore all possibilities
        dfs(root->right, targetSum - root->val, path, ans);

        path.pop_back(); // Remove last node to backtrack
                         // Ensures path is restored before next sibling call
    }

    // Driver function: returns all root-to-leaf paths summing to targetSum
    // Calls DFS and returns complete result
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans; // Stores all valid paths
                                // Final answer to return
        vector<int> path;    // Current root-to-node path accumulator
                             // Used during DFS
        dfs(root, targetSum, path, ans); // Begin DFS from root
                                         // Fills ans with all valid paths
        return ans;          // Return all found paths to caller
                            // Output as required
    }
};

int main() {
    /*
           5
          / \
         4   8
        /   / \
       11  13  4
      /  \    / \
     7    2  5   1

     targetSum = 22

     Output:
     [
       [5,4,11,2],
       [5,8,4,5]
     ]
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 22;

    auto res = sol.pathSum(root, targetSum);
    cout << "Paths with sum " << targetSum << ":\n";
    for (auto& v : res) {
        for (int x : v) cout << x << " ";
        cout << "\n";
    }
}
