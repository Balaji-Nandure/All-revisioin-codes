/*
Approach Used: Variable Size Sliding Window (Optimal O(n) Solution)
-------------------------------------------------------------------
We solve the "Minimum Size Subarray Sum" problem using the sliding window technique with two pointers.
The goal is to find the minimal length of a contiguous subarray of which the sum is at least the target value.

Logic:
------
- Use two pointers (i and j) to represent the current window [i, j].
- Expand the window by moving 'j' and adding nums[j] to the current sum.
- When the sum becomes >= target, try to shrink the window from the left (move 'i' forward) to find the smallest window that still satisfies the sum >= target.
- Update the minimum length whenever a valid window is found.

Why this works:
---------------
- Each element is added and removed from the window at most once, so the time complexity is O(n).
- The window only grows or shrinks as needed, ensuring optimal performance.

Better Alternatives & Detailed Approaches:
------------------------------------------
1. **Brute Force (O(n^2)):**
   For each starting index, try all possible ending indices and check if the sum is >= target.
   ```
   int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
       int minLen = INT_MAX;
       for(int i = 0; i < n; i++) {
           int sum = 0;
           for(int j = i; j < n; j++) {
               sum += nums[j];
               if(sum >= target) {
                   minLen = min(minLen, j - i + 1);
                   break; // No need to check longer subarrays starting at i
               }
           }
       }
       return minLen == INT_MAX ? 0 : minLen;
   }
   ```
   - Not efficient for large inputs.

2. **Prefix Sum + Binary Search (O(n log n)):**
   - Compute prefix sums.
   - For each index, use binary search to find the smallest subarray ending at or after that index with sum >= target.
   ```
   int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
       vector<int> prefix(n+1, 0);
       for(int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];
       int minLen = INT_MAX;
       for(int i = 1; i <= n; i++) {
           int toFind = prefix[i] - target;
           auto it = lower_bound(prefix.begin(), prefix.begin() + i, toFind);
           if(it != prefix.begin() + i) {
               int idx = it - prefix.begin();
               minLen = min(minLen, i - idx);
           }
       }
       return minLen == INT_MAX ? 0 : minLen;
   }
   ```
   - Slightly better than brute force, but not as optimal as sliding window.

3. **Optimal Sliding Window (O(n)) [Used Below]:**
   - See code below.

Dry Run:
--------
Input: target = 7, nums = [2,3,1,2,4,3]
Step-by-step:
- j=0, sum=2 (not enough)
- j=1, sum=5 (not enough)
- j=2, sum=6 (not enough)
- j=3, sum=8 (>=7) -> window [0,3], len=4, shrink: sum=6, i=1
- j=4, sum=10 (add 4), (>=7) -> window [1,4], len=4, shrink: sum=7, i=2, len=3, shrink: sum=6, i=3
- j=5, sum=9 (add 3), (>=7) -> window [3,5], len=3, shrink: sum=7, i=4, len=2, shrink: sum=3, i=5
- End. Minimum length found is 2 ([4,3]).

*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        int minLen = INT_MAX; // Initialize minimum length to a large value
        int sum = 0; // Current sum of the window
        int left = 0; // Left pointer of the window

        // Iterate with right pointer
        for(int right = 0; right < n; right++) {
            sum += nums[right]; // Expand window: include nums[right] in sum

            // While current window sum is enough, try to shrink from left
            while(sum >= target) {
                minLen = min(minLen, right - left + 1); // Update minimum length if smaller window found
                sum -= nums[left]; // Remove nums[left] from sum as we shrink window
                left++; // Move left pointer forward to try and find smaller window
            }
        }

        // If no valid window found, return 0
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

/*
Dry Run Example:
----------------
Input: target = 7, nums = [2,3,1,2,4,3]

right=0, sum=2
right=1, sum=5
right=2, sum=6
right=3, sum=8 (>=7)
    minLen = 4 (window [0,3])
    shrink: sum=6, left=1
right=4, sum=10 (add 4)
    minLen = 4 (window [1,4])
    shrink: sum=7, left=2
    minLen = 3 (window [2,4])
    shrink: sum=6, left=3
right=5, sum=9 (add 3)
    minLen = 3 (window [3,5])
    shrink: sum=7, left=4
    minLen = 2 (window [4,5])
    shrink: sum=3, left=5

Result: minLen = 2 ([4,3])
*/
