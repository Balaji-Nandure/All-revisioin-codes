/*
-----------------------------------
🧠 Approach: Sort a Stack using Recursion
-----------------------------------
🎯 Goal:
    - Sort a stack in ascending order (smallest element at the top).
    - Use recursion only (no extra stack or array allowed).

🧩 Idea:
    - Recursively pop all elements from the stack until it becomes empty.
    - When the recursion unwinds, insert each popped element
      back into the sorted stack in its correct position.

📘 Logic Steps:
    1️⃣ Base Case:
        - If the stack is empty, return (it's trivially sorted).
    2️⃣ Recursive Case:
        - Pop the top element.
        - Recursively sort the remaining smaller stack.
        - Insert the popped element back into its correct position
          in the sorted stack using a helper function.

💡 Helper Function (`insertInSortedOrder`):
    - Recursively insert an element into the correct position
      in an already sorted stack.

🕒 Time Complexity: O(n²)
🧮 Space Complexity: O(n) (due to recursion call stack)
-----------------------------------
*/

#include <iostream>
#include <stack>
using namespace std;

// Helper function: insert an element in sorted order into a sorted stack
void insertInSortedOrder(stack<int>& st, int element) {
    // Base case: if stack is empty or top element is smaller/equal
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }

    // Otherwise, remove the top element temporarily
    int topElement = st.top();
    st.pop();

    // Recursive call to insert in the smaller sorted stack
    insertInSortedOrder(st, element);

    // Put back the removed element
    st.push(topElement);
}

// Function to sort the stack recursively
void sortStack(stack<int>& st) {
    // Base case: if stack has 0 or 1 element, it's already sorted
    if (st.empty() || st.size() == 1)
        return;

    // Pop the top element
    int topElement = st.top();
    st.pop();

    // Recursively sort the remaining stack
    sortStack(st);

    // Insert the popped element in sorted order
    insertInSortedOrder(st, topElement);
}

// Utility function to print the stack (top to bottom)
void printStack(stack<int> st) {
    cout << "Stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// Driver function to test sorting
int main() {
    stack<int> st;

    // Push some unsorted elements
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    st.push(5);

    cout << "Original ";
    printStack(st);

    // Sort the stack
    sortStack(st);

    cout << "\nSorted ";
    printStack(st);

    return 0;
}
