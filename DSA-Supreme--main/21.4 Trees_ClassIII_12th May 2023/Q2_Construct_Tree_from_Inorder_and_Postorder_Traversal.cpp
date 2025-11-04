/*
    Approach Used:
    ----------------
    Given inorder and postorder traversals of a binary tree, the task is to construct the binary tree.

    - Postorder traversal: [Left][Right][Root]
    - Inorder traversal:   [Left][Root][Right]

    Steps:
    1. The last element in postorder is always the root of the (sub)tree.
    2. Find the root in inorder to determine the left and right subtree boundaries.
    3. Recursively repeat for right and left subtrees (note: right first, because postorder is traversed from end).

    Optimizations:
    - Use a hashmap to store value->index mapping for inorder traversal for O(1) lookup, instead of O(n) linear search.

    Better/Alternative Approaches:
    -----------------------------
    1. **Iterative Construction (using stack):**
       - For some tree construction problems, iterative stack-based approaches can be used, but for this specific problem, recursion is most natural and clear.

    2. **Generalization for Unique Trees:**
       - If the tree contains duplicate values, mapping should be value+index or use a multimap.

    3. **If only preorder and postorder are given (no inorder):**
       - Unique construction is not always possible unless the tree is full (every node has 0 or 2 children).

    Example code for iterative approach (not recommended for this problem, but for reference):
    -----------------------------------------------------
    // Not included here as recursion is more natural for this problem.

    Dry Run Example at the end of this file.
*/

#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

// Node structure for binary tree
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data = data;      // Assign data to node
            this->left = NULL;      // Initialize left child as NULL
            this->right = NULL;     // Initialize right child as NULL
        }
};

/*
    Function to create value->index mapping for inorder array.
    This allows O(1) lookup for any value's position in inorder traversal.
*/
void createMapping(unordered_map<int,int>&mapping, int inorder[], int n){
    for(int i = 0; i < n; i++){
        mapping[inorder[i]] = i;    // Map value to its index in inorder
    }
}

/*
    Recursive function to build the tree from inorder and postorder traversal.
    postIndex: current index in postorder array (passed by reference, decremented as we build tree)
    inorderStart, inorderEnd: current subtree boundaries in inorder array
    mapping: value->index mapping for inorder array
*/
Node* buildTree(int inorder[], int postorder[], int size, int &postIndex, int inorderStart, int inorderEnd, unordered_map<int,int>&mapping){
    // Base case: if no elements to construct subtree
    if(postIndex < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    // The current root is the last element in postorder (for this subtree)
    int element = postorder[postIndex--];
    Node* root = new Node(element); // Create root node

    // Find the index of root in inorder traversal (O(1) using mapping)
    int pos = mapping[element];

    // Important: Build right subtree first, then left subtree
    // Because in postorder, right subtree comes just before root (when traversing from end)
    root->right = buildTree(inorder, postorder, size, postIndex, pos+1, inorderEnd, mapping);

    // Build left subtree
    root->left = buildTree(inorder, postorder, size, postIndex, inorderStart, pos-1, mapping);

    // Return constructed subtree root
    return root;
}

/*
    Function to print the tree in level order (BFS).
    Each level is printed on a new line.
*/
void levelOrderTraversal(Node *root)
{
    // If tree is empty, return
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);      // Push root node
    q.push(NULL);      // Level marker

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // End of current level
            cout << endl;
            // If there are more nodes, add another level marker
            if (!q.empty())
            {
                q.push(NULL);
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
    int inorder[] = {40,20,10,50,30,60};         // Inorder traversal
    int postOrder[] = {40,20,50,60,30,10};       // Postorder traversal
    int size = 6;                                // Number of nodes

    int postIndex = size-1;                      // Start from last index of postorder
    int inorderStart = 0;                        // Start index for inorder
    int inorderEnd = size-1;                     // End index for inorder

    unordered_map<int,int>mapping;               // Mapping for inorder value->index
    createMapping(mapping, inorder, size);       // Preprocess mapping

    cout<<"Building tree"<<endl;
    Node* root = buildTree(inorder, postOrder, size, postIndex, inorderStart, inorderEnd, mapping);

    cout<<"Printing the tree (Level Order):"<<endl;
    levelOrderTraversal(root);

    return 0;
}

/*
Dry Run Example:
----------------
Input:
    inorder[]   = {40, 20, 10, 50, 30, 60}
    postOrder[] = {40, 20, 50, 60, 30, 10}

Step-by-step:
1. postIndex = 5, postOrder[5]=10 => root=10
   - Find 10 in inorder at index 2
   - Left subtree: inorder[0..1], Right subtree: inorder[3..5]

2. Build right subtree (inorder[3..5]):
   - postIndex=4, postOrder[4]=30 => root=30
   - Find 30 in inorder at index 4
   - Left: inorder[3..3], Right: inorder[5..5]

3. Build right subtree of 30 (inorder[5..5]):
   - postIndex=3, postOrder[3]=60 => root=60
   - Find 60 in inorder at index 5
   - Left/Right: out of bounds => NULL

4. Build left subtree of 30 (inorder[3..3]):
   - postIndex=2, postOrder[2]=50 => root=50
   - Find 50 in inorder at index 3
   - Left/Right: out of bounds => NULL

5. Build left subtree of 10 (inorder[0..1]):
   - postIndex=1, postOrder[1]=20 => root=20
   - Find 20 in inorder at index 1

6. Build right subtree of 20 (inorder[2..1]): out of bounds => NULL

7. Build left subtree of 20 (inorder[0..0]):
   - postIndex=0, postOrder[0]=40 => root=40
   - Find 40 in inorder at index 0
   - Left/Right: out of bounds => NULL

Final Tree (Level Order):
10
20 30
40 50 60

*/