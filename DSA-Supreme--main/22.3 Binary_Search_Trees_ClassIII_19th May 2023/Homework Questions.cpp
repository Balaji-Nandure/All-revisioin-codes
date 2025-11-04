

/*
================================================================================
1) Check whether approach of inorder in Largest BST in a binary tree will work or not.
================================================================================

Approach:
----------
- The naive idea is: If we do an inorder traversal of a BST, we get a sorted sequence.
- So, for a binary tree, if the inorder traversal is sorted, then the tree is a BST.
- For the "Largest BST in a Binary Tree" problem, one might think to do inorder traversal and find the largest sorted subarray, but this does NOT always work.
- This is because the inorder traversal being sorted does not guarantee the subtree structure is a BST (as parent-child relationships may be violated).

Example where inorder fails:
---------------------------
        10
       /  \
      5    15
     / \   /
    1   8 7

Inorder: 1 5 8 10 7 15 (not sorted, so we might try to find the largest sorted subarray: 1 5 8 10 or 7 15)
But, the subtree rooted at 5 (1,5,8) is a BST, and the subtree rooted at 15 (7,15) is also a BST.

So, inorder approach is not sufficient.

Better Approach (Optimal):
--------------------------
- Use postorder traversal.
- For each node, collect:
    - Whether the subtree is BST
    - Size of the subtree
    - Min and Max value in the subtree
- If left and right subtrees are BSTs, and current node's value is greater than max in left and less than min in right, then current subtree is BST.
- Keep track of the largest BST size found.

Code (C++):
------------
struct Info {
    int size;      // Size of subtree
    int max;       // Max value in subtree
    int min;       // Min value in subtree
    int ans;       // Size of largest BST
    bool isBST;    // Is subtree BST
};

Info largestBST(Node* root) {
    // Base case
    if (!root)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (!root->left && !root->right)
        return {1, root->data, root->data, 1, true};

    Info l = largestBST(root->left);
    Info r = largestBST(root->right);

    Info ret;
    ret.size = 1 + l.size + r.size;

    // If left and right are BST and current node is in range
    if (l.isBST && r.isBST && l.max < root->data && root->data < r.min) {
        ret.min = min(l.min, min(r.min, root->data));
        ret.max = max(r.max, max(l.max, root->data));
        ret.ans = ret.size;
        ret.isBST = true;
        return ret;
    }

    // Otherwise, not BST
    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;
    return ret;
}

Dry Run:
---------
For the above tree:
        10
       /  \
      5    15
     / \   /
    1   8 7

- left subtree (5,1,8) is BST of size 3
- right subtree (15,7) is BST of size 2
- root (10) is not BST because 7 < 10 < 15 fails for right subtree
- So, largest BST size is 3

================================================================================
2) Merge 2 BSTs
================================================================================

Approach:
----------
- The idea is to merge two BSTs into a single BST.
- Steps:
    1. Do inorder traversal of both BSTs to get two sorted arrays.
    2. Merge the two sorted arrays into one sorted array.
    3. Build a balanced BST from the merged sorted array.

Code (C++):
------------
void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

Node* sortedArrayToBST(vector<int>& arr, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

Node* mergeBSTs(Node* root1, Node* root2) {
    vector<int> arr1, arr2, merged;
    inorder(root1, arr1); // Get sorted elements of first BST
    inorder(root2, arr2); // Get sorted elements of second BST
    // Merge two sorted arrays
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) merged.push_back(arr1[i++]);
        else merged.push_back(arr2[j++]);
    }
    while (i < arr1.size()) merged.push_back(arr1[i++]);
    while (j < arr2.size()) merged.push_back(arr2[j++]);
    // Build BST from merged array
    return sortedArrayToBST(merged, 0, merged.size() - 1);
}

Dry Run:
---------
BST1:      2
          / \
         1   3

BST2:      7
          / \
         6   8

Inorder1: [1,2,3]
Inorder2: [6,7,8]
Merged:   [1,2,3,6,7,8]
Build BST from merged array.

================================================================================
Summary:
- For Largest BST in Binary Tree, inorder approach is NOT sufficient; use postorder with min/max tracking.
- For merging 2 BSTs, use inorder traversals, merge arrays, and build BST.

*/
