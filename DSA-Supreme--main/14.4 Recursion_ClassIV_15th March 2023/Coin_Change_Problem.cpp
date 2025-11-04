/*
Approach Used:
--------------
- This code solves the classic **Coin Change Problem** using simple recursion (brute-force).
- Given a set of coin denominations and a target amount, the goal is to find the minimum number of coins needed to make up the target amount.
- At each recursive call, the function tries every coin denomination, subtracts its value from the target, and recursively solves the subproblem.
- The minimum among all possible choices is taken as the answer for the current target.
- If the target becomes 0, 0 coins are needed (base case).
- If the target becomes negative, the path is invalid (return INT_MAX to ignore this path).

Key Points & Comments:
----------------------
- The code explores all possible combinations (with repetition) of coins to reach the target.
- No memoization is used, so the time complexity is exponential (very slow for large targets or many coins).
- INT_MAX is used to represent an impossible case (so that invalid paths do not affect the minimum).
- The code prints the minimum number of coins needed to make up the target amount.

Better/Alternative Approaches:
-----------------------------
1. **Memoization (Top-Down DP):**
   - Store results of subproblems in a dp array to avoid recomputation.
   - Reduces time complexity from exponential to O(n*target), where n = number of coins.
   - Example:
     ```
     int solveMemo(vector<int>& arr, int target, vector<int>& dp) {
         if(target == 0) return 0;
         if(target < 0) return INT_MAX;
         if(dp[target] != -1) return dp[target];
         int mini = INT_MAX;
         for(int i = 0; i < arr.size(); i++) {
             int ans = solveMemo(arr, target - arr[i], dp);
             if(ans != INT_MAX)
                 mini = min(mini, ans + 1);
         }
         dp[target] = mini;
         return mini;
     }
     // Usage:
     // vector<int> dp(target+1, -1);
     // int ans = solveMemo(arr, target, dp);
     ```

2. **Tabulation (Bottom-Up DP):**
   - Build up the answer iteratively from 0 to target.
   - Example:
     ```
     int coinChangeTabulation(vector<int>& arr, int target) {
         vector<int> dp(target+1, INT_MAX);
         dp[0] = 0;
         for(int t = 1; t <= target; t++) {
             for(int coin : arr) {
                 if(t - coin >= 0 && dp[t - coin] != INT_MAX)
                     dp[t] = min(dp[t], dp[t - coin] + 1);
             }
         }
         return dp[target] == INT_MAX ? -1 : dp[target];
     }
     ```

3. **Breadth-First Search (BFS):**
   - Treat each amount as a node and use BFS to find the shortest path to the target.
   - Guarantees the minimum number of coins.

4. **Greedy Approach:**
   - Only works for some coin systems (not all). Not applicable for arbitrary denominations.

----------------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
using namespace std;

// Recursive function to find the minimum number of coins needed to make up the target amount
int solve(vector<int>& arr, int target) {
    // Base Case: If target is 0, no coins are needed
    if(target == 0)
        return 0;
    // Base Case: If target is negative, this path is invalid
    if(target < 0)
        return INT_MAX; // Use INT_MAX to indicate impossible case

    int mini = INT_MAX; // Initialize minimum coins needed as INT_MAX

    // Try every coin denomination
    for(int i = 0; i < arr.size(); i++) {
        // Recursive call: try using coin arr[i]
        int remAns = solve(arr, target - arr[i]);
        // If ans is valid, update mini
        if(remAns != INT_MAX) // Avoid overflow when adding 1
            mini = min(mini, ans + 1);
    }
    // Return the minimum coins needed for current target
    return mini;
}

int main() {
    vector<int> arr{1, 2}; // Coin denominations
    int target = 5;        // Target amount

    int ans = solve(arr, target); // Find minimum coins needed

    // If ans is INT_MAX, it means target cannot be formed
    if(ans == INT_MAX)
        cout << "It is not possible to form the target amount with given coins." << endl;
    else
        cout << "Answer is " << ans << endl; // Print the answer

    return 0;
}

/*
Dry Run:
--------
arr = {1, 2}, target = 5

solve(5):
    try coin 1: solve(4)
        try coin 1: solve(3)
            try coin 1: solve(2)
                try coin 1: solve(1)
                    try coin 1: solve(0) => 0
                    try coin 2: solve(-1) => INT_MAX
                    min = 1 (0+1)
                try coin 2: solve(0) => 0
                min = 1 (0+1)
            min = 2 (1+1)
            try coin 2: solve(1)
                try coin 1: solve(0) => 0
                try coin 2: solve(-1) => INT_MAX
                min = 1 (0+1)
            min = 2 (1+1)
        min = 3 (2+1)
        try coin 2: solve(2)
            try coin 1: solve(1) => 1
            try coin 2: solve(0) => 0
            min = 1 (0+1)
        min = 2 (1+1)
    min = 3 (2+1)
    try coin 2: solve(3)
        try coin 1: solve(2) => 1
        try coin 2: solve(1) => 1
        min = 2 (1+1)
    min = 3 (2+1)

Final answer: 3 (minimum coins needed to make 5 using {1,2} is 3: 2+2+1 or 1+1+1+2, etc.)
*/