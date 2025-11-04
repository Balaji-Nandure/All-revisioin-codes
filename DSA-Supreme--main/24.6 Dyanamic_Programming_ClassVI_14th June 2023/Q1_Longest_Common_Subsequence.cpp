// https://leetcode.com/problems/longest-common-subsequence/description/

/*
Approach Used:
---------------
This code solves the Longest Common Subsequence (LCS) problem using four approaches:
1. Pure Recursion (Exponential Time, TLE for large inputs)
2. Top-Down Dynamic Programming (Memoization, O(N*M) Time, O(N*M) Space)
3. Bottom-Up Dynamic Programming (Tabulation, O(N*M) Time, O(N*M) Space)
4. Space Optimized DP (O(N*M) Time, O(M) Space)

LCS Problem: Given two strings, find the length of their longest subsequence that appears in both strings (not necessarily contiguous).

Better Alternatives:
--------------------
- For reconstructing the LCS string, you can backtrack from the DP table (see code in comments below).
- For very large strings, use the space optimized approach as implemented.
- For small strings, memoization is easy to implement and debug.

Detailed code for all approaches is provided below, with comments explaining each important line.
A dry run is provided at the end.
*/

class Solution {
public:
    // 1. Pure Recursive Approach (Exponential Time)
    int solveRec(const string& a, const string& b, int i, int j) {
        // Base Case: If either string is fully traversed, no more common subsequence possible
        if (i == a.length() || j == b.length())
            return 0;
        // If current characters match, include this character and move both pointers
        if (a[i] == b[j]) {
            return 1 + solveRec(a, b, i + 1, j + 1);
        }
        // If not matching, try skipping one character from either string and take the max
        else {
            return max(solveRec(a, b, i, j + 1), solveRec(a, b, i + 1, j));
        }
    }

    // 2. Top-Down DP (Memoization) Approach
    int solveTopDown(const string& a, const string& b, int i, int j, vector<vector<int>>& dp) {
        // Base Case: If either string is fully traversed
        if (i == a.length() || j == b.length())
            return 0;
        // If already computed, return stored result
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        // If characters match, include and move both pointers
        if (a[i] == b[j]) {
            ans = 1 + solveTopDown(a, b, i + 1, j + 1, dp);
        }
        // Else, skip one character from either string and take the max
        else {
            ans = max(solveTopDown(a, b, i, j + 1, dp), solveTopDown(a, b, i + 1, j, dp));
        }
        // Store result in dp table
        dp[i][j] = ans;
        return ans;
    }

    // 3. Bottom-Up DP (Tabulation) Approach
    int solveTab(const string& a, const string& b) {
        int n = a.length();
        int m = b.length();
        // dp[i][j] = LCS of a[i:] and b[j:]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // +1 for base case (empty string)
        // Fill dp table from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    // If match, include and move diagonally
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    // Else, take max by skipping one character from either string
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[0][0]; // LCS of entire strings
    }

    // 4. Space Optimized DP (Only two rows needed at a time)
    int spaceOpt(const string& a, const string& b) {
        int n = a.length();
        int m = b.length();
        // Only need current and next row for DP
        vector<int> curr(m + 1, 0); // Current row
        vector<int> next(m + 1, 0); // Next row (i+1)
        // Iterate from bottom to top
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    // If match, include and move diagonally
                    curr[j] = 1 + next[j + 1];
                } else {
                    // Else, take max by skipping one character from either string
                    curr[j] = max(curr[j + 1], next[j]);
                }
            }
            // Move current row to next for next iteration
            next = curr;
        }
        return next[0]; // LCS of entire strings
    }

    // Main function to call the desired approach
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        // 1. Recursive (Uncomment to use, not recommended for large inputs)
        // return solveRec(text1, text2, 0, 0);

        // 2. Top-Down DP (Memoization)
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solveTopDown(text1, text2, 0, 0, dp);

        // 3. Bottom-Up DP (Tabulation)
        // return solveTab(text1, text2);

        // 4. Space Optimized DP (Best for large inputs)
        return spaceOpt(text1, text2);
    }

    /*
    // (Optional) To reconstruct the LCS string itself, not just its length:
    string getLCS(string a, string b) {
        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (a[i] == b[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        // Reconstruct LCS string
        string lcs = "";
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] == b[j]) {
                lcs += a[i];
                i++; j++;
            } else if (dp[i+1][j] >= dp[i][j+1]) {
                i++;
            } else {
                j++;
            }
        }
        return lcs;
    }
    */
};

/*
Dry Run Example:
----------------
text1 = "abcde", text2 = "ace"

DP Table (Bottom-Up):
      a  c  e
   0 0  0  0  0
a 0 3  2  1  0
b 0 2  2  1  0
c 0 2  2  1  0
d 0 1  1  1  0
e 0 1  1  1  0

LCS length = 3 ("ace")

Space Optimized Dry Run:
- Only two rows are maintained at a time, so memory usage is O(M) instead of O(N*M).

Summary of Approaches:
----------------------
- Recursion: Simple, but exponential time.
- Memoization: O(N*M) time, O(N*M) space.
- Tabulation: O(N*M) time, O(N*M) space, easy to reconstruct LCS.
- Space Optimized: O(N*M) time, O(M) space, best for large inputs.

*/