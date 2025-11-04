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

    void pushFront(int data)           // insert element at front
    {
        if (isFull())                  // if full: cannot insert
        {
            cout << "Q is full, cannot insert at front" << endl;
            return;
        }
        else if (isEmpty())            // first element insertion
        {
            front = rear = 0;
        }
        else if (front == 0)           // wrap front to end
        {
            front = size - 1;
        }
        else
        {
            front = (front - 1 + size) % size; // move front backward circularly
        }
        arr[front] = data;             // place element
    }

    void popFront()                    // remove element from front
    {
        if (isEmpty())                 // if empty: cannot pop
        {
            cout << "Q is empty, cannot pop from front" << endl;
            return;
        }
        else if (front == rear)        // only one element case: empty deque after pop
        {
            arr[front] = -1;
            front = rear = -1;
        }
        else if (front == size - 1)    // wrap front to start
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front = (front + 1) % size; // move front forward circularly
        }
    }

    void popRear()                     // remove element from rear
    {
        if (isEmpty())                 // if empty: cannot pop
        {
            cout << "Q is empty, cannot pop from rear" << endl;
            return;
        }
        else if (front == rear)        // only one element case: empty deque after pop
        {
            arr[rear] = -1;
            front = rear = -1;
        }
        else if (rear == 0)            // wrap rear to end
        {
            arr[rear] = -1;
            rear = size - 1;
        }
        else
        {
            arr[rear] = -1;
            rear = (rear - 1 + size) % size; // move rear backward circularly
        }
    }

    void print()                       // print the contents of the deque
    {
        cout << "Deque state: ";
        if (isEmpty())                 // if empty: print "Empty"
        {
            cout << "Empty" << endl;
            return;
        }
        int i = front;                 // start from front
        while (true)
        {
            cout << arr[i] << " ";     // print element
            if (i == rear)             // stop at rear
                break;
            i = (i + 1) % size;        // move forward circularly
        }
        cout << endl;
    }
};

int main()
{
    Deque dq(10);                      // create deque of size 10

    dq.pushRear(10);                   // insert 10 at rear
    dq.pushRear(20);                   // insert 20 at rear
    dq.pushRear(30);                   // insert 30 at rear
    dq.pushRear(40);                   // insert 40 at rear
    dq.pushRear(50);                   // insert 50 at rear
    dq.pushRear(60);                   // insert 60 at rear
    dq.pushRear(70);                   // insert 70 at rear
    dq.pushRear(80);                   // insert 80 at rear
    dq.pushRear(90);                   // insert 90 at rear
    dq.pushRear(100);                  // insert 100 at rear

    dq.print();                        // print deque state

    dq.popFront();                     // remove front element
    dq.pushFront(5);                   // insert 5 at front
    dq.print();                        // print deque state

    dq.popRear();                      // remove rear element
    dq.print();                        // print deque state

    return 0;                          // end program
}