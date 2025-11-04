/*
    Problem: Given a rod of length n and three possible segment lengths x, y, z,
    cut the rod into maximum number of segments such that each segment is of length x, y, or z.

    Approach Used in Code:
    ----------------------
    - This is a classic recursion problem similar to the "minimum coin change" problem.
    - At each step, we try to cut the rod by x, y, or z and recursively solve for the remaining length.
    - The base case is when n == 0 (no length left, so 0 cuts needed) or n < 0 (invalid, so return negative infinity).
    - The answer is the maximum of the three possible choices at each step.

    Better Alternatives:
    --------------------
    1. **Memoization (Top-Down DP):**
        - Store results for each n to avoid recomputation.
        - Reduces time complexity from exponential to O(n).
    2. **Tabulation (Bottom-Up DP):**
        - Iteratively build up the answer from 0 to n.
        - Most efficient for this problem.

    Both alternatives are shown in comments below the main code.

    Dry Run for n=7, x=5, y=2, z=2:
    --------------------------------
    solve(7,5,2,2)
      -> max(
            solve(2,5,2,2)+1,   // 7-5=2
            solve(5,5,2,2)+1,   // 7-2=5
            solve(5,5,2,2)+1    // 7-2=5
         )
    solve(2,5,2,2)
      -> max(
            solve(-3,5,2,2)+1,  // -3 < 0, returns INT_MIN
            solve(0,5,2,2)+1,   // 2-2=0, returns 1
            solve(0,5,2,2)+1    // 2-2=0, returns 1
         )
      -> max(INT_MIN,1,1) = 1
    solve(5,5,2,2)
      -> max(
            solve(0,5,2,2)+1,   // 5-5=0, returns 1
            solve(3,5,2,2)+1,   // 5-2=3
            solve(3,5,2,2)+1    // 5-2=3
         )
    solve(3,5,2,2)
      -> max(
            solve(-2,5,2,2)+1,  // -2 < 0, returns INT_MIN
            solve(1,5,2,2)+1,   // 3-2=1
            solve(1,5,2,2)+1    // 3-2=1
         )
    solve(1,5,2,2)
      -> max(
            solve(-4,5,2,2)+1,  // -4 < 0, returns INT_MIN
            solve(-1,5,2,2)+1,  // -1 < 0, returns INT_MIN
            solve(-1,5,2,2)+1   // -1 < 0, returns INT_MIN
         )
      -> max(INT_MIN,INT_MIN,INT_MIN) = INT_MIN
    So, solve(3,5,2,2) = max(INT_MIN, INT_MIN, INT_MIN) = INT_MIN
    So, solve(5,5,2,2) = max(1, INT_MIN, INT_MIN) = 1
    So, solve(7,5,2,2) = max(1+1, 1+1, 1+1) = 2

    Final answer: 2

*/

#include<iostream>
#include<climits> // For INT_MIN
using namespace std;

// Recursive function to find the maximum number of segments
int solve(int n, int x, int y, int z) {
    // Base Case: If rod length is 0, no more cuts needed
    if(n == 0)
        return 0;
    // If rod length becomes negative, this is not a valid way
    if(n < 0)
        return INT_MIN;

    // Try cutting by x, y, and z, and take the maximum
    int a = solve(n - x, x, y, z) + 1; // Cut by x and add 1 to count this cut
    int b = solve(n - y, x, y, z) + 1; // Cut by y and add 1 to count this cut
    int c = solve(n - z, x, y, z) + 1; // Cut by z and add 1 to count this cut

    // Take the maximum of all three options
    int ans = max(a, max(b, c));
    return ans;
}

int main() {
    int n = 7; // Length of the rod
    int x = 5; // First possible segment length
    int y = 2; // Second possible segment length
    int z = 2; // Third possible segment length

    // Call the recursive function to get the answer
    int ans = solve(n, x, y, z);

    // If answer is negative, it means it's not possible to cut the rod
    if(ans < 0)
        ans = 0;

    cout << "Answer is " << ans;
    return 0;
}

/*
-------------------------------
Better Approach 1: Memoization
-------------------------------
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int solveMemo(int n, int x, int y, int z, vector<int>& dp) {
    if(n == 0) return 0;
    if(n < 0) return INT_MIN;
    if(dp[n] != -1) return dp[n];

    int a = solveMemo(n - x, x, y, z, dp) + 1;
    int b = solveMemo(n - y, x, y, z, dp) + 1;
    int c = solveMemo(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int main() {
    int n = 7, x = 5, y = 2, z = 2;
    vector<int> dp(n+1, -1);
    int ans = solveMemo(n, x, y, z, dp);
    if(ans < 0) ans = 0;
    cout << "Answer is " << ans;
    return 0;
}

-------------------------------
Better Approach 2: Tabulation
-------------------------------
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int solveTab(int n, int x, int y, int z) {
    vector<int> dp(n+1, INT_MIN);
    dp[0] = 0; // 0 length rod needs 0 cuts

    for(int i = 1; i <= n; ++i) {
        if(i - x >= 0 && dp[i-x] != INT_MIN)
            dp[i] = max(dp[i], dp[i-x] + 1);
        if(i - y >= 0 && dp[i-y] != INT_MIN)
            dp[i] = max(dp[i], dp[i-y] + 1);
        if(i - z >= 0 && dp[i-z] != INT_MIN)
            dp[i] = max(dp[i], dp[i-z] + 1);
    }
    return dp[n] < 0 ? 0 : dp[n];
}

int main() {
    int n = 7, x = 5, y = 2, z = 2;
    cout << "Answer is " << solveTab(n, x, y, z);
    return 0;
}
*/