/*
    Approach:
    -----------
    - The given code implements a modified binary search to find a target element in a "nearly sorted" array.
    - In a nearly sorted array, every element may be misplaced by at most one position from its correct sorted position.
    - So, for any mid index, the target can be at mid, mid-1, or mid+1.
    - If not found, we can safely ignore mid and its adjacent elements and continue the search in the remaining part.

    Better Alternatives (without code):
    -----------------------------------
    1. Linear Search: O(n) time, but not efficient for large arrays.
    2. Standard Binary Search: Not suitable for nearly sorted arrays, as elements may be misplaced by one position.
    3. Modified Binary Search (used here): O(log n) time, checks mid, mid-1, mid+1, and then skips two indices accordingly.
    4. If the array is k-nearly sorted (misplaced by at most k positions), we can extend this approach to check k neighbors on both sides, but time per iteration increases.

    Dry Run Example:
    ----------------
    arr = [10, 3, 40, 20, 50, 80], target = 40
    Iteration 1: s=0, e=5, mid=2, arr[mid]=40 -> found at index 2

    arr = [10, 3, 40, 20, 50, 80], target = 20
    Iteration 1: s=0, e=5, mid=2, arr[mid]=40
        arr[mid-1]=3, arr[mid+1]=20 -> found at index 3

    arr = [10, 3, 40, 20, 50, 80], target = 700
    Iteration 1: s=0, e=5, mid=2, arr[mid]=40
        target > arr[mid], s=mid+2=4
    Iteration 2: s=4, e=5, mid=4, arr[mid]=50
        target > arr[mid], s=mid+2=6
    Loop ends, return -1

*/

#include<iostream>
#include<vector>
using namespace std;

// Function to perform binary search in a nearly sorted array
int binarySearch(const vector<int>& arr, int target) {
    int s = 0; // Start index
    int e = arr.size() - 1; // End index

    while (s <= e) {
        int mid = s + (e - s) / 2; // Calculate mid to avoid overflow

        // Check if mid is the target
        if (arr[mid] == target) {
            return mid;
        }

        // Check if mid-1 is within bounds and is the target
        if (mid - 1 >= s && arr[mid - 1] == target) {
            return mid - 1;
        }

        // Check if mid+1 is within bounds and is the target
        if (mid + 1 <= e && arr[mid + 1] == target) {
            return mid + 1;
        }

        // If target is greater than arr[mid], ignore left part including mid and mid+1
        if (target > arr[mid]) {
            s = mid + 2;
        }
        // If target is less than arr[mid], ignore right part including mid and mid-1
        else {
            e = mid - 2;
        }
    }
    // Target not found
    return -1;
}

int main() {
    // Example nearly sorted array
    vector<int> arr{10, 3, 40, 20, 50, 80};
    int target = 700; // Target to search

    int ans = binarySearch(arr, target); // Call the search function

    if (ans == -1) {
        cout << "Not Found" << endl; // Target not found
    } else {
        cout << "Found at index: " << ans << endl; // Target found at index ans
    }

    return 0;
}

/*
Dry Run for target = 700:
-------------------------
arr = [10, 3, 40, 20, 50, 80]
s=0, e=5
mid=2, arr[mid]=40
    arr[mid-1]=3, arr[mid+1]=20
    target > arr[mid] => s = mid+2 = 4

s=4, e=5
mid=4, arr[mid]=50
    arr[mid-1]=20, arr[mid+1]=80
    target > arr[mid] => s = mid+2 = 6

s=6, e=5 => loop ends, return -1 (Not Found)
*/