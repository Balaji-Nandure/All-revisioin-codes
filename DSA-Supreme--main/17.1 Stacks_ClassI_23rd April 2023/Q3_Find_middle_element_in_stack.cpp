/*
Approach:
---------
- To find the middle element of a stack without altering it, we use recursion.
- We recursively pop elements from the stack until we reach the middle element (size/2).
- Once the middle element is found, we print it.
- After printing, we push each popped element back to restore the original stack.
- The main function demonstrates this with a sample stack and shows that the stack remains unchanged.
*/

#include <iostream>      // Include input/output stream
#include <stack>         // Include stack STL
using namespace std;

// Recursive helper function to get middle element
void findMiddleHelper(stack<int>& st, int size, int current) {
    // If current index is at middle, print and return
    if (current == size / 2) {                     
        cout << "Middle element: " << st.top() << endl; // Print the middle
        return;                                
    }

    int temp = st.top();      // Store top element
    st.pop();                 // Pop top element to go deeper

    findMiddleHelper(st, size, current + 1); // Recursive call with incremented index

    st.push(temp);            // Push stored element back to restore stack
}

// Function to initiate finding the middle element
void findMiddle(stack<int>& st) {
    int size = st.size();                 // Get size of the stack
    if (size == 0) {                      // If stack is empty
        cout << "Stack is empty!" << endl; // Print message and return
        return;                           
    }
    findMiddleHelper(st, size, 0);        // Call helper function with starting index 0
}

int main() {
    stack<int> st;                        // Declare a stack

    // Push values 1 to 5 onto stack (top=5, bottom=1)
    for (int i = 1; i <= 5; i++) {        
        st.push(i);                      
    }

    cout << "Stack elements (top to bottom): "; 
    stack<int> temp = st;                 // Make a copy to display elements
    while (!temp.empty()) {               // While there are elements in temp stack
        cout << temp.top() << " ";        // Print top element
        temp.pop();                       // Remove top element
    }
    cout << endl;

    findMiddle(st);                       // Find and print the middle element

    cout << "Stack after finding middle (unchanged): ";
    temp = st;                            // Copy stack again to show unchanged state
    while (!temp.empty()) {               // Print all elements again
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;                             // End of program
}
