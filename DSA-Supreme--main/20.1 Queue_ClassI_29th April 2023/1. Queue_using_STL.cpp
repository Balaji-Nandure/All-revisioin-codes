/*
STL Queue Example:
------------------
- A queue is FIFO (First-In-First-Out)
- Operations:
    push(x)   : insert element at back
    pop()     : remove element from front
    front()   : access front element
    back()    : access back element
    empty()   : check if queue is empty
    size()    : number of elements
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;  // create an empty queue of integers

    // 1. Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "After pushing 10,20,30:\n";

    // Print front and back
    cout << "Front: " << q.front() << ", Back: " << q.back() << "\n";
    cout << "Size: " << q.size() << "\n\n";

    // 2. Pop element
    q.pop();
    cout << "After popping one element:\n";
    cout << "Front: " << q.front() << ", Back: " << q.back() << "\n";
    cout << "Size: " << q.size() << "\n\n";

    // 3. Push more elements
    q.push(40);
    q.push(50);
    cout << "After pushing 40,50:\n";
    cout << "Front: " << q.front() << ", Back: " << q.back() << "\n";
    cout << "Size: " << q.size() << "\n\n";

    // 4. Empty the queue completely
    cout << "Emptying the queue:\n";
    while(!q.empty()) {
        cout << "Popping: " << q.front() << "\n";
        q.pop();
    }
    cout << "Queue empty? " << (q.empty() ? "Yes" : "No") << "\n";

    return 0;
}
