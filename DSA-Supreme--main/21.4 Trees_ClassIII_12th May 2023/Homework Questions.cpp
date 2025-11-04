
/*
Approach and Improvements:

1) Efficient findPos using HashMap:
   - Instead of searching for an element's index in O(n) time in an array, we preprocess the array and store value->index mappings in an unordered_map (hashmap).
   - This allows O(1) lookup for any value's position.
   - This is especially useful in tree construction from traversals (like inorder/preorder/postorder).

2) Construct Binary Tree from Preorder and Postorder Traversal:
   - This is not always possible for a unique tree unless the tree is full (every node has 0 or 2 children).
   - The approach is to use recursion, keeping track of indices in preorder and postorder arrays.
   - We use a hashmap for O(1) index lookup in postorder.
   - Alternative: If inorder is available, construction is unique and easier.

3) Traversals:
   - Vertical Order Traversal: Use a map to group nodes by horizontal distance (hd) from root.
   - Zig Zag Traversal: Use a queue and reverse order at alternate levels.
   - Boundary Traversal: Print left boundary, leaves, and right boundary (in reverse).
   - Diagonal Traversal: Use a queue and map to group nodes by diagonal distance.

Below is the improved code with detailed comments and dry run at the end.
*/

// 1) Efficient findPos using HashMap

// Function to create value->index mapping for an array
unordered_map<int, int> createMapping(vector<int>& arr) {
    unordered_map<int, int> mp;
    for(int i = 0; i < arr.size(); i++) {
        mp[arr[i]] = i; // Store index of each value
    }
    return mp;
}

// Example usage:
// vector<int> inorder = {4,2,5,1,6,3,7};
// unordered_map<int,int> inMap = createMapping(inorder);
// Now, inMap[val] gives O(1) index of val in inorder

// 2) Construct a tree from preorder and postorder traversal (for full binary tree)

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d): data(d), left(NULL), right(NULL) {}
};

// Helper function to construct tree
Node* constructFromPrePost(vector<int>& pre, vector<int>& post, int& preIndex, int l, int r, unordered_map<int,int>& postMap) {
    if(preIndex >= pre.size() || l > r) return NULL;

    Node* root = new Node(pre[preIndex++]); // Create root from preorder

    // If there are no more children, return root
    if(l == r || preIndex >= pre.size()) return root;

    // Next preorder element is left child, find its index in postorder
    int idx = postMap[pre[preIndex]];

    // Recursively construct left and right subtrees
    root->left = constructFromPrePost(pre, post, preIndex, l, idx, postMap);
    root->right = constructFromPrePost(pre, post, preIndex, idx+1, r-1, postMap);

    return root;
}

// Usage:
// vector<int> pre = {1,2,4,5,3,6,7};
// vector<int> post = {4,5,2,6,7,3,1};
// unordered_map<int,int> postMap = createMapping(post);
// int preIndex = 0;
// Node* root = constructFromPrePost(pre, post, preIndex, 0, post.size()-1, postMap);

// Alternative (if inorder is available): Use preorder and inorder for unique tree construction.

// 3) Traversals

// a) Vertical Order Traversal
vector<vector<int>> verticalOrder(Node* root) {
    map<int, vector<int>> nodes; // hd -> list of nodes
    queue<pair<Node*, int>> q; // node, hd
    if(root) q.push({root, 0});
    while(!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        nodes[hd].push_back(node->data);
        if(node->left) q.push({node->left, hd-1});
        if(node->right) q.push({node->right, hd+1});
    }
    vector<vector<int>> res;
    for(auto& p : nodes) res.push_back(p.second);
    return res;
}

// b) Zig Zag Traversal (Level Order, alternate direction)
vector<vector<int>> zigzagLevelOrder(Node* root) {
    vector<vector<int>> res;
    if(!root) return res;
    queue<Node*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()) {
        int n = q.size();
        vector<int> level(n);
        for(int i=0; i<n; i++) {
            Node* node = q.front(); q.pop();
            int idx = leftToRight ? i : n-1-i;
            level[idx] = node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        res.push_back(level);
        leftToRight = !leftToRight;
    }
    return res;
}

// c) Boundary Traversal
void leftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while(curr) {
        if(curr->left || curr->right) res.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
void rightBoundary(Node* root, vector<int>& res) {
    vector<int> tmp;
    Node* curr = root->right;
    while(curr) {
        if(curr->left || curr->right) tmp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i=tmp.size()-1; i>=0; i--) res.push_back(tmp[i]);
}
void leaves(Node* root, vector<int>& res) {
    if(!root) return;
    if(!root->left && !root->right) res.push_back(root->data);
    leaves(root->left, res);
    leaves(root->right, res);
}
vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if(!root) return res;
    res.push_back(root->data);
    leftBoundary(root, res);
    leaves(root->left, res);
    leaves(root->right, res);
    rightBoundary(root, res);
    return res;
}

// d) Diagonal Traversal
vector<vector<int>> diagonalTraversal(Node* root) {
    vector<vector<int>> res;
    if(!root) return res;
    map<int, vector<int>> diag;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()) {
        auto [node, d] = q.front(); q.pop();
        diag[d].push_back(node->data);
        if(node->left) q.push({node->left, d+1});
        if(node->right) q.push({node->right, d});
    }
    for(auto& p : diag) res.push_back(p.second);
    return res;
}

/*
Dry Run Example (for constructFromPrePost):

pre = [1,2,4,5,3,6,7]
post = [4,5,2,6,7,3,1]

Step 1: preIndex=0, root=1
    Next pre[1]=2, postMap[2]=2
    left: l=0, r=2 (post[0..2])
        preIndex=1, root=2
        Next pre[2]=4, postMap[4]=0
        left: l=0, r=0
            preIndex=2, root=4 (leaf)
        right: l=1, r=1
            preIndex=3, root=5 (leaf)
    right: l=3, r=5 (post[3..5])
        preIndex=4, root=3
        Next pre[5]=6, postMap[6]=3
        left: l=3, r=3
            preIndex=5, root=6 (leaf)
        right: l=4, r=4
            preIndex=6, root=7 (leaf)

Tree constructed:
        1
      /   \
     2     3
    / \   / \
   4  5  6  7

All traversals will work as expected on this tree.

Alternative approaches:
- For unique tree construction, prefer preorder+inorder or postorder+inorder.
- For traversals, can use iterative or recursive methods as per need.
*/
