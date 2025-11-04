// Problem: Reverse Only Letters in a String

// Approach Used: Two Pointer Approach
// The idea is to use two pointers, one starting from the beginning and one from the end of the string.
// Move both pointers towards each other, swapping only the alphabetic characters and skipping non-alphabetic ones.

class Solution {
public:
    // Helper function to check if a character is an alphabet (A-Z or a-z)
    bool isAlphabet(char ch){
        // Check for uppercase
        if(ch >= 'A' && ch <= 'Z')
            return true;
        // Check for lowercase
        if(ch >= 'a' && ch <= 'z')
            return true;
        // Not an alphabet
        return false;
    }

    string reverseOnlyLetters(string s) {
        // Two pointers: i at start, j at end
        int i = 0;
        int j = s.length() - 1;

        // Loop until the two pointers meet or cross
        while(i < j){
            // Move i forward if not an alphabet
            while(i < j && !isAlphabet(s[i])) {
                i++;
            }
            // Move j backward if not an alphabet
            while(i < j && !isAlphabet(s[j])) {
                j--;
            }
            // Both s[i] and s[j] are alphabets, swap them
            if(i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        // Return the modified string
        return s;
    }
};

/*
Alternative Approach 1: Using Stack
-----------------------------------
    // This approach collects all the alphabets in a stack and then replaces them in reverse order.
    string reverseOnlyLetters(string s) {
        stack<char> st;
        // Push all alphabets to stack
        for(char ch : s) {
            if(isalpha(ch)) st.push(ch);
        }
        // Replace alphabets in string with top of stack (reversed)
        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) {
                s[i] = st.top();
                st.pop();
            }
        }
        return s;
    }
    // Time Complexity: O(N), Space Complexity: O(N)

Alternative Approach 2: Using Extra String
------------------------------------------
    // Store all alphabets, then fill them in reverse order
    string reverseOnlyLetters(string s) {
        string letters;
        for(char ch : s) {
            if(isalpha(ch)) letters += ch;
        }
        int idx = letters.size() - 1;
        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) {
                s[i] = letters[idx--];
            }
        }
        return s;
    }
    // Time Complexity: O(N), Space Complexity: O(N)

Note: The two-pointer approach used in the main code is optimal in terms of space (O(1)) and time (O(N)).

Dry Run Example:
----------------
Input:  s = "a-bC-dEf-ghIj"
Step-by-step:
i=0, j=12: s[0]='a', s[12]='j' -> both alphabets, swap -> "j-bC-dEf-ghIa"
i=1, j=11: s[1]='-', not alphabet, i++
i=2, j=11: s[2]='b', s[11]='I' -> swap -> "j-IbC-dEf-gha"
i=3, j=10: s[3]='C', s[10]='h' -> swap -> "j-IhC-dEf-gba"
i=4, j=9: s[4]='-', not alphabet, i++
i=5, j=9: s[5]='d', s[9]='g' -> swap -> "j-IhC-gEf-dba"
i=6, j=8: s[6]='E', s[8]='f' -> swap -> "j-IhC-gfE-dba"
i=7, j=7: pointers meet, done.
Output: "j-IhC-gfE-dba"

Summary:
- Two-pointer approach is optimal for this problem.
- Alternatives using stack or extra string are also valid but use extra space.
- All approaches have O(N) time complexity.
*/