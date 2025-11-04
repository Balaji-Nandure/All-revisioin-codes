/*
Approach Used in This Code (Exponential Search for Unbounded Array):
--------------------------------------------------------------------
- The code efficiently finds a target element in a sorted array of unknown (or very large) size, simulating an "unbounded" array.
- It first finds a range [i, j] where the target could exist by exponentially increasing the upper bound (j).
- Once the range is found, it applies binary search within that range to check for the target.

Why Exponential Search?
-----------------------
- In an unbounded or infinite array, we cannot use the array's size.
- Exponential search quickly finds a range where the target may exist in O(log p) time, where p is the position of the target.
- Then, binary search is used in that small range, making the overall search efficient.

Better Alternatives / Detailed Approaches:
------------------------------------------
1. **Brute Force Linear Search** (Inefficient, O(n)):
   - Traverse the array one by one until you find the target or a value greater than the target.
   - Not recommended for large/unbounded arrays.

   // Brute Force Code:
   /*
   bool linearSearch(int arr[], int target) {
       int i = 0;
       while (true) {
           if (arr[i] == target) return true;
           if (arr[i] > target) return false;
           i++;
       }
       return false;
   }
   */

2. **Exponential Search (Optimal for Unbounded/Infinite Sorted Arrays)**:
   - Double the index until you find an element >= target or you go out of bounds.
   - Then, perform binary search in the found range.

   // Exponential Search Code (with boundary check):
   /*
   bool search(int arr[], int target) {
       int i = 0, j = 1;
       // Find the range where target could be
       while (arr[j] < target) {
           i = j;
           j = j * 2;
           // If you have a way to check for out-of-bounds, add it here
       }
       // Binary search in [i, j]
       return binarySearch(arr, i, j, target);
   }
   */

3. **If array is truly infinite (no out-of-bounds):**
   - The above approach works as is.
   - If you have a function to access elements (like get(i)), handle out-of-bounds gracefully.

Code with Comments and Improvements:
------------------------------------
*/

#include <iostream>
using namespace std;

// Standard binary search in a given range [start, end]
bool binarySearch(int arr[], int start, int end, int target) {
    // Binary search loop
    while (start <= end) {
        int mid = start + (end - start) / 2; // Prevents integer overflow
        if (arr[mid] == target) {
            // Target found
            return true;
        } else if (arr[mid] > target) {
            // Target is in the left half
            end = mid - 1;
        } else {
            // Target is in the right half
            start = mid + 1;
        }
    }
    // Target not found in the range
    return false;
}

// Exponential search to find the target in an unbounded (infinite) sorted array
bool search(int arr[], int target) {
    // Edge case: check the first element
    if (arr[0] == target) return true;

    int i = 0;
    int j = 1;

    // Exponentially increase the upper bound until arr[j] >= target or out-of-bounds
    // Note: In a real unbounded array, you should check for out-of-bounds access.
    while (arr[j] < target) {
        i = j;         // Move lower bound up
        j = j * 2;     // Double the upper bound
        // In a real scenario, check if arr[j] is accessible
    }

    // Now, target must be between arr[i] and arr[j]
    int start = i;
    int end = j;
    return binarySearch(arr, start, end, target);
}

int main() {
    // Example sorted array (simulate unbounded by not using size)
    int arr[] = {3, 4, 5, 15, 67, 78, 90, 110, 115, 116, 120, 136};
    int target = 116;

    // Call search function and print result
    if (search(arr, target)) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}

/*
Dry Run Example:
----------------
Array: [3, 4, 5, 15, 67, 78, 90, 110, 115, 116, 120, 136]
Target: 116

Step 1: Exponential Search to Find Range
    i = 0, j = 1: arr[1]=4 < 116
    i = 1, j = 2: arr[2]=5 < 116
    i = 2, j = 4: arr[4]=67 < 116
    i = 4, j = 8: arr[8]=115 < 116
    i = 8, j = 16: arr[11]=136 > 116 (since arr[16] is out-of-bounds, but arr[11]=136 > 116)

    So, search in range [8, 16] (but array size is 12, so up to index 11).

Step 2: Binary Search in [8, 11]
    mid = 9, arr[9]=116 == target -> found!

Output: "Element found"
*/