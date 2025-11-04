
/*
================================================================================
1) More space optimization possible in Longest Common Subsequence (LCS)?
================================================================================

Approach:
----------
- The classic LCS DP solution uses a 2D DP table of size (n+1)x(m+1).
- Space optimization: Since each row only depends on the previous row, we can use two 1D arrays.
- Further optimization: We can use only one 1D array and update it from right to left to avoid overwriting needed values.

Code with comments:
-------------------
int lcs(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<int> dp(m+1, 0); // Only one row needed for space optimization

    for(int i = n-1; i >= 0; --i) {
        int prev = 0; // To store dp[j+1] from previous iteration
        for(int j = m-1; j >= 0; --j) {
            int temp = dp[j]; // Save current dp[j] before overwriting
            if(text1[i] == text2[j])
                dp[j] = 1 + prev; // If chars match, add 1 to result from next indices
            else
                dp[j] = max(dp[j], dp[j+1]); // Else, take max of skipping one char from either string
            prev = temp; // Update prev for next iteration
        }
    }
    return dp[0]; // Final answer
}

Alternative approaches:
-----------------------
- Recursive with memoization (top-down DP): Easy to implement but uses O(n*m) space for memo table.
- Tabulation (bottom-up DP): Standard, but uses O(n*m) space.
- Space optimized (as above): O(m) space.

================================================================================
2) Dry run code of Longest Palindromic Subsequence (LPS)
================================================================================

Approach:
----------
- LPS of a string is the LCS of the string and its reverse.
- Use DP to compute LCS between s and reverse(s).

Code with comments:
-------------------
int longestPalindromeSubseq(string s) {
    string t = s;
    reverse(t.begin(), t.end()); // Reverse the string
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); // DP table

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1]; // If chars match, add 1 to result from previous indices
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // Else, take max of skipping one char from either string
        }
    }
    return dp[n][n]; // Final answer
}

/*
Dry run for s = "bbbab":
t = "babbb"
DP Table (partial):
    b b b a b
b [1 1 1 1 1]
b [1 2 2 2 2]
b [1 2 3 3 3]
a [1 2 3 4 4]
b [1 2 3 4 4]
Final answer: 4 ("bbbb")
*/

================================================================================
3) Repeat base case modification in space optimization code for edit distance code.
================================================================================

Approach:
----------
- Edit Distance classic DP uses a 2D table.
- Space optimization: Use two 1D arrays (current and previous).
- Base cases: If one string is empty, the answer is the length of the other string.

Code with comments:
-------------------
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);

    // Base case: If word1 is empty, need to insert all of word2's chars
    for(int j=0; j<=m; ++j) prev[j] = j;

    for(int i=1; i<=n; ++i) {
        curr[0] = i; // Base case: If word2 is empty, need to delete all of word1's chars
        for(int j=1; j<=m; ++j) {
            if(word1[i-1] == word2[j-1])
                curr[j] = prev[j-1]; // If chars match, no operation needed
            else
                curr[j] = 1 + min({prev[j-1], prev[j], curr[j-1]}); // Min of replace, delete, insert
        }
        prev = curr; // Move current row to previous for next iteration
    }
    return prev[m];
}

/*
Dry run for word1 = "horse", word2 = "ros":
Base cases:
prev = [0 1 2 3]
After i=1 ('h'):
curr = [1 1 2 3]
After i=2 ('o'):
curr = [2 2 1 2]
...
Final answer: 3
*/

================================================================================
Summary:
- Used space optimized DP for LCS and Edit Distance.
- Explained logic and base cases in comments.
- Provided dry runs for LPS and Edit Distance.
- For further optimization, always check if you can reduce DP dimensions by analyzing dependencies.
*/
