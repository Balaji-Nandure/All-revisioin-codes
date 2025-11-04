// https://leetcode.com/problems/reverse-vowels-of-a-string/description/

/*
Approach Used:
---------------
- Two pointer approach: One pointer starts from the beginning (i), and the other from the end (j) of the string.
- Move both pointers towards each other, swapping vowels when both pointers point to vowels.
- Continue until the pointers cross.
- Helper function isVowel checks if a character is a vowel (case-insensitive).

Better Alternatives:
--------------------
1. Use an unordered_set for faster vowel lookup in isVowel.
2. Use STL functions like std::tolower for case conversion.
3. Precompute the positions of vowels, then swap from the list (less efficient for this problem, but possible).
4. Use a single pass to collect vowels, then replace them in reverse order (uses extra space).

Alternative code using unordered_set and std::tolower:
------------------------------------------------------
    unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    bool isVowel(char ch) { return vowels.count(ch); }
    // or use std::tolower(ch) in the set

Dry Run Example:
----------------
Input: "hello"
i=0, j=4
s[0]='h' (not vowel), i++
i=1, s[1]='e' (vowel), s[4]='o' (vowel) => swap, i++, j--
Now s="holle"
i=2, s[2]='l' (not vowel), i++
i=3, s[3]='l' (not vowel), i++
i=4, loop ends
Output: "holle"
*/

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Helper function to check if a character is a vowel (case-insensitive)
    bool isVowel(char ch){
        // Convert uppercase to lowercase using bitwise OR (faster than tolower)
        ch = ch | 32; // 'A'->'a', 'E'->'e', etc.
        // Check if character is a vowel
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string reverseVowels(string s) {
        int i = 0; // Left pointer
        int j = s.length() - 1; // Right pointer

        // Loop until the two pointers meet
        while(i < j){
            // Move left pointer forward if not a vowel
            while(i < j && !isVowel(s[i])) i++;
            // Move right pointer backward if not a vowel
            while(i < j && !isVowel(s[j])) j--;
            // Both s[i] and s[j] are vowels, swap them
            if(i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s; // Return the modified string
    }
};

/*
Alternative approach using unordered_set and STL tolower:
---------------------------------------------------------
#include <unordered_set>
class Solution {
public:
    unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
    bool isVowel(char ch) {
        return vowels.count(ch);
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            while(i < j && !isVowel(s[i])) i++;
            while(i < j && !isVowel(s[j])) j--;
            if(i < j) swap(s[i++], s[j--]);
        }
        return s;
    }
};
*/

/*
Dry Run:
--------
Input: "leetcode"
i=0, j=7
s[0]='l' (not vowel), i++
s[1]='e' (vowel), s[7]='e' (vowel) => swap (no change), i++, j--
i=2, j=6
s[2]='e' (vowel), s[6]='d' (not vowel), j--
j=5, s[5]='o' (vowel), swap s[2] and s[5]
Now s="leotcede"
i++, j--
i=3, j=4
s[3]='t' (not vowel), i++
i=4, j=4 (loop ends)
Output: "leotcede"
*/