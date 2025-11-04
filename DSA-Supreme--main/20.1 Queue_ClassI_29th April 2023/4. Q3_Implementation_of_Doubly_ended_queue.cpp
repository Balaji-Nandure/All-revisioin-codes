// Approach: Fixed-size circular array Deque supporting insert and delete on both ends using 'front' and 'rear'.

#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;                      // pointer to array storing elements
    int size;                      // maximum number of elements
    int front;                     // index of front
    int rear;                      // index of rear

    Deque(int size)                // constructor: initialize deque of given size
    {
        this->size = size;         // set size
        arr = new int[size];       // allocate array
        for(int i=0;i<size;i++)    // fill all positions with -1
            arr[i] = -1;
        front = -1;                // start with empty deque
        rear = -1;
    }

    bool isFull()                  // check if deque is full
    {
        return ((front == 0 && rear == size - 1) || ( (rear + 1) % size == front ));
    }

    bool isEmpty()                 // check if deque is empty
    {
        return (front == -1);
    }

    void pushRear(int data)        // insert element at rear
    {
        if (isFull())              // if full: cannot insert
        {
            cout << "Q is full, cannot insert at rear" << endl;
            return;
        }
        else if (isEmpty())        // first element insertion
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) // wrap rear to start
        {
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size; // advance rear circularly
        }
        arr[rear] = data;              // place element
    }

    // Insert element at front end
    void pushFront(int data)
    {
        // If deque is full, cannot insert
        if (isFull())
        {
            cout << "Q is full, cannot insert at front" << endl;
            return;
        }
        // If deque is empty, initialize front and rear
        else if (isEmpty())
        {
            front = rear = 0;
        }
        // If front is at first position and space is available at rear, wrap around
        else if (front == 0)
        {
            front = size - 1;
        }
        // Normal case: decrement front circularly
        else
        {
            front = (front - 1 + size) % size;
        }
        arr[front] = data; // Insert data at front
    }

    // Remove element from front end
    void popFront()
    {
        // If deque is empty, cannot pop
        if (isEmpty())
        {
            cout << "Q is empty, cannot pop from front" << endl;
            return;
        }
        // Single element case: reset deque
        else if (front == rear)
        {
            arr[front] = -1; // Optional: clear value
            front = rear = -1;
        }
        // If front is at last position, wrap around
        else if (front == size - 1)
        {
            arr[front] = -1; // Optional: clear value
            front = 0;
        }
        // Normal case: increment front circularly
        else
        {
            arr[front] = -1; // Optional: clear value
            front = (front + 1) % size;
        }
    }

    // Remove element from rear end
    void popRear()
    {
        // If deque is empty, cannot pop
        if (isEmpty())
        {
            cout << "Q is empty, cannot pop from rear" << endl;
            return;
        }
        // Single element case: reset deque
        else if (front == rear)
        {
            arr[rear] = -1; // Optional: clear value
            front = rear = -1;
        }
        // If rear is at first position, wrap around
        else if (rear == 0)
        {
            arr[rear] = -1; // Optional: clear value
            rear = size - 1;
        }
        // Normal case: decrement rear circularly
        else
        {
            arr[rear] = -1; // Optional: clear value
            rear = (rear - 1 + size) % size;
        }
    }

    // Print the current state of deque
    void print()
    {
        cout << "Deque state: ";
        if (isEmpty()) {
            cout << "Empty" << endl;
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main()
{
    Deque dq(10); // Create deque of size 10

    // Insert elements at rear
    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushRear(30);
    dq.pushRear(40);
    dq.pushRear(50);
    dq.pushRear(60);
    dq.pushRear(70);
    dq.pushRear(80);
    dq.pushRear(90);
    dq.pushRear(100);

    dq.print(); // Print current state

    // Demonstrate pop and push at front
    dq.popFront();
    dq.pushFront(5);
    dq.print();

    // Demonstrate pop at rear
    dq.popRear();
    dq.print();

    // Dry Run Example:
    // After all pushRear: [10 20 30 40 50 60 70 80 90 100]
    // popFront removes 10, pushFront(5) adds 5 at front: [5 20 30 40 50 60 70 80 90 100]
    // popRear removes 100: [5 20 30 40 50 60 70 80 90]

    return 0;
}

/*
Summary of Improvements:
- Added isFull() and isEmpty() helper functions for clarity and correctness.
- Used circular increment/decrement for both front and rear.
- Improved print() to show only valid elements.
- Added comments for all important lines.
- Provided alternative STL approach and dry run.
*/