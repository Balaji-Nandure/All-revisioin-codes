/*
    Approach Used:
    ----------------
    1. Build a balanced BST from a sorted array using recursive mid-point selection.
    2. Convert the BST to a sorted Doubly Linked List (DLL) using reverse inorder traversal.
    3. Convert the sorted DLL back to a balanced BST using in-place construction (simulating inorder traversal).

    Key Points:
    - The conversion from BST to DLL is done in-place, using the left and right pointers as prev and next.
    - The conversion from DLL to BST is done by recursively building left subtree, then using the current head as root, then building right subtree.
    - Level order traversal is used to print the BSTs for verification.

    Alternative Approaches:
    -----------------------
    1. **Array to BST directly**: If you have a sorted array, you can directly build a BST using the mid-point approach (as shown in bstUsingInorder).
    2. **DLL to BST using slow/fast pointer**: Instead of passing the length, you can use slow/fast pointers to find the middle node of the DLL for root selection, but this increases time complexity to O(n log n).
    3. **Morris Traversal**: For in-place conversion without recursion/stack, but is more complex and not needed here.

    See detailed alternative code at the end in comments.

    Dry Run is provided at the end of the file.
*/

#include<iostream>
#include<queue>
using namespace std;

// Node class for BST and DLL
class Node{
    public:
        int data;
        Node* left;   // For BST: left child, For DLL: previous node
        Node* right;  // For BST: right child, For DLL: next node
        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

/*
    Function: sortedLLIntoBST
    -------------------------
    Converts a sorted Doubly Linked List to a balanced BST.
    Arguments:
        - head: reference to the head pointer of DLL (will be updated as we progress)
        - n: number of nodes in DLL
    Returns:
        - root of the constructed BST

    Logic:
        - Recursively build left subtree with n/2 nodes
        - The current head node becomes the root
        - Move head to next node (right)
        - Recursively build right subtree with remaining nodes
*/
Node* sortedLLIntoBST(Node* &head, int n){
    // Base case: If DLL is empty or no nodes left, return NULL
    if(head == NULL || n <= 0 ){
        return NULL;
    }

    // Recursively construct the left subtree with n/2 nodes
    Node* leftSubtree = sortedLLIntoBST(head, n/2);

    // The current head node is the root for this subtree
    Node* root = head;

    // Attach left subtree to root
    root->left = leftSubtree;

    // Move head to next node for right subtree construction
    head = head->right;

    // Recursively construct the right subtree with remaining nodes
    root->right = sortedLLIntoBST(head, n - 1 - n/2);

    return root;
}

/*
    Function: bstUsingInorder
    -------------------------
    Builds a balanced BST from a sorted array using recursive mid-point selection.
    Arguments:
        - inorder: sorted array
        - s: start index
        - e: end index
    Returns:
        - root of the constructed BST
*/
Node *bstUsingInorder(int inorder[], int s, int e){
    // Base Case: If start index exceeds end, return NULL
    if(s > e){
        return NULL;
    }

    // Find middle index to maintain balance
    int mid = s + (e - s) / 2;
    int element = inorder[mid];

    // Create root node with middle element
    Node* root = new Node(element);

    // Recursively build left and right subtrees
    root->left = bstUsingInorder(inorder, s, mid - 1);
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;
}

/*
    Function: printDLL
    ------------------
    Prints the data of nodes in a Doubly Linked List from head to end.
*/
void printDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        // Move to next node (right pointer in DLL)
        temp = temp->right; 
    }
    cout << endl;
}

/*
    Function: convertToDLL
    ----------------------
    Converts a BST to a sorted Doubly Linked List in-place using reverse inorder traversal.
    Arguments:
        - root: current node of BST
        - head: reference to head pointer of DLL (will be updated)
    Logic:
        - Traverse right subtree first (reverse inorder)
        - Attach root to DLL
        - Update head
        - Traverse left subtree
*/
void convertToDLL(Node* root, Node* &head){
    // Base case: If node is NULL, return
    if(root == NULL){
        return;
    }

    // Convert right subtree first (reverse inorder for head insertion)
    convertToDLL(root->right, head);

    // Attach root node to the DLL
    root->right = head; // right acts as next in DLL

    // If DLL is not empty, set previous pointer
    if(head != NULL)
        head->left = root; // left acts as prev in DLL

    // Update head to current root
    head = root;

    // Convert left subtree
    convertToDLL(root->left, head);
}

/*
    Function: levelOrderTraversal
    ----------------------------
    Prints the level order traversal of a BST.
    Arguments:
        - root: root of the BST
    Logic:
        - Use queue for BFS
        - Use NULL as level marker
*/
void levelOrderTraversal(Node *root)
{
    // If tree is empty, return
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    // Push the root and level marker (NULL)
    q.push(root);
    q.push(NULL);

    // Loop until queue is empty
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

/*
    Main function to demonstrate the conversions and traversals.
*/
int main(){
    // Step 1: Create a sorted array
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int s = 0;
    int e = 8;

    // Step 2: Build BST from sorted array
    Node* root = bstUsingInorder(inorder, s, e);

    cout << "Level Order Traversal of BST built from sorted array:" << endl;
    levelOrderTraversal(root);

    // Step 3: Convert BST to Sorted Doubly Linked List (DLL)
    Node* head = NULL;
    convertToDLL(root, head);

    cout << "Printing Sorted Doubly Linked List:" << endl;
    printDLL(head);

    // Step 4: Convert Sorted DLL back to Balanced BST
    Node* root1 = NULL;
    root1 = sortedLLIntoBST(head, 9);

    cout << endl << "Level Order Traversal of BST built from Sorted DLL:" << endl;
    levelOrderTraversal(root1);

    return 0;
}

/*
    -------------------------------
    Alternative Approach (DLL to BST)
    -------------------------------
    // Instead of passing length, use slow/fast pointer to find mid node as root.
    // This is less efficient (O(n log n)), but doesn't require knowing the length.

    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while(fast && fast->right) {
            prev = slow;
            slow = slow->right;
            fast = fast->right->right;
        }
        if(prev) prev->right = NULL; // Split DLL
        if(slow) slow->left = NULL;
        return slow;
    }

    Node* sortedDLLToBST(Node* head) {
        if(!head) return NULL;
        Node* mid = findMiddle(head);
        Node* root = mid;
        if(head != mid) root->left = sortedDLLToBST(head);
        root->right = sortedDLLToBST(mid->right);
        return root;
    }

    // Usage: Node* bstRoot = sortedDLLToBST(head);

    -------------------------------
    Dry Run (for main function)
    -------------------------------
    1. Sorted array: [1,2,3,4,5,6,7,8,9]
    2. bstUsingInorder builds BST:
           5
         /   \
        2     7
       / \   / \
      1  3  6   8
           \     \
            4     9
    3. convertToDLL creates DLL: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 7 <-> 8 <-> 9
    4. sortedLLIntoBST reconstructs BST (balanced):
           5
         /   \
        2     7
       / \   / \
      1  3  6   8
           \     \
            4     9
    5. Level order traversals print the BSTs at each stage.

    Time Complexity:
    - bstUsingInorder: O(n)
    - convertToDLL: O(n)
    - sortedLLIntoBST: O(n)
    - Overall: O(n)
*/