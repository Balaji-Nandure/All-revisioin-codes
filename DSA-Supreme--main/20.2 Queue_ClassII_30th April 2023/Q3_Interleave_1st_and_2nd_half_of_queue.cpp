/*
Approach:
---------
Interleave the first and second halves of a queue.
If the queue has an odd length, the middle element remains at the end.

Steps:
1. Move the first half into a temporary queue.
2. Alternately push from the temp queue and the remaining elements.
3. If odd length, move the extra element to the back.

Time: O(n)
Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();
    if (n <= 1) return;

    int half = n / 2;
    queue<int> firstHalf;

    // Step 1: store first half
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: interleave
    while (!firstHalf.empty() && !q.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }

    // Step 3: if odd, rotate leftover
    if (n % 2 != 0) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    for (int i = 10; i <= 80; i += 10) q.push(i);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";

    /*
    Dry Run:
    Input: [10,20,30,40,50,60,70,80]
    Step1: firstHalf=[10,20,30,40], q=[50,60,70,80]
    Step2: result=[10,50,20,60,30,70,40,80]
    Output: 10 50 20 60 30 70 40 80
    */
}
