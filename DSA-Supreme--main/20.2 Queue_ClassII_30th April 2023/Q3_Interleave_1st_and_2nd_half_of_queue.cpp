/*
Approach Used:
--------------
This code interleaves the first half and the second half of a queue.
Given a queue of even length: [1,2,3,4,5,6,7,8], the output will be: [1,5,2,6,3,7,4,8].
The approach is:
1. Move the first half of the queue into a temporary queue.
2. Alternately push elements from the temporary queue and the remaining original queue back into the original queue.
3. If the queue has odd length, handle the last element.

Better Alternative Approaches:
-----------------------------
1. Using Stack for O(1) extra space (for interleaving, but only works for even length):
   - Push first half into stack, then enqueue back, then again push first half into stack, then interleave.
   - More complex, but can be more space efficient.
2. Using only one queue and recursion (not recommended for large queues due to stack overflow risk).
3. Using STL deque for more flexibility.

Alternative Code (using STL deque):
-----------------------------------
    #include <deque>
    void interleaveQueueWithDeque(queue<int>& q) {
        int n = q.size();
        deque<int> dq;
        for(int i=0; i<n/2; ++i) {
            dq.push_back(q.front());
            q.pop();
        }
        while(!dq.empty()) {
            q.push(dq.front());
            dq.pop_front();
            q.push(q.front());
            q.pop();
        }
        if(n%2) q.push(q.front()), q.pop();
    }

Dry Run Example:
----------------
Input:  [10, 20, 30, 40, 50, 60, 70, 80]
Step 1: newQueue = [10,20,30,40], originalQueue = [50,60,70,80]
Step 2: Interleave:
    Push 10 (from newQueue), then 50 (from originalQueue)
    Push 20 (from newQueue), then 60 (from originalQueue)
    Push 30 (from newQueue), then 70 (from originalQueue)
    Push 40 (from newQueue), then 80 (from originalQueue)
Result: [10,50,20,60,30,70,40,80]

If odd: [1,2,3,4,5] => [1,4,2,5,3]

Code with detailed comments:
*/

#include<iostream>
#include<queue>
using namespace std;

// Function to interleave the first and second half of the queue
void interleaveQueue(queue<int>& originalQueue) {
    // Edge case: If queue is empty or has only one element, nothing to do
    if(originalQueue.empty() || originalQueue.size() == 1){
        return;
    }

    int n = originalQueue.size();      // Total number of elements in the queue
    int k = n / 2;                     // Number of elements in the first half
    int count = 0;                     // Counter for moving elements
    queue<int> newQueue;               // Temporary queue to store first half

    // Step 1: Move first half elements from originalQueue to newQueue
    while(count < k && !originalQueue.empty()){
        int temp = originalQueue.front();   // Get the front element
        originalQueue.pop();                // Remove it from originalQueue
        newQueue.push(temp);                // Push it into newQueue
        count++;
    }

    // Step 2: Interleave elements from newQueue and originalQueue
    // For each pair, push one from newQueue (first half), then one from originalQueue (second half)
    while(!newQueue.empty() && !originalQueue.empty()){
        int first = newQueue.front();       // Get element from first half
        newQueue.pop();
        originalQueue.push(first);          // Push it to the back of originalQueue

        int second = originalQueue.front(); // Get element from second half
        originalQueue.pop();
        originalQueue.push(second);         // Push it to the back of originalQueue
    }

    // Step 3: If the queue has odd number of elements, push the last remaining element to the back
    if(n & 1){ // If n is odd
        int element = originalQueue.front();
        originalQueue.pop();
        originalQueue.push(element);
    }
}

int main(){
    queue<int> q;
    // Example input: 8 elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    interleaveQueue(q);

    // Printing the interleaved queue
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // Dry Run Output for above input:
    // 10 50 20 60 30 70 40 80

    return 0;
}

/*
Dry Run for Odd Length:
-----------------------
Input: [1,2,3,4,5]
Step 1: newQueue = [1,2], originalQueue = [3,4,5]
Step 2: Interleave:
    Push 1 (from newQueue), then 3 (from originalQueue)
    Push 2 (from newQueue), then 4 (from originalQueue)
Step 3: One element left (5), push to back
Result: [1,3,2,4,5]
*/