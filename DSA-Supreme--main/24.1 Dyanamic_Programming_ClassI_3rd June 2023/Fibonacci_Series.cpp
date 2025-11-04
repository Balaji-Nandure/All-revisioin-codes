/*
Approach Used:
---------------
This code demonstrates four different approaches to solve the Fibonacci number problem:

1. Pure Recursion (recSolve): 
   - Simple but highly inefficient (exponential time complexity O(2^n)), as it recalculates subproblems multiple times.

2. Top-Down Dynamic Programming (Memoization) (topDownSolve): 
   - Uses recursion + memoization (stores results in a dp array to avoid recomputation).
   - Time Complexity: O(n), Space Complexity: O(n) (for recursion stack and dp array).

3. Bottom-Up Dynamic Programming (Tabulation) (BottomUpSolve): 
   - Iteratively builds up the solution from the base cases.
   - Time Complexity: O(n), Space Complexity: O(n) (for dp array).

4. Space Optimized Iterative Approach (spaceOptSolve): 
   - Only keeps track of the last two computed values.
   - Time Complexity: O(n), Space Complexity: O(1).

Better Alternatives:
--------------------
- For very large n, use Matrix Exponentiation (O(log n) time, O(1) space).
- For direct computation, use Binet's Formula (not recommended due to floating point inaccuracies for large n).

Matrix Exponentiation Example (O(log n)):
-----------------------------------------
/*
long long fibMatrixExpo(int n) {
    if (n == 0) return 0;
    vector<vector<long long>> F = {{1,1},{1,0}};
    auto multiply = [](vector<vector<long long>>& a, vector<vector<long long>>& b) {
        vector<vector<long long>> c(2, vector<long long>(2));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j];
        a = c;
    };
    auto power = [&](vector<vector<long long>>& F, int n) {
        vector<vector<long long>> res = {{1,0},{0,1}};
        while(n) {
            if(n&1) multiply(res, F);
            multiply(F, F);
            n >>= 1;
        }
        F = res;
    };
    power(F, n-1);
    return F[0][0];
}
*/

#include <vector>
using namespace std;

class Solution {
public:
    // 1. Pure Recursion (Inefficient)
    int recSolve(int n){
        // Base case: fib(0) = 0, fib(1) = 1
        if(n == 0 || n == 1){
            return n;
        }
        // Recursive call: fib(n) = fib(n-1) + fib(n-2)
        return recSolve(n-1) + recSolve(n-2);
    }

    // 2. Top-Down DP (Memoization)
    int topDownSolve(int n, vector<int>& dp){
        // Base case
        if(n == 0 || n == 1){
            return n;
        }
        // If already computed, return stored value
        if(dp[n] != -1){
            return dp[n];
        }
        // Store the result in dp[n] to avoid recomputation
        dp[n] = topDownSolve(n-1, dp) + topDownSolve(n-2, dp);
        return dp[n];
    }

    // 3. Bottom-Up DP (Tabulation)
    int BottomUpSolve(int n){
        // Handle base case
        if(n == 0) return 0;
        // Create dp array to store results up to n
        vector<int> dp(n+1, 0);
        dp[0] = 0; // fib(0)
        dp[1] = 1; // fib(1)
        // Build the dp array iteratively
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2]; // fib(i) = fib(i-1) + fib(i-2)
        }
        return dp[n];
    }

    // 4. Space Optimized Iterative Approach
    int spaceOptSolve(int n){
        // Handle base cases
        if(n == 0) return 0;
        if(n == 1) return 1;
        int prev2 = 0; // fib(0)
        int prev1 = 1; // fib(1)
        int curr = 0;
        // Only keep last two values to save space
        for(int i = 2; i <= n; i++){
            curr = prev1 + prev2; // fib(i) = fib(i-1) + fib(i-2)
            prev2 = prev1;        // Update prev2 to previous prev1
            prev1 = curr;         // Update prev1 to current
        }
        return curr;
    }

    // Main function to compute nth Fibonacci number
    int fib(int n) {
        // Uncomment any approach to use it

        // 1. Pure Recursion (Not recommended for large n)
        // return recSolve(n);

        // 2. Top-Down DP (Memoization)
        // vector<int> dp(n+1, -1); // Initialize dp array with -1
        // return topDownSolve(n, dp);

        // 3. Bottom-Up DP (Tabulation)
        // return BottomUpSolve(n);

        // 4. Space Optimized Iterative Approach (Best for most cases)
        return spaceOptSolve(n);

        // 5. Matrix Exponentiation (For very large n, see code above)
        // return (int)fibMatrixExpo(n);
    }
};

/*
Dry Run Example for n = 5 (using spaceOptSolve):

Initial: prev2 = 0, prev1 = 1

i=2: curr = 1 (1+0), prev2=1, prev1=1
i=3: curr = 2 (1+1), prev2=1, prev1=2
i=4: curr = 3 (2+1), prev2=2, prev1=3
i=5: curr = 5 (3+2), prev2=3, prev1=5

Return curr = 5

Fibonacci Sequence: 0, 1, 1, 2, 3, 5
fib(5) = 5
*/