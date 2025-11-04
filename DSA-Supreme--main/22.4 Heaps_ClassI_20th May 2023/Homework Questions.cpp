/*
    Approach Used:
    --------------
    1. Implement a Heap class using a dynamic array (std::vector in C++) for flexible sizing.
    2. Support standard heap operations: insert, delete, buildHeap, and heapify.
    3. Explain why buildHeap has O(n) time complexity, not O(nlogn).

    Key Points:
    -----------
    - Dynamic array (vector) allows the heap to grow/shrink as needed, avoiding fixed-size limitations.
    - Heap is typically 1-indexed for easier parent/child calculations (parent = i/2, left = 2*i, right = 2*i+1).
    - buildHeap works in O(n) time due to the decreasing number of operations required for nodes closer to the leaves.

    Better Alternatives:
    -------------------
    1. Use STL's priority_queue for max-heap/min-heap (recommended for most use-cases).
    2. Use 0-based indexing for more natural C++ array usage.
    3. Use iterative heapify to avoid recursion stack overhead.
    4. For min-heap, reverse the comparison in heapify.

    Example: Heap class using dynamic array (vector)
    -----------------------------------------------
*/
#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> arr; // Dynamic array to store heap elements

public:
    Heap() {
        arr.push_back(-1); // 1-based indexing, arr[0] is dummy
    }

    // Insert a new value into the heap
    void insert(int val) {
        arr.push_back(val); // Add at the end
        int index = arr.size() - 1; // Index of inserted element
        // Percolate up: swap with parent if heap property violated
        while (index > 1 && arr[index/2] < arr[index]) {
            swap(arr[index/2], arr[index]);
            index = index/2;
        }
    }

    // Heapify subtree rooted at index i (max-heap)
    void heapify(int i) {
        int n = arr.size() - 1; // Current heap size
        int largest = i;
        int left = 2*i;
        int right = 2*i+1;
        // Check if left child exists and is greater
        if (left <= n && arr[left] > arr[largest]) largest = left;
        // Check if right child exists and is greater
        if (right <= n && arr[right] > arr[largest]) largest = right;
        // If largest is not the current node, swap and continue heapifying
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Build heap from current array (O(n) time)
    void buildHeap() {
        int n = arr.size() - 1;
        // Start from last non-leaf node and heapify each
        for (int i = n/2; i >= 1; i--) {
            heapify(i);
        }
    }

    // Delete root (max element)
    void deleteRoot() {
        int n = arr.size() - 1;
        if (n < 1) return;
        arr[1] = arr[n]; // Move last element to root
        arr.pop_back();  // Remove last element
        heapify(1);      // Restore heap property
    }

    // Print heap elements
    void print() {
        for (int i = 1; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

/*
    Why is buildHeap O(n) and not O(nlogn)?
    --------------------------------------
    - At first glance, heapifying each node seems O(log n), and there are n/2 nodes to heapify, so O(nlogn).
    - But, most nodes are near the leaves and require less work:
        - Height 0 (leaves): 2^(h) nodes, 0 swaps
        - Height 1: 2^(h-1) nodes, 1 swap
        - Height 2: 2^(h-2) nodes, 2 swaps
        - ...
    - Total work: sum_{i=0}^{log n} (number of nodes at height i) * (work per node at height i)
    - This sum is O(n), not O(nlogn).
    - See CLRS or Wikipedia "Heap Construction" for detailed proof.

    Alternative: STL priority_queue (max-heap)
    ------------------------------------------
    #include <queue>
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    cout << pq.top(); // 20
    pq.pop();

    Alternative: 0-based heapify
    ----------------------------
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && arr[left] > arr[largest]) largest = left;
        if (right < n && arr[right] > arr[largest]) largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    Dry Run Example:
    ----------------
    Insert: 50, 30, 20, 15, 10, 8, 16
    After each insert:
    1. 50
    2. 50 30
    3. 50 30 20
    4. 50 30 20 15
    5. 50 30 20 15 10
    6. 50 30 20 15 10 8
    7. 50 30 20 15 10 8 16

    Now, buildHeap (if starting from unsorted array):
    Input: -1 10 20 30 25 5 40 35
    buildHeap:
    - Start from i=4: heapify(4) -> 25, 5 (no swap)
    - i=3: heapify(3) -> 30, 40, 35 -> swap 30 and 40
    - i=2: heapify(2) -> 20, 25, 5 (swap 20 and 25)
    - i=1: heapify(1) -> 10, 25, 40, 15, 5, 30, 35 -> swap 10 and 40
    Final heap: 40 25 35 15 5 30 10

    Output: 40 25 35 15 5 30 10
*/
