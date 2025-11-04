/*
Approach:
---------
We are to find the index of the first occurrence of string s2 (needle) in string s1 (haystack).
This is a classic substring search problem.

- If s2 is empty, by convention, return 0 (empty string is always found at the start).
- If s2 is longer than s1, it cannot be a substring, so return -1.
- Otherwise, for each possible starting index i in s1 (from 0 to n-m), check if the substring of s1 starting at i matches s2.
    - For each i, compare s1[i + j] with s2[j] for all j from 0 to m-1.
    - If all characters match, return i (the starting index).
    - If any character does not match, break and try the next i.
- If no match is found after checking all possible positions, return -1.

Time Complexity: O((n-m+1) * m) in the worst case, where n = s1.length(), m = s2.length().

Dry Run:
--------
Example 1:
s1 = "hello", s2 = "ll"
n = 5, m = 2

i = 0: s1[0] = 'h', s2[0] = 'l' (not equal) -> move to next i
i = 1: s1[1] = 'e', s2[0] = 'l' (not equal) -> move to next i
i = 2: s1[2] = 'l', s2[0] = 'l' (equal)
        s1[3] = 'l', s2[1] = 'l' (equal)
      All matched, return 2

Example 2:
s1 = "aaaaa", s2 = "bba"
n = 5, m = 3

i = 0: s1[0] = 'a', s2[0] = 'b' (not equal)
i = 1: s1[1] = 'a', s2[0] = 'b' (not equal)
i = 2: s1[2] = 'a', s2[0] = 'b' (not equal)
No match found, return -1

*/

class Solution {
public:
    int strStr(string s1, string s2) {
        // Check if the needle string is empty
        // By convention, return 0 if s2 is empty (empty string always found at start)
        if(s2.empty()) return 0; 

        // Get the length of the haystack string
        // Store the length for later use in loop bounds
        int n = s1.length();

        // Get the length of the needle string
        // Store the length for substring comparison
        int m = s2.length();

        // If the needle is longer than the haystack, it can't be a substring
        // Return -1 to indicate no possible match
        if(m > n) return -1; 

        // Loop through all possible starting indices in s1 where s2 could fit
        // The loop goes from 0 to n-m (inclusive) to avoid overflow
        for(int i = 0; i <= n - m; i++) {
            int j = 0; // Initialize a pointer for s2 comparison
            // Compare each character of s2 with the corresponding character in s1
            // Continue as long as characters match and j is within bounds
            for(; j < m; j++) {
                // If a mismatch is found, break out of the inner loop
                // This means s2 does not match s1 starting at index i
                if(s1[i + j] != s2[j])
                    break;
            }
            // If all characters matched (j reached m), we found the substring
            // Return the starting index i where s2 is found in s1
            if(j == m)
                return i;
        }
        // If no match is found after checking all positions, return -1
        // Indicates that s2 does not occur in s1
        return -1;
    }
};
