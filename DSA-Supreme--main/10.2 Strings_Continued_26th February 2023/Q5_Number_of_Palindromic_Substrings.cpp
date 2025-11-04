#include<iostream>
using namespace std;

/*
Approach Used:
---------------
We use the "Expand Around Center" approach to count all palindromic substrings in a given string.
For each character (and each pair of consecutive characters), we expand outwards as long as the substring remains a palindrome.
This covers both odd and even length palindromes.

Time Complexity: O(n^2), where n is the length of the string.
Space Complexity: O(1), as we use only a few variables.
*/

// Helper function to count palindromic substrings centered at indices i and j
int expandAroundIndex(const string& s, int i, int j){
    int count = 0;
    // Expand as long as the characters at i and j are equal and within bounds
    while(i >= 0 && j < s.length() && s[i] == s[j]){
        count++;    // Found a palindrome
        i--;        // Move left pointer outward
        j++;        // Move right pointer outward
    }
    return count;   // Return number of palindromic substrings found for this center
}

// Main function to count all palindromic substrings in the string
int countPalindromicSubstrings(const string& s){
    int count = 0;              // To store total count of palindromic substrings
    int n = s.length();         // Length of the string
    for(int i = 0; i < n; i++){
        // Odd length palindromes (single character center)
        int oddAns = expandAroundIndex(s, i, i);
        count += oddAns;

        // Even length palindromes (consecutive character center)
        int evenAns = expandAroundIndex(s, i, i + 1);
        count += evenAns;
    }
    return count;
}

int main(){
    string s = "aaa";   // Input string
    int ans = countPalindromicSubstrings(s); // Get the count of palindromic substrings
    cout << ans;        // Output the result
    return 0;
}

/*
-------------------------------
Better Alternative Approaches:
-------------------------------

1. Dynamic Programming (DP) Approach:
   - Create a 2D DP table where dp[i][j] is true if substring s[i..j] is a palindrome.
   - Fill the table in increasing order of substring length.
   - Time Complexity: O(n^2), Space Complexity: O(n^2)
   - Code:

   // DP Approach
   int countPalindromicSubstringsDP(const string& s) {
       int n = s.length();
       vector<vector<bool>> dp(n, vector<bool>(n, false));
       int count = 0;
       for (int len = 1; len <= n; len++) {
           for (int i = 0; i <= n - len; i++) {
               int j = i + len - 1;
               if (s[i] == s[j]) {
                   if (len <= 2) dp[i][j] = true;
                   else dp[i][j] = dp[i+1][j-1];
               }
               if (dp[i][j]) count++;
           }
       }
       return count;
   }

2. Manacher's Algorithm:
   - Finds all palindromic substrings in O(n) time.
   - More complex to implement, but optimal for large strings.
   - Not shown here due to complexity, but worth exploring for interviews or large datasets.

-------------------------------
Dry Run (for s = "aaa"):
-------------------------------
All substrings:
"a" (0,0) -> palindrome
"a" (1,1) -> palindrome
"a" (2,2) -> palindrome
"aa" (0,1) -> palindrome
"aa" (1,2) -> palindrome
"aaa" (0,2) -> palindrome

Total palindromic substrings = 6

Expand Around Center steps:
i=0: odd (0,0): "a" (1), even (0,1): "aa" (1), expand to (−1,2): stop
i=1: odd (1,1): "a" (1), expand to (0,2): "aaa" (1), expand to (−1,3): stop; even (1,2): "aa" (1)
i=2: odd (2,2): "a" (1), even (2,3): out of bounds

Total: 1+1+2+1+1 = 6

Output: 6
*/