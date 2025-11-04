/*
    Approach Used:
    --------------
    1. Build a Binary Search Tree (BST) from a sorted inorder array using recursion.
    2. Convert the BST into a sorted Doubly Linked List (DLL) in-place using reverse inorder traversal (right-root-left).
    3. Print the BST in level order and the resulting DLL.

    Key Points:
    - The DLL is created in-place by reusing the left and right pointers of the BST nodes.
    - The head of the DLL is updated during traversal.
    - The conversion is done in O(N) time and O(H) space (due to recursion stack), where N is the number of nodes and H is the height of the tree.

    Alternative Approaches:
    ----------------------
    1. **Iterative Inorder Traversal with Stack:**
       - Use an explicit stack to perform inorder traversal and build the DLL iteratively.
       - Avoids recursion stack, but uses an explicit stack.

       // Example code for iterative approach:
       /*
       void convertToDLLIterative(Node* root, Node*& head) {
           stack<Node*> st;
           Node* curr = root;
           Node* prev = NULL;
           while (curr || !st.empty()) {
               while (curr) {
                   st.push(curr);
                   curr = curr->left;
               }
               curr = st.top(); st.pop();
               if (!head) head = curr;
               curr->left = prev;
               if (prev) prev->right = curr;
               prev = curr;
               curr = curr->right;
           }
           if (prev) prev->right = NULL;
       }
       */

    2. **Morris Traversal (O(1) space):**
       - Use Morris traversal to do inorder traversal without stack or recursion.
       - More complex, but reduces space to O(1).

       // Example code for Morris approach:
       /*
       void convertToDLLMorris(Node* root, Node*& head) {
           Node* curr = root;
           Node* prev = NULL;
           while (curr) {
               if (!curr->left) {
                   if (!head) head = curr;
                   curr->left = prev;
                   if (prev) prev->right = curr;
                   prev = curr;
                   curr = curr->right;
               } else {
                   Node* pred = curr->left;
                   while (pred->right && pred->right != curr)
                       pred = pred->right;
                   if (!pred->right) {
                       pred->right = curr;
                       curr = curr->left;
                   } else {
                       pred->right = NULL;
                       if (!head) head = curr;
                       curr->left = prev;
                       if (prev) prev->right = curr;
                       prev = curr;
                       curr = curr->right;
                   }
               }
           }
           if (prev) prev->right = NULL;
       }
       */

    Dry Run Example:
    ----------------
    Input inorder[] = {1,2,3,4,5,6,7,8,9}
    BST constructed:
            5
          /   \
         2     7
        / \   / \
       1   3 6   8
            \     \
             4     9

    DLL after conversion: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 7 <-> 8 <-> 9

    Each node's left pointer points to previous node, right pointer to next node.
*/

#include<iostream>
#include<queue>
using namespace std;

// Node class for BST and DLL
class Node{
    public:
        int data;
        Node* left;   // For BST: left child; For DLL: previous node
        Node* right;  // For BST: right child; For DLL: next node
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

// Insert a node into BST (recursive)
// Returns new root after insertion
Node* insertIntoBST(Node* root,int data){
    // If tree is empty, create new node as root
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    // If data is less than root, insert into left subtree
    if(root->data > data){
        root->left = insertIntoBST(root->left,data);
    }
    else{
        // If data is greater or equal, insert into right subtree
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}

// Take input from user and build BST until -1 is entered
void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

// Convert BST to Doubly Linked List (DLL) in-place using reverse inorder traversal
// head: reference to head pointer of DLL
void convertToDLL(Node* root,Node* &head){
    // Base case: if root is NULL, do nothing
    if(root == NULL){
        return;
    }
    // First, convert right subtree to DLL (so that head points to smallest node at the end)
    convertToDLL(root->right,head);

    // Attach current root node to the DLL
    root->right = head; // right pointer acts as next in DLL

    // If DLL is not empty, set previous pointer of head to current root
    if(head!=NULL)
        head->left = root; // left pointer acts as previous in DLL

    // Move head to current root (new head of DLL)
    head = root;

    // Convert left subtree to DLL
    convertToDLL(root->left,head);
}

// Print BST in level order (BFS)
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
            // If more nodes exist, add level marker for next level
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            // Push left child if exists
            if (temp->left)
            {
                q.push(temp->left);
            }
            // Push right child if exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Build a balanced BST from sorted inorder array
Node *bstUsingInorder(int inorder[],int s,int e){
    // Base Case: if start > end, no elements to form tree
    if(s>e){
        return NULL;
    }
    // Find middle element to keep tree balanced
    int mid = s + (e-s)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    // Recursively build left and right subtrees
    root->left = bstUsingInorder(inorder,s,mid-1);
    root->right = bstUsingInorder(inorder,mid+1,e);
    return root;
}

// Print the Doubly Linked List from head to end
void printDLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->right; // Move to next node in DLL
    }
}

int main(){
    // Example input: sorted inorder array
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int s = 0;
    int e = 8;

    // Build balanced BST from inorder array
    Node* root = bstUsingInorder(inorder,s,e);

    // Print BST in level order
    cout << "Level Order Traversal of BST:" << endl;
    levelOrderTraversal(root);

    // Convert BST to DLL
    Node* head = NULL;
    convertToDLL(root,head);

    // Print the sorted Doubly Linked List
    cout<<"Printing Sorted Doubly Linked List"<<endl;
    printDLL(head);

    return 0;
}

/*
Dry Run:
--------
Input: inorder[] = {1,2,3,4,5,6,7,8,9}

Step 1: Build BST (balanced)
        5
      /   \
     2     7
    / \   / \
   1   3 6   8
        \     \
         4     9

Step 2: Convert BST to DLL (in-place, reverse inorder)
- Start from rightmost node (9), set as head.
- Move to 8, link 8<->9, update head to 8.
- Continue to 7, link 7<->8, update head to 7.
- ... and so on, until 1 is linked at the head.

Final DLL: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 7 <-> 8 <-> 9

Output:
Level Order Traversal of BST:
5 
2 7 
1 3 6 8 
4 9 
Printing Sorted Doubly Linked List
1 2 3 4 5 6 7 8 9 
*/