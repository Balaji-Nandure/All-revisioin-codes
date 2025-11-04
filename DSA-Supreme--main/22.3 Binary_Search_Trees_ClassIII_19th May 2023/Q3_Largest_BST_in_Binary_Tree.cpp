/*
Approach Used:
---------------
We use a bottom-up postorder traversal to find the largest BST in a binary tree. 
For each node, we recursively check its left and right subtrees, and gather:
    - size of the largest BST in the subtree
    - min and max values in the subtree
    - whether the subtree is a valid BST

If both left and right subtrees are BSTs and the current node's value is greater than the max in the left subtree and less than the min in the right subtree, then the subtree rooted at the current node is also a BST. We update the answer accordingly.

Time Complexity: O(N), where N is the number of nodes in the tree.
Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

Alternative Approaches (in comments at the end):
------------------------------------------------
1. Brute Force: For every node, check if the subtree rooted at that node is a BST and count its size. This is O(N^2).
2. Morris Traversal: Not suitable for this problem as we need to check BST property for all subtrees.

*/

// Include necessary headers
#include<iostream>
#include<queue>
#include<climits> // For INT_MIN and INT_MAX
using namespace std;

// Node structure for the binary tree
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// Helper class to store information about subtree
class NodeData{
    public:
        int size;       // Size of the subtree
        int minVal;     // Minimum value in the subtree
        int maxVal;     // Maximum value in the subtree
        bool validBST;  // Is the subtree a valid BST?
        NodeData(){
            // Default constructor
            size = 0;
            minVal = INT_MAX;
            maxVal = INT_MIN;
            validBST = true;
        }
        NodeData(int size,int max,int min,bool valid){
            this->size = size;
            minVal = min;
            maxVal = max;
            validBST = valid;
        }
};

// Function to find the largest BST in a binary tree
NodeData findLargestBST(Node* root,int &ans){
    // Base Case: If node is NULL, it's a valid BST of size 0
    if(root == NULL){
        NodeData temp(0,INT_MIN,INT_MAX,true);
        return temp;
    }

    // Recursively find info for left subtree
    NodeData leftAns = findLargestBST(root->left,ans);

    // Recursively find info for right subtree
    NodeData rightAns = findLargestBST(root->right,ans);

    // Prepare current node's data
    NodeData currNode;
    currNode.size = leftAns.size + rightAns.size + 1; // Size includes left, right, and current node

    // The minimum value in the current subtree
    currNode.minVal = min(root->data, leftAns.minVal);
    // The maximum value in the current subtree
    currNode.maxVal = max(root->data, rightAns.maxVal);

    // Check if the current subtree is a BST:
    // 1. Left and right subtrees must be BSTs
    // 2. Current node's value must be greater than max in left subtree
    // 3. Current node's value must be less than min in right subtree
    if(leftAns.validBST && rightAns.validBST && (root->data > leftAns.maxVal && root->data < rightAns.minVal)){
        currNode.validBST = true;
    }
    else{
        currNode.validBST = false;
    }

    // If current subtree is a BST, update the answer
    if(currNode.validBST){
        ans = max(ans,currNode.size);
    }

    // Return current node's data to parent call
    return currNode;
}

int main(){
    /*
    Constructing the following tree:
            5
           / \
          2   4
         / \
        1   3
    */
    Node* root = new Node(5);
    Node* first = new Node(2);
    Node* second = new Node(4);
    Node* third = new Node(1);
    Node* fourth = new Node(3);
    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;

    int ans = 0; // To store the size of the largest BST
    findLargestBST(root,ans);
    cout<<"Largest BST size = "<<ans<<endl;

    return 0;
}

/*
-------------------------------
Dry Run of the Above Example:
-------------------------------
Tree:
        5
       / \
      2   4
     / \
    1   3

- Node 1: left/right NULL, valid BST, size=1, min=1, max=1
- Node 3: left/right NULL, valid BST, size=1, min=3, max=3
- Node 2: left=1 (BST), right=3 (BST), 2>1, 2<3 => valid BST, size=3, min=1, max=3
- Node 4: left/right NULL, valid BST, size=1, min=4, max=4
- Node 5: left=2 (BST), right=4 (BST), 5>3, 5<4 => 5<4 is false, so not a BST

Largest BST is the subtree rooted at 2 (size=3).

Output:
Largest BST size = 3

---------------------------------
Alternative (Brute Force) Approach:
---------------------------------
/*
int countNodes(Node* root) {
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isBST(Node* root, int minV, int maxV) {
    if(!root) return true;
    if(root->data <= minV || root->data >= maxV) return false;
    return isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV);
}
int largestBST(Node* root) {
    if(!root) return 0;
    if(isBST(root, INT_MIN, INT_MAX)) return countNodes(root);
    return max(largestBST(root->left), largestBST(root->right));
}
Time Complexity: O(N^2)
*/