/*
-----------------------------------
🧠 Approach: Design Min Stack
-----------------------------------
Goal:
    Implement a stack data structure that supports the following operations in *O(1)* time:
        - push(val): push the element val onto the stack.
        - pop(): remove the element on top of the stack.
        - top(): get the top element.
        - getMin(): retrieve the minimum element in the stack.

Idea:
    Maintain two stacks (or one stack of pairs/structs) so that we can always get the current minimum quickly.
    - Primary stack (“data stack”) stores the values pushed.
    - Secondary stack (“min stack”) stores the minimum value corresponding to each position (or only when minimum changes).
    When pushing:
        - Push the value onto the data stack.
        - Also push the current minimum (either the new value if it’s smaller, or the previous minimum) onto the min stack.
    When popping:
        - Pop from both stacks.
    When top:
        - Return the top of the data stack.
    When getMin:
        - Return the top of the min stack.

Time Complexity: O(1) per operation.
Space Complexity: O(n) auxiliary space for the min stack.
-----------------------------------
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> dataStack;  // stores all pushed values
    stack<int> minStack;   // stores current minimum value at each level

public:
    /** initialize your data structure here. */
    MinStack() {
        // nothing special to initialize beyond the stacks
    }
    
    void push(int val) {
        dataStack.push(val);
        // If minStack is empty or new val is smaller than current min, push val.
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        } else {
            // Otherwise, push the current min again (so minStack stays aligned with dataStack)
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        if (!dataStack.empty()) {
            dataStack.pop();
            minStack.pop();
        }
    }
    
    int top() {
        if (!dataStack.empty()) {
            return dataStack.top();
        }
        // Depending on problem constraints this may never be called on empty stack
        return -1; 
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        // Depending on problem constraints this may never be called on empty stack
        return -1;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    cout << "getMin() -> " << minStack.getMin() << endl;   // should print -3
    minStack.pop();
    cout << "top() -> " << minStack.top() << endl;         // should print 0
    cout << "getMin() -> " << minStack.getMin() << endl;   // should print -2

    return 0;
}
