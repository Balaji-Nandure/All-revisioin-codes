/*
Approach Used:
---------------
We are building a binary tree from user input (using -1 as a marker for NULL/leaf nodes), and then printing the right view of the tree.
The right view of a binary tree is the set of nodes visible when the tree is viewed from the right side.

The right view is computed using a modified pre-order traversal (root, right, left), and for each level, we only add the first node we encounter (which will be the rightmost node at that level).

Key Points:
-----------
- Tree is built recursively from user input.
- Right view is computed recursively by traversing right child before left child.
- For each level, if it's the first time we reach that level, we add the node's data to the answer.
- Level order traversal function is provided for debugging/visualization.

Alternative Approaches:
----------------------
1. **Level Order Traversal (BFS) Approach**:
   - Traverse the tree level by level using a queue.
   - For each level, the last node encountered is the rightmost node for that level.
   - This approach is iterative and can be more intuitive for some.

   // See detailed code for this approach in the comments at the end.

2. **DFS with Map**:
   - Use a map to store the last node at each level during a normal pre-order traversal.
   - At the end, the map contains the rightmost node for each level.

Improvements Made:
------------------
- Added detailed comments for all important lines.
- Improved variable naming for clarity.
- Added dry run at the end.
- Provided alternative approach code in comments.

*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

// Node structure for the binary tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to build the binary tree recursively from user input
Node *buildTree(int data)
{
    // Base Case: If data is -1, this is a NULL node (no child)
    if (data == -1)
    {
        return NULL;
    }
    // Create a new node with the given data
    Node *root = new Node(data);

    // Input for left child
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    // Recursively build the left subtree
    root->left = buildTree(leftData);

    // Input for right child
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    // Recursively build the right subtree
    root->right = buildTree(rightData);

    // Return the constructed subtree rooted at 'root'
    return root;
}

// Function to print the tree level-wise (for debugging/visualization)
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
    // Marker for end of current level
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // End of current level, print newline
            cout << endl;
            // If there are more nodes, add marker for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // Print current node's data
            cout << temp->data << " ";
            // Enqueue left child if exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // Enqueue right child if exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Recursive function to compute the right view of the binary tree
void printRightView(Node* root, vector<int>& ans, int level)
{
    // Base case: If node is NULL, return
    if (root == NULL)
    {
        return;
    }
    // If this is the first node at this level, add it to the answer
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    // First, traverse the right subtree (so rightmost nodes are visited first)
    printRightView(root->right, ans, level + 1);
    // Then, traverse the left subtree
    printRightView(root->left, ans, level + 1);
}

int main()
{
    // Build the tree from user input (root data is 10)
    Node* root = buildTree(10);

    // Vector to store the right view nodes
    vector<int> ans;
    // Compute the right view starting from root at level 0
    printRightView(root, ans, 0);

    // Print the right view
    cout << "Right view of the tree: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    // Optional: Print the tree level-wise for visualization
    // cout << "Level order traversal:" << endl;
    // levelOrderTraversal(root);

    return 0;
}

/*
-------------------------------
Alternative Approach 1: BFS (Level Order Traversal)
-------------------------------
This approach uses a queue to traverse the tree level by level and prints the last node at each level.

void rightViewBFS(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 1; i <= n; ++i) {
            Node* temp = q.front();
            q.pop();
            // If it's the last node of this level, print it
            if (i == n) cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}

-------------------------------
Alternative Approach 2: DFS with Map
-------------------------------
void rightViewDFS(Node* root, int level, map<int, int>& mp) {
    if (!root) return;
    mp[level] = root->data; // Overwrite, so rightmost stays
    rightViewDFS(root->left, level + 1, mp);
    rightViewDFS(root->right, level + 1, mp);
}
// At the end, print mp[0], mp[1], ... for right view

-------------------------------
Dry Run Example:
-------------------------------
Suppose the input is:
10
20
40
-1
-1
50
-1
-1
30
-1
60
-1
-1

The tree is:
        10
       /  \
     20    30
    /  \     \
  40   50    60

Right view traversal:
- Level 0: 10 (first node at level 0)
- Level 1: 30 (right child of 10, first at level 1)
- Level 2: 60 (right child of 30, first at level 2)

So, output: 10 30 60

-------------------------------
Time Complexity:
-------------------------------
- Both approaches: O(N), where N is the number of nodes in the tree.
- Space: O(H) for recursion stack (H = height), O(N) for answer vector.

*/