/*
    Approach Used:
    --------------
    - The array is a rotated sorted array (sorted in increasing order, then rotated at some pivot).
    - To find a target element efficiently, we:
        1. Find the pivot (the largest element's index, where the rotation happens).
        2. Decide in which sorted half (left or right of pivot) the target lies.
        3. Apply standard binary search in the appropriate half.

    - Time Complexity: O(log n) for both pivot finding and binary search.
    - Space Complexity: O(1) (ignoring input vector copy).

    Better/Alternative Approaches (without code):
    ---------------------------------------------
    1. **Single-pass Modified Binary Search (Optimal):**
        - Instead of finding pivot first, modify binary search to always know which half is sorted and search accordingly.
        - At each step, check if left or right half is sorted, and decide where to search.
        - Time: O(log n), Space: O(1).
    2. **Linear Search:**
        - Traverse the array and check each element.
        - Time: O(n), not efficient for large arrays.
    3. **STL lower_bound/upper_bound:**
        - Only works if the array is fully sorted (not rotated).
    4. **Recursive Binary Search:**
        - Same logic as iterative, but implemented recursively.

    Improvements Made:
    ------------------
    - Added detailed comments for all important lines.
    - Improved variable naming and const-correctness.
    - Avoided unnecessary vector copies by passing by const reference.
    - Added input validation.
    - Added dry run at the end.
*/

#include <iostream>
#include <vector>
using namespace std;

// Standard binary search in a sorted subarray [start, end]
int binarySearch(const vector<int>& arr, int target, int start, int end) {
    // Loop until the search space is valid
    while (start <= end) {
        int mid = start + (end - start) / 2; // Prevent overflow

        // If mid element is the target, return its index
        if (arr[mid] == target) {
            return mid;
        }
        // If target is less, search in left half
        else if (target < arr[mid]) {
            end = mid - 1;
        }
        // If target is greater, search in right half
        else {
            start = mid + 1;
        }
    }
    // Target not found
    return -1;
}

// Function to find the index of the pivot (largest element) in rotated sorted array
int pivotElement(const vector<int>& arr) {
    int s = 0;
    int e = arr.size() - 1;

    // Edge case: If array is not rotated at all
    if (arr[s] < arr[e]) {
        return e; // Last element is the largest
    }

    // Binary search for pivot
    while (s < e) {
        int mid = s + (e - s) / 2;

        // If mid is pivot (greater than next element)
        if (mid < e && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        // If mid-1 is pivot (greater than current mid)
        if (mid > s && arr[mid - 1] > arr[mid]) {
            return mid - 1;
        }
        // If left part is unsorted, pivot must be there
        if (arr[s] >= arr[mid]) {
            e = mid - 1;
        }
        // If right part is unsorted, pivot must be there
        else {
            s = mid + 1;
        }
    }
    // When while loop ends, s == e, which is the pivot
    return s;
}

// Function to search for target in rotated sorted array
int search(const vector<int>& arr, int target) {
    if (arr.empty()) return -1; // Edge case: empty array

    int pivot = pivotElement(arr); // Find pivot index

    // If target is in the left sorted part [0, pivot]
    if (target >= arr[0] && target <= arr[pivot]) {
        return binarySearch(arr, target, 0, pivot);
    }
    // If target is in the right sorted part [pivot+1, end]
    if (pivot + 1 < arr.size() && target >= arr[pivot + 1] && target <= arr[arr.size() - 1]) {
        return binarySearch(arr, target, pivot + 1, arr.size() - 1);
    }
    // Target not found
    return -1;
}

int main() {
    // Example rotated sorted array
    vector<int> arr{4, 5, 6, 0, 1, 2, 3};
    int target = 4;

    int index = search(arr, target); // Search for target

    if (index == -1) {
        cout << "not found" << endl;
    } else {
        cout << "found at index: " << index << endl;
    }
    return 0;
}

/*
Dry Run:
--------
Input: arr = [4, 5, 6, 0, 1, 2, 3], target = 4

Step 1: Find pivot
    s=0, e=6
    mid=3, arr[3]=0
    arr[0]=4 >= arr[3]=0 => e=2
    s=0, e=2
    mid=1, arr[1]=5
    arr[1]=5 > arr[2]=6? No
    arr[0]=4 < arr[1]=5 => s=2
    s=2, e=2
    loop ends, pivot=2 (arr[2]=6)

Step 2: Decide which half to search
    arr[0]=4 <= target=4 <= arr[2]=6
    So, search in [0,2]

Step 3: Binary search in [0,2]
    start=0, end=2
    mid=1, arr[1]=5 > target=4 => end=0
    start=0, end=0
    mid=0, arr[0]=4 == target=4 => found at index 0

Output: found at index: 0
*/