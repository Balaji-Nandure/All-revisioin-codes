/*
Approach Used:
--------------
Below are recursive solutions for three classic dynamic programming problems:
1. Coin Change (Minimum Coins to Make Amount)
2. House Robber (Maximum Non-Adjacent Sum)
3. House Robber II (Circular Houses Variant)

For each, we provide:
- A clear recursive approach with comments explaining the logic behind each line.
- Better alternatives (Memoization, Tabulation, Space Optimization) with code in comments.
- Dry run at the end for understanding.

----------------------------------------------------------
1) Coin Change (Minimum Coins to Make Amount)
----------------------------------------------------------
Problem: Given coins[] and an amount, find the minimum number of coins needed to make up that amount. If not possible, return -1.

Recursive Approach (Exponential Time):
--------------------------------------
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Recursive function to find minimum coins needed for amount
int coinChangeRec(vector<int>& coins, int amount) {
    // Base case: If amount is 0, no coins are needed
    if (amount == 0) return 0;
    // If amount is negative, not possible to form amount
    if (amount < 0) return INT_MAX;

    int minCoins = INT_MAX; // Initialize minimum coins as infinity

    // Try every coin and choose the one that gives minimum coins
    for (int coin : coins) {
        int res = coinChangeRec(coins, amount - coin); // Recursive call for (amount - coin)
        if (res != INT_MAX) { // If subproblem is solvable
            minCoins = min(minCoins, 1 + res); // Add current coin and update minCoins
        }
    }
    return minCoins;
}

/*
Better Alternative: Top-Down DP (Memoization)
---------------------------------------------
int coinChangeMemo(vector<int>& coins, int amount, vector<int>& dp) {
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;
    if (dp[amount] != -1) return dp[amount];

    int minCoins = INT_MAX;
    for (int coin : coins) {
        int res = coinChangeMemo(coins, amount - coin, dp);
        if (res != INT_MAX) minCoins = min(minCoins, 1 + res);
    }
    dp[amount] = minCoins;
    return dp[amount];
}

Bottom-Up DP (Tabulation)
-------------------------
int coinChangeTab(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i-coin] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i-coin]);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
*/

/*
----------------------------------------------------------
2) House Robber (Maximum Non-Adjacent Sum)
----------------------------------------------------------
Problem: Given an array of non-negative integers, find the maximum sum of non-adjacent elements.

Recursive Approach:
-------------------
*/

int houseRobberRec(vector<int>& nums, int idx) {
    // Base case: If index is out of bounds, return 0
    if (idx >= nums.size()) return 0;

    // Option 1: Rob current house and skip next
    int rob = nums[idx] + houseRobberRec(nums, idx + 2);

    // Option 2: Skip current house
    int skip = houseRobberRec(nums, idx + 1);

    // Return the maximum of both options
    return max(rob, skip);
}

/*
Better Alternative: Top-Down DP (Memoization)
---------------------------------------------
int houseRobberMemo(vector<int>& nums, int idx, vector<int>& dp) {
    if (idx >= nums.size()) return 0;
    if (dp[idx] != -1) return dp[idx];
    int rob = nums[idx] + houseRobberMemo(nums, idx + 2, dp);
    int skip = houseRobberMemo(nums, idx + 1, dp);
    return dp[idx] = max(rob, skip);
}

Bottom-Up DP (Tabulation)
-------------------------
int houseRobberTab(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n+2, 0);
    for (int i = n-1; i >= 0; --i) {
        dp[i] = max(nums[i] + dp[i+2], dp[i+1]);
    }
    return dp[0];
}

Space Optimized
---------------
int houseRobberSpaceOpt(vector<int>& nums) {
    int prev1 = 0, prev2 = 0;
    for (int i = nums.size()-1; i >= 0; --i) {
        int curr = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
*/

/*
----------------------------------------------------------
3) House Robber II (Circular Houses)
----------------------------------------------------------
Problem: Houses are in a circle. Cannot rob first and last together.

Approach:
---------
- Rob houses from 0 to n-2 (exclude last)
- Rob houses from 1 to n-1 (exclude first)
- Take the maximum of both

Recursive Approach:
-------------------
*/

int houseRobber2Rec(vector<int>& nums, int start, int end) {
    // Base case: If index is out of bounds, return 0
    if (start > end) return 0;

    // Option 1: Rob current house and skip next
    int rob = nums[start] + houseRobber2Rec(nums, start + 2, end);

    // Option 2: Skip current house
    int skip = houseRobber2Rec(nums, start + 1, end);

    // Return the maximum of both options
    return max(rob, skip);
}

int houseRobber2(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    // Exclude last house
    int ans1 = houseRobber2Rec(nums, 0, n-2);
    // Exclude first house
    int ans2 = houseRobber2Rec(nums, 1, n-1);
    return max(ans1, ans2);
}

/*
Better Alternative: Use Memoization or Tabulation for each subarray as in House Robber I.
*/

/*
-------------------
Dry Run Example
-------------------
Coin Change:
coins = [1,2,5], amount = 5
coinChangeRec([1,2,5], 5)
-> Try coin 1: coinChangeRec([1,2,5], 4)
   -> Try coin 1: coinChangeRec([1,2,5], 3)
      ... (continues recursively)
   -> Try coin 2: coinChangeRec([1,2,5], 3)
   -> Try coin 5: coinChangeRec([1,2,5], 0) => 0
   minCoins = min( ... , 1 + 0 ) = 1
So, answer is 1 (using coin 5).

House Robber:
nums = [2,7,9,3,1]
houseRobberRec([2,7,9,3,1], 0)
-> Rob 2 + houseRobberRec([2,7,9,3,1], 2)
   -> Rob 9 + houseRobberRec([2,7,9,3,1], 4)
      -> Rob 1 + houseRobberRec([2,7,9,3,1], 6) = 1
      -> Skip 1: houseRobberRec([2,7,9,3,1], 5) = 0
      max(1,0) = 1
   -> Skip 9: houseRobberRec([2,7,9,3,1], 3)
      ...
   max(...)
-> Skip 2: houseRobberRec([2,7,9,3,1], 1)
   ...
Final answer: 12

House Robber II:
nums = [2,3,2]
houseRobber2([2,3,2])
-> max(houseRobber2Rec([2,3,2], 0, 1), houseRobber2Rec([2,3,2], 1, 2))
   = max(2, 3) = 3

All approaches can be optimized using DP as shown in the alternatives above.
*/
