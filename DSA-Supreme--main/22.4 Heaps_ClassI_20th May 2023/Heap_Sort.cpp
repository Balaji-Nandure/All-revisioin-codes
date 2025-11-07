/*
APPROACH: HEAPIFY, BUILD-HEAP, HEAP-SORT (MAX-HEAP, 0-INDEXED)

1) HEAPIFY (Down-heap / percolate down):
   Given an index i, assume its LEFT and RIGHT subtrees are already heaps.
   Check children:
        left  = 2*i + 1
        right = 2*i + 2
   Find the largest among (i, left, right).
   If largest is not i → swap i with largest and continue heapify on that index.
   Time: O(log n)

2) BUILD-HEAP:
   Convert normal array into a max-heap.
   Start heapify from the last non-leaf node down to root:
        for (i = n/2 - 1; i >= 0; i--) heapify(i)
   Time: O(n), NOT O(n log n) (important point for interviews)

3) HEAP-SORT (Ascending order):
   - First build a max-heap (largest element at root).
   - Swap arr[0] with arr[end], reduce heap size by 1.
   - Call heapify(0) again to restore heap.
   - Continue until heap size reduces to 1.
   Result array becomes sorted in increasing order.

Time:
    Build heap = O(n)
    Extract n times = O(n log n)
    Overall = O(n log n)
Space = O(1) (in-place sorting)
*/

#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;         
    int left = 2*i + 1;
    int right = 2*i + 2;

    // Compare with left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Compare with right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If root is not largest, swap and continue heapify
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    // Start from last non-leaf node
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    // Step 1: Build max-heap
    buildHeap(arr, n);

    // Step 2: Extract elements from heap one by one
    for (int i = n-1; i > 0; i--) {
        // Move current max to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Restore heap for reduced size
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    // Print sorted
    for(int i = 0; i < n; i++) std::cout << arr[i] << " ";

    return 0;
}

