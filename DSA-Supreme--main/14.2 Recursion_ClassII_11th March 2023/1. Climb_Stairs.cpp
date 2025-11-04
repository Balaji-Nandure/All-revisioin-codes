/*
Approach Used in This Code:
---------------------------
- The problem is to count the number of distinct ways to climb to the top of a staircase with 'n' steps, where at each step you can climb either 1 or 2 stairs.
- This is a classic recursion problem and is mathematically equivalent to finding the (n+1)th Fibonacci number.
- The recursive relation is: ways(n) = ways(n-1) + ways(n-2)
    - ways(n-1): Take a single step from (n-1)th stair.
    - ways(n-2): Take a double step from (n-2)th stair.
- Base cases:
    - If n == 0: 1 way (stay at the ground).
    - If n == 1: 1 way (single step).

// ----------------------
// Better/Alternative Approaches (with code):
// ----------------------

// 1. Memoization (Top-Down DP): O(n) time, O(n) space
/*
#include <vector>
int climbStairsMemo(int n, std::vector<int>& dp) {
    if(n == 0 || n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = climbStairsMemo(n-1, dp) + climbStairsMemo(n-2, dp);
}
int main() {
    int n = 5;
    std::vector<int> dp(n+1, -1);
    std::cout << "Total ways (Memoization): " << climbStairsMemo(n, dp) << std::endl;
}
*/

// 2. Tabulation (Bottom-Up DP): O(n) time, O(n) space
/*
#include <vector>
int climbStairsTab(int n) {
    std::vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i=2; i<=n; ++i)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}
int main() {
    int n = 5;
    std::cout << "Total ways (Tabulation): " << climbStairsTab(n) << std::endl;
}
*/

// 3. Space Optimized Iterative Approach: O(n) time, O(1) space
/*
int climbStairsOpt(int n) {
    if(n == 0 || n == 1) return 1;
    int prev2 = 1, prev1 = 1, curr;
    for(int i=2; i<=n; ++i) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main() {
    int n = 5;
    std::cout << "Total ways (Space Optimized): " << climbStairsOpt(n) << std::endl;
}
*/

// 4. Matrix Exponentiation: O(log n) time, O(1) space
// (Omitted for brevity, but can be implemented for very large n)

// 5. Direct Formula (Binet's Formula): Not recommended for large n due to floating point errors

// ----------------------
// Main Recursive Approach (with detailed comments):
// ----------------------

#include<iostream>
using namespace std;

// Recursive function to calculate number of ways to climb n stairs
int climbStairs(int n){
    // Base Case: If n is 0 or 1, there is only 1 way to reach that stair
    // - n == 0: Stay at the ground (1 way)
    // - n == 1: Take a single step (1 way)
    if(n == 0 || n == 1){
        return 1;
    }
    // Recursive Case:
    // - Number of ways to reach nth stair is sum of:
    //   a) ways to reach (n-1)th stair (then take 1 step)
    //   b) ways to reach (n-2)th stair (then take 2 steps)
    int ans = climbStairs(n-1) + climbStairs(n-2);
    return ans;
}

int main(){
    int n = 5; // Number of stairs to climb (change this value to test for different n)
    // Calculate the number of ways to reach the nth stair using the recursive function
    int ways = climbStairs(n);
    // Output the result
    cout << "Total ways to reach the " << n << "th stair is " << ways << endl;
    return 0; // Indicate successful program termination
}

/*
Dry Run (n = 4):
-----------------
climbStairs(4)
    = climbStairs(3) + climbStairs(2)
        = [climbStairs(2) + climbStairs(1)] + [climbStairs(1) + climbStairs(0)]
            = [[climbStairs(1) + climbStairs(0)] + 1] + [1 + 1]
                = [[1 + 1] + 1] + 2
                = [2 + 1] + 2
                = 3 + 2
                = 5

So, there are 5 ways to reach the 4th stair.

Summary:
--------
- The function recursively computes the number of ways to climb stairs.
- For large n, use DP or iterative approach for efficiency.
- For n = 5, output is: 8

Time Complexity (Recursive): O(2^n) (Exponential, not recommended for large n)
Space Complexity (Recursive): O(n) (due to recursion stack)
*/