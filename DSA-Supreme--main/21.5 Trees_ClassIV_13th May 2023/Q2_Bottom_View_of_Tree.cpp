/*
    Approach Used:
    --------------
    - The code constructs a binary tree from user input using recursion.
    - It then prints the bottom view of the binary tree using level order traversal (BFS).
    - For the bottom view, we keep track of the horizontal distance (hd) of each node from the root.
    - We use a map to store the latest node's value at each horizontal distance encountered during BFS.
    - At the end, the map contains the bottommost node for each horizontal distance, which is the bottom view.

    Better Alternatives:
    --------------------
    1. Use unordered_map for faster access if order is not required, but for bottom view, we need sorted order of hd, so map is fine.
    2. Instead of printing hd->value, print only the values in left-to-right order for a cleaner bottom view.
    3. For large trees, iterative tree construction (level order) can be used for efficiency.
    4. For input, a vector or array can be used to build the tree without repeated user prompts.

    Alternative Bottom View Code (Cleaner Output):
    ----------------------------------------------
    // void printBottomView(Node* root) {
    //     if (!root) return;
    //     map<int, int> hdNode;
    //     queue<pair<Node*, int>> q;
    //     q.push({root, 0});
    //     while (!q.empty()) {
    //         auto [node, hd] = q.front(); q.pop();
    //         hdNode[hd] = node->data;
    //         if (node->left) q.push({node->left, hd-1});
    //         if (node->right) q.push({node->right, hd+1});
    //     }
    //     for (auto& [hd, val] : hdNode) cout << val << " ";
    //     cout << endl;
    // }

    Dry Run Example:
    ----------------
    Input (preorder with -1 as NULL): 10 20 40 -1 -1 50 -1 -1 30 -1 60 -1 -1
    Tree:
            10
           /  \
         20    30
        /  \     \
      40   50    60

    Bottom View: 40 20 50 30 60

*/

#include <iostream>
#include <queue>
#include <map>

using namespace std;

// Node class for binary tree
class Node
{
public:
    int data;       // Value of the node
    Node *left;     // Pointer to left child
    Node *right;    // Pointer to right child

    // Constructor to initialize node with data
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
    // Base case: -1 means no node (NULL)
    if (data == -1)
    {
        return NULL;
    }

    // Create new node with given data
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

    // Return constructed subtree root
    return root;
}

// Function to print tree level by level (BFS)
void levelOrderTraversal(Node *root)
{
    // If tree is empty, return
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;        // Queue for BFS
    q.push(root);           // Start with root
    q.push(NULL);           // Level marker

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
            cout << temp->data << " "; // Print node data

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

// Function to print the bottom view of the binary tree
void printBottomView(Node* root){
    if(root == NULL){
        // If tree is empty, nothing to print
        return;
    }

    // Map to store the last node's value at each horizontal distance (hd)
    map<int,int> bottomNode;

    // Queue for BFS: stores pairs of (node pointer, horizontal distance)
    queue<pair<Node*,int>> q;

    // Start BFS with root at hd = 0
    q.push(make_pair(root,0));

    while(!q.empty()){
        // Get the front node and its horizontal distance
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        // For bottom view, always update the value at hd
        bottomNode[hd] = frontNode->data;

        // If left child exists, enqueue with hd-1
        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        // If right child exists, enqueue with hd+1
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    // Print the bottom view (leftmost to rightmost)
    cout << "Bottom View: ";
    for(auto i : bottomNode){
        cout << i.second << " ";
    }
    cout << endl;

    // If you want to see the mapping of hd to value, uncomment below:
    // for(auto i : bottomNode){
    //     cout << "hd " << i.first << " -> " << i.second << endl;
    // }
}

int main()
{
    /*
        Example Input for Dry Run:
        Enter the data for left child of 10
        20
        Enter the data for left child of 20
        40
        Enter the data for left child of 40
        -1
        Enter the data for right child of 40
        -1
        Enter the data for right child of 20
        50
        Enter the data for left child of 50
        -1
        Enter the data for right child of 50
        -1
        Enter the data for right child of 10
        30
        Enter the data for left child of 30
        -1
        Enter the data for right child of 30
        60
        Enter the data for left child of 60
        -1
        Enter the data for right child of 60
        -1

        Output:
        Bottom View: 40 20 50 30 60
    */

    // Build tree from user input (root data is 10)
    Node* root = buildTree(10);

    // Print bottom view of the tree
    printBottomView(root);

    return 0;
}

/*
Dry Run:
--------
Input: 10 20 40 -1 -1 50 -1 -1 30 -1 60 -1 -1

Tree Structure:
        10
       /  \
     20    30
    /  \     \
  40   50    60

Horizontal Distances (hd):
- 40: hd = -2
- 20: hd = -1
- 10: hd = 0
- 50: hd = 0
- 30: hd = 1
- 60: hd = 2

BFS Traversal:
- Visit 10 (hd=0): bottomNode[0]=10
- Visit 20 (hd=-1): bottomNode[-1]=20
- Visit 30 (hd=1): bottomNode[1]=30
- Visit 40 (hd=-2): bottomNode[-2]=40
- Visit 50 (hd=0): bottomNode[0]=50 (overwrites 10)
- Visit 60 (hd=2): bottomNode[2]=60

Final bottomNode map:
-2: 40
-1: 20
 0: 50
 1: 30
 2: 60

Bottom View Output: 40 20 50 30 60
*/