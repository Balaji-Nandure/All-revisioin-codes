/*

Approach Used:
---------------
This code implements Exponential Search, which is efficient for searching in sorted arrays, especially when the element to be searched is near the beginning. 
Exponential Search works in two steps:
1. Find the range where the target element may reside by repeatedly doubling the index (exponential jumps).
2. Once the range is found, perform Binary Search in that range.

Time Complexity:
- O(log i) where i is the index of the target element.

Better Alternatives:
--------------------
- If the array is not sorted, use Linear Search (O(n)).
- If the array is sorted and random access is allowed, Binary Search (O(log n)) is standard.
- For unbounded/infinite arrays, Exponential Search is preferred.
- For very large datasets, consider Interpolation Search (works best if data is uniformly distributed).

Below is the improved code with detailed comments and a dry run at the end.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Standard Binary Search function to search for target in arr[start...end]
bool binarySearch(const vector<int>& arr, int start, int end, int target) {
    // Loop until the search space is valid
    while (start <= end) {
        int mid = start + (end - start) / 2; // Prevents integer overflow
        // If target found at mid, return true
        if (arr[mid] == target) {
            return true;
        }
        // If target is smaller, ignore right half
        else if (arr[mid] > target) {
            end = mid - 1;
        }
        // If target is greater, ignore left half
        else {
            start = mid + 1;
        }
    }
    // Target not found
    return false;
}

// Exponential Search function
bool expoSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    if (n == 0) return false; // Edge case: empty array

    // Check if the first element is the target
    if (arr[0] == target)
        return true;

    // Find range for binary search by repeated doubling
    int i = 1;
    while (i < n && arr[i] <= target) {
        i = i * 2; // Exponentially increase i
    }

    // Calculate the range for binary search
    int start = i / 2; // Start from previous power of 2
    int end = min(i, n - 1); // End at current i or last index

    // Perform binary search in the found range
    return binarySearch(arr, start, end, target);
}

int main() {
    // Example sorted array
    vector<int> arr = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int target = 71; // Element to search

    // Call exponential search and print result
    if (expoSearch(arr, target)) {
        cout << "Element found" << endl;
    }
    else {
        cout << "Not found";
    }
    return 0;
}

/*
Alternative Approach: Pure Binary Search
----------------------------------------
If you know the array size and it is sorted, you can use only binary search:

bool binarySearchOnly(const vector<int>& arr, int target) {
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) start = mid + 1;
        else end = mid - 1;
    }
    return false;
}

int main() {
    vector<int> arr = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int target = 71;
    if (binarySearchOnly(arr, target)) cout << "Element found" << endl;
    else cout << "Not found";
    return 0;
}

Dry Run of Exponential Search:
-----------------------------
arr = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70}
target = 71

Step 1: arr[0] != 71
Step 2: i = 1, arr[1]=4 <= 71 -> i=2
        arr[2]=5 <= 71 -> i=4
        arr[4]=11 <= 71 -> i=8
        arr[8]=56 <= 71 -> i=16 (now i >= n)
Step 3: start = i/2 = 8, end = min(i, n-1) = 9
Step 4: Binary search in arr[8..9]:
        mid = 8, arr[8]=56 < 71 -> start=9
        mid = 9, arr[9]=70 < 71 -> start=10
        start > end, so not found.

Output: Not found

*/