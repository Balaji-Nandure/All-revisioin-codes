/*
Approach Used:
--------------
This code solves the classic "Coin Change" problem: Given a set of coin denominations and a target amount, find the minimum number of coins needed to make up that amount. If it's not possible, return -1.

We demonstrate three approaches:
1. Pure Recursion (solveRec): Try every possibility, no memoization. Exponential time.
2. Top-Down Dynamic Programming (Memoization) (solveTopDown): Store results for subproblems to avoid recomputation. O(n*amount) time.
3. Bottom-Up Dynamic Programming (Tabulation) (solveTab): Iteratively build up the answer from 0 to amount. O(n*amount) time, O(amount) space.

Better Alternatives:
--------------------
- Space Optimization: For this problem, bottom-up is already O(amount) space.
- BFS/Queue-based: For unbounded coin change, DP is optimal.
- For large coin sets, use unordered_map for memoization to save space.

Below is the improved code with detailed comments and a dry run at the end.
*/

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// 1. Pure Recursive Approach (Inefficient, Exponential Time)
/*
Logic:
- For each coin, try to use it and recursively solve for (amount - coin).
- Base case: If amount == 0, no coins needed. If amount < 0, not possible.
- Take the minimum among all choices.
*/
int solveRec(const vector<int> &coins, int amount) {
    // Base case: If amount is 0, no coins needed
    if (amount == 0) return 0;
    // If amount is negative, not possible to form amount
    if (amount < 0) return INT_MAX;

    int mini = INT_MAX; // To store minimum coins needed
    // Try every coin
    for (int i = 0; i < coins.size(); i++) {
        int res = solveRec(coins, amount - coins[i]); // Recursive call for reduced amount
        if (res != INT_MAX) {
            // If valid, update minimum (add 1 for current coin)
            mini = min(mini, 1 + res);
        }
    }
    return mini; // May return INT_MAX if not possible
}

// 2. Top-Down DP (Memoization)
/*
Logic:
- Same as recursion, but store results for each amount in dp[] to avoid recomputation.
- dp[amt] = minimum coins needed for amt.
*/
int solveTopDown(const vector<int>& coins, int amount, vector<int>& dp) {
    // Base case: If amount is 0, no coins needed
    if (amount == 0) return 0;
    // If amount is negative, not possible
    if (amount < 0) return INT_MAX;
    // If already computed, return stored value
    if (dp[amount] != -1) return dp[amount];

    int mini = INT_MAX;
    // Try every coin
    for (int i = 0; i < coins.size(); i++) {
        int res = solveTopDown(coins, amount - coins[i], dp);
        if (res != INT_MAX) {
            mini = min(mini, 1 + res);
        }
    }
    dp[amount] = mini; // Store result for future
    return dp[amount];
}

// 3. Bottom-Up DP (Tabulation)
/*
Logic:
- dp[i] = minimum coins needed to make amount i.
- Start from dp[0]=0, build up to dp[amount].
- For each amount i, try every coin: if (i-coin)>=0 and dp[i-coin] is valid, update dp[i].
*/
int solveTab(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX); // dp[i] = min coins for amount i
    dp[0] = 0; // Base case: 0 coins for amount 0

    // Build up dp[] from 1 to amount
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coins.size(); j++) {
            int coin = coins[j];
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                // If possible to form (i-coin), update dp[i]
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return dp[amount]; // May be INT_MAX if not possible
}

/*
Alternative: BFS Approach (Not needed for this problem, but possible)
- Use a queue to try all possible sums, level by level.
- Each level = one more coin used.
- Stop when amount is reached.
*/

// Main function to choose approach and handle -1 case
int coinChange(vector<int> &coins, int amount) {
    // Uncomment any approach to use

    // 1. Pure Recursion (Inefficient, for small inputs only)
    // int ans = solveRec(coins, amount);
    // if (ans == INT_MAX) return -1;
    // return ans;

    // 2. Top-Down DP (Memoization)
    // vector<int> dp(amount + 1, -1); // Initialize dp array with -1
    // int ans = solveTopDown(coins, amount, dp);
    // if (ans == INT_MAX) return -1;
    // return ans;

    // 3. Bottom-Up DP (Tabulation) (Recommended)
    int ans = solveTab(coins, amount);
    if (ans == INT_MAX) return -1; // If not possible, return -1 as per problem statement
    return ans;
}

int main() {
    // Example usage
    vector<int> coins = {1, 2}; // Coin denominations
    int amount = 3; // Target amount

    int ans = coinChange(coins, amount); // Get minimum coins required
    cout << "Coins required = " << ans << endl; // Output result

    return 0;
}

/*
Dry Run Example:
----------------
coins = [1,2], amount = 3

Bottom-Up DP Table:
dp[0] = 0
dp[1] = min(1+dp[0]) = 1
dp[2] = min(1+dp[1], 1+dp[0]) = min(2,1) = 1
dp[3] = min(1+dp[2], 1+dp[1]) = min(2,2) = 2

So, minimum coins required = 2 (2+1 or 1+1+1)

If amount = 11, coins = [2,5], dp[11] = -1 (not possible)

Time Complexity:
- Recursion: O(n^amount) (exponential)
- Top-Down/Bottom-Up: O(n*amount), where n = number of coins

Space Complexity:
- Top-Down: O(amount) for dp + recursion stack
- Bottom-Up: O(amount) for dp

Better Alternatives:
- For very large coin sets, use unordered_map for dp.
- For coin change with limited coins, use 2D DP (not needed here).
*/