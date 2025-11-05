/*
Circular Queue Implementation
-----------------------------
- Fixed-size array that behaves circularly.
- Operations:
    enqueue(x): insert element at rear
    dequeue(): remove element from front
    front(): access front element
    rear(): access rear element
    isEmpty(): check if empty
    isFull(): check if full
    size(): number of elements

Time Complexity: O(1) for all operations
*/

#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
private:
    int *arr;
    int frontIndex, rearIndex, count, capacity;

public:
    // Constructor
    CircularQueue(int size) {
        arr = new int[size];
        capacity = size;
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    // Destructor
    ~CircularQueue() { delete[] arr; }

    bool isEmpty() { return count == 0; }
    bool isFull() { return count == capacity; }
    int size() { return count; }

    // Add element at rear
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << val << "\n";
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = val;
        count++;
    }

    // Remove element from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    // Get front element
    int front() {
        if (isEmpty()) throw runtime_error("Queue is empty!");
        return arr[frontIndex];
    }

    // Get rear element
    int rear() {
        if (isEmpty()) throw runtime_error("Queue is empty!");
        return arr[rearIndex];
    }

    // Display elements
    void print() {
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue q(5); // queue with capacity 5

    // Test enqueue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();

    // Test dequeue
    q.dequeue();
    q.dequeue();
    q.print();

    // Add more elements
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // should show full when exceeding
    q.print();

    cout << "Front: " << q.front() << ", Rear: " << q.rear() << "\n";
    cout << "Size: " << q.size() << "\n";

    // Empty the queue
    while (!q.isEmpty()) {
        cout << "Dequeuing: " << q.front() << "\n";
        q.dequeue();
    }
    cout << "Queue empty? " << (q.isEmpty() ? "Yes" : "No") << "\n";
}
