#include <iostream> // for input/output streams
using namespace std; // use standard C++ namespace

class Stack {
private:
    int top;        // index of the top element in the stack
    int capacity;   // maximum size of the stack
    int* arr;       // dynamic array to store stack elements

public:
    // Constructor to initialize stack
    Stack(int size) {
        capacity = size;                  // set stack capacity
        arr = new int[capacity];          // allocate array of given capacity
        top = -1;                         // initialize top to -1 (empty stack)
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;                     // deallocate dynamically allocated array
    }

    // Push operation to add element to stack
    void push(int value) {
        if (top == capacity - 1) {        // check if stack is full
            cout << "Stack Overflow! Cannot push " << value << endl; // overflow message
            return;                       // exit the function
        }
        arr[++top] = value;               // increment top and insert element
        cout << value << " pushed into stack." << endl; // confirmation message
    }

    // Pop operation to remove element from stack
    void pop() {
        if (isEmpty()) {                  // check if stack is empty
            cout << "Stack Underflow! Cannot pop." << endl; // underflow message
            return;                       // exit the function
        }
        cout << arr[top--] << " popped from stack." << endl; // print and remove top element
    }

    // Peek operation to view top element without removing
    int peek() {
        if (isEmpty()) {                  // check if stack is empty
            cout << "Stack is empty!" << endl; // print warning
            return -1;                    // return invalid value for empty stack
        }
        return arr[top];                  // return current top element
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;                 // return true if top is -1 (empty)
    }

    // Display all elements in stack
    void display() {
        if (isEmpty()) {                  // check if stack is empty
            cout << "Stack is empty!" << endl; // print message
            return;                       // exit function
        }
        cout << "Stack elements (top to bottom): "; // print label
        for (int i = top; i >= 0; i--) {  // loop from top to bottom
            cout << arr[i] << " ";        // print element at index i
        }
        cout << endl;                     // newline after displaying stack
    }
};

// Entry point of program, tests the Stack
int main() {
    Stack s(5);  // create stack of size 5

    s.push(10);  // push 10 to stack
    s.push(20);  // push 20 to stack
    s.push(30);  // push 30 to stack
    s.display(); // display current stack

    cout << "Top element is: " << s.peek() << endl; // show element at top

    s.pop();      // pop top element from stack
    s.display();  // display current stack

    s.push(40);   // push 40 to stack
    s.push(50);   // push 50 to stack
    s.push(60);   // push 60 to stack
    s.push(70);   // push 70 to stack (should trigger overflow)
    s.display();  // display current stack

    while (!s.isEmpty()) { // loop to pop until stack is empty
        s.pop();           // pop top element
    }
    s.pop(); // attempt to pop from empty stack (should trigger underflow)

    return 0; // indicate successful completion
}
