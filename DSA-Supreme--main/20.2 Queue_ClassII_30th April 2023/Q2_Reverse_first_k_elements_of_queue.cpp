/*
Approach:
----------
We need to reverse the first k elements of a queue.

Steps:
1. Use a stack to reverse order of first k elements.
   - Dequeue first k elements from queue and push them into stack.
2. Pop all from stack and enqueue back to queue — now they are reversed.
3. Move the remaining (n - k) elements from front to back to restore order.

Time Complexity: O(n)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>
using namespace std;

void reverseFirstK(queue<int> &q, int k) {
    if (q.empty() || k <= 0 || k > q.size()) return;

    stack<int> st;

    // Step 1: Push first k elements into stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue back the stack elements (reversed order)
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move remaining elements to back to maintain order
    int remaining = q.size() - k;
    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    for (int i = 1; i <= 7; i++) q.push(i);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) { cout << temp.front() << " "; temp.pop(); }
    cout << "\n";

    int k = 4;
    reverseFirstK(q, k);

    cout << "After reversing first " << k << " elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}
