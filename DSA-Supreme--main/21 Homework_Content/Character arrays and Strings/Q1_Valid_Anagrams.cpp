// https://leetcode.com/problems/valid-anagram/description/

/*
Approach Used in this Code:
---------------------------
We are using the "Counting Frequency" approach to check if two strings are anagrams.
- An anagram means both strings have the same characters with the same frequency.
- Since the problem states that the strings contain only lowercase English letters, we can use a fixed-size array of 26 to count the frequency of each character.

Detailed Steps:
1. If the lengths of the two strings are not equal, they cannot be anagrams.
2. Count the frequency of each character in the first string and increment the corresponding index in the count array.
3. For the second string, decrement the frequency for each character in the same count array.
4. If all values in the count array are zero at the end, the strings are anagrams; otherwise, they are not.

Better Alternatives:
--------------------
1. **Sorting Approach** (Simple, but less efficient for large strings):
   - Sort both strings and compare them.
   - Time Complexity: O(n log n)
   - Code:
     ```
     bool isAnagram(string s, string t) {
         if(s.length() != t.length()) return false;
         sort(s.begin(), s.end());
         sort(t.begin(), t.end());
         return s == t;
     }
     ```
2. **Hash Map Approach** (Handles Unicode and all characters):
   - Use unordered_map<char, int> to count frequencies.
   - Works for all character sets, not just lowercase.
   - Code:
     ```
     bool isAnagram(string s, string t) {
         if(s.length() != t.length()) return false;
         unordered_map<char, int> freq;
         for(char c : s) freq[c]++;
         for(char c : t) freq[c]--;
         for(auto &p : freq) if(p.second != 0) return false;
         return true;
     }
     ```

Optimized and Commented Code:
----------------------------
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are not equal, they can't be anagrams
        if(s.length() != t.length()) return false;

        // Array to store frequency of each character (for 'a' to 'z')
        int count[26] = {0};

        // Count frequency for each character in string s
        for(int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; // Increment count for character in s
        }

        // Subtract frequency for each character in string t
        for(int i = 0; i < t.length(); i++) {
            count[t[i] - 'a']--; // Decrement count for character in t
        }

        // If all counts are zero, then s and t are anagrams
        for(int i = 0; i < 26; i++) {
            if(count[i] != 0) { // If any count is not zero, not an anagram
                return false;
            }
        }
        return true; // All counts are zero, so s and t are anagrams
    }
};

/*
Dry Run Example:
----------------
s = "anagram"
t = "nagaram"

Step 1: Lengths are equal (7 == 7), so continue.

Step 2: Count frequencies for s:
    'a': 3, 'n': 1, 'g': 1, 'r': 1, 'm': 1

Step 3: Subtract frequencies for t:
    After processing 'n': 'n' count becomes 0
    After processing 'a': 'a' count becomes 2
    After processing 'g': 'g' count becomes 0
    After processing 'a': 'a' count becomes 1
    After processing 'r': 'r' count becomes 0
    After processing 'a': 'a' count becomes 0
    After processing 'm': 'm' count becomes 0

Step 4: All counts are zero, so return true.

Time Complexity: O(n), where n is the length of the strings.
Space Complexity: O(1), since the count array size is fixed (26).
*/