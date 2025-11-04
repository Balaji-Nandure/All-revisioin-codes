/*
----------------------------------------------------------
1) Partition Equal Subset Sum - Space Optimized Approach
----------------------------------------------------------
Problem:
Given an array of positive integers, determine if it can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Approach Used:
---------------
- This is a classic 0/1 Knapsack (subset sum) problem.
- We want to check if there exists a subset whose sum is exactly half of the total sum.
- If total sum is odd, it's not possible.
- We use space optimized DP (using only 1D array) to reduce space from O(n*sum) to O(sum).

Code with Comments:
-------------------
*/

#include <vector>
#include <iostream>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for (int num : nums) totalSum += num; // Calculate total sum

    if (totalSum % 2 != 0) return false; // If sum is odd, can't partition

    int target = totalSum / 2; // Each subset must sum to target

    // Space optimized DP: only 1D array needed
    vector<bool> dp(target + 1, false);
    dp[0] = true; // Base case: sum 0 is always possible

    // For each number, update dp array from right to left
    for (int num : nums) {
        for (int j = target; j >= num; --j) {
            // If sum j-num was possible before, sum j is now possible
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target]; // If target sum is possible, partition exists
}

/*
Better Alternatives:
--------------------
- Recursive + Memoization (Top-Down DP): O(n*sum), but uses recursion stack.
- 2D DP (Tabulation): dp[i][j] = true if sum j is possible with first i elements.
- Bitset optimization (for large sum): Use std::bitset for very large arrays.

Recursive + Memoization Example:
--------------------------------
bool canPartitionRec(vector<int>& nums, int n, int target, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (n == 0) return nums[0] == target;
    if (dp[n][target] != -1) return dp[n][target];
    bool notTake = canPartitionRec(nums, n-1, target, dp);
    bool take = false;
    if (nums[n] <= target)
        take = canPartitionRec(nums, n-1, target-nums[n], dp);
    return dp[n][target] = take || notTake;
}

Dry Run:
--------
nums = [1, 5, 11, 5]
totalSum = 22, target = 11
dp[0] = true
For num=1: dp[1]=true
For num=5: dp[6]=true, dp[5]=true
For num=11: dp[11]=true, dp[12]=false...
For num=5: dp[11]=true (already true), etc.
At end, dp[11]=true => Partition possible.

----------------------------------------------------------
2) Minimum Swaps to Make Sequence Increasing
----------------------------------------------------------
Problem:
Given two integer arrays A and B of the same length, you are allowed to swap A[i] and B[i] at any index i. Find the minimum number of swaps required to make both sequences strictly increasing.

Approach Used:
---------------
- Dynamic Programming with two states:
    - keep[i]: Minimum swaps to make sequences increasing up to i, without swapping at i.
    - swap[i]: Minimum swaps to make sequences increasing up to i, with swapping at i.
- At each index, check if swapping or not swapping maintains strictly increasing order.

Code with Comments:
-------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

int minSwap(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> keep(n, INT_MAX);  // keep[i]: min swaps if we do NOT swap at i
    vector<int> swap(n, INT_MAX);  // swap[i]: min swaps if we swap at i

    keep[0] = 0;   // No swap at first index
    swap[0] = 1;   // Swap at first index

    for (int i = 1; i < n; ++i) {
        // If both sequences are strictly increasing without swap
        if (A[i] > A[i-1] && B[i] > B[i-1]) {
            keep[i] = keep[i-1];           // No swap at i
            swap[i] = swap[i-1] + 1;       // Swap at i, so add 1 to previous swap
        }
        // If swapping at i or i-1 makes sequences strictly increasing
        if (A[i] > B[i-1] && B[i] > A[i-1]) {
            keep[i] = min(keep[i], swap[i-1]);     // No swap at i, but swap at i-1
            swap[i] = min(swap[i], keep[i-1] + 1); // Swap at i, no swap at i-1
        }
    }
    return min(keep[n-1], swap[n-1]); // Minimum swaps at last index
}

/*
Better Alternatives:
--------------------
- Space Optimization: Only keep previous keep/swap values (O(1) space).
- Greedy: Not possible due to dependencies between swaps.

Space Optimized Version:
------------------------
int minSwap(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int keep = 0, swap = 1;
    for (int i = 1; i < n; ++i) {
        int keepNew = INT_MAX, swapNew = INT_MAX;
        if (A[i] > A[i-1] && B[i] > B[i-1]) {
            keepNew = min(keepNew, keep);
            swapNew = min(swapNew, swap + 1);
        }
        if (A[i] > B[i-1] && B[i] > A[i-1]) {
            keepNew = min(keepNew, swap);
            swapNew = min(swapNew, keep + 1);
        }
        keep = keepNew;
        swap = swapNew;
    }
    return min(keep, swap);
}

Dry Run:
--------
A = [1,3,5,4], B = [1,2,3,7]
i=0: keep=0, swap=1
i=1: A[1]>A[0] && B[1]>B[0] => keep=0, swap=1
      A[1]>B[0] && B[1]>A[0] => keep=min(0,1)=0, swap=min(1,1)=1
i=2: A[2]>A[1] && B[2]>B[1] => keep=0, swap=1
      A[2]>B[1] && B[2]>A[1] => keep=min(0,1)=0, swap=min(1,1)=1
i=3: A[3]>A[2] && B[3]>B[2] => false
      A[3]>B[2] && B[3]>A[2] => keep=min(INT_MAX,1)=1, swap=min(INT_MAX,1)=1
Result: min(keep, swap) = 1
