/*
    Approach Used:
    --------------
    - The code checks for redundant (extra) brackets in a given mathematical expression.
    - Redundant brackets are those which do not enclose any operator (like '+', '-', '*', '/').
    - The idea is to use a stack to process the expression:
        - Push every character onto the stack except when a closing bracket ')' is encountered.
        - When ')' is found, check the top of the stack for any operator between the matching '(' and ')'.
        - If no operator is found, the brackets are redundant.

    Why Stack?
    ----------
    - Stack helps to keep track of the most recent opening brackets and the elements inside them.
    - It allows us to efficiently check the contents between a pair of brackets.

    Better Alternatives:
    --------------------
    1. **Counter Approach (Not recommended for this problem):**
        - Use a counter to track brackets, but it cannot check for operators inside brackets.
        - Not suitable for detecting redundancy.

    2. **Recursive Parsing:**
        - Recursively parse the expression and check for operators inside brackets.
        - More complex and less efficient than stack-based approach.

    3. **Using Regular Expressions:**
        - Can be used for simple cases, but not reliable for nested or complex expressions.

    // Example code for recursive approach (for illustration only):
    /*
    bool hasOperator(const string& expr, int l, int r) {
        for(int i = l+1; i < r; ++i) {
            if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
                return true;
        }
        return false;
    }
    bool checkRedundantRec(const string& expr, int l, int r) {
        for(int i = l; i <= r; ++i) {
            if(expr[i] == '(') {
                int j = i, cnt = 0;
                for(; j <= r; ++j) {
                    if(expr[j] == '(') cnt++;
                    if(expr[j] == ')') cnt--;
                    if(cnt == 0) break;
                }
                if(!hasOperator(expr, i, j)) return true;
                if(checkRedundantRec(expr, i+1, j-1)) return true;
                i = j;
            }
        }
        return false;
    }
    */

    Dry Run:
    --------
    Expression: "((a+b))"
    Stack: [ ( a + b ]  // push until ')'
    On ')': pop b, +, a, (  // found operator '+', so not redundant
    Next ')': pop (  // no operator found, so redundant

    Expression: "(a+(b)/c)"
    Stack: [ ( a + ( b ) / c ]
    On ')': pop b, (  // no operator, so redundant
    On ')': pop c, /, (  // found operator '/', so not redundant

    Expression: "(a+b*(c-d))"
    Stack: [ ( a + b * ( c - d ] 
    On ')': pop d, -, c, (  // found operator '-', so not redundant
    On ')': pop (  // no operator, so redundant

*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check for redundant brackets in the expression
bool hasRedundantBrackets(const string& expr) {
    stack<char> st; // Stack to store characters of the expression

    for(char ch : expr) { // Traverse each character in the expression
        if(ch == ')') { // If closing bracket is found
            bool operatorFound = false; // Flag to check if any operator is found inside brackets

            // Pop elements until opening bracket '(' is found
            while(!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();
                // If an operator is found, set the flag
                if(top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorFound = true;
                }
            }
            // Pop the opening bracket '('
            if(!st.empty()) st.pop();

            // If no operator was found, brackets are redundant
            if(!operatorFound) {
                return true;
            }
        } else {
            // Push all other characters (including opening bracket) onto the stack
            st.push(ch);
        }
    }
    // No redundant brackets found
    return false;
}

int main() {
    string expr;
    cout << "Enter the expression: ";
    cin >> expr;

    if(hasRedundantBrackets(expr)) {
        cout << "Redundant brackets found in the expression." << endl;
    } else {
        cout << "No redundant brackets in the expression." << endl;
    }

    /*
    Dry Run Example:
    ----------------
    Input: ((a+b))
    Stack after processing: ( a + b
    On encountering ')': pop b, +, a, (  // operator '+' found, not redundant
    Next ')': pop (  // no operator found, so redundant
    Output: Redundant brackets found in the expression.

    Input: (a+(b)/c)
    Stack after processing: ( a + ( b ) / c
    On encountering ')': pop b, (  // no operator, so redundant
    Output: Redundant brackets found in the expression.
    */
    return 0;
}
