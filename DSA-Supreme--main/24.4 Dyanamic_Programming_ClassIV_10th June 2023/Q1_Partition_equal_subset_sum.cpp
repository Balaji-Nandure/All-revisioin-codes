// https://leetcode.com/problems/partition-equal-subset-sum/

/*
    Approach Used: Subset Sum DP (0/1 Knapsack style)
    -------------------------------------------------
    The problem asks if we can partition the array into two subsets with equal sum.
    This is equivalent to asking: "Is there a subset whose sum is exactly half of the total sum?"

    - If the total sum is odd, it's impossible.
    - Otherwise, we check if a subset with sum = total_sum/2 exists.

    We solve this using:
    1. Pure Recursion (Exponential, for understanding)
    2. Top-Down DP (Memoization)
    3. Bottom-Up DP (Tabulation)
    4. Space Optimized DP (Best for constraints)

    Each approach is explained and commented below.
    At the end, a dry run is provided for clarity.

    Alternative Efficient Approach:
    ------------------------------
    - Use a 1D DP array (classic subset sum) for O(n*target) time and O(target) space.
    - See commented code at the end for this approach.
*/

class Solution {
public:
    // 1. Pure Recursive Approach (Exponential Time)
    // Returns true if subset sum 'target' can be formed from index..end
    bool solveRec(int index, vector<int>& nums, int target) {
        // Base case: If target is 0, subset found
        if (target == 0) return true;
        // If index out of bounds or target negative, not possible
        if (index >= nums.size() || target < 0) return false;

        // Try including current element
        bool include = solveRec(index + 1, nums, target - nums[index]);
        // Try excluding current element
        bool exclude = solveRec(index + 1, nums, target);

        // If either way is possible, return true
        return include || exclude;
    }

    // 2. Top-Down DP (Memoization)
    // dp[index][target] stores if target sum is possible from index..end
    bool solveTopDown(int index, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) return true; // Subset found
        if (index >= nums.size() || target < 0) return false; // Out of bounds or negative

        // If already computed, return stored result
        if (dp[index][target] != -1) return dp[index][target];

        // Include current element if possible
        bool include = solveTopDown(index + 1, nums, target - nums[index], dp);
        // Exclude current element
        bool exclude = solveTopDown(index + 1, nums, target, dp);

        // Store result in dp table
        dp[index][target] = include || exclude;
        return dp[index][target];
    }

    // 3. Bottom-Up DP (Tabulation)
    // Iteratively build up the answer using a 2D dp table
    bool solveTab(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[i][t] = true if sum 't' can be formed using elements from i..n-1
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: sum 0 is always possible (empty subset)
        for (int i = 0; i <= n; i++) dp[i][0] = true;

        // Fill dp table from bottom up
        for (int index = n - 1; index >= 0; index--) {
            for (int t = 1; t <= target; t++) {
                bool include = (t - nums[index] >= 0) ? dp[index + 1][t - nums[index]] : false;
                bool exclude = dp[index + 1][t];
                dp[index][t] = include || exclude;
            }
        }
        // Answer is whether we can form 'target' sum starting from index 0
        return dp[0][target];
    }

    // 4. Space Optimized DP (Best for Constraints)
    // Only keep two 1D arrays for current and next row
    bool spaceOptimization1(vector<int>& nums, int target) {
        int n = nums.size();
        vector<bool> curr(target + 1, false), next(target + 1, false);

        // Base case: sum 0 is always possible
        curr[0] = next[0] = true;

        // Fill dp from last index to first
        for (int index = n - 1; index >= 0; index--) {
            for (int t = 1; t <= target; t++) {
                bool include = (t - nums[index] >= 0) ? next[t - nums[index]] : false;
                bool exclude = next[t];
                curr[t] = include || exclude;
            }
            // Move current row to next for next iteration
            next = curr;
        }
        // Final answer is in curr[target]
        return curr[target];
    }

    // Main function to check if partition is possible
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        // Calculate total sum of array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // If sum is odd, cannot partition into two equal subsets
        if (sum & 1) return false;

        int target = sum / 2; // Each subset must sum to target

        // Uncomment any approach to use:

        // 1. Pure Recursion (Not recommended for large input)
        // return solveRec(0, nums, target);

        // 2. Top-Down DP (Memoization)
        // vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        // return solveTopDown(0, nums, target, dp);

        // 3. Bottom-Up DP (Tabulation)
        // return solveTab(nums, target);

        // 4. Space Optimized DP (Best for constraints)
        return spaceOptimization1(nums, target);
    }
};

/*
-------------------------------
Alternative Efficient Approach:
-------------------------------
    // 1D DP (Classic Subset Sum)
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int t = target; t >= num; t--) {
                dp[t] = dp[t] || dp[t - num];
            }
        }
        return dp[target];
    }
-------------------------------

-------------------------------
Dry Run Example:
-------------------------------
Input: nums = [1, 5, 11, 5]
Total sum = 22 (even), target = 11

DP Table (space optimized, curr/next):
Iteration for index = 3 (nums[3]=5):
    curr[0]=true, curr[5]=true (by including 5)
Iteration for index = 2 (nums[2]=11):
    curr[0]=true, curr[5]=true, curr[11]=true (by including 11)
Iteration for index = 1 (nums[1]=5):
    curr[0]=true, curr[5]=true, curr[10]=true (by including 5)
Iteration for index = 0 (nums[0]=1):
    curr[0]=true, curr[1]=true (by including 1), curr[5]=true, curr[6]=true, curr[10]=true, curr[11]=true

Final: curr[11]=true => Subset with sum 11 exists, so partition is possible.

-------------------------------
Time Complexity:
- All DP approaches: O(n*target)
- Space: O(target) for space optimized, O(n*target) for 2D DP

-------------------------------
*/