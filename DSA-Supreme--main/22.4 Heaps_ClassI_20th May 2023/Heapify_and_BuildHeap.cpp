/*
    Approach Used:
    ----------------
    - The code implements the heapify and buildHeap functions to construct a max-heap from an array.
    - The heap is 1-indexed (arr[0] is dummy), so for node at index i:
        - left child: 2*i
        - right child: 2*i + 1
    - heapify ensures the subtree rooted at index i satisfies the max-heap property.
    - buildHeap calls heapify from the last non-leaf node up to the root.

    Better Alternatives:
    ---------------------
    1. Use 0-based indexing for more natural C++ arrays.
    2. Use an iterative version of heapify to avoid recursion stack overhead.
    3. For large data, use std::vector for dynamic sizing.
    4. For min-heap, just reverse the comparison in heapify.

    // 0-based heapify alternative:
    /*
    void heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < n && arr[left] > arr[largest]) largest = left;
        if(right < n && arr[right] > arr[largest]) largest = right;
        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    */

    // STL alternative:
    /*
    #include <algorithm>
    make_heap(arr, arr+n); // arr is 0-based
    */

    // Dry Run for input: arr[] = {-1,12,15,13,11,14}, n = 5
    /*
    Initial array (1-indexed): 12 15 13 11 14
    buildHeap starts from i=2:
    i=2: left=4, right=5, arr[2]=15, arr[4]=11, arr[5]=14
        - arr[2] > arr[4] and arr[2] > arr[5], so no swap
    i=1: left=2, right=3, arr[1]=12, arr[2]=15, arr[3]=13
        - arr[2]=15 > arr[1]=12, so swap arr[1] and arr[2]
        - Now, at index=2, left=4, right=5, arr[2]=12, arr[4]=11, arr[5]=14
        - arr[5]=14 > arr[2]=12, so swap arr[2] and arr[5]
    Final heap: 15 14 13 11 12
    Output: -1 15 14 13 11 12
    */
*/

#include<iostream>
using namespace std;

// Function to maintain the max-heap property for subtree rooted at index 'i'
void heapify(int arr[], int n, int i) {
    int index = i; // Current node index
    int leftIndex = 2 * i;     // Left child index (1-based)
    int rightIndex = 2 * i + 1;// Right child index (1-based)
    int largest = index;       // Assume current node is largest

    // If left child exists and is greater than current largest, update largest
    if (leftIndex <= n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }
    // If right child exists and is greater than current largest, update largest
    if (rightIndex <= n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }
    // If largest is not the current node, swap and continue heapifying
    if (largest != index) {
        swap(arr[largest], arr[index]); // Swap with the largest child
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to build a max-heap from an unordered array
void buildHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node up to the root
    // Last non-leaf node is at index n/2 (1-based indexing)
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    // Example array (1-based indexing, arr[0] is dummy)
    int arr[] = { -1, 12, 15, 13, 11, 14 };
    int n = 5; // Number of elements in heap (excluding dummy at index 0)

    // Build the max-heap
    buildHeap(arr, n);

    cout << "Printing the heap" << endl;
    // Print the heap (including dummy at index 0 for clarity)
    for (int i = 0; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    /*
    Dry Run:
    --------
    Initial array: -1 12 15 13 11 14
    buildHeap:
      i = 2:
        left = 4, right = 5
        arr[2]=15, arr[4]=11, arr[5]=14
        15 > 11 and 15 > 14, so no swap
      i = 1:
        left = 2, right = 3
        arr[1]=12, arr[2]=15, arr[3]=13
        arr[2]=15 > arr[1]=12, so swap arr[1] and arr[2]
        arr: -1 15 12 13 11 14
        Now, heapify at index=2:
          left=4, right=5
          arr[2]=12, arr[4]=11, arr[5]=14
          arr[5]=14 > arr[2]=12, so swap arr[2] and arr[5]
          arr: -1 15 14 13 11 12
    Final heap: -1 15 14 13 11 12
    Output: -1 15 14 13 11 12
    */
    return 0;
}