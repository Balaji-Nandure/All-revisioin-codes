/*
Problem:
---------
Given two integer arrays preorder and inorder, construct the binary tree and return its root.

Concept Recap:
---------------
- Preorder:  [Root | Left | Right]
- Inorder:   [Left | Root | Right]
→ From preorder, we know the root.
→ From inorder, we can find how many nodes belong to the left and right subtrees.

Approach:
----------
1. Use a recursive helper function with preorder index tracking.
2. Maintain a map from value → index (for O(1) inorder lookup).
3. Build left and right subtrees using inorder index boundaries.

Steps:
------
- Pick preorder[preIndex] as root.
- Find root’s index in inorder[] using map.
- Recurse left: inorder range [start, rootIndex-1]
- Recurse right: inorder range [rootIndex+1, end]
- Increment preIndex each time we pick a root.

Time Complexity: O(n)
Space Complexity: O(n)  // map + recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    unordered_map<int, int> inorderIndex; // Maps value to index in inorder; used for O(1) lookup
                                          // Helps quickly locate root position in inorder

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder,
                              int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;  // Return null if current inorder range is invalid
                                              // Base case: no node to construct in this subtree

        // Step 1: Pick current root from preorder
        int rootVal = preorder[preIndex++];   // Take value at preIndex as root, increment for next call
                                              // Preorder: first item is always the root for current subtree
        TreeNode* root = new TreeNode(rootVal); // Create node for root
                                                // Dynamic allocation for constructed node

        // Step 2: Find index of this root in inorder
        int pos = inorderIndex[rootVal];      // O(1) lookup for index of root in inorder
                                              // Splits inorder into left and right subtree boundaries

        // Step 3: Build left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, preIndex, inStart, pos - 1); // Left tree from [inStart,pos-1]
                                                                                     // Recursively construct left child
        root->right = buildTreeHelper(preorder, inorder, preIndex, pos + 1, inEnd);  // Right tree from [pos+1,inEnd]
                                                                                     // Recursively construct right child

        return root;                           // Return pointer to constructed root node
                                              // Combines this node with constructed children
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)  // Build mapping of value to its index in inorder
                                                  // Enables fast lookups for position in inorder
            inorderIndex[inorder[i]] = i;         // Store index of each inorder value in map
                                                  // Avoids repeated linear search

        int preIndex = 0;                         // Start preorder index at root (0th element)
                                                  // Preindex is incremented as recursion proceeds
        return buildTreeHelper(preorder, inorder, preIndex, 0, inorder.size() - 1); // Start recursion on full inorder range
                                                                                    // Pass preorder index by reference for correct incrementing
    }
};

// Utility function to print inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution sol;
    TreeNode* root = sol.buildTree(preorder, inorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    cout << endl;
}
