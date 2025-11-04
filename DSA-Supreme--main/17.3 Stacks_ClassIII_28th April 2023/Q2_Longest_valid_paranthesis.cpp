/*
-----------------------------------
🧠 Approach: Longest Valid Parentheses
-----------------------------------
Goal:
    Given a string containing '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Idea:
    1️⃣ Use a stack to keep track of indices of '(' characters.
    2️⃣ Push -1 onto the stack initially to handle edge cases (like a valid substring starting at index 0).
    3️⃣ Traverse the string:
        - If '(' → push its index onto the stack.
        - If ')' → pop the top index:
            * If stack becomes empty → push current index as a new base.
            * Otherwise → current length = i - stack.top(); update max length.
    4️⃣ At the end, max length will contain the length of the longest valid substring.

Time Complexity: O(n)
Space Complexity: O(n)
-----------------------------------
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValidParentheses(const string& s) {
    stack<int> st;
    st.push(-1);  // Base for valid substring calculation
    int maxLength = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            // Push index of '('
            st.push(i);
        } else {
            // Pop top index for matching '('
            st.pop();

            if (st.empty()) {
                // No matching '(', push current index as new base
                st.push(i);
            } else {
                // Valid substring length = current index - index of last unmatched '('
                maxLength = max(maxLength, i - st.top());
            }
        }
    }

    return maxLength;
}

int main() {
    string s1 = "(()";
    string s2 = ")()())";
    string s3 = "";
    string s4 = "()(())";

    cout << s1 << " -> " << longestValidParentheses(s1) << endl; // 2
    cout << s2 << " -> " << longestValidParentheses(s2) << endl; // 4
    cout << s3 << " -> " << longestValidParentheses(s3) << endl; // 0
    cout << s4 << " -> " << longestValidParentheses(s4) << endl; // 6

    return 0;
}
