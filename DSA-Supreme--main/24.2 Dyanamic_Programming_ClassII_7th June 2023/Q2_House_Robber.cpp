/*
    House Robber Problem (Leetcode 198): 
    Given a list of non-negative integers representing the amount of money of each house, 
    determine the maximum amount of money you can rob tonight without alerting the police 
    (i.e., you cannot rob two adjacent houses).

    Approaches used in this code:
    1. Pure Recursion (Exponential Time, not recommended for large input)
    2. Top-Down DP (Memoization, O(n) Time, O(n) Space)
    3. Bottom-Up DP (Tabulation, O(n) Time, O(n) Space)
    4. Space Optimized DP (O(n) Time, O(1) Space) [Best]
    
    Each approach is explained with comments and alternatives are provided in comments.
    Dry run is provided at the end.
*/

class Solution {
public: 
    // 1. Pure Recursion (Brute Force)
    // n: index of current house
    // Returns: max money that can be robbed from house 0 to n
    int solveRec(vector<int>& nums, int n) {
        // Base case: If index is negative, no house to rob
        if (n < 0) return 0;
        // Base case: Only one house, rob it
        if (n == 0) return nums[0];
        // Option 1: Rob current house, skip previous
        int include = nums[n] + solveRec(nums, n - 2);
        // Option 2: Skip current house
        int exclude = solveRec(nums, n - 1);
        // Return the better of the two options
        return max(include, exclude);
    }

    // 2. Top-Down DP (Memoization)
    // dp[n]: stores max money that can be robbed from house 0 to n
    int solveTopDown(vector<int>& nums, int n, vector<int>& dp) {
        // Base case: If index is negative, no house to rob
        if (n < 0) return 0;
        // Base case: Only one house, rob it
        if (n == 0) return nums[0];
        // If already computed, return stored value
        if (dp[n] != -1) return dp[n];
        // Option 1: Rob current house, skip previous
        int include = nums[n] + solveTopDown(nums, n - 2, dp);
        // Option 2: Skip current house
        int exclude = solveTopDown(nums, n - 1, dp);
        // Store and return the better of the two options
        dp[n] = max(include, exclude);
        return dp[n];
    }

    // 3. Bottom-Up DP (Tabulation)
    // Iteratively build up the solution from base cases
    int solveTab(vector<int>& nums, int n) {
        // Edge case: No houses
        if (n < 0) return 0;
        // dp[i]: max money that can be robbed from house 0 to i
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0]; // Base case: only one house
        // Build the dp array
        for (int i = 1; i <= n; i++) {
            int include = nums[i];
            if (i - 2 >= 0) include += dp[i - 2]; // Add value from non-adjacent house
            int exclude = dp[i - 1]; // Skip current house
            dp[i] = max(include, exclude); // Take the better option
        }
        return dp[n];
    }

    // 4. Space Optimized DP (Best Approach)
    // Only keep track of last two results instead of full dp array
    int spaceOpt(vector<int>& nums, int n) {
        // Edge case: No houses
        if (n < 0) return 0;
        // Edge case: Only one house
        if (n == 0) return nums[0];
        int prev2 = 0;         // dp[i-2]
        int prev1 = nums[0];   // dp[i-1]
        int curr = prev1;      // dp[i]
        for (int i = 1; i <= n; i++) {
            int include = nums[i] + prev2; // Rob current, add dp[i-2]
            int exclude = prev1;           // Skip current, take dp[i-1]
            curr = max(include, exclude);  // Best of both
            prev2 = prev1;                 // Move window forward
            prev1 = curr;
        }
        return curr;
    }

    // Main function to call the best approach
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        // Uncomment any approach to use it:

        // 1. Pure Recursion (Not recommended for large input)
        // return solveRec(nums, n);

        // 2. Top-Down DP (Memoization)
        // vector<int> dp(n + 1, -1);
        // return solveTopDown(nums, n, dp);

        // 3. Bottom-Up DP (Tabulation)
        // return solveTab(nums, n);

        // 4. Space Optimized DP (Best)
        return spaceOpt(nums, n);
    }
};

/*
-------------------
Alternative Approaches (with code):

// 1. Iterative Tabulation with O(1) space (slightly different style)
int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int x : nums) {
        int curr = max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

-------------------
Dry Run Example:
Input: nums = [2, 7, 9, 3, 1]

Index:   0  1  2  3  4
Value:   2  7  9  3  1

Space Optimized DP:
prev2 = 0, prev1 = 2

i=1: include = 7 + 0 = 7, exclude = 2 => curr = 7, prev2=2, prev1=7
i=2: include = 9 + 2 = 11, exclude = 7 => curr = 11, prev2=7, prev1=11
i=3: include = 3 + 7 = 10, exclude = 11 => curr = 11, prev2=11, prev1=11
i=4: include = 1 + 11 = 12, exclude = 11 => curr = 12, prev2=11, prev1=12

Final answer: 12

-------------------
Summary:
- Use Space Optimized DP for best performance (O(n) time, O(1) space).
- For learning, try recursion and memoization to understand the problem structure.
- Always handle edge cases (empty input, single house).
*/