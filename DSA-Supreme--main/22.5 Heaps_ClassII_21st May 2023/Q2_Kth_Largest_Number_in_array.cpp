#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/*
Approach Used:
---------------
We use a Min Heap (priority_queue with greater<int>) to efficiently find the Kth largest element in an array.
- Insert the first k elements into the min heap.
- For each remaining element, if it is greater than the heap's top (smallest among the k largest so far), pop the top and insert the new element.
- After processing all elements, the heap's top is the Kth largest element.

Time Complexity: O(n log k)
Space Complexity: O(k)
*/

// Function to find the Kth largest element in the array
int findKthLargest(int arr[], int n, int k) {
    // Min heap to store the k largest elements seen so far
    priority_queue<int, vector<int>, greater<int>> pq;

    // Insert first k elements into the min heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]); // Heap grows to size k
    }

    // Process the remaining elements
    for (int i = k; i < n; i++) {
        // If current element is larger than the smallest in heap
        if (arr[i] > pq.top()) {
            pq.pop();         // Remove the smallest among k largest
            pq.push(arr[i]);  // Insert the new candidate
        }
        // Else, ignore as it's not among the k largest
    }

    // The root of the min heap is the Kth largest element
    return pq.top();
}

int main() {
    int arr[] = {10, 5, 20, 4, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    int ans = findKthLargest(arr, n, k);
    cout << "Ans = " << ans << endl; // Output the Kth largest element
    return 0;
}

/*
Alternative Approaches:
-----------------------
1. Sorting:
    - Sort the array in descending order and pick the (k-1)th index.
    - Time Complexity: O(n log n)
    - Code:
        sort(arr, arr+n, greater<int>());
        return arr[k-1];

2. QuickSelect (Hoare's Selection Algorithm):
    - Average Time Complexity: O(n), Worst: O(n^2)
    - Partition the array as in quicksort, recursively process the relevant partition.
    - Code (C++ STL nth_element):
        nth_element(arr, arr + (n - k), arr + n);
        return arr[n - k];

3. Max Heap:
    - Build a max heap and pop k-1 times.
    - Time Complexity: O(n + k log n)
    - Not as efficient as min heap for large k.

4. Multiset (for dynamic data):
    - Use multiset to maintain k largest elements.

Dry Run:
--------
Input: arr = {10, 5, 20, 4, 15}, n = 5, k = 2

Step 1: Insert first k elements into min heap:
    Heap: [5, 10] (5 is top)

Step 2: Process arr[2] = 20
    20 > 5 (heap top), so pop 5, push 20
    Heap: [10, 20] (10 is top)

Step 3: Process arr[3] = 4
    4 < 10, ignore

Step 4: Process arr[4] = 15
    15 > 10, pop 10, push 15
    Heap: [15, 20] (15 is top)

Result: Kth largest (2nd largest) is 15

Output: Ans = 15
*/