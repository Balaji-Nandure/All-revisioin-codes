#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
Approach 1: Using Recursion (In-place, O(N) time, O(N) space due to call stack)
- The idea is to remove the front element, recursively reverse the remaining queue, and then push the removed element at the back.
- This way, the order of the queue is reversed as the recursion unwinds.
*/

void reverseQueue(queue<int>& q) {
    // Base case: If queue is empty, do nothing (recursion ends)
    if(q.empty()){
        return;
    }
    // Remove the front element and store it
    int element = q.front();
    q.pop();
    // Recursively reverse the remaining queue
    reverseQueue(q);
    // Push the removed element at the back (so it comes last)
    q.push(element);
}

/*
Alternative Approach 2: Using Stack (Iterative, O(N) time, O(N) space)
- Push all elements from the queue into a stack (LIFO).
- Pop all elements from the stack and push them back into the queue.
- This reverses the queue because the stack reverses the order.
*/
void reverseQueueWithStack(queue<int>& q) {
    stack<int> st;
    // Move all elements from queue to stack
    while(!q.empty()){
        st.push(q.front()); // Push front element to stack
        q.pop();           // Remove from queue
    }
    // Move all elements back from stack to queue
    while(!st.empty()){
        q.push(st.top());  // Push top of stack to queue
        st.pop();          // Remove from stack
    }
}

/*
Alternative Approach 3: Using Deque (STL) - Not required here, but for completeness
- You can use a deque to reverse efficiently, but stack/recursion is more standard for this problem.
*/

int main(){
    queue<int> q;
    // Insert elements into the queue
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    // Call the recursive reverse function
    reverseQueue(q);
    // Alternatively, use the stack-based approach:
    // reverseQueueWithStack(q);

    // Print the reversed queue
    while(!q.empty()){
        cout << q.front() << " "; // Print front element
        q.pop();                  // Remove printed element
    }
    return 0;
}

/*
Dry Run (for input: 3 6 9 2 8):

Initial Queue: front [3, 6, 9, 2, 8] back

reverseQueue(q):
- Remove 3, call reverseQueue([6,9,2,8])
    - Remove 6, call reverseQueue([9,2,8])
        - Remove 9, call reverseQueue([2,8])
            - Remove 2, call reverseQueue([8])
                - Remove 8, call reverseQueue([])
                    - q is empty, return
                - q: []
                - push 8 -> [8]
            - q: [8]
            - push 2 -> [8,2]
        - q: [8,2]
        - push 9 -> [8,2,9]
    - q: [8,2,9]
    - push 6 -> [8,2,9,6]
- q: [8,2,9,6]
- push 3 -> [8,2,9,6,3]

Final Queue: front [8, 2, 9, 6, 3] back

So output: 8 2 9 6 3
*/

/*
Summary of Approaches:
1. Recursion: Elegant, but uses call stack (O(N) space).
2. Stack: Iterative, explicit O(N) space.
3. Deque: Not standard for this problem, but possible.
Both recursion and stack are optimal for this problem.
*/