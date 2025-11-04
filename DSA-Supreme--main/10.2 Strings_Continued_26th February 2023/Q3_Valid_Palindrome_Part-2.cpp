/*
Approach Used:
---------------
This code checks if a given string can be a palindrome after removing at most one character.
- It uses a two-pointer approach: one pointer starts from the beginning (i), the other from the end (j).
- If characters at i and j are equal, move both pointers inward.
- If a mismatch is found, try skipping either the left or right character and check if the remaining substring is a palindrome.
- If either case is a palindrome, return true; otherwise, return false.

Time Complexity: O(n), where n is the length of the string.
Space Complexity: O(1), as no extra space is used except for variables.

Better Alternatives:
--------------------
1. The current approach is already optimal for this problem (O(n) time, O(1) space).
2. For more complex cases (e.g., Unicode, ignoring non-alphanumeric), preprocess the string to filter/normalize characters.
3. For large strings, use iterators instead of indices for efficiency in some languages.

Alternative Approach (Recursive):
---------------------------------
/*
bool validPalindrome(string s, int left, int right, int chance) {
    while (left < right) {
        if (s[left] != s[right]) {
            if (chance == 0) return false;
            // Try removing either left or right character
            return validPalindrome(s, left+1, right, 0) || validPalindrome(s, left, right-1, 0);
        }
        left++;
        right--;
    }
    return true;
}
bool palindrome(string s) {
    return validPalindrome(s, 0, s.length()-1, 1);
}
*/

*/

#include<iostream>
using namespace std;

// Helper function to check if substring s[start...end] is a palindrome
bool checkPalindrome(const string& s, int start, int end){
    // Loop until the two pointers meet or cross
    while(start <= end){
        // If mismatch found, substring is not a palindrome
        if(s[start] != s[end]){
            return false;
        }
        start++; // Move start pointer forward
        end--;   // Move end pointer backward
    }
    // If no mismatches, substring is a palindrome
    return true;
}

// Main function to check if string can be palindrome after at most one removal
bool palindrome(const string& s){
    int i = 0;                  // Left pointer
    int j = s.length() - 1;     // Right pointer

    while(i <= j){
        if(s[i] != s[j]){ // Mismatch found
            // Try removing either s[i] or s[j] and check if the rest is palindrome
            // If either is true, the string can be a palindrome after one removal
            return checkPalindrome(s, i+1, j) || checkPalindrome(s, i, j-1);
        }
        else{
            // Characters match, move both pointers inward
            i++;
            j--;
        }
    }
    // If loop completes, string is already a palindrome
    return true;
}

int main(){
    string s = "abca"; // Test string

    // Call palindrome function and print result
    if(palindrome(s)){
        cout << "Yes"; // String can be palindrome after at most one removal
    }
    else{
        cout << "No";  // Not possible even after one removal
    }
    return 0;
}

/*
Dry Run:
--------
Input: "abca"
i=0, j=3: s[0]='a', s[3]='a' -> match, i++, j--
i=1, j=2: s[1]='b', s[2]='c' -> mismatch
    Try removing s[1] ('b'): checkPalindrome("aca", 2, 2) => true
    Try removing s[2] ('c'): checkPalindrome("aba", 1, 1) => true
At least one removal leads to palindrome, so output is "Yes".

Another Example:
Input: "abc"
i=0, j=2: s[0]='a', s[2]='c' -> mismatch
    Try removing s[0]: checkPalindrome("bc", 1, 2) => 'b' != 'c' -> false
    Try removing s[2]: checkPalindrome("ab", 0, 1) => 'a' != 'b' -> false
Both false, so output is "No".
*/