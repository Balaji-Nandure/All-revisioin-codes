// Single-pass Modified Binary Search (Optimal)

// At each mid:

// Check if left half is sorted (nums[l] <= nums[mid])

// If target is in this range, move r = mid - 1.

// Else move l = mid + 1.

// Otherwise, right half is sorted.

// If target is in this range, move l = mid + 1.

// Else move r = mid - 1.

// Include necessary headers
#include<iostream>
#include<vector>
using namespace std;

// ----------- Brute Force Approach -----------
int searchBrute(vector<int>& nums, int target) {
    // Loop through each element
    for (int i = 0; i < nums.size(); i++) {
        // If current element equals target, return index
        if (nums[i] == target) {
            return i;
        }
    }
    // If we finish loop without finding, return -1
    return -1;
}

// ----------- Optimal Approach: Modified Binary Search -----------
int searchOptimal(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Prevents integer overflow

        // ✅ Step 1: Check if mid element itself is the target
        if (nums[mid] == target) {
            return mid;
        }

        // ✅ Step 2: Decide which half is sorted
        if (nums[left] <= nums[mid]) {
            // Left half is sorted
            if (nums[left] <= target && target < nums[mid]) {
                // Target lies inside sorted left half
                right = mid - 1;
            } else {
                // Target must lie in the right half
                left = mid + 1;
            }
        } else {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[right]) {
                // Target lies inside sorted right half
                left = mid + 1;
            } else {
                // Target must lie in the left half
                right = mid - 1;
            }
        }
    }

    // If we exit loop, element not found
    return -1;
}

// ----------- Main Function -----------
int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;

    cout << "Brute Force result: " << searchBrute(nums, target) << endl;
    cout << "Optimal Binary Search result: " << searchOptimal(nums, target) << endl;

    return 0;
}