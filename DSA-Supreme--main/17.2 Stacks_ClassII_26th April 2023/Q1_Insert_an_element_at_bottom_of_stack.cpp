#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int>& st, int x) {
    // Base case: If stack is empty, push the element — it becomes the bottom element
    if (st.empty()) {
        st.push(x);
        return;
    }

    // Step 1: Remove the top element temporarily
    int temp = st.top();
    st.pop();

    // Step 2: Recursively call the function until stack is empty
    insertAtBottom(st, x);

    // Step 3: Push the removed element back to restore original order
    st.push(temp);
}

// Utility function to print stack (from top to bottom)
void printStack(stack<int> st) {
    cout << "Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;

    // Push some elements into the stack
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Original ";
    printStack(st);

    int newElement = 5;
    cout << "\nInserting " << newElement << " at the bottom of stack...\n";

    // Call the function to insert at bottom
    insertAtBottom(st, newElement);

    cout << "\nAfter insertion ";
    printStack(st);

    return 0;
}
