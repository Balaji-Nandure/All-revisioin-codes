/*
Approach Used:
---------------
The code reverses the first k elements of a queue using a stack. The stack is used to reverse the order of the first k elements, and then the remaining elements are appended to the back of the queue. This is a classic use of stack and queue to manipulate order.

Step-by-step logic:
1. Check for invalid k (k==0 or k>queue size).
2. Remove first k elements from queue and push them onto stack (reverses their order).
3. Pop all elements from stack and enqueue them back to queue (now reversed).
4. Move the remaining n-k elements (originally after the first k) to the back to maintain their order.

Improvements:
-------------
- Use more descriptive variable names.
- Remove unnecessary checks and simplify loops.
- Add more robust input validation.
- Provide an alternative approach using recursion in comments.
- Add detailed comments for each step.
- Add a dry run at the end.

Alternative Approach (Recursive):
---------------------------------
/*
void reverseKRecursive(queue<int>& q, int k) {
    if (k <= 0 || q.empty()) return;
    int temp = q.front();
    q.pop();
    reverseKRecursive(q, k-1);
    q.push(temp);
}
void reverseFirstK(queue<int>& q, int k) {
    int n = q.size();
    if (k > n || k <= 0) return;
    reverseKRecursive(q, k);
    // Move the rest n-k elements to the back
    for (int i = 0; i < n-k; ++i) {
        q.push(q.front());
        q.pop();
    }
}
*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Function to reverse first k elements of a queue
void reverseKQueue(queue<int>& q, int k) {
    // Get the size of the queue
    int n = q.size();

    // Edge case: if k is 0, negative, or greater than queue size, do nothing
    if (k <= 0 || k > n) {
        // Invalid k, no operation performed
        return;
    }

    stack<int> s; // Stack to reverse order of first k elements

    // Step 1: Push first k elements from queue to stack
    for (int i = 0; i < k; ++i) {
        // Remove from front of queue and push onto stack
        s.push(q.front());
        q.pop();
    }

    // Step 2: Pop all elements from stack and enqueue back to queue
    // This reverses the order of first k elements
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move the remaining n-k elements (which are at the front) to the back
    // This maintains their original order
    for (int i = 0; i < n - k; ++i) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    // Inserting elements into the queue
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);

    int k = 2; // Number of elements to reverse

    reverseKQueue(q, k); // Call function to reverse first k elements

    // Printing the queue after reversal
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}

/*
Dry Run:
--------
Initial Queue: 3 6 9 12 15
k = 2

Step 1: Push first k elements to stack
Stack: 3 (bottom), 6 (top)
Queue: 9 12 15

Step 2: Pop from stack and enqueue
Queue after pushing from stack: 9 12 15 6 3

But since we push to queue, the order is:
After pushing 6: 9 12 15 6
After pushing 3: 9 12 15 6 3

But actually, after step 2, queue is: 9 12 15 6 3

Step 3: Move n-k = 3 elements to back
Pop 9, push 9: 12 15 6 3 9
Pop 12, push 12: 15 6 3 9 12
Pop 15, push 15: 6 3 9 12 15

Final Queue: 6 3 9 12 15

Output:
6 3 9 12 15

Time Complexity: O(n)
Space Complexity: O(k) (for stack)
*/

/*
Alternative Approach (using only queue, no stack):
--------------------------------------------------
This approach is less efficient (O(k*n)), but possible.

void reverseKQueueAlt(queue<int>& q, int k) {
    int n = q.size();
    if (k <= 0 || k > n) return;
    for (int i = 0; i < k; ++i) {
        int x = q.front();
        q.pop();
        // Move the next k-1 elements to the back
        for (int j = 0; j < k-1; ++j) {
            q.push(q.front());
            q.pop();
        }
        q.push(x);
    }
    // Move the rest n-k elements to the back
    for (int i = 0; i < n-k; ++i) {
        q.push(q.front());
        q.pop();
    }
}
*/