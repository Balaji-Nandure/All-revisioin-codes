
/*
================================================================================
1) Min Heap using STL priority_queue with vector<int> and greater<int>
================================================================================
Approach:
- By default, priority_queue in C++ is a max-heap.
- To create a min-heap, use: priority_queue<int, vector<int>, greater<int>>
- 'greater<int>' is a comparator that makes the smallest element have the highest priority.

Example:
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void minHeapExample() {
    // Create a min-heap using priority_queue
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert elements into the min-heap
    minHeap.push(10); // pushes 10
    minHeap.push(5);  // pushes 5
    minHeap.push(20); // pushes 20

    // Print and remove elements from min-heap (should be in increasing order)
    while (!minHeap.empty()) {
        cout << minHeap.top() << " "; // prints the smallest element
        minHeap.pop(); // removes the top element
    }
    cout << endl;
}

/*
Alternative:
- You can use make_heap, pop_heap, push_heap with vector and greater<int> for more control.
- But priority_queue is more convenient for most use-cases.
*/

/*
================================================================================
2) Merge 2 Max Heaps (Approach 1: Simple Merge + Heapify, Approach 2: Merge and Heapify Down)
================================================================================
Approach 1 (Simple Merge + Heapify):
- Merge both heaps into a single array.
- Use make_heap to convert the merged array into a max-heap.

Approach 2 (Manual Heapify Down):
- Merge both arrays.
- Starting from the last non-leaf node, heapify down each node.

Code for Approach 1:
*/

void mergeMaxHeaps1(vector<int>& a, vector<int>& b, vector<int>& result) {
    // Merge both heaps
    result = a;
    result.insert(result.end(), b.begin(), b.end());

    // Convert merged array into max-heap
    make_heap(result.begin(), result.end()); // default is max-heap
}

/*
Code for Approach 2:
*/

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    // If left child is larger
    if (left < n && arr[left] > arr[largest])
        largest = left;
    // If right child is larger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

void mergeMaxHeaps2(vector<int>& a, vector<int>& b, vector<int>& result) {
    // Merge both heaps
    result = a;
    result.insert(result.end(), b.begin(), b.end());
    int n = result.size();

    // Heapify from last non-leaf node
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(result, n, i);
    }
}

/*
Better Alternative:
- Both approaches are O(N), but using STL's make_heap is more concise and less error-prone.
- For very large heaps, use make_heap for simplicity and performance.
*/

/*
================================================================================
3) Convert BST to Max-Heap (Approach: Inorder + Postorder Fill)
================================================================================
Approach:
- Inorder traversal of BST gives sorted order.
- Store inorder traversal in a vector.
- Do a postorder traversal of the BST, and replace each node's value with the next value from the inorder vector.
- This ensures the tree structure remains the same, but heap property is satisfied.

Code:
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Inorder traversal to store values
void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Postorder traversal to assign values from sorted array (max-heapify)
void bstToMaxHeap(Node* root, vector<int>& arr, int& idx) {
    if (!root) return;
    bstToMaxHeap(root->left, arr, idx);
    bstToMaxHeap(root->right, arr, idx);
    root->data = arr[idx++]; // assign next largest value
}

/*
Usage:
vector<int> arr;
inorder(root, arr);
int idx = 0;
bstToMaxHeap(root, arr, idx);
*/

/*
Alternative:
- You can use a queue instead of index for more clarity.
- This approach is O(N) time and space.
*/

/*
================================================================================
4) Check if a Binary Tree is a Complete Binary Tree (CBT)
================================================================================
Approach:
- Level order traversal (BFS) using a queue.
- After a NULL child is seen, all following nodes must not have any children.
- If a node after a NULL child has children, it's not a CBT.

Code:
*/

bool isCBT(Node* root) {
    if (!root) return true;
    queue<Node*> q;
    q.push(root);
    bool nullChildSeen = false;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (curr->left) {
            if (nullChildSeen) return false; // If null child seen before, not CBT
            q.push(curr->left);
        } else {
            nullChildSeen = true;
        }

        // Right child
        if (curr->right) {
            if (nullChildSeen) return false;
            q.push(curr->right);
        } else {
            nullChildSeen = true;
        }
    }
    return true;
}

/*
Alternative:
- You can also use index-based approach: For N nodes, if you assign indices as in array representation,
  and if any node's index >= N, it's not CBT.
- But BFS is more intuitive and easy to implement.
*/

/*
================================================================================
Dry Run Example for Min Heap:
================================================================================
Input: 10, 5, 20
minHeap.push(10) -> Heap: [10]
minHeap.push(5)  -> Heap: [5, 10]
minHeap.push(20) -> Heap: [5, 10, 20]
Output (pop order): 5 10 20

================================================================================
Dry Run Example for Merge Max Heaps:
================================================================================
a = [10, 5, 6], b = [12, 7, 9]
Merged: [10, 5, 6, 12, 7, 9]
After make_heap: [12, 10, 9, 5, 7, 6] (max-heap property)

================================================================================
Dry Run Example for BST to Max-Heap:
================================================================================
BST:      4
         / \
        2   6
Inorder: [2, 4, 6]
Postorder fill: left, right, root
Assign 2 to left, 4 to right, 6 to root
Resulting tree (max-heap): 6
                              / \
                             2   4

================================================================================
Dry Run Example for CBT Check:
================================================================================
Tree:      1
          / \
         2   3
        /
       4
Level order: 1,2,3,4
No node after a NULL child has children => CBT

Tree:      1
          / \
         2   3
          \
           4
Level order: 1,2,3,NULL,4
Node after NULL child has child => Not CBT

================================================================================
*/
