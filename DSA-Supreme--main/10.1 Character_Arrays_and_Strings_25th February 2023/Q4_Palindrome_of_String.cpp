/*
Approach Used:
---------------
- The code checks if a given character array (C-style string) is a palindrome.
- It uses two pointers: one starting from the beginning (s) and one from the end (e) of the string.
- The pointers move towards each other, comparing characters at each step.
- If all corresponding characters match, the string is a palindrome.

Better Alternatives (without code):
-----------------------------------
1. Use C++ std::string for safer and more convenient string handling.
2. Convert the string to lowercase/uppercase before checking, to make the check case-insensitive.
3. Ignore non-alphanumeric characters for a more robust palindrome check.
4. Use STL algorithms like std::equal with reverse iterators for concise code.
5. For very large strings, consider parallel processing (advanced).

Dry Run Example:
----------------
Input: "racecar"
s=0, e=6: name[0]='r', name[6]='r' -> match, s++, e--
s=1, e=5: name[1]='a', name[5]='a' -> match, s++, e--
s=2, e=4: name[2]='c', name[4]='c' -> match, s++, e--
s=3, e=3: name[3]='e', name[3]='e' -> match, s++, e--
s=4, e=2: s>e, exit loop, return true

*/

#include<iostream>
#include<cstring> // Use cstring instead of string.h for C++ compatibility
using namespace std;

// Function to check if a given char array is a palindrome
bool checkPalindrome(const char name[]) {
    int s = 0; // Start pointer at beginning of string
    int e = strlen(name) - 1; // End pointer at last character (excluding null terminator)

    // Loop until the two pointers meet or cross
    while (s < e) {
        // If characters at current pointers do not match, not a palindrome
        if (name[s] != name[e]) {
            return false;
        }
        // Move pointers towards the center
        s++;
        e--;
    }
    // All characters matched, so it's a palindrome
    return true;
}

int main() {
    // Input string (can be modified for user input)
    char name[100] = "racecar";

    // Call palindrome check function and print result
    if (checkPalindrome(name)) {
        cout << "Palindrome";
    } else {
        cout << "Not Palindrome";
    }
    return 0;
}

/*
Dry Run:
--------
Input: "racecar"
s=0, e=6: name[0]='r', name[6]='r' -> match, s++, e--
s=1, e=5: name[1]='a', name[5]='a' -> match, s++, e--
s=2, e=4: name[2]='c', name[4]='c' -> match, s++, e--
s=3, e=3: name[3]='e', name[3]='e' -> match, s++, e--
s=4, e=2: s>e, exit loop, return true

Output: Palindrome
*/