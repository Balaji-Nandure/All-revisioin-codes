/*
    Approach:
    ----------
    This code implements the classic Binary Search algorithm to find the index of a target element in a sorted array.
    Binary Search works by repeatedly dividing the search interval in half. If the value of the search key is less than 
    the item in the middle of the interval, narrow the interval to the lower half. Otherwise, narrow it to the upper half.
    Repeatedly check until the value is found or the interval is empty.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int target) {
    int start = 0;                  // Start index of the search range
    int end = size - 1;             // End index of the search range

    // Loop until the search range is valid
    while (start <= end) {
        // To avoid potential overflow, use this way to calculate mid
        int mid = start + (end - start) / 2; // Middle index of current search range

        // If the middle element is the target, return its index
        if (arr[mid] == target) {
            return mid;
        }
        // If target is less than mid element, search in left half
        else if (target < arr[mid]) {
            end = mid - 1;
        }
        // If target is greater than mid element, search in right half
        else {
            start = mid + 1;
        }
    }
    // If element is not found, return -1 (invalid index)
    return -1;
}

int main() {
    int arr[] = {1, 3, 7, 9, 11, 13, 15, 19}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);      // Calculate size of array
    int target = 15;                           // Element to search for

    int index = binarySearch(arr, n, target);  // Call binary search

    if (index == -1) {
        cout << "Element not found " << endl;  // If not found, print message
    }
    else {
        cout << "Found at index = " << index << endl; // If found, print index
    }
    return 0;
}

/*
    Better/Alternative Approaches:
    -----------------------------

    1. Recursive Binary Search:
    --------------------------
    // Recursive implementation of binary search
    int binarySearchRecursive(int arr[], int start, int end, int target) {
        if (start > end) return -1; // Base case: not found
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return mid;
        else if (target < arr[mid]) return binarySearchRecursive(arr, start, mid - 1, target);
        else return binarySearchRecursive(arr, mid + 1, end, target);
    }

    // Usage:
    // int index = binarySearchRecursive(arr, 0, n-1, target);

    2. STL Approach (C++ Standard Library):
    ---------------------------------------
    // Using std::binary_search to check existence
    #include <algorithm>
    bool found = binary_search(arr, arr + n, target);

    // To get index, use lower_bound
    auto it = lower_bound(arr, arr + n, target);
    if (it != arr + n && *it == target) {
        int index = it - arr;
        // Found at index
    } else {
        // Not found
    }

    3. Handling Duplicates (First/Last Occurrence):
    -----------------------------------------------
    // To find first occurrence of target
    int firstOccurrence(int arr[], int n, int target) {
        int ans = -1, start = 0, end = n-1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                ans = mid;
                end = mid - 1; // Move left to find earlier occurrence
            } else if (target < arr[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

    // Similar logic for last occurrence (move start = mid + 1 on match)

    4. Binary Search on Descending Sorted Array:
    --------------------------------------------
    // If array is sorted in descending order, reverse the comparison logic.

    5. Exponential Search (for unbounded/infinite arrays):
    ------------------------------------------------------
    // Use exponential search to find the range, then binary search in that range.

    6. Ternary Search (for unimodal functions):
    -------------------------------------------
    // Used for finding maximum/minimum in unimodal functions, not for sorted arrays.

    Dry Run:
    --------
    Array: [1, 3, 7, 9, 11, 13, 15, 19]
    Target: 15

    Iteration 1:
        start = 0, end = 7
        mid = 0 + (7-0)/2 = 3
        arr[3] = 9 < 15 => start = mid + 1 = 4

    Iteration 2:
        start = 4, end = 7
        mid = 4 + (7-4)/2 = 5
        arr[5] = 13 < 15 => start = mid + 1 = 6

    Iteration 3:
        start = 6, end = 7
        mid = 6 + (7-6)/2 = 6
        arr[6] = 15 == 15 => return 6

    Output: Found at index = 6
*/