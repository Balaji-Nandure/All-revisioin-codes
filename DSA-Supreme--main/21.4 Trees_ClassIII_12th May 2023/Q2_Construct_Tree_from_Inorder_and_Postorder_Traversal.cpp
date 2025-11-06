/*
Problem:
---------
Given two integer arrays inorder and postorder, construct the binary tree and return its root.

Concept Recap:
---------------
- Inorder:   [Left | Root | Right]
- Postorder: [Left | Right | Root]
→ From postorder, we know the root (last element).
→ From inorder, we can find left and right subtree boundaries.

Approach:
----------
1. Use a recursive helper with a postIndex (starting from end).
2. Use a map to find root index in inorder[] in O(1).
3. Recurse:
     - Build right subtree first (since postorder gives root → right → left)
     - Then build left subtree.

Time Complexity: O(n)
Space Complexity: O(n)  // for map + recursion
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
    unordered_map<int, int> inorderIndex; // value → index map

    TreeNode* buildHelper(vector<int>& inorder, vector<int>& postorder, 
                          int& postIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        // Step 1: Pick current root from postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Step 2: Find index of root in inorder
        int pos = inorderIndex[rootVal];

        // Step 3: Build right first, then left (important!)
        root->right = buildHelper(inorder, postorder, postIndex, pos + 1, inEnd);
        root->left = buildHelper(inorder, postorder, postIndex, inStart, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        int postIndex = postorder.size() - 1;
        return buildHelper(inorder, postorder, postIndex, 0, inorder.size() - 1);
    }
};

// Helper to print preorder traversal to verify structure
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Preorder of constructed tree: ";
    printPreorder(root);
    cout << endl;
}
