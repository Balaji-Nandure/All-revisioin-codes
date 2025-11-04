#include<iostream>
using namespace std;

/*
Approach Used:
---------------
- The function iteratively searches for the substring 'part' in the string 's'.
- Whenever 'part' is found, it is erased from 's'.
- This process continues until 'part' is no longer found in 's'.
- Finally, the modified string is returned.

Time Complexity: O(N * M), where N is the length of s and M is the length of part, because each find and erase operation can take O(N) time in the worst case.

Better Alternative Approach:
---------------------------
- We can use a stack-like approach to build the answer string.
- For each character in 's', append it to a result string.
- After appending, check if the last 'part.length()' characters of the result string match 'part'.
- If they do, remove those characters.
- This approach is more efficient, especially for large strings, as it avoids repeated searching and erasing.

Alternative Code (Stack-like approach):
---------------------------------------
/*
string removeOccurrence(string s, string part) {
    string result;
    int plen = part.length();
    for(char c : s) {
        result.push_back(c); // Add current character to result
        // If the end of result matches 'part', remove it
        if(result.size() >= plen && result.substr(result.size()-plen, plen) == part) {
            result.erase(result.size()-plen, plen);
        }
    }
    return result;
}
*/

string removeOccurrence(string s, string part){
    // Find the index of the first occurrence of 'part' in 's'
    int pos = s.find(part); 
    // Continue removing 'part' as long as it is found in 's'
    while(pos >= 0) {
        // Remove 'part' from 's' starting at index 'pos'
        s.erase(pos, part.length()); 
        // Search for the next occurrence of 'part' in the updated 's'
        pos = s.find(part); 
    }
    // Return the modified string after all occurrences are removed
    return s; 
}

int main(){
    string s = "daabcbaabcbc"; // Input string
    string part = "abc";       // Substring to remove
    string ans = removeOccurrence(s, part); // Remove all occurrences of 'part' from 's'
    cout << ans; // Output the result
    return 0;
}

/*
Dry Run:
--------
Input: s = "daabcbaabcbc", part = "abc"

Step 1: Find "abc" in s -> found at index 2
        Remove "abc": s = "dabaabcbc"
Step 2: Find "abc" in s -> found at index 5
        Remove "abc": s = "dabaac"
Step 3: Find "abc" in s -> not found (npos)
        Stop

Output: "dabcbc"
But let's check with the stack-like approach for correctness:

Stack-like approach:
result = ""
Iterate over s:
'd' -> "d"
'a' -> "da"
'a' -> "daa"
'b' -> "daab"
'c' -> "daabc" (last 3: "abc" == part, remove) -> "daa"
'b' -> "daab"
'a' -> "daaba"
'a' -> "daabaa"
'b' -> "daabaab"
'c' -> "daabaabc" (last 3: "abc" == part, remove) -> "daabaab"
Output: "daabaab"

So, the original code outputs "dabcbc", but the correct output should be "daabcbc" (as per Leetcode and stack-like approach).
Hence, the stack-like approach is more robust for overlapping cases.

*/