/*
-----------------------------------
🧠 Approach: Valid Parenthesis Checker
-----------------------------------
1️⃣ Use a stack to keep track of opening brackets.

2️⃣ Traverse each character of the input string:
    - If it's an opening bracket ('(', '{', '['), push it to the stack.
    - If it's a closing bracket (')', '}', ']'):
        🔹 If the stack is empty → invalid (no matching opening bracket).
        🔹 Otherwise, pop the top element and check:
            - '(' matches ')'
            - '{' matches '}'
            - '[' matches ']'
        🔹 If they don't match → invalid.

3️⃣ After traversal:
    - If the stack is empty → all brackets matched → Valid.
    - If not empty → some openings weren't closed → Invalid.

🕒 Time Complexity: O(n)
🧮 Space Complexity: O(n)
-----------------------------------
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if parentheses are valid
bool isValidParenthesis(const string& s) {
    stack<char> st;

    // Traverse each character in the string
    for (char ch : s) {
        // If it's an opening bracket, push onto stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        // If it's a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack empty, no matching opening bracket → invalid
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // Check if the pair matches correctly
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If stack empty → all brackets matched → valid
    return st.empty();
}

// Test function
int main() {
    string s1 = "({[]})";
    string s2 = "({[)]}";
    string s3 = "((()))";
    string s4 = "{[()]}[]";
    string s5 = "(((";

    cout << s1 << " -> " << (isValidParenthesis(s1) ? "Valid" : "Invalid") << endl;
    cout << s2 << " -> " << (isValidParenthesis(s2) ? "Valid" : "Invalid") << endl;
    cout << s3 << " -> " << (isValidParenthesis(s3) ? "Valid" : "Invalid") << endl;
    cout << s4 << " -> " << (isValidParenthesis(s4) ? "Valid" : "Invalid") << endl;
    cout << s5 << " -> " << (isValidParenthesis(s5) ? "Valid" : "Invalid") << endl;

    return 0;
}
