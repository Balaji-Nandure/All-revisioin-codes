// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

/*
Approach Used in This Code (Method 3):
--------------------------------------
1. Sort the array to enable binary search and easy duplicate handling.
2. For each element nums[i], search for nums[i] + k in the subarray to its right using binary search.
3. Use a set to store unique pairs (nums[i], nums[i]+k) to avoid counting duplicates.
4. Return the size of the set as the answer.

Time Complexity: O(n log n) due to sorting and binary search for each element.
Space Complexity: O(n) for the set storing unique pairs.

Alternative & Better Approaches:
-------------------------------
1. HashMap Approach (Optimal, O(n) time, O(n) space):
   - Count frequency of each number.
   - For k > 0: For each unique number, check if num+k exists.
   - For k == 0: Count numbers with frequency > 1.
   - See code in comments below.

2. Two Pointer Approach (O(n log n) time, O(1) space if sorting in-place):
   - Sort the array.
   - Use two pointers to find pairs with difference k, skip duplicates.

HashMap Approach Example Code:
------------------------------
/*
int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0; // Difference can't be negative
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    int count = 0;
    if (k == 0) {
        for (auto& [num, f] : freq)
            if (f > 1) count++;
    } else {
        for (auto& [num, _] : freq)
            if (freq.count(num + k)) count++;
    }
    return count;
}
*/

class Solution {
public:
    // Binary search helper function to find 'target' in nums[start...end]
    bool binarySearch(vector<int>& nums, int start, int end, int target) {
        // Standard binary search
        while (start <= end) {
            int mid = start + (end - start) / 2; // Calculate mid index
            if (nums[mid] == target) {
                return true; // Target found
            } else if (nums[mid] > target) {
                end = mid - 1; // Search left half
            } else {
                start = mid + 1; // Search right half
            }
        }
        return false; // Target not found
    }

    int findPairs(vector<int>& nums, int k) {
        // Edge case: k < 0 is invalid for absolute difference
        if (k < 0) return 0;

        // Sort the array to enable binary search and handle duplicates
        sort(nums.begin(), nums.end());

        set<pair<int, int>> ans; // To store unique k-diff pairs

        for (int i = 0; i < nums.size() - 1; ++i) {
            // Skip duplicate elements to avoid duplicate pairs
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int secondElement = nums[i] + k; // The value we want to find

            // Search for secondElement in the subarray nums[i+1...end]
            if (binarySearch(nums, i + 1, nums.size() - 1, secondElement)) {
                ans.insert({nums[i], secondElement}); // Insert unique pair
            }
        }
        return ans.size(); // Number of unique k-diff pairs
    }
};

/*
Dry Run Example:
----------------
Input: nums = [3,1,4,1,5], k = 2

Step 1: Sort nums -> [1,1,3,4,5]
Step 2: For each i:
    i=0, nums[i]=1, search for 3 in [1,3,4,5] -> found at index 2, insert (1,3)
    i=1, nums[i]=1 (duplicate of previous), skip
    i=2, nums[i]=3, search for 5 in [4,5] -> found at index 4, insert (3,5)
    i=3, nums[i]=4, search for 6 in [5] -> not found
    i=4, nums[i]=5, no elements to the right

ans = {(1,3), (3,5)}
Return 2

Alternative (HashMap) would also return 2.
*/