/*
    Approach Used: Sliding Window with Hash Maps (Optimal O(n) Solution)
    --------------------------------------------------------------------
    This code solves the "Minimum Window Substring" problem using a variable-size sliding window and two hash maps to track character frequencies.
    The main idea is to expand the window to the right until all characters of the pattern are included, then try to shrink the window from the left to find the minimum length substring that contains all characters of the pattern (including duplicates).

    Key Logic:
    ----------
    - Use two hash maps:
        1. patMap: Stores the frequency of each character in the pattern string 'p'.
        2. windowMap: Stores the frequency of each character in the current window of string 's'.
    - Expand the window by moving the right pointer and updating windowMap.
    - When the window contains all characters of the pattern (with required frequencies), try to shrink the window from the left to minimize its size.
    - Update the answer whenever a smaller valid window is found.

    Why this works:
    ---------------
    - Each character is processed at most twice (once when expanding, once when contracting), so the time complexity is O(n).
    - Hash maps allow O(1) frequency checks and updates.

    Better Alternatives & Detailed Approaches:
    ------------------------------------------
    1. **Brute Force (O(n^3)):**
       - For every possible substring, check if it contains all characters of the pattern.
       - Not efficient for large inputs.

       // Code:
       /*
       string minWindow(string s, string t) {
           int minLen = INT_MAX, start = -1;
           for(int i = 0; i < s.size(); i++) {
               for(int j = i; j < s.size(); j++) {
                   string sub = s.substr(i, j-i+1);
                   unordered_map<char, int> mp;
                   for(char c : sub) mp[c]++;
                   bool valid = true;
                   for(char c : t) {
                       if(--mp[c] < 0) { valid = false; break; }
                   }
                   if(valid && (j-i+1) < minLen) {
                       minLen = j-i+1;
                       start = i;
                   }
               }
           }
           return (start == -1) ? "" : s.substr(start, minLen);
       }
       */

    2. **Optimal Sliding Window (Current Approach, O(n)):**
       - As implemented below.

    Dry Run Example:
    ----------------
    s = "ADOBECODEBANC", p = "ABC"
    patMap: {A:1, B:1, C:1}
    Window expands to include A, D, O, B, E, C (at index 5), now window is "ADOBEC"
    Try to shrink from left: remove A (window "DOBEC"), not valid anymore, so stop.
    Continue expanding and shrinking, finally get "BANC" as the minimum window.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string p) {
        int n = s.length();
        int m = p.length();

        // Edge case: if pattern is longer than string, no solution
        if(n < m) return "";

        // patMap: stores required frequency of each character in pattern
        unordered_map<char, int> patMap;
        for(char ch : p) {
            patMap[ch]++;
        }

        // windowMap: stores frequency of characters in current window
        unordered_map<char, int> windowMap;

        int required = patMap.size(); // number of unique chars in pattern to be matched
        int formed = 0; // number of unique chars in current window with required freq

        int left = 0, right = 0; // window pointers
        int minLen = INT_MAX; // minimum window length found so far
        int minStart = 0;     // starting index of minimum window

        // This map keeps track of how many times each char in pattern is matched in window
        // windowMap[ch] == patMap[ch] means this char is satisfied

        while(right < n) {
            char ch = s[right];
            windowMap[ch]++; // include current character in window

            // If current char is in pattern and its freq matches, increment 'formed'
            if(patMap.count(ch) && windowMap[ch] == patMap[ch]) {
                formed++;
            }

            // Try to contract the window till it ceases to be 'desirable'
            while(left <= right && formed == required) {
                // Update answer if this window is smaller
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                // Remove the leftmost character from window
                char leftChar = s[left];
                windowMap[leftChar]--;

                // If leftChar is in pattern and its freq falls below required, decrement 'formed'
                if(patMap.count(leftChar) && windowMap[leftChar] < patMap[leftChar]) {
                    formed--;
                }
                left++; // shrink window from left
            }
            right++; // expand window to right
        }

        // If no valid window found, return empty string
        if(minLen == INT_MAX) return "";

        // Return the minimum window substring
        return s.substr(minStart, minLen);
    }
};

/*
Dry Run:
--------
Input: s = "ADOBECODEBANC", p = "ABC"
patMap: {A:1, B:1, C:1}
windowMap: {}
left = 0, right = 0

Expand right:
right=0, s[0]=A, windowMap={A:1}, formed=1
right=1, s[1]=D, windowMap={A:1,D:1}, formed=1
right=2, s[2]=O, windowMap={A:1,D:1,O:1}, formed=1
right=3, s[3]=B, windowMap={A:1,D:1,O:1,B:1}, formed=2
right=4, s[4]=E, windowMap={A:1,D:1,O:1,B:1,E:1}, formed=2
right=5, s[5]=C, windowMap={A:1,D:1,O:1,B:1,E:1,C:1}, formed=3

Now formed==required (3), try to shrink from left:
left=0, window="ADOBEC", minLen=6, minStart=0
Remove A, windowMap[A]=0, formed=2, left=1

Continue expanding right and shrinking left as possible.
Eventually, min window found is "BANC" (start=9, len=4).

Output: "BANC"
*/