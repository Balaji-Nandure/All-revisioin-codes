/*
Approach:
-----------
This section covers the basic and advanced concepts of queue data structures, focusing on circular queues and deques.
We will discuss:
1. Understanding queue operations and their documentation.
2. Handling the "full" condition in circular queues, especially when the front index is ahead of the rear.
3. Implementing a circular queue using the modulus operator for efficient wrap-around.
4. Understanding and using double-ended queues (deque).

Below are the detailed explanations, code snippets, and alternatives.

1) // Read documentation of queue.
   // Logic: Understand the basic queue operations: enqueue (push), dequeue (pop), front, rear, isEmpty, isFull.
   // Approach: Use STL queue or implement your own. STL queue is FIFO and does not allow random access.
   // Example:
   /*
   #include <queue>
   std::queue<int> q;
   q.push(10); // enqueue
   q.pop();    // dequeue
   int f = q.front(); // get front element
   */

2) // Handle the case of full in case of circular queue when front is ahead of rear.
   // Logic: In a circular queue, the queue is full when (rear + 1) % size == front.
   // This handles the wrap-around when rear reaches the end and starts from 0.
   // Example:
   /*
   int size = 5;
   int front = 2, rear = 1;
   // After some operations, if (rear + 1) % size == front, queue is full.
   if ((rear + 1) % size == front) {
       // Queue is full
   }
   */

3) // Implement circular queue with the help of modulus operator.
   // Logic: Use modulus operator to wrap rear and front indices to the start when they reach the end.
   // This allows efficient use of space and avoids shifting elements.
   // Example Implementation:
   /*
   class CircularQueue {
       int *arr;
       int size;
       int front, rear;
   public:
       CircularQueue(int n) {
           size = n;
           arr = new int[size];
           front = rear = -1;
       }
       bool isFull() {
           return (front == (rear + 1) % size);
       }
       bool isEmpty() {
           return (front == -1);
       }
       void enqueue(int val) {
           if (isFull()) {
               // Queue is full
               return;
           }
           if (isEmpty()) {
               front = rear = 0;
           } else {
               rear = (rear + 1) % size;
           }
           arr[rear] = val;
       }
       void dequeue() {
           if (isEmpty()) {
               // Queue is empty
               return;
           }
           if (front == rear) {
               front = rear = -1;
           } else {
               front = (front + 1) % size;
           }
       }
   };
   */
   // Alternative: Use STL std::queue for simple queue, or std::deque for double-ended queue.

4) // Read documentation of deque.
   // Logic: Deque (double-ended queue) allows insertion and deletion from both ends.
   // Approach: Use STL std::deque for efficient operations at both ends.
   // Example:
   /*
   #include <deque>
   std::deque<int> dq;
   dq.push_front(10); // insert at front
   dq.push_back(20);  // insert at rear
   dq.pop_front();    // remove from front
   dq.pop_back();     // remove from rear
   */

-----------------
Better Alternatives:
-----------------
- For most use-cases, prefer STL containers (std::queue, std::deque) for reliability and efficiency.
- For fixed-size circular buffer, use std::vector with manual index management as shown above.
- For thread-safe queues, use concurrent queue implementations.

-----------------
Dry Run Example (Circular Queue of size 5):
-----------------
Initial: front = -1, rear = -1
enqueue(10): front = 0, rear = 0, arr[0]=10
enqueue(20): rear = 1, arr[1]=20
enqueue(30): rear = 2, arr[2]=30
dequeue(): front = 1
enqueue(40): rear = 3, arr[3]=40
enqueue(50): rear = 4, arr[4]=50
enqueue(60): (rear+1)%5 == front => (4+1)%5==1 => 0==1 (false), so rear=0, arr[0]=60 (overwrites 10 if not handled)
If (rear+1)%size == front, queue is full, so do not enqueue.

*/
