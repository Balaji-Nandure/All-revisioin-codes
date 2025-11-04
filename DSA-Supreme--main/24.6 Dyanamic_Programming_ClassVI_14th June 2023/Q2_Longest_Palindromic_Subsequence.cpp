// https://leetcode.com/problems/longest-palindromic-subsequence/description/

/*
Approach Used:
---------------
This code finds the length of the Longest Palindromic Subsequence (LPS) in a given string.
The key idea is that the LPS of a string is the same as the Longest Common Subsequence (LCS) between the string and its reverse.
We use a space-optimized dynamic programming approach to compute the LCS, reducing space from O(n^2) to O(n).

Better Alternatives:
--------------------
1. **Tabulation (Bottom-Up DP):**
   - Use a 2D DP table of size n x n.
   - dp[i][j] = length of LPS in substring s[i...j].
   - Time: O(n^2), Space: O(n^2).
   - See code in comments below.

2. **Memoization (Top-Down DP):**
   - Use recursion with memoization.
   - Time: O(n^2), Space: O(n^2).
   - See code in comments below.

3. **Space Optimized LCS (Current Approach):**
   - Use two 1D arrays to store only the current and next row.
   - Time: O(n^2), Space: O(n).

-----------------------------------
*/

class Solution {
public:
    // Space Optimized LCS function to find LPS
    int spaceOpt(string a, string b) {
        int n = a.length();
        // curr and next store the current and next row of DP table
        vector<int> curr(n + 1, 0); // Current row
        vector<int> next(n + 1, 0); // Next row (i+1)

        // Iterate from end to start for both strings
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int ans = 0;
                if (a[i] == b[j]) {
                    // If characters match, include it and move diagonally
                    ans = 1 + next[j + 1];
                } else {
                    // If not match, take max of skipping one char from either string
                    ans = max(curr[j + 1], next[j]);
                }
                curr[j] = ans; // Store result for this subproblem
            }
            next = curr; // Move to next row for next iteration
        }
        return next[0]; // The answer for the full string is at next[0]
    }

    int longestPalindromeSubseq(string s) {
        // Copy original string
        string first = s;
        // Reverse the string to get the second string for LCS
        reverse(s.begin(), s.end());
        string second = s;
        // Find LCS between original and reversed string
        int ans = spaceOpt(first, second);
        return ans;
    }
};

/*
-----------------------------------
Alternative 1: Tabulation (2D DP)
-----------------------------------
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n-1; i >= 0; i--) {
        dp[i][i] = 1; // Single char is palindrome
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j])
                dp[i][j] = 2 + dp[i+1][j-1];
            else
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

-----------------------------------
Alternative 2: Memoization (Top-Down DP)
-----------------------------------
int solve(string &s, int i, int j, vector<vector<int>>& dp) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == s[j])
        return dp[i][j] = 2 + solve(s, i+1, j-1, dp);
    else
        return dp[i][j] = max(solve(s, i+1, j, dp), solve(s, i, j-1, dp));
}
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solve(s, 0, n-1, dp);
}

-----------------------------------
Dry Run Example:
-----------------------------------
Input: s = "bbbab"
Reverse: "babb b"
LCS("bbbab", "babbb"):
- i=4, j=4: a[4]=b, b[4]=b => match, ans=1+next[5]=1
- i=3, j=3: a[3]=a, b[3]=b => not match, ans=max(curr[4], next[3])
...
Final answer: 4 ("bbbb" is the longest palindromic subsequence)
*/