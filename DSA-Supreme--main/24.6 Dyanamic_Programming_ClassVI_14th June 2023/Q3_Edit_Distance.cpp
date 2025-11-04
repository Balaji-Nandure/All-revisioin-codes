// https://leetcode.com/problems/edit-distance/description/

/*
    Approach Used: Edit Distance (Levenshtein Distance) using Dynamic Programming

    Problem: Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
    Allowed operations: Insert a character, Delete a character, Replace a character.

    Approaches:
    1. Pure Recursion (Exponential Time, not recommended for large inputs)
    2. Top-Down DP (Memoization) - O(N*M) time, O(N*M) space
    3. Bottom-Up DP (Tabulation) - O(N*M) time, O(N*M) space
    4. Space Optimized DP - O(N*M) time, O(M) space

    Below, all approaches are implemented with detailed comments.
    At the end, a dry run is provided for better understanding.
*/

class Solution {
public:
    // 1. Pure Recursive Approach (Exponential Time)
    int solveRec(string &a, string &b, int i, int j) {
        // Base case: If all characters of a are processed, insert remaining of b
        if (i == a.length()) return b.length() - j;
        // Base case: If all characters of b are processed, delete remaining of a
        if (j == b.length()) return a.length() - i;

        int ans = 0;
        if (a[i] == b[j]) {
            // If characters match, move to next character in both strings
            ans = solveRec(a, b, i + 1, j + 1);
        } else {
            // If characters don't match, try all three operations:
            // 1. Insert: Insert b[j] into a, so move j forward
            int insertOp = 1 + solveRec(a, b, i, j + 1);
            // 2. Delete: Delete a[i], so move i forward
            int deleteOp = 1 + solveRec(a, b, i + 1, j);
            // 3. Replace: Replace a[i] with b[j], move both i and j forward
            int replaceOp = 1 + solveRec(a, b, i + 1, j + 1);
            // Take minimum of all three
            ans = min(insertOp, min(deleteOp, replaceOp));
        }
        return ans;
    }

    // 2. Top-Down DP (Memoization)
    int solveTopDown(string &a, string &b, int i, int j, vector<vector<int>>& dp) {
        // Base cases as above
        if (i == a.length()) return b.length() - j;
        if (j == b.length()) return a.length() - i;

        // If already computed, return stored value
        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if (a[i] == b[j]) {
            // Characters match, no operation needed
            ans = solveTopDown(a, b, i + 1, j + 1, dp);
        } else {
            // Try all three operations
            int insertOp = 1 + solveTopDown(a, b, i, j + 1, dp);
            int deleteOp = 1 + solveTopDown(a, b, i + 1, j, dp);
            int replaceOp = 1 + solveTopDown(a, b, i + 1, j + 1, dp);
            ans = min(insertOp, min(deleteOp, replaceOp));
        }
        // Store result in dp array
        dp[i][j] = ans;
        return ans;
    }

    // 3. Bottom-Up DP (Tabulation)
    int solveTab(string &a, string &b) {
        int n = a.length();
        int m = b.length();
        // dp[i][j] = min operations to convert a[i:] to b[j:]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill base cases: If a is empty, insert all of b; if b is empty, delete all of a
        for (int j = 0; j <= m; j++) dp[n][j] = m - j;
        for (int i = 0; i <= n; i++) dp[i][m] = n - i;

        // Fill dp table from bottom right to top left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    // Characters match, no operation needed
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    // Try all three operations
                    int insertOp = 1 + dp[i][j + 1];
                    int deleteOp = 1 + dp[i + 1][j];
                    int replaceOp = 1 + dp[i + 1][j + 1];
                    dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
                }
            }
        }
        return dp[0][0];
    }

    // 4. Space Optimized DP (Only two rows needed at a time)
    int spaceOpt(string &a, string &b) {
        int n = a.length();
        int m = b.length();
        vector<int> curr(m + 1, 0); // Current row
        vector<int> next(m + 1, 0); // Next row (i+1)

        // Base case: If a is empty, insert all of b
        for (int j = 0; j <= m; j++) next[j] = m - j;

        // Fill from bottom to top
        for (int i = n - 1; i >= 0; i--) {
            curr[m] = n - i; // If b is empty, delete all of a[i:]
            for (int j = m - 1; j >= 0; j--) {
                if (a[i] == b[j]) {
                    curr[j] = next[j + 1]; // Characters match
                } else {
                    int insertOp = 1 + curr[j + 1];    // Insert b[j]
                    int deleteOp = 1 + next[j];        // Delete a[i]
                    int replaceOp = 1 + next[j + 1];   // Replace a[i] with b[j]
                    curr[j] = min(insertOp, min(deleteOp, replaceOp));
                }
            }
            next = curr; // Move current row to next for next iteration
        }
        return next[0];
    }

    // Main function to call the desired approach
    int minDistance(string word1, string word2) {
        int i = 0, j = 0;

        // Uncomment any one approach to use:

        // 1. Pure Recursion (Not recommended for large inputs)
        // return solveRec(word1, word2, i, j);

        // 2. Top-Down DP (Memoization)
        // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        // return solveTopDown(word1, word2, i, j, dp);

        // 3. Bottom-Up DP (Tabulation)
        // return solveTab(word1, word2);

        // 4. Space Optimized DP (Best for large inputs)
        return spaceOpt(word1, word2);
    }
};

/*
    Alternative Approaches (with code):

    // 1. Using only 1D DP (if you want to further optimize, but not needed for this problem)
    // Not shown here as spaceOpt is already O(M) space.

    // 2. Using std::min({a, b, c}) for clarity:
    // #include <algorithm>
    // int ans = std::min({insertOp, deleteOp, replaceOp});

    // 3. If you want to reconstruct the sequence of operations, you can backtrack from the dp table.

    Dry Run Example:
    ----------------
    word1 = "horse", word2 = "ros"

    DP Table (Bottom-Up):
        r o s
      0 1 2 3
    h 3 2 3 4
    o 2 1 1 2
    r 1 1 2 3
    s 0 1 1 2
    e 1 1 2 3

    Final answer: 3
    Explanation:
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose  (remove 'r')
    rose  -> ros   (remove 'e')

    So, minimum 3 operations required.

    Time Complexity:
    - All DP approaches: O(N*M)
    - Space Complexity: O(N*M) for full DP, O(M) for space optimized

    For interview: Always mention all approaches, and use space optimized DP for best performance.
*/
