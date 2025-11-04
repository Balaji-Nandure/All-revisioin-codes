
/*
Approach 1: Left View of Binary Tree using Level Order Traversal (BFS)
- We use a queue to perform level order traversal.
- For each level, the first node we encounter is the leftmost node of that level.
- We print/store this node as part of the left view.

Time Complexity: O(N), where N is the number of nodes.
Space Complexity: O(N), for the queue.

Alternative: We can also use DFS (preorder traversal) to achieve the left view with less space.

Below is the code with detailed comments:
*/

#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to print left view using Level Order Traversal (BFS)
void leftViewBFS(Node* root) {
    if (!root) return; // If tree is empty, return

    queue<Node*> q; // Queue for level order traversal
    q.push(root);

    while (!q.empty()) {
        int n = q.size(); // Number of nodes at current level

        for (int i = 0; i < n; ++i) {
            Node* curr = q.front();
            q.pop();

            // The first node at each level is the leftmost node
            if (i == 0) {
                cout << curr->data << " ";
            }

            // Enqueue left child first to ensure leftmost node is processed first
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    cout << endl;
}

/*
Approach 2: Left View using Map (DFS)
- We use a map to store the first node at each level.
- We traverse the tree using preorder traversal (root-left-right).
- For each level, if it is not present in the map, we add the node's data.

Time Complexity: O(N)
Space Complexity: O(N) for the map and recursion stack.

Below is the code with detailed comments:
*/

void leftViewDFSUtil(Node* root, int level, map<int, int>& leftViewMap) {
    if (!root) return;

    // If this level is not present in map, add the node's data
    if (leftViewMap.find(level) == leftViewMap.end()) {
        leftViewMap[level] = root->data;
    }

    // Traverse left subtree first to ensure leftmost node is stored
    leftViewDFSUtil(root->left, level + 1, leftViewMap);
    leftViewDFSUtil(root->right, level + 1, leftViewMap);
}

void leftViewDFS(Node* root) {
    map<int, int> leftViewMap; // Map to store first node at each level
    leftViewDFSUtil(root, 0, leftViewMap);

    // Print the left view from the map
    for (auto it : leftViewMap) {
        cout << it.second << " ";
    }
    cout << endl;
}

/*
Alternative (Better) Approach: Left View using DFS without Map (using maxLevel variable)
- We can avoid using a map by keeping track of the maximum level visited so far.
- For each recursive call, if the current level is greater than maxLevel, we print/store the node.

Code:
*/
// Helper function for DFS left view without map
void leftViewDFSNoMapUtil(Node* root, int level, int& maxLevel) {
    if (!root) return;

    // If this is the first node of its level
    if (level > maxLevel) {
        cout << root->data << " ";
        maxLevel = level;
    }

    // Traverse left subtree first
    leftViewDFSNoMapUtil(root->left, level + 1, maxLevel);
    leftViewDFSNoMapUtil(root->right, level + 1, maxLevel);
}

void leftViewDFSNoMap(Node* root) {
    int maxLevel = -1;
    leftViewDFSNoMapUtil(root, 0, maxLevel);
    cout << endl;
}

/*
Dry Run Example:

Consider the following tree:
        1
       / \
      2   3
     / \   \
    4   5   6
         \
          7

Level Order Traversal (BFS):
Level 0: 1         -> leftmost: 1
Level 1: 2 3       -> leftmost: 2
Level 2: 4 5 6     -> leftmost: 4
Level 3: 7         -> leftmost: 7

Left View Output: 1 2 4 7

DFS with map or maxLevel will also output: 1 2 4 7

*/
