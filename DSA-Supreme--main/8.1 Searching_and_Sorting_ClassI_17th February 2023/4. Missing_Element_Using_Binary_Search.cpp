// Problem: Find Missing Number in a Sorted Consecutive Array using Binary Search

// Steps:
// 1. In a perfect sequence:
//    arr[i] - arr[0] = i

// 2. If this condition holds → missing number is on the right.
//    If not → missing number is on the left.

// 3. Use binary search:
//    - mid = (left + right)/2
//    - If arr[mid] - arr[0] == mid → move right
//    - Else → move left

// 4. At the end:
//    Missing number = arr[0] + left

// Example:
// arr = [1,2,3,4,6,7,8]
// → Missing number = 5

// Complexity:
// Time = O(log n), Space = O(1)

#include <iostream>
#include <vector>
using namespace std;

int findMissing(const vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    int start = arr[0];  // first element (to compare differences)

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If difference matches, missing is on the right side
        if (arr[mid] - start == mid) {
            left = mid + 1;
        } else {
            // Otherwise, missing is on the left side
            right = mid - 1;
        }
    }

    // At the end, 'left' points to index of missing number
    return start + left;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 6, 7, 8};
    cout << "Missing number: " << findMissing(arr) << endl;
    return 0;
}
