/*
    Problem: Paint Fence
    Given n fence posts and k colors, find the number of ways to paint the fence such that no more than two adjacent posts have the same color.

    Approach Used:
    - This code demonstrates four approaches to solve the problem:
        1. Pure Recursion
        2. Top-Down DP (Memoization)
        3. Bottom-Up DP (Tabulation)
        4. Space Optimized DP

    Recurrence Relation:
    Let dp[i] = number of ways to paint i posts.
    For i >= 3:
        dp[i] = (dp[i-1] + dp[i-2]) * (k-1)
    Explanation:
        - If the last two posts have different colors, we can paint the ith post with any color except the last one: dp[i-1] * (k-1)
        - If the last two posts have the same color, the (i-1)th and (i-2)th must be different, so dp[i-2] * (k-1)
        - Total = (dp[i-1] + dp[i-2]) * (k-1)

    Alternatives:
    - Iterative DP with O(n) space (shown)
    - Space optimized DP with O(1) space (shown)
    - Pure recursion (not recommended for large n due to exponential time)
    - Top-down DP with memoization (recommended for clarity and efficiency)
*/

#include<iostream>
#include<vector>
using namespace std;

// Pure Recursive Approach (Exponential Time)
// Returns number of ways to paint n posts with k colors
int solveRec(int n, int k) {
    // Base case: Only one post, can be painted in k ways
    if (n == 1) return k;
    // Base case: Two posts, can be painted in k*k ways if both different, or k ways if both same
    if (n == 2) return k + k * (k - 1);
    // Recursive case: Use recurrence relation
    int ans = (solveRec(n - 1, k) + solveRec(n - 2, k)) * (k - 1);
    return ans;
}

// Top-Down DP (Memoization)
// dp[n] stores the number of ways to paint n posts
int solveTopDown(int n, int k, vector<int>& dp) {
    // Base cases
    if (n == 1) return k;
    if (n == 2) return k + k * (k - 1);
    // If already computed, return stored value
    if (dp[n] != -1) return dp[n];
    // Compute and store in dp[n]
    dp[n] = (solveTopDown(n - 1, k, dp) + solveTopDown(n - 2, k, dp)) * (k - 1);
    return dp[n];
}

// Bottom-Up DP (Tabulation)
// Iteratively fills dp array from 1 to n
int solveTab(int n, int k) {
    // Create dp array of size n+1, initialized to 0
    vector<int> dp(n + 1, 0);
    // Base cases
    dp[1] = k;
    if (n >= 2) dp[2] = k + k * (k - 1);
    // Fill dp array using recurrence
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);
    }
    return dp[n];
}

// Space Optimized DP
// Only keeps last two computed values, reducing space to O(1)
int solveSpaceOpt(int n, int k) {
    if (n == 1) return k;
    if (n == 2) return k + k * (k - 1);
    int prev2 = k; // dp[i-2]
    int prev1 = k + k * (k - 1); // dp[i-1]
    for (int i = 3; i <= n; i++) {
        int curr = (prev1 + prev2) * (k - 1); // Current dp[i]
        prev2 = prev1; // Shift for next iteration
        prev1 = curr;
    }
    return prev1;
}

/*
    Alternative: Iterative DP with explicit same/diff tracking (for clarity)
    // Let same = ways where last two posts have same color
    // Let diff = ways where last two posts have different color
    int paintFence(int n, int k) {
        if (n == 1) return k;
        int same = k, diff = k * (k - 1);
        for (int i = 3; i <= n; i++) {
            int prev_diff = diff;
            diff = (same + diff) * (k - 1);
            same = prev_diff;
        }
        return same + diff;
    }
*/

// Main function to test all approaches
int main() {
    int n = 4; // Number of posts
    int k = 3; // Number of colors

    // Uncomment any approach to test

    // 1. Pure Recursive (Not recommended for large n)
    // int ans = solveRec(n, k);

    // 2. Top-Down DP (Memoization)
    // vector<int> dp(n + 1, -1);
    // int ans = solveTopDown(n, k, dp);

    // 3. Bottom-Up DP (Tabulation)
    // int ans = solveTab(n, k);

    // 4. Space Optimized DP (Recommended)
    int ans = solveSpaceOpt(n, k);

    cout << "Number of ways to paint the fence: " << ans << endl;

    /*
        Dry Run for n = 4, k = 3:

        Base cases:
        dp[1] = 3
        dp[2] = 3 + 3*(3-1) = 3 + 6 = 9

        For i = 3:
        dp[3] = (dp[2] + dp[1]) * (k-1) = (9 + 3) * 2 = 12 * 2 = 24

        For i = 4:
        dp[4] = (dp[3] + dp[2]) * (k-1) = (24 + 9) * 2 = 33 * 2 = 66

        So, output: 66
    */

    return 0;
}