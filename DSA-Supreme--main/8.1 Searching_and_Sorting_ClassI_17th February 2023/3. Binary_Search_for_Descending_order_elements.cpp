
// Approach:
// ----------
// This code implements Binary Search for a sorted array in *descending* order.
// Binary Search is an efficient algorithm to find an element in a sorted array (O(log n) time).
// For descending order, the direction of search is reversed compared to ascending order.

// Key Points:
// - The array must be sorted in descending order.
// - At each step, compare the middle element with the key.
// - If the middle element is greater than the key, search the right half (since all elements to the right are smaller).
// - If the middle element is less than the key, search the left half.

// Improvements:
// -------------
// - Pass the vector by const reference to avoid unnecessary copying.
// - Use more descriptive variable names.
// - Add more comments for clarity.
// - Print the index if the element is found.
// - Handle empty array edge case.
// - Provide alternative approach for both ascending and descending order (see comments below).
// - Add a dry run at the end.

// Alternative Approach (for both ascending and descending order):
// ---------------------------------------------------------------
// You can write a single binary search function that works for both ascending and descending arrays by checking the order at runtime.

// Example:
// --------
//     bool isDescending = arr.front() > arr.back();
//     if(isDescending) { /* use descending logic */ }
//     else { /* use ascending logic */ }

// See code comments for a detailed alternative implementation.



#include <iostream>
#include <vector>
using namespace std;

// Binary Search for Descending Order Array
int binarySearchDescending(const vector<int>& arr, int key) {
    int start = 0; // Start index of search range
    int end = arr.size() - 1; // End index of search range

    // Continue searching while the range is valid
    while (start <= end) {
        // Calculate mid to avoid integer overflow
        int mid = start + (end - start) / 2;

        // If the key is found at mid, return its index
        if (arr[mid] == key) {
            return mid;
        }
        // Since array is in descending order:
        // If mid element is greater than key, search right half
        else if (arr[mid] > key) {
            start = mid + 1;
        }
        // If mid element is less than key, search left half
        else {
            end = mid - 1;
        }
    }
    // If element is not found, return -1
    return -1;
}

/*
Alternative: Binary Search for both Ascending and Descending Order
------------------------------------------------------------------
int binarySearchOrderAgnostic(const vector<int>& arr, int key) {
    int start = 0, end = arr.size() - 1;
    bool isDescending = arr.size() > 1 && arr.front() > arr.back();

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key) return mid;

        if (isDescending) {
            if (arr[mid] > key) start = mid + 1;
            else end = mid - 1;
        } else {
            if (arr[mid] < key) start = mid + 1;
            else end = mid - 1;
        }
    }
    return -1;
}
*/

int main() {
    // Example array sorted in descending order
    vector<int> arr{13, 10, 9, 6, 2, 1};
    int key = 10; // Element to search for

    // Call binary search function
    int index = binarySearchDescending(arr, key);

    // Output result
    if (index == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index: " << index << endl;
    }

    return 0;
}

/*
Dry Run:
--------
Array: [13, 10, 9, 6, 2, 1]
Key: 11

Step 1:
start = 0, end = 5
mid = 0 + (5-0)/2 = 2
arr[2] = 9
arr[2] < 11, so search left half: end = mid - 1 = 1

Step 2:
start = 0, end = 1
mid = 0 + (1-0)/2 = 0
arr[0] = 13
arr[0] > 11, so search right half: start = mid + 1 = 1

Step 3:
start = 1, end = 1
mid = 1 + (1-1)/2 = 1
arr[1] = 10
arr[1] < 11, so search left half: end = mid - 1 = 0

Now, start (1) > end (0), so loop ends. Element not found.

Output: "Element not found"
*/

/*
Summary of Better Alternatives:
-------------------------------
- Use order-agnostic binary search for both ascending and descending arrays.
- Always pass large containers by const reference.
- Add input validation for empty arrays.
- For real-world use, consider using STL's std::binary_search or std::lower_bound for ascending arrays.
*/