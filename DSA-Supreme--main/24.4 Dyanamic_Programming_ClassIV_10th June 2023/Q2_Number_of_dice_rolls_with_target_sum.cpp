// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

/*
Approach Used:
---------------
This problem is a classic example of Dynamic Programming (DP) - specifically, counting the number of ways to achieve a target sum by rolling n dice, each with k faces (numbered 1 to k). 
We use several approaches:
1. Pure Recursion (Exponential Time, not recommended for large inputs)
2. Top-Down DP (Memoization)
3. Bottom-Up DP (Tabulation)
4. Space Optimized DP (Best for constraints)

The final solution uses the space optimized DP for best performance.

Better Alternatives:
--------------------
- If constraints are small, recursion or memoization is fine.
- For large n/target, use tabulation or space optimized DP.
- For even more optimization, use 1D DP and rolling arrays.

Below, all approaches are implemented and explained.
*/

class Solution {
public:
    long long int MOD = 1000000007; // To avoid integer overflow, take result modulo 1e9+7

    // 1. Pure Recursion (Exponential Time)
    int solveRec(int n, int k, int target) {
        // Base case: If no dice left and target is also 0, 1 way (all dice used and sum matched)
        if (n == 0 && target == 0)
            return 1;
        // If no dice left but target not 0, or negative dice, or negative target, no way
        if (n == 0 || target < 0 || n < 0)
            return 0;

        long long int ans = 0;
        // Try all faces for current dice
        for (int i = 1; i <= k; i++) {
            ans += solveRec(n - 1, k, target - i); // Recurse for remaining dice and reduced target
        }
        return ans;
    }

    // 2. Top-Down DP (Memoization)
    long long int solveTopDown(int n, int k, int target, vector<vector<long long int>>& dp) {
        // Base cases as above
        if (n == 0 && target == 0)
            return 1;
        if (n == 0 || target < 0 || n < 0)
            return 0;

        // If already computed, return stored value
        if (dp[n][target] != -1)
            return dp[n][target];

        long long int ans = 0;
        // Try all faces for current dice
        for (int i = 1; i <= k; i++) {
            if (target - i >= 0) { // Only valid if target-i is non-negative
                ans = (ans + solveTopDown(n - 1, k, target - i, dp)) % MOD;
            }
        }
        dp[n][target] = ans; // Store result for future
        return ans;
    }

    // 3. Bottom-Up DP (Tabulation)
    int solveTab(int n, int k, int target) {
        // dp[i][t] = number of ways to get sum t with i dice
        vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, 0));
        dp[0][0] = 1; // Base: 1 way to get sum 0 with 0 dice

        // Build up the table
        for (int dice = 1; dice <= n; dice++) {
            for (int t = 1; t <= target; t++) {
                long long int ans = 0;
                // Try all faces for current dice
                for (int face = 1; face <= k; face++) {
                    if (t - face >= 0) {
                        ans = (ans + dp[dice - 1][t - face]) % MOD;
                    }
                }
                dp[dice][t] = ans;
            }
        }
        return dp[n][target];
    }

    // 4. Space Optimized DP (Best for constraints)
    int spaceOptimization(int n, int k, int target) {
        // Only keep previous and current row to save space
        vector<int> prev(target + 1, 0), curr(target + 1, 0);
        prev[0] = 1; // Base: 1 way to get sum 0 with 0 dice

        for (int dice = 1; dice <= n; dice++) {
            fill(curr.begin(), curr.end(), 0); // Reset current row
            for (int t = 1; t <= target; t++) {
                long long int ans = 0;
                // Try all faces for current dice
                for (int face = 1; face <= k; face++) {
                    if (t - face >= 0) {
                        ans = (ans + prev[t - face]) % MOD;
                    }
                }
                curr[t] = ans;
            }
            prev = curr; // Move to next dice
        }
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        // Uncomment any approach to use it

        // 1. Pure Recursion (Not recommended for large n/target)
        // return solveRec(n, k, target);

        // 2. Top-Down DP (Memoization)
        // vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, -1));
        // return solveTopDown(n, k, target, dp);

        // 3. Bottom-Up DP (Tabulation)
        // return solveTab(n, k, target);

        // 4. Space Optimized DP (Best for large constraints)
        return spaceOptimization(n, k, target);
    }
};

/*
-------------------
Dry Run Example:
-------------------
Suppose n = 2, k = 6, target = 7

We want number of ways to roll 2 dice (each 1-6) to sum to 7.

All possible pairs:
(1,6), (2,5), (3,4), (4,3), (5,2), (6,1) => 6 ways

Let's see how DP builds up:
- dp[0][0] = 1 (1 way to get sum 0 with 0 dice)
- For dice=1, dp[1][1..6]=1 (1 way to get each sum 1..6)
- For dice=2:
    For t=7:
        For face=1: prev[6]=1
        For face=2: prev[5]=1
        ...
        For face=6: prev[1]=1
        So, dp[2][7] = sum of prev[6], prev[5], ..., prev[1] = 1+1+1+1+1+1 = 6

Final answer: 6

-------------------
Alternative Approaches:
-------------------
- If k is very large, can use prefix sum optimization to reduce inner loop to O(1) per cell.
- If n or target is very large, use 1D DP and rolling arrays for further space reduction.

Time Complexity:
- Tabulation/Space Optimized: O(n * target * k)
- Memoization: O(n * target * k) with memo table

Space Complexity:
- Tabulation: O(n * target)
- Space Optimized: O(target)
*/
