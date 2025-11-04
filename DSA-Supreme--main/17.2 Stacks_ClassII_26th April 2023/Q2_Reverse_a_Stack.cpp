// Pop the top element.
// Recursively reverse the remaining stack.
// Insert the popped element at the bottom of the reversed stack.

#include <iostream>              // Include for input/output operations
#include <stack>                 // Include stack STL
using namespace std;

// Helper function to insert an element at the bottom of stack
void insertAtBottom(stack<int>& st, int x) {
    if (st.empty()) {            // If stack is empty
        st.push(x);              // Push the element at the bottom
        return;                  // Done
    }
    int temp = st.top();         // Store the top element
    st.pop();                    // Remove the top element
    insertAtBottom(st, x);       // Recursively call to reach the bottom
    st.push(temp);               // Push back the stored element
}

// Function to reverse the given stack using recursion
void reverseStack(stack<int>& st) {
    if (st.empty())              // Base case: if stack is empty
        return;                  // Nothing to do
    int topElement = st.top();   // Store the top element
    st.pop();                    // Remove the top element
    reverseStack(st);            // Recursively reverse the rest of the stack
    insertAtBottom(st, topElement); // Insert the removed element at the bottom
}

// Utility function to print stack (top to bottom)
void printStack(stack<int> st) {
    cout << "Stack (top to bottom): "; // Print heading
    while (!st.empty()) {              // While stack is not empty
        cout << st.top() << " ";       // Print the top element
        st.pop();                      // Remove the top element
    }
    cout << endl;                      // Newline after printing stack
}

int main() {
    stack<int> st;                     // Declare a stack of integers

    // Push some elements into the stack
    st.push(1);  // bottom             // Push element 1 (bottom)
    st.push(2);                        // Push element 2
    st.push(3);                        // Push element 3
    st.push(4);                        // Push element 4
    st.push(5);  // top                // Push element 5 (top)

    cout << "Original ";               // Print before reversal
    printStack(st);

    // Reverse the stack
    reverseStack(st);                  // Call function to reverse stack

    cout << "\nReversed ";             // Print after reversal
    printStack(st);

    return 0;                          // End main function
}

/*
Dry Run:
----------
Stack before: top -> 5 4 3 2 1 (bottom)
reverseStack:
- Pop 5, reverse [4 3 2 1]
  - Pop 4, reverse [3 2 1]
    - Pop 3, reverse [2 1]
      - Pop 2, reverse [1]
        - Pop 1, reverse []
          - Stack is empty, return
        - insertAtBottom(1): stack = 1
      - insertAtBottom(2): stack = 2 1
    - insertAtBottom(3): stack = 3 2 1
  - insertAtBottom(4): stack = 4 3 2 1
- insertAtBottom(5): stack = 5 4 3 2 1
Stack after: top -> 1 2 3 4 5 (bottom)
*/
