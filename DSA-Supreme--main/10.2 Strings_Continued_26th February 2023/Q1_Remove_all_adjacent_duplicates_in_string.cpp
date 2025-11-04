/*
Approach Used:
---------------
We use a stack-like approach with a string (ans) to remove all adjacent duplicates in the input string.
- Traverse the input string character by character.
- For each character, check if the last character in 'ans' is the same as the current character.
    - If yes, pop the last character from 'ans' (removing the duplicate).
    - If no, push the current character to 'ans'.
- At the end, 'ans' contains the string with all adjacent duplicates removed.

Time Complexity: O(N), where N is the length of the string.
Space Complexity: O(N), for the auxiliary string used as a stack.

Better Alternatives:
--------------------
1. Using an explicit stack<char> instead of a string for clarity.
2. In-place modification (if allowed) to reduce space usage.
3. Recursive approach (less efficient due to call stack overhead).

Alternative 1: Using stack<char>
--------------------------------
/*
#include <stack>
string removeDuplicates(string &s) {
    stack<char> st;
    for(char c : s) {
        if(!st.empty() && st.top() == c)
            st.pop();
        else
            st.push(c);
    }
    string ans = "";
    while(!st.empty()) {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}
*/

Alternative 2: In-place (two pointer)
-------------------------------------
/*
string removeDuplicates(string &s) {
    int i = 0; // slow pointer
    for(int j = 0; j < s.size(); ++j) { // fast pointer
        if(i > 0 && s[i-1] == s[j]) {
            --i; // remove previous char
        } else {
            s[i++] = s[j]; // keep current char
        }
    }
    return s.substr(0, i);
}
*/

Code with detailed comments and improved readability:
----------------------------------------------------
*/

#include<iostream>
using namespace std;

// Function to remove all adjacent duplicates in a string
string removeDuplicates(const string &s){
    string ans = ""; // 'ans' acts as a stack to store result without adjacent duplicates

    // Traverse each character in the input string
    for(char c : s) {
        // If 'ans' is not empty and last character is same as current, remove last character
        if(!ans.empty() && ans.back() == c) {
            ans.pop_back(); // Remove duplicate
        } else {
            ans.push_back(c); // Add current character to 'ans'
        }
    }
    return ans; // Return the processed string
}

int main(){
    string s = "abbaca";
    string ans = removeDuplicates(s);
    cout << ans; // Output the result

    /*
    Dry Run:
    --------
    Input: "abbaca"
    Step-by-step:
    ans = ""
    i=0, c='a' -> ans="" -> push 'a' => ans="a"
    i=1, c='b' -> ans="a" -> push 'b' => ans="ab"
    i=2, c='b' -> ans="ab" (last is 'b') -> pop 'b' => ans="a"
    i=3, c='a' -> ans="a" (last is 'a') -> pop 'a' => ans=""
    i=4, c='c' -> ans="" -> push 'c' => ans="c"
    i=5, c='a' -> ans="c" -> push 'a' => ans="ca"
    Output: "ca"
    */
    return 0;
}

/*
Summary of Approaches:
----------------------
- Stack-like string (used above): Simple, efficient, O(N) time and space.
- Explicit stack<char>: More explicit, but similar logic.
- In-place two-pointer: Space optimized, modifies input.
- Recursive: Not recommended for large strings due to stack overflow risk.
*/