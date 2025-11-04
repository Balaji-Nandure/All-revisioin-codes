// Approach: Implements a circular queue using a fixed-size array. Supports enqueue (push), dequeue (pop), and display. Uses modulo arithmetic to wrap indices.

#include<iostream>
using namespace std;

class CircularQueue {
public:
    int size;   // size of circular queue
    int *arr;   // pointer to integer array
    int front;  // index of front element
    int rear;   // index of rear element

    CircularQueue(int n) {                  // initialize size, array, front and rear
        size = n;
        arr = new int[size];
        front = -1;                         // start as empty queue
        rear = -1;                          // start as empty queue
    }

    void push(int data) {                   // insert new element at rear
        if ((front == 0 && rear == size - 1) || (rear + 1) % size == front) {
            cout << "Queue is full" << endl;    // if queue full, print message
            return;
        }
        else if (front == -1) {                 // if empty queue
            front = rear = 0;                   // first element at 0
            arr[rear] = data;
        }
        else {
            rear = (rear + 1) % size;           // advance rear using modulo
            arr[rear] = data;
        }
    }

    void pop() {                            // remove element from front
        if (front == -1) {                      // empty case
            cout << "Queue is empty" << endl;   // notify empty
            return;
        }
        else if (front == rear) {               // only one element
            arr[front] = -1;
            front = rear = -1;                  // reset to empty state
        }
        else {
            arr[front] = -1;                    // remove front value
            front = (front + 1) % size;         // move front forward
        }
    }

    void display() {                        // print current queue
        if (front == -1) {                      // if empty, notify
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;                          // start from front
        while (true) {
            cout << arr[i] << " ";              // print element
            if (i == rear)
                break;
            i = (i + 1) % size;                 // move to next position
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5);                    // create a queue with size 5
    cq.push(10);                            // enqueue 10
    cq.push(20);                            // enqueue 20
    cq.push(30);                            // enqueue 30
    cq.push(40);                            // enqueue 40
    cq.push(50);                            // enqueue 50
    cq.push(60);                            // queue full, will print message
    cq.display();                           // display current queue

    cq.pop();                               // dequeue front
    cq.display();                           // display updated queue

    cq.push(60);                            // enqueue 60 (should wrap)
    cq.display();                           // display

    cq.pop();                               // dequeue
    cq.pop();                               // dequeue
    cq.display();                           // final display

    return 0;                               // exit program
}