// https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/

/*
Approach Used:
---------------
This problem is a classic example of Dynamic Programming (DP) - specifically, interval DP.
The goal is to minimize the maximum cost required to guarantee a win in the "Guess Number Higher or Lower II" game.
For any range [start, end], we try every possible guess 'i' in that range, and for each guess, the cost is:
    cost = i + max(cost of left subproblem, cost of right subproblem)
We want the minimum of these maximum costs for all possible guesses in the range.

We provide three approaches:
1. Pure Recursion (Exponential Time, TLE for large n)
2. Top-Down DP (Memoization, O(n^3) Time, O(n^2) Space)
3. Bottom-Up DP (Tabulation, O(n^3) Time, O(n^2) Space, Most Efficient for this problem)

Alternative/Better Approaches:
------------------------------
- For this problem, interval DP is optimal. There is no known O(n^2) solution, but you can optimize the inner loop by skipping some guesses using binary search or by only considering mid-points (not always correct for this problem).
- For small n, recursion with memoization is sufficient.
- For large n, use bottom-up DP as shown.

Below is the improved code with detailed comments and a dry run at the end.
*/

class Solution {
public:
    // Pure Recursive Approach (Exponential Time)
    int solveRec(int start, int end) {
        // Base Case: If the range is invalid or only one number, no cost needed
        if (start >= end) {
            return 0;
        }
        int ans = INT_MAX; // Initialize answer to a large value
        // Try every possible guess in the range [start, end]
        for (int i = start; i <= end; i++) {
            // The cost is the current guess 'i' plus the worst-case cost of the two subranges
            int cost = i + max(solveRec(start, i - 1), solveRec(i + 1, end));
            ans = min(ans, cost); // Take the minimum among all possible guesses
        }
        return ans;
    }

    // Top-Down DP (Memoization)
    int solveTopDown(int start, int end, vector<vector<int>>& dp) {
        // Base Case: If the range is invalid or only one number, no cost needed
        if (start >= end) {
            return 0;
        }
        // If already computed, return the stored result
        if (dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX; // Initialize answer to a large value
        // Try every possible guess in the range [start, end]
        for (int i = start; i <= end; i++) {
            // The cost is the current guess 'i' plus the worst-case cost of the two subranges
            int cost = i + max(solveTopDown(start, i - 1, dp), solveTopDown(i + 1, end, dp));
            ans = min(ans, cost); // Take the minimum among all possible guesses
        }
        dp[start][end] = ans; // Store the result for future use
        return dp[start][end];
    }

    // Bottom-Up DP (Tabulation)
    int solveTab(int n) {
        // dp[start][end] will store the minimum cost to guarantee a win for range [start, end]
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); // n+2 to avoid out-of-bounds

        // Fill the table for increasing lengths of the interval
        for (int len = 2; len <= n; len++) { // length of interval
            for (int start = 1; start <= n - len + 1; start++) {
                int end = start + len - 1;
                dp[start][end] = INT_MAX;
                // Try every possible guess in the interval [start, end]
                for (int i = start; i <= end; i++) {
                    // The cost is the current guess 'i' plus the worst-case cost of the two subranges
                    int cost = i + max((i - 1 >= start ? dp[start][i - 1] : 0),
                                       (i + 1 <= end ? dp[i + 1][end] : 0));
                    dp[start][end] = min(dp[start][end], cost); // Take the minimum among all possible guesses
                }
            }
        }
        // The answer for the whole range [1, n]
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        // Uncomment any approach to use

        // 1. Pure Recursive (Not recommended for large n)
        // return solveRec(1, n);

        // 2. Top-Down DP (Memoization)
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return solveTopDown(1, n, dp);

        // 3. Bottom-Up DP (Tabulation) - Most efficient for this problem
        return solveTab(n);
    }
};

/*
Dry Run Example:
----------------
Suppose n = 3. We want to find the minimum amount of money to guarantee a win.

Possible numbers: 1, 2, 3

- If we pick 1 first:
    - If the number is 1: cost = 0
    - If the number is 2 or 3: we must pay 1, then guess in [2,3]
        - If we pick 2: if number is 2: cost = 0; if 3: pay 2
        - So, worst case: pay 1 (first guess) + 2 (second guess) = 3

- If we pick 2 first:
    - If the number is 2: cost = 0
    - If the number is 1: pay 2, then guess in [1,1]: cost = 0
    - If the number is 3: pay 2, then guess in [3,3]: cost = 0
    - So, worst case: pay 2

- If we pick 3 first:
    - If the number is 3: cost = 0
    - If the number is 1 or 2: pay 3, then guess in [1,2]
        - If we pick 1: if number is 1: cost = 0; if 2: pay 1
        - So, worst case: pay 3 (first guess) + 1 (second guess) = 4

So, the minimum among all strategies is 2 (pick 2 first).

Output: 2

Time Complexity:
----------------
- Both Top-Down and Bottom-Up DP: O(n^3)
- Space Complexity: O(n^2)
*/