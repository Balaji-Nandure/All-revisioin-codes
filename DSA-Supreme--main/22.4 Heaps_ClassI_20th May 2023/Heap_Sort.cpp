/*
    Heap Sort Approach Used:
    ------------------------
    1. Build a max-heap from the input array.
    2. Swap the root (maximum element) with the last element of the heap.
    3. Reduce the heap size by one and heapify the root.
    4. Repeat steps 2-3 until the heap size is greater than 1.

    This implementation uses 1-based indexing for the heap (arr[0] is dummy).

    Time Complexity: O(n log n)
    Space Complexity: O(1) (in-place)

    Alternatives:
    -------------
    - Use 0-based indexing for more natural C++ arrays.
    - Use STL's make_heap, pop_heap, sort_heap for heap sort.
    - Use iterative heapify to avoid recursion stack overhead.

    Alternative code for 0-based indexing heapify and heap sort is provided at the end as comments.

    Dry Run is provided at the end of the file.
*/

#include<iostream>
using namespace std;

// Heapify function to maintain max-heap property for subtree rooted at index 'i'
void heapify(int arr[], int n, int i) {
    int index = i; // Current node index
    int leftIndex = 2 * i; // Left child index (1-based)
    int rightIndex = 2 * i + 1; // Right child index (1-based)
    int largest = index; // Assume current node is largest

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
        swap(arr[largest], arr[index]); // Swap with largest child
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to build a max-heap from the array
void buildHeap(int arr[], int n) {
    // Start from the last non-leaf node and heapify each node
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Build max-heap (already done before calling this in main)
    int heapSize = n; // Current heap size (1-based)
    // Extract elements from heap one by one
    while (heapSize > 1) {
        swap(arr[1], arr[heapSize]); // Move current root to end
        heapSize--; // Reduce heap size
        // Heapify root to maintain max-heap property
        heapify(arr, heapSize, 1);
    }
}

int main() {
    // Example array (1-based indexing, arr[0] is dummy)
    int arr[] = { -1, 12, 15, 13, 11, 14 }; // n = 5, arr[1..5] are valid
    int n = 5; // Number of elements

    // Step 1: Build max-heap
    buildHeap(arr, n);

    cout << "Printing the heap (after buildHeap):" << endl;
    for (int i = 1; i <= n; i++) { // Print heap (skip dummy 0th index)
        cout << arr[i] << " ";
    }
    cout << endl;

    // Step 2: Heap sort
    heapSort(arr, n);

    cout << "Printing the sorted array:" << endl;
    for (int i = 1; i <= n; i++) { // Print sorted array
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
-------------------------------
Alternative: 0-based Indexing
-------------------------------
    // 0-based heapify
    void heapify(int arr[], int n, int i) {
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
    // 0-based heap sort
    void heapSort(int arr[], int n) {
        // Build heap
        for(int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
        // Extract elements
        for(int i = n-1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

-------------------------------
Alternative: Using STL
-------------------------------
    #include <algorithm>
    vector<int> v = {12, 15, 13, 11, 14};
    make_heap(v.begin(), v.end());
    sort_heap(v.begin(), v.end());

-------------------------------
Dry Run (for arr[] = {-1,12,15,13,11,14}, n=5)
-------------------------------
Initial array (1-based): 12 15 13 11 14

Step 1: Build Heap
- Start from i=2: heapify at 2 (15,11,14) => 15 is already largest
- i=1: heapify at 1 (12,15,13) => 15 is largest, swap 12<->15
  Now: 15 12 13 11 14
  heapify at 2: 12,11,14 => 14 is largest, swap 12<->14
  Now: 15 14 13 11 12

Heap after buildHeap: 15 14 13 11 12

Step 2: Heap Sort
- Swap 15<->12: 12 14 13 11 15, heapify(1,4)
  heapify at 1: 12,14,13 => 14 is largest, swap 12<->14
  Now: 14 12 13 11 15
  heapify at 2: 12,11 => 12 is largest
- Swap 14<->11: 11 12 13 14 15, heapify(1,3)
  heapify at 1: 11,12,13 => 13 is largest, swap 11<->13
  Now: 13 12 11 14 15
- Swap 13<->11: 11 12 13 14 15, heapify(1,2)
  heapify at 1: 11,12 => 12 is largest, swap 11<->12
  Now: 12 11 13 14 15
- Swap 12<->11: 11 12 13 14 15

Sorted array: 11 12 13 14 15

*/