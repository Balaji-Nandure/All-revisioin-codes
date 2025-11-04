/*
-----------------------------------
🧠 Approach: Check for Redundant Brackets
-----------------------------------
Goal:
    Given a balanced expression string containing operands, operators (+, –, *, /), and parentheses, determine if it contains any redundant brackets. Redundant brackets are those that don’t affect the meaning, i.e., removing them wouldn’t change the expression.

Idea:
    Use a stack to traverse the expression:
    1. Traverse each character of the string:
        - If the character is anything but a closing parenthesis ‘)’, push it onto the stack.
        - If the character is a closing parenthesis ‘)’:
            * Pop elements from the stack until we find an opening parenthesis ‘(’.
            * Meanwhile track if we popped any operator (+, –, *, /).
            * If no operator was found in that bracket-pair scope, then the brackets are redundant.
            * If the very first popped element is ‘(’ (i.e., the top was ‘(’ immediately), then it’s also redundant.
    2. If we finish the traversal without finding redundant brackets, return false; otherwise true.

Time Complexity: O(n) where n = length of the string.
Space Complexity: O(n) in worst-case (stack usage).
-----------------------------------
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool hasRedundantBrackets(const string &s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == ')') {
            // When encountering a closing parenthesis, check inside the bracket
            char topChar = st.top();
            st.pop();
            
            bool foundOperator = false;
            
            // Pop until opening parenthesis is found
            while (!st.empty() && topChar != '(') {
                if (topChar == '+' || topChar == '-' || topChar == '*' || topChar == '/') {
                    foundOperator = true;
                }
                topChar = st.top();
                st.pop();
            }
            
            // If no operator was found between '(' and ')', the brackets are redundant
            if (!foundOperator) {
                return true;
            }
        } else {
            // Push operand, operator or '(' onto the stack
            st.push(ch);
        }
    }
    // If we finish and no redundant found
    return false;
}

int main() {
    // Test cases
    string expr1 = "((a+b))";
    string expr2 = "(a+(b)/c)";
    string expr3 = "(a+b*(c-d))";
    string expr4 = "(a)";
    
    cout << expr1 << " -> " << (hasRedundantBrackets(expr1) ? "YES" : "NO") << endl;
    cout << expr2 << " -> " << (hasRedundantBrackets(expr2) ? "YES" : "NO") << endl;
    cout << expr3 << " -> " << (hasRedundantBrackets(expr3) ? "YES" : "NO") << endl;
    cout << expr4 << " -> " << (hasRedundantBrackets(expr4) ? "YES" : "NO") << endl;
    
    return 0;
}
