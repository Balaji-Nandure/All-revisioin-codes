
/*
================================================================================
1) Kth Ancestor in a Binary Tree (Vector Approach)
================================================================================
Approach:
- Store the path from root to the target node in a vector.
- The kth ancestor is at index path.size() - k - 1.
- Time Complexity: O(N) for path finding.
- Space Complexity: O(H) for path storage (H = height of tree).

Better Alternative:
- Binary Lifting (preprocessing with O(NlogN), query in O(logN)).
- See commented code below.

Code:
*/

// Function to find path from root to given node
bool getPath(TreeNode* root, int target, vector<TreeNode*>& path) {
    if (!root) return false;
    path.push_back(root); // add current node to path
    if (root->val == target) return true; // found target
    // search in left or right subtree
    if (getPath(root->left, target, path) || getPath(root->right, target, path))
        return true;
    path.pop_back(); // backtrack if not found in this path
    return false;
}

// Main function to find kth ancestor
TreeNode* kthAncestor(TreeNode* root, int target, int k) {
    vector<TreeNode*> path;
    if (!getPath(root, target, path)) return nullptr; // target not found
    int idx = path.size() - k - 1; // kth ancestor index
    if (idx < 0) return nullptr; // not enough ancestors
    return path[idx];
}

/*
Alternative: Binary Lifting (for multiple queries)
-----------------------------------------------
- Preprocess parent pointers for each node at powers of 2.
- Query kth ancestor in O(logK) time.

Example code (commented):

const int LOG = 20; // for up to 10^6 nodes
vector<vector<TreeNode*>> up; // up[node][j] = 2^j-th ancestor

void dfs(TreeNode* node, TreeNode* parent) {
    up[node->val][0] = parent;
    for (int j = 1; j < LOG; ++j) {
        if (up[node->val][j-1])
            up[node->val][j] = up[up[node->val][j-1]->val][j-1];
        else
            up[node->val][j] = nullptr;
    }
    if (node->left) dfs(node->left, node);
    if (node->right) dfs(node->right, node);
}

TreeNode* getKthAncestor(TreeNode* node, int k) {
    for (int j = 0; j < LOG && node; ++j)
        if (k & (1 << j))
            node = up[node->val][j];
    return node;
}
*/

/*
Dry Run:
Tree:      1
         /   \
        2     3
       /
      4
Target = 4, k = 2
Path: [1,2,4]
kth ancestor: path[3-2-1]=path[0]=1
*/

/*
================================================================================
2) Check whether a tree is a Sum Tree or not
================================================================================
Approach:
- A sum tree is a tree where every node's value is equal to the sum of values in its left and right subtrees.
- Use postorder traversal to check and return sum at each node.
- Time Complexity: O(N)
- Space Complexity: O(H)

Code:
*/

pair<bool, int> isSumTreeUtil(TreeNode* root) {
    if (!root) return {true, 0}; // empty tree is sum tree
    if (!root->left && !root->right) return {true, root->val}; // leaf node
    auto left = isSumTreeUtil(root->left);
    auto right = isSumTreeUtil(root->right);
    bool isSum = left.first && right.first && (root->val == left.second + right.second);
    int sum = root->val + left.second + right.second;
    return {isSum, sum};
}

bool isSumTree(TreeNode* root) {
    return isSumTreeUtil(root).first;
}

/*
Alternative:
- Can be done in a single traversal as above.
- For large trees, iterative postorder can be used to avoid stack overflow.
*/

/*
Dry Run:
Tree:      26
         /    \
        10     3
       /  \     \
      4    6     3
Check: 26 == 10+3, 10==4+6, 3==3, 4,6,3 are leaves.
Returns true.
*/

/*
================================================================================
3) Any node to any node target sum path (Path Sum III)
================================================================================
Approach:
- Use prefix sum and hashmap to count number of paths with given sum.
- Traverse tree, keep running sum, and check if (currSum - target) exists in map.
- Time Complexity: O(N)
- Space Complexity: O(H)

Code:
*/

int pathSumUtil(TreeNode* root, int targetSum, long currSum, unordered_map<long, int>& prefix) {
    if (!root) return 0;
    currSum += root->val;
    int res = prefix[currSum - targetSum]; // number of paths ending here with sum = targetSum
    prefix[currSum]++;
    res += pathSumUtil(root->left, targetSum, currSum, prefix);
    res += pathSumUtil(root->right, targetSum, currSum, prefix);
    prefix[currSum]--; // backtrack
    return res;
}

int pathSum(TreeNode* root, int targetSum) {
    unordered_map<long, int> prefix;
    prefix[0] = 1; // base case: path from root
    return pathSumUtil(root, targetSum, 0, prefix);
}

/*
Alternative:
- Brute force: For each node, start a new path and check all paths. O(N^2)
- Above approach is optimal.
*/

/*
Dry Run:
Tree:      10
         /    \
        5     -3
       / \      \
      3   2      11
     / \   \
    3  -2   1
TargetSum = 8
Paths: [5,3], [5,2,1], [10,-3,11]
Returns 3.
*/

/*
================================================================================
4) Sum of Longest Bloodline (Longest Root-to-Leaf Path Sum)
================================================================================
Approach:
- Use DFS to track current path length and sum.
- Update max sum if longer path found, or if same length and sum is greater.
- Time Complexity: O(N)
- Space Complexity: O(H)

Code:
*/

void longestBloodlineUtil(TreeNode* root, int currLen, int currSum, int& maxLen, int& maxSum) {
    if (!root) return;
    currSum += root->val;
    currLen++;
    if (!root->left && !root->right) { // leaf node
        if (currLen > maxLen) {
            maxLen = currLen;
            maxSum = currSum;
        } else if (currLen == maxLen) {
            maxSum = max(maxSum, currSum);
        }
        return;
    }
    longestBloodlineUtil(root->left, currLen, currSum, maxLen, maxSum);
    longestBloodlineUtil(root->right, currLen, currSum, maxLen, maxSum);
}

int sumOfLongestBloodline(TreeNode* root) {
    int maxLen = 0, maxSum = 0;
    longestBloodlineUtil(root, 0, 0, maxLen, maxSum);
    return maxSum;
}

/*
Alternative:
- Can also be done using BFS with queue storing (node, currLen, currSum).
*/

/*
Dry Run:
Tree:      1
         /   \
        2     3
       / \     \
      4   5     6
Longest path: 1-2-4 (sum=7), 1-2-5 (sum=8), 1-3-6 (sum=10)
Returns 10.
*/
