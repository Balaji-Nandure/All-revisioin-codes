/*
================================================================================
Approach Used: Merge K Sorted Arrays using Min Heap (Priority Queue)
================================================================================
- We are given k sorted arrays, each of size n.
- The goal is to merge all these arrays into a single sorted array efficiently.

Logic:
------
- Use a min heap (priority_queue with custom comparator) to always extract the minimum element among the current heads of all arrays.
- Each heap node stores:
    - The value of the element.
    - The row (which array it belongs to).
    - The column (its index in that array).
- Initially, insert the first element of each array into the min heap.
- Repeatedly extract the minimum element from the heap, add it to the result, and insert the next element from the same array (if any) into the heap.
- Continue until the heap is empty.

Time Complexity: O(N * log K), where N = total number of elements (k*n), K = number of arrays.
Space Complexity: O(K) for the heap.

================================================================================
Better Alternatives:
================================================================================
1. **Using std::merge repeatedly (Not optimal):**
   - Merge first two arrays, then merge result with third, and so on.
   - Time: O(k * n * log n) (worse than heap approach for large k).

2. **Using Divide and Conquer (Pairwise Merge):**
   - Merge arrays in pairs recursively (like merge sort).
   - Time: O(N * log k), similar to heap approach.
   - Code:
     ```
     vector<int> mergeTwoArrays(const vector<int>& a, const vector<int>& b) {
         vector<int> res;
         int i = 0, j = 0;
         while (i < a.size() && j < b.size()) {
             if (a[i] < b[j]) res.push_back(a[i++]);
             else res.push_back(b[j++]);
         }
         while (i < a.size()) res.push_back(a[i++]);
         while (j < b.size()) res.push_back(b[j++]);
         return res;
     }
     vector<int> mergeKArrays(vector<vector<int>>& arrays, int left, int right) {
         if (left == right) return arrays[left];
         int mid = left + (right - left) / 2;
         vector<int> l = mergeKArrays(arrays, left, mid);
         vector<int> r = mergeKArrays(arrays, mid+1, right);
         return mergeTwoArrays(l, r);
     }
     // Usage: mergeKArrays(arrays, 0, k-1);
     ```

3. **Flatten and Sort (Simple but not optimal):**
   - Copy all elements to a single array and sort.
   - Time: O(N log N), where N = k*n.

================================================================================
Code with Detailed Comments and Dry Run at the End
================================================================================
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Class to store information about each element in the heap
class info {
public:
    int data; // Value of the element
    int row;  // Which array (row) this element belongs to
    int col;  // Index in that array (column)
    info(int val, int r, int c) {
        data = val;
        row = r;
        col = c;
    }
};

// Comparator for min heap (priority_queue)
// Returns true if a's data is greater than b's data (min heap)
class compare {
public:
    bool operator()(info* a, info* b) {
        return a->data > b->data;
    }
};

// Function to merge k sorted arrays of size n each
vector<int> mergeKSortedArrays(int arr[][4], int k, int n) {
    // Min heap to store the next minimum element from each array
    priority_queue<info*, vector<info*>, compare> minHeap;

    // Insert the first element of each array into the min heap
    for (int i = 0; i < k; i++) {
        info* temp = new info(arr[i][0], i, 0); // arr[i][0] is the first element of i-th array
        minHeap.push(temp);
    }

    vector<int> ans; // Resultant merged sorted array

    // Continue until all elements are processed (heap is empty)
    while (!minHeap.empty()) {
        // Step 1: Get the smallest element from the heap
        info* temp = minHeap.top();
        int topElement = temp->data; // Value to be added to result
        int topRow = temp->row;      // Which array this element came from
        int topCol = temp->col;      // Index in that array
        minHeap.pop();               // Remove the element from heap

        // Step 2: Add the smallest element to the result array
        ans.push_back(topElement);

        // Step 3: If there is a next element in the same array, insert it into the heap
        if (topCol + 1 < n) {
            info* newInfo = new info(arr[topRow][topCol + 1], topRow, topCol + 1);
            minHeap.push(newInfo);
        }
        // If not, do nothing (that array is exhausted)
    }

    return ans; // Return the merged sorted array
}

int main() {
    // Example input: 3 sorted arrays of size 4 each
    int arr[][4] = { {2, 4, 6, 8}, {1, 3, 5, 7}, {0, 9, 10, 11} };
    int k = 3; // Number of arrays
    int n = 4; // Size of each array

    // Call the merge function
    vector<int> ans = mergeKSortedArrays(arr, k, n);

    // Print the merged sorted array
    cout << "Merged Sorted Array: ";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
================================================================================
Dry Run:
================================================================================
Input:
    arr = {
        {2, 4, 6, 8},
        {1, 3, 5, 7},
        {0, 9, 10, 11}
    }
    k = 3, n = 4

Initial heap:
    [2 from row 0], [1 from row 1], [0 from row 2]
    Heap after heapify: [0, 2, 1] (min at top)

Step-by-step:
1. Pop 0 (row 2, col 0), push 9 (row 2, col 1)
   Heap: [1, 2, 9]
   ans: [0]
2. Pop 1 (row 1, col 0), push 3 (row 1, col 1)
   Heap: [2, 9, 3]
   ans: [0, 1]
3. Pop 2 (row 0, col 0), push 4 (row 0, col 1)
   Heap: [3, 9, 4]
   ans: [0, 1, 2]
4. Pop 3 (row 1, col 1), push 5 (row 1, col 2)
   Heap: [4, 9, 5]
   ans: [0, 1, 2, 3]
5. Pop 4 (row 0, col 1), push 6 (row 0, col 2)
   Heap: [5, 9, 6]
   ans: [0, 1, 2, 3, 4]
6. Pop 5 (row 1, col 2), push 7 (row 1, col 3)
   Heap: [6, 9, 7]
   ans: [0, 1, 2, 3, 4, 5]
7. Pop 6 (row 0, col 2), push 8 (row 0, col 3)
   Heap: [7, 9, 8]
   ans: [0, 1, 2, 3, 4, 5, 6]
8. Pop 7 (row 1, col 3), no more in row 1
   Heap: [8, 9]
   ans: [0, 1, 2, 3, 4, 5, 6, 7]
9. Pop 8 (row 0, col 3), no more in row 0
   Heap: [9]
   ans: [0, 1, 2, 3, 4, 5, 6, 7, 8]
10. Pop 9 (row 2, col 1), push 10 (row 2, col 2)
    Heap: [10]
    ans: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
11. Pop 10 (row 2, col 2), push 11 (row 2, col 3)
    Heap: [11]
    ans: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
12. Pop 11 (row 2, col 3), no more in row 2
    Heap: []
    ans: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

Output:
    Merged Sorted Array: 0 1 2 3 4 5 6 7 8 9 10 11

================================================================================
*/