/*
Approach Used:
---------------
We are implementing two stacks in a single array. 
- Stack1 starts from the left (index 0) and grows towards the right.
- Stack2 starts from the right (last index) and grows towards the left.
- Two pointers, top1 and top2, are used to keep track of the tops of Stack1 and Stack2 respectively.
- Overflow occurs if both stacks try to use the same space (i.e., top1 + 1 == top2).
- Underflow occurs if we try to pop from an empty stack.

Advantages:
- Efficient use of space: Both stacks can use the array as long as there is space.
- No fixed division of array size between stacks.

Better Alternatives:
--------------------
1. Dynamic Array: Use std::vector for dynamic resizing, but that loses the fixed-size array constraint.
2. Linked List: Use two separate linked lists for two stacks, but that uses extra memory for pointers.
3. Circular Array: Not suitable for stacks, more for queues.

Alternative Code (using std::vector for dynamic size):
------------------------------------------------------
    // vector<int> arr;
    // int top1, top2, size;
    // Stack(int size) {
    //     arr.resize(size);
    //     this->size = size;
    //     top1 = -1;
    //     top2 = size;
    // }
    // // Rest logic remains same

*/

#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;      // Pointer to the array that holds both stacks
    int top1;      // Top pointer for Stack 1 (grows from left to right)
    int top2;      // Top pointer for Stack 2 (grows from right to left)
    int size;      // Total size of the array

    // Constructor to initialize the stack
    Stack(int size){
        arr = new int[size];      // Allocate memory for the array
        this->size = size;        // Set the size
        top1 = -1;                // Initialize top1 to -1 (Stack1 is empty)
        top2 = size;              // Initialize top2 to size (Stack2 is empty)
    }

    // Push operation for Stack 1
    void push1(int data){
        // Check if there is space between top1 and top2
        if(top2 - top1 == 1){
            cout<<"Overflow (Stack1)"<<endl; // No space left for Stack1
        }
        else{
            top1++;                 // Move top1 to next position
            arr[top1] = data;       // Insert data at top1
        }
    }

    // Push operation for Stack 2
    void push2(int data){
        // Check if there is space between top1 and top2
        if(top2 - top1 == 1){
            cout<<"Overflow (Stack2)"<<endl; // No space left for Stack2
        }
        else{
            top2--;                 // Move top2 to previous position
            arr[top2] = data;       // Insert data at top2
        }
    }

    // Pop operation for Stack 1
    void pop1(){
        if(top1 == -1){
            cout<<"Underflow (Stack1)"<<endl; // Stack1 is empty
        }
        else{
            // Optionally, clear the value: arr[top1] = 0;
            top1--;                 // Move top1 back (remove top element)
        }
    }

    // Pop operation for Stack 2
    void pop2(){
        if(top2 == size){
            cout<<"Underflow (Stack2)"<<endl; // Stack2 is empty
        }
        else{
            // Optionally, clear the value: arr[top2] = 0;
            top2++;                 // Move top2 forward (remove top element)
        }
    }

    // Utility function to print the current state of the array
    void print(){
        cout << "Array: ";
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Stack1 (0 to " << top1 << "): ";
        for(int i = 0; i <= top1; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "Stack2 (" << top2 << " to " << size-1 << "): ";
        for(int i = top2; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Stack s(6);           // Create a stack of size 6

    s.push1(10);          // Stack1: 10
    s.push2(20);          // Stack2: 20
    s.push1(30);          // Stack1: 10, 30
    s.push2(40);          // Stack2: 40, 20
    s.push1(50);          // Stack1: 10, 30, 50
    s.push2(60);          // Stack2: 60, 40, 20

    s.print();            // Print the current state of both stacks

    // Uncomment below to test overflow
    // s.push1(70);       // Should print overflow

    // Uncomment below to test underflow
    // s.pop1(); s.pop1(); s.pop1(); s.pop1(); // Last pop should print underflow

    return 0;
}

/*
Dry Run:
--------
Stack s(6);

Initial: arr = [_, _, _, _, _, _], top1 = -1, top2 = 6

s.push1(10): top1=0, arr[0]=10
    arr = [10, _, _, _, _, _], top1=0, top2=6

s.push2(20): top2=5, arr[5]=20
    arr = [10, _, _, _, _, 20], top1=0, top2=5

s.push1(30): top1=1, arr[1]=30
    arr = [10, 30, _, _, _, 20], top1=1, top2=5

s.push2(40): top2=4, arr[4]=40
    arr = [10, 30, _, _, 40, 20], top1=1, top2=4

s.push1(50): top1=2, arr[2]=50
    arr = [10, 30, 50, _, 40, 20], top1=2, top2=4

s.push2(60): top2=3, arr[3]=60
    arr = [10, 30, 50, 60, 40, 20], top1=2, top2=3

Now, top1=2, top2=3, so next push1 or push2 will cause overflow.

print() will show:
Array: 10 30 50 60 40 20 
Stack1 (0 to 2): 10 30 50 
Stack2 (3 to 5): 60 40 20 
*/