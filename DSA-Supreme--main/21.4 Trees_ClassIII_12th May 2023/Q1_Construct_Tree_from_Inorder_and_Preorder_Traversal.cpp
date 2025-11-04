/*
    Approach Used:
    ----------------
    Given preorder and inorder traversals of a binary tree, the task is to construct the binary tree.

    - Preorder traversal: [Root][Left][Right]
    - Inorder traversal:  [Left][Root][Right]

    Steps:
    1. The first element in preorder is always the root.
    2. Find the root in inorder to determine the left and right subtree boundaries.
    3. Recursively repeat for left and right subtrees.

    Optimization:
    - To avoid O(n) search for root in inorder, use a hashmap to store value->index mapping for inorder traversal.

    Alternatives:
    -------------
    - Instead of using array and index, you can use vector and iterators for more flexibility.
    - You can also reconstruct the tree using postorder and inorder traversals (with similar logic).
    - For very large trees, iterative approaches or stack-based solutions can be considered.

    Dry Run Example at the end of code.
*/

#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

// Node class for tree node
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

/*
    // Alternative: If you don't want to use hashmap, you can use this function
    // to find the index of the root in inorder traversal (O(n) time).
    int findPos(int arr[],int n,int element){
        for(int i = 0;i<n;i++){
            if(arr[i]==element){
                return i;
            }
        }
        return -1;
    }
*/

// Function to build the tree from inorder and preorder traversal
Node* buildTree(
    int inorder[],           // inorder traversal array
    int preorder[],          // preorder traversal array
    int size,                // size of arrays
    int &preIndex,           // current index in preorder array (passed by reference)
    int inorderStart,        // start index for current inorder subarray
    int inorderEnd,          // end index for current inorder subarray
    unordered_map<int,int>&mapping // hashmap for inorder value->index
){
    // Base case: if no elements to construct subtree
    if(preIndex >= size || inorderStart > inorderEnd){
        return NULL;
    }

    // Step 1: Pick current node from Preorder traversal using preIndex and increment preIndex
    int element = preorder[preIndex++];
    Node* root = new Node(element); // Create the root node

    // Step 2: Find the index of this node in Inorder traversal to split left/right subtree
    int pos = mapping[element];

    // Step 3: Recursively build left subtree
    root->left = buildTree(inorder,preorder,size,preIndex,inorderStart,pos-1,mapping);

    // Step 4: Recursively build right subtree
    root->right = buildTree(inorder,preorder,size,preIndex,pos+1,inorderEnd,mapping);

    // Step 5: Return constructed subtree root
    return root;
}

// Function to create a mapping from node value to its index in inorder traversal
void createMapping(unordered_map<int,int>&mapping,int inorder[],int n){
    for(int i = 0;i<n;i++){
        mapping[inorder[i]] = i; // Store value->index for O(1) lookup
    }
}

// Function to print level order traversal (BFS) of the tree
void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        // Tree is empty
        return;
    }
    queue<Node *> q;
    q.push(root);    // Start with root node
    q.push(NULL);    // Level marker

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // End of current level
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL); // Add marker for next level
            }
        }
        else
        {
            cout << temp->data << " "; // Print current node

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

int main(){
    // Example input
    int inorder[] = {3,1,4,5,2};      // Inorder traversal
    int preorder[] = {5,1,3,4,2};     // Preorder traversal
    int size = 5;                     // Number of nodes

    int preIndex = 0;                 // Initialize preorder index
    int inorderStart = 0;             // Start index for inorder
    int inorderEnd = size-1;          // End index for inorder

    unordered_map<int,int>mapping;    // Hashmap for inorder value->index
    createMapping(mapping,inorder,size); // Build the mapping

    cout<<"Building tree"<<endl;
    Node* root = buildTree(inorder,preorder,size,preIndex,inorderStart,inorderEnd,mapping);

    cout<<"Printing the tree (Level Order):"<<endl;
    levelOrderTraversal(root);

    return 0;
}

/*
    -------------------------------
    Dry Run for Example Input:
    -------------------------------
    inorder[]  = {3,1,4,5,2}
    preorder[] = {5,1,3,4,2}

    Step 1: preIndex=0, preorder[0]=5 => root=5
            Find 5 in inorder at index 3
            Left subtree: inorder[0..2] (3,1,4)
            Right subtree: inorder[4..4] (2)

    Step 2: preIndex=1, preorder[1]=1 => root->left=1
            Find 1 in inorder at index 1
            Left subtree: inorder[0..0] (3)
            Right subtree: inorder[2..2] (4)

    Step 3: preIndex=2, preorder[2]=3 => root->left->left=3
            Find 3 in inorder at index 0
            Left: inorder[0..-1] => NULL
            Right: inorder[1..0] => NULL

    Step 4: preIndex=3, preorder[3]=4 => root->left->right=4
            Find 4 in inorder at index 2
            Left: inorder[2..1] => NULL
            Right: inorder[3..2] => NULL

    Step 5: preIndex=4, preorder[4]=2 => root->right=2
            Find 2 in inorder at index 4
            Left: inorder[4..3] => NULL
            Right: inorder[5..4] => NULL

    Final Tree:
            5
           / \
          1   2
         / \
        3   4

    Level Order Output:
    5
    1 2
    3 4

    -------------------------------
    Alternative Approach (with code):
    -------------------------------
    // Using vector and iterators for more flexibility:
    Node* buildTree(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int,int>& mapping) {
        if(preStart > preEnd || inStart > inEnd) return NULL;
        int rootVal = preorder[preStart];
        Node* root = new Node(rootVal);
        int inRoot = mapping[rootVal];
        int numsLeft = inRoot - inStart;
        root->left = buildTree(preorder, preStart+1, preStart+numsLeft,
                               inorder, inStart, inRoot-1, mapping);
        root->right = buildTree(preorder, preStart+numsLeft+1, preEnd,
                                inorder, inRoot+1, inEnd, mapping);
        return root;
    }
*/