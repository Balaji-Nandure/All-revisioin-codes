
/*
Approach for 1) Check if two trees are identical:
-------------------------------------------------
- Two binary trees are identical if:
    1. Both are empty (NULL).
    2. Both are non-empty, and:
        a. The data at their roots is the same.
        b. Their left subtrees are identical.
        c. Their right subtrees are identical.
- This is a classic recursive problem.

Code:
*/

bool areIdentical(TreeNode* root1, TreeNode* root2) {
    // If both nodes are NULL, trees are identical up to this node
    if (root1 == NULL && root2 == NULL)
        return true;
    // If one is NULL and other is not, trees are not identical
    if (root1 == NULL || root2 == NULL)
        return false;
    // Check current node data and recursively check left and right subtrees
    return (root1->val == root2->val) &&
           areIdentical(root1->left, root2->left) &&
           areIdentical(root1->right, root2->right);
}

/*
Alternative Approach:
---------------------
- Iterative using queue (BFS): Traverse both trees in parallel using queues and compare nodes.
- This avoids stack overflow for very deep trees.

Code (Iterative):
-----------------
bool areIdenticalIterative(TreeNode* root1, TreeNode* root2) {
    queue<TreeNode*> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty()) {
        TreeNode* n1 = q1.front(); q1.pop();
        TreeNode* n2 = q2.front(); q2.pop();
        if (!n1 && !n2) continue;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;
        q1.push(n1->left); q1.push(n1->right);
        q2.push(n2->left); q2.push(n2->right);
    }
    return q1.empty() && q2.empty();
}
*/

/*
Approach for 2) Check if two trees are mirror of each other:
------------------------------------------------------------
- Two trees are mirror if:
    1. Both are NULL.
    2. Both are non-NULL, and:
        a. The data at their roots is the same.
        b. The left subtree of one is mirror of the right subtree of the other, and vice versa.

Code:
*/

bool areMirror(TreeNode* root1, TreeNode* root2) {
    // If both nodes are NULL, they are mirror at this node
    if (root1 == NULL && root2 == NULL)
        return true;
    // If one is NULL and other is not, not mirror
    if (root1 == NULL || root2 == NULL)
        return false;
    // Check current node data and recursively check mirror subtrees
    return (root1->val == root2->val) &&
           areMirror(root1->left, root2->right) &&
           areMirror(root1->right, root2->left);
}

/*
Alternative Approach:
---------------------
- Iterative using queue: Traverse both trees in parallel, but compare left of one with right of other.

Code (Iterative):
-----------------
bool areMirrorIterative(TreeNode* root1, TreeNode* root2) {
    queue<TreeNode*> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while (!q1.empty() && !q2.empty()) {
        TreeNode* n1 = q1.front(); q1.pop();
        TreeNode* n2 = q2.front(); q2.pop();
        if (!n1 && !n2) continue;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;
        q1.push(n1->left); q1.push(n1->right);
        q2.push(n2->right); q2.push(n2->left);
    }
    return q1.empty() && q2.empty();
}
*/

/*
Dry Run Example for areIdentical:
---------------------------------
Tree1:      1
           / \
          2   3
Tree2:      1
           / \
          2   3

areIdentical(root1, root2):
- root1->val == root2->val (1 == 1) -> true
- areIdentical(root1->left, root2->left): (2 == 2) -> true
    - left and right children are NULL -> true
- areIdentical(root1->right, root2->right): (3 == 3) -> true
    - left and right children are NULL -> true
- All true, so trees are identical.

Dry Run Example for areMirror:
------------------------------
Tree1:      1
           / \
          2   3
Tree2:      1
           / \
          3   2

areMirror(root1, root2):
- root1->val == root2->val (1 == 1) -> true
- areMirror(root1->left, root2->right): (2 == 2) -> true
    - left and right children are NULL -> true
- areMirror(root1->right, root2->left): (3 == 3) -> true
    - left and right children are NULL -> true
- All true, so trees are mirror of each other.

*/
