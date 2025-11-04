/*

    Approach Used: 
    ----------------
    The code builds a binary tree from user input and prints the top view of the tree.
    The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
    To achieve this, we use a level order traversal (BFS) and track the horizontal distance (HD) of each node from the root.
    For each HD, we store the first node encountered (since it will be the topmost node for that HD).
    We use a map to store the first node at each HD.

    Steps:
    1. Build the tree recursively from user input.
    2. Traverse the tree in level order, keeping track of HD.
    3. For each HD, store the first node encountered.
    4. Print the nodes in order of their HDs (from leftmost to rightmost).

    Better Alternatives:
    --------------------
    - Instead of std::map (which is O(log n) for insert/find), we can use std::unordered_map for O(1) average time, but then we need to find min/max HD for ordered output.
    - For large trees, we can optimize input by using a vector or array for level order input.
    - For top view, a DFS approach is possible but more complex and less intuitive for this problem.

    Alternative Code for Top View (using unordered_map and min/max HD):
    -------------------------------------------------------------------
    // See the comment block at the end of this file for an alternative implementation.

    Dry Run Example:
    ----------------
    Input (preorder, -1 for NULL): 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
    Tree:
            1
           / \
          2   3
         / \   \
        4   5   6

    Top View: 4 2 1 3 6
*/

#include <iostream>
#include <queue>
#include <map>

using namespace std;

// Node class for binary tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize node data and children
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build tree recursively from user input
Node *buildTree(int data)
{
    // Base case: -1 means no node (leaf's child)
    if (data == -1)
    {
        return NULL;
    }
    // Create the root node with given data
    Node *root = new Node(data);

    // Input for left child
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    // Recursively build left subtree
    root->left = buildTree(leftData);

    // Input for right child
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    // Recursively build right subtree
    root->right = buildTree(rightData);

    return root;
}

// Function to print the tree level-wise (BFS)
void levelOrderTraversal(Node *root)
{
    // If tree is empty, return
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // Start with root node
    q.push(root);
    // Level marker (NULL)
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // End of current level
            cout << endl;
            // If more nodes exist, add level marker
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // Add left child if exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // Add right child if exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

/*
    Function to print the top view of a binary tree.
    Logic:
    - Use BFS to traverse the tree level by level.
    - For each node, track its horizontal distance (HD) from the root.
    - For each HD, store the first node encountered (topmost node at that HD).
    - Use a map to store HD -> node data.
    - At the end, print the map in order of HD (leftmost to rightmost).
*/
void printTopView(Node* root){
    if(root == NULL){
        // If tree is empty, nothing to print
        return;
    }
    // Map to store the first node at each horizontal distance (HD)
    map<int,int> topNode; // key: HD, value: node data

    // Queue for BFS: stores pairs of (node pointer, HD)
    queue<pair<Node*,int>> q;

    // Start BFS with root at HD = 0
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first; // Current node
        int hd = temp.second;         // Current node's HD

        // If this HD is not already present in map, add it
        // (first node encountered at this HD from top)
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        // If left child exists, enqueue with HD - 1
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        // If right child exists, enqueue with HD + 1
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    // Print the top view nodes in order of HD (left to right)
    cout<<"Printing the top view"<<endl;
    for(auto i : topNode){
        cout<<i.second<<" "; // Only print node data for top view
    }
    cout << endl;
}

/*
    Alternative Efficient Approach (using unordered_map and min/max HD):
    --------------------------------------------------------------------
    #include <unordered_map>
    void printTopViewAlt(Node* root) {
        if(!root) return;
        unordered_map<int, int> topNode;
        queue<pair<Node*, int>> q;
        int minHD = 0, maxHD = 0;
        q.push({root, 0});
        while(!q.empty()) {
            auto [node, hd] = q.front(); q.pop();
            if(topNode.find(hd) == topNode.end()) topNode[hd] = node->data;
            minHD = min(minHD, hd);
            maxHD = max(maxHD, hd);
            if(node->left) q.push({node->left, hd-1});
            if(node->right) q.push({node->right, hd+1});
        }
        for(int hd = minHD; hd <= maxHD; ++hd) {
            if(topNode.count(hd)) cout << topNode[hd] << " ";
        }
        cout << endl;
    }
*/

/*
    Dry Run Example:
    ----------------
    Input (preorder, -1 for NULL): 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

    Tree:
            1
           / \
          2   3
         / \   \
        4   5   6

    BFS Traversal with HD:
    - Start with (1,0)
    - Enqueue (2,-1), (3,1)
    - Enqueue (4,-2), (5,0), (6,2)
    - Map after traversal: {-2:4, -1:2, 0:1, 1:3, 2:6}
    - Top View: 4 2 1 3 6
*/

int main()
{
    // Build tree from user input (root data is 10 for initial call)
    Node* root = buildTree(10);

    // Print the top view of the tree
    printTopView(root);

    // Uncomment to print level order traversal for debugging
    // levelOrderTraversal(root);

    return 0;
}