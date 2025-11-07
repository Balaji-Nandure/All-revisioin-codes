/*
APPROACH: CONVERT BST TO SORTED DOUBLY LINKED LIST (IN-PLACE)

Idea:
- Inorder traversal of a BST visits nodes in ascending order.
- While traversing, connect:
    prev->right = curr    (next)
    curr->left  = prev    (prev)
- Keep track of:
    - 'prev' : last processed node
    - 'head' : first node (leftmost) ⇒ head of DLL
- Reuse BST pointers:
    left  → prev
    right → next

Why it works:
- Inorder guarantees sorted order.
- Linking during traversal builds a proper sorted DLL.

Complexity:
- Time:  O(n)  (visit each node once)
- Space: O(h)  recursion stack (h = tree height)

Notes:
- Returns the head of the doubly linked list.
- Works in-place (no extra nodes).
*/

struct Node {
    int data;
    Node *left;   // prev in DLL
    Node *right;  // next in DLL
    Node(int v) { data = v; left = right = nullptr; }
};

void inorderLink(Node* cur, Node*& prev, Node*& head) {
    if (!cur) return;

    // Left subtree
    inorderLink(cur->left, prev, head);

    // Link prev <-> cur
    if (prev == nullptr) {
        head = cur;          // first (leftmost) node becomes head
    } else {
        prev->right = cur;   // prev -> next
        cur->left  = prev;   // cur  -> prev
    }
    prev = cur;              // advance prev

    // Right subtree
    inorderLink(cur->right, prev, head);
}

Node* bstToDoublyLinkedList(Node* root) {
    Node* head = nullptr;
    Node* prev = nullptr;
    inorderLink(root, prev, head);
    return head;
}


Node* insert(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->data) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    return root;
}

int main() {
    // Build BST: 4,2,5,1,3
    Node* root = nullptr;
    int a[] = {4,2,5,1,3};
    for (int x : a) root = insert(root, x);

    Node* head = bstToDoublyLinkedList(root);

    // Print forward
    // for (Node* p = head; p; p = p->right) std::cout << p->data << " ";

    // Print backward from tail
    // Node* tail = head;
    // while (tail && tail->right) tail = tail->right;
    // for (Node* p = tail; p; p = p->left) std::cout << p->data << " ";

    return 0;
}
