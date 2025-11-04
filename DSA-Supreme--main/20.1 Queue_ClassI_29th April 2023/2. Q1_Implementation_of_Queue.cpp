#include<iostream> // Include header for input/output
using namespace std; // Use standard namespace

// Queue class for basic queue implementation
class Queue{
    public:
    int *arr;    // Array to store queue elements
    int front;   // Index of front element
    int rear;    // Index of next insertion
    int size;    // Maximum size of queue

    // Constructor to initialize queue
    Queue(int n){
        size = n;           // Set size
        front = 0;          // Set front to 0
        rear = 0;           // Set rear to 0
        arr = new int[size]; // Allocate array of given size
    }

    // Destructor to free dynamic memory
    ~Queue() {
        delete[] arr;       // Free allocated memory
    }

    // Insert element at the rear
    void push(int data){
        if(rear == size){   // If queue is full
            cout<<"Full queue"<<endl; // Print message
        }
        else{
            arr[rear] = data; // Insert at rear
            rear++;           // Increment rear index
        }
    }

    // Remove element from front
    void pop(){
        if(front == rear){    // If queue is empty
            cout<<"Empty queue"<<endl; // Print message
        }
        else{
            front++;           // Increment front index to remove element
            if(front == rear){ // If queue becomes empty after removal
                front = 0;     // Reset front and rear to 0
                rear = 0;
            }
        }
    }

    // Get the front element
    int getFront(){
        if(front == rear){    // If queue is empty
            return -1;        // Return -1 for empty queue
        }
        else{
            return arr[front]; // Return front element
        }
    }

    // Get current size of queue
    int getSize(){
        return rear - front;   // Number of elements
    }

    // Check if queue is empty
    bool isEmpty(){
        return (front == rear); // Returns true if empty
    }
};

int main(){
    Queue q(10);          // Create a queue of size 10

    q.push(5);            // Push 5
    q.push(10);           // Push 10
    q.push(15);           // Push 15
    q.push(20);           // Push 20

    cout<<"Size of queue = "<<q.getSize()<<endl; // Print size

    q.pop();              // Pop front element

    cout<<"Size of queue = "<<q.getSize()<<endl; // Print size

    cout<<"Front element = "<<q.getFront()<<endl; // Print front

    if(q.isEmpty()){      // Check if queue is empty
        cout<<"Empty queue"<<endl;    // Print if empty
    }
    else{
        cout<<"Not empty"<<endl;      // Print if not empty
    }
    return 0;           // End program
}
