/*
    Approach Used:
    ----------------
    Given a sorted inorder traversal array, the task is to construct a height-balanced Binary Search Tree (BST).
    The optimal way is to always pick the middle element as the root, recursively for left and right subarrays.
    This ensures the tree is as balanced as possible.

    Steps:
    1. Find the middle element of the current subarray, make it the root.
    2. Recursively repeat for left subarray (elements before mid) and right subarray (elements after mid).
    3. Use level order traversal to print the tree.

    Time Complexity: O(N), where N is the number of nodes.
    Space Complexity: O(logN) for recursion stack (balanced tree).
*/

#include<iostream>
#include<queue>
using namespace std;

// Node class for BST
class Node{
    public:
        int data;       // Value of the node
        Node* left;     // Pointer to left child
        Node* right;    // Pointer to right child

        // Constructor to initialize node with data and null children
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

/*
    Function: levelOrderTraversal
    ----------------------------
    Prints the tree in level order (BFS), each level on a new line.
    Uses a queue to traverse nodes level by level.
*/
void levelOrderTraversal(Node *root)
{
    // If tree is empty, nothing to print
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;        // Queue for BFS
    q.push(root);           // Start with root node
    q.push(NULL);           // NULL as marker for end of level

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
            cout << temp->data << " "; // Print current node

            // If left child exists, add to queue
            if (temp->left)
            {
                q.push(temp->left);
            }
            // If right child exists, add to queue
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

/*
    Function: bstUsingInorder
    -------------------------
    Recursively builds a balanced BST from a sorted inorder array.

    Parameters:
        inorder[] : sorted array (inorder traversal of BST)
        s         : start index
        e         : end index

    Returns:
        Pointer to root of constructed BST
*/
Node *bstUsingInorder(int inorder[], int s, int e){
    // Base Case: If subarray is invalid, return NULL (no node)
    if(s > e){
        return NULL;
    }

    // Find middle index to keep tree balanced
    int mid = s + (e - s) / 2;
    int element = inorder[mid];           // Middle element becomes root

    Node* root = new Node(element);       // Create node with middle element

    // Recursively build left subtree from left subarray
    root->left = bstUsingInorder(inorder, s, mid - 1);

    // Recursively build right subtree from right subarray
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;                          // Return root of subtree
}

int main(){
    // Example inorder traversal (sorted array)
    int inorder[] = {10,20,30,40,50,60,70,80,90};
    int s = 0;
    int e = 8; // last index

    // Build BST from inorder array
    Node* root = bstUsingInorder(inorder, s, e);

    // Print BST in level order
    levelOrderTraversal(root);

    return 0;
}

/*
    Alternative Approaches (with code in comments):

    1. Iterative Approach:
        - It is possible to build BST iteratively using a queue and range information, but recursion is more natural and concise for this problem.

    2. Using vector instead of array:
        - If input is a vector, code can be adapted to use vector<int>& inorder and pass by reference.

    3. For unbalanced BST (not required here):
        - If the inorder array is not sorted, or if you want to build an unbalanced BST, you can insert elements one by one.

    // Example: Insert one by one (not balanced)
    Node* insertBST(Node* root, int data) {
        if (!root) return new Node(data);
        if (data < root->data) root->left = insertBST(root->left, data);
        else root->right = insertBST(root->right, data);
        return root;
    }
    // for (int i = 0; i < n; ++i) root = insertBST(root, inorder[i]);

    4. Using STL vector for dynamic input:
    // vector<int> inorder = {10,20,30,40,50,60,70,80,90};
    // Node* root = bstUsingInorder(inorder, 0, inorder.size()-1);

    5. For large trees, consider iterative level order traversal to avoid stack overflow.

    Dry Run:
    --------
    Input: inorder[] = {10,20,30,40,50,60,70,80,90}
    s = 0, e = 8

    1st call: mid = 4, element = 50 -> root = 50
        left: s=0, e=3
            mid=1, element=20 -> left child = 20
                left: s=0, e=0
                    mid=0, element=10 -> left child = 10
                        left: s=0, e=-1 -> NULL
                        right: s=1, e=0 -> NULL
                right: s=2, e=3
                    mid=2, element=30 -> right child = 30
                        left: s=2, e=1 -> NULL
                        right: s=3, e=3
                            mid=3, element=40 -> right child = 40
                                left: s=3, e=2 -> NULL
                                right: s=4, e=3 -> NULL
        right: s=5, e=8
            mid=6, element=70 -> right child = 70
                left: s=5, e=5
                    mid=5, element=60 -> left child = 60
                        left: s=5, e=4 -> NULL
                        right: s=6, e=5 -> NULL
                right: s=7, e=8
                    mid=7, element=80 -> right child = 80
                        left: s=7, e=6 -> NULL
                        right: s=8, e=8
                            mid=8, element=90 -> right child = 90
                                left: s=8, e=7 -> NULL
                                right: s=9, e=8 -> NULL

    Level order output:
    50
    20 70
    10 30 60 80
    40 90

*/