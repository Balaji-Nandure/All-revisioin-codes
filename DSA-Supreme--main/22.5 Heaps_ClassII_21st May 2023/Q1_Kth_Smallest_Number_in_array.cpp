/*
================================================================================
Approach Used: Kth Smallest Element in Array using Max Heap (Priority Queue)
================================================================================
- We want to find the kth smallest element in an unsorted array.
- The idea is to maintain a max heap of size k. The heap will always contain the k smallest elements seen so far.
- The top of the max heap is the largest among the k smallest, i.e., the kth smallest overall.

Steps:
1. Insert the first k elements into the max heap.
2. For each remaining element, if it is smaller than the heap's top (i.e., the current kth smallest), pop the top and insert the new element.
3. After processing all elements, the top of the heap is the kth smallest.

Time Complexity: O(n log k)
Space Complexity: O(k)

================================================================================
Better Alternatives:
================================================================================
1. **Using std::nth_element (QuickSelect, Average O(n)):**
   ```
   #include <algorithm>
   int kthSmallest(vector<int>& arr, int k) {
       nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
       return arr[k-1];
   }
   ```
   - This rearranges the array so that the kth smallest is at index k-1.
   - Not stable, but very fast for large arrays.

2. **Sorting (O(n log n)):**
   ```
   sort(arr, arr+n);
   return arr[k-1];
   ```
   - Simple, but slower than heap or QuickSelect for large k << n.

3. **Min Heap for Kth Largest:**
   - For kth largest, use a min heap of size k.

================================================================================
Code with Detailed Comments and Dry Run
================================================================================
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to find the kth smallest element in the array
int findKthSmallest(int arr[], int n, int k) {
    // Max heap to store the k smallest elements seen so far
    priority_queue<int> pq; // By default, this is a max heap

    // Insert first k elements into the max heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]); // Push element into heap
        // Heap now contains up to k elements
    }

    // Process the remaining elements
    for (int i = k; i < n; i++) {
        // If current element is smaller than the largest in heap (top)
        if (arr[i] < pq.top()) {
            pq.pop();           // Remove the largest among k smallest
            pq.push(arr[i]);    // Insert the new smaller element
        }
        // Else, ignore as it's not among the k smallest
    }

    // The top of the heap is the kth smallest element
    return pq.top();
}

int main() {
    int arr[] = {10, 5, 20, 4, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    int ans = findKthSmallest(arr, n, k);
    cout << "Ans = " << ans << endl;

    /*
    =========================
    Dry Run for Input:
    arr = {10, 5, 20, 4, 15}, n = 5, k = 2

    Step 1: Insert first k=2 elements into max heap
        Heap: [10]
        Heap: [10, 5]   // 10 at top

    Step 2: Process remaining elements
        i=2, arr[2]=20
            20 > 10 (heap top), so ignore

        i=3, arr[3]=4
            4 < 10 (heap top)
            Pop 10, push 4
            Heap: [5, 4]   // 5 at top

        i=4, arr[4]=15
            15 > 5 (heap top), so ignore

    Step 3: Heap top is 5, which is the 2nd smallest element

    Output: Ans = 5
    =========================
    */

    return 0;
}

/*
================================================================================
Alternative: Using nth_element (QuickSelect, Average O(n))
================================================================================
#include <algorithm>
#include <vector>
int kthSmallest(vector<int>& arr, int k) {
    nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
    return arr[k-1];
}
================================================================================
Alternative: Using Sorting (O(n log n))
================================================================================
sort(arr, arr+n);
return arr[k-1];
================================================================================
*/