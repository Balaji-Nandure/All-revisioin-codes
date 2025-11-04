

#include<iostream>
#include<stack> // Import STL stack container
using namespace std;

int main(){
    // Create an empty stack of integers
    stack<int> s;

    // Insert elements into the stack (push operation)
    s.push(10); // Stack: [10]
    s.push(20); // Stack: [10, 20]
    s.push(30); // Stack: [10, 20, 30]
    s.push(40); // Stack: [10, 20, 30, 40]

    // Remove the top element from the stack (pop operation)
    s.pop(); // Removes 40, Stack: [10, 20, 30]

    // Access the topmost element (peek operation)
    cout << "Topmost element = " << s.top() << endl; // Should print 30

    // Get the current size of the stack
    cout << "Size of stack = " << s.size() << endl; // Should print 3

    // Check if the stack is empty
    if(s.empty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Stack is not empty" << endl;
    }

    // Print and remove all elements from the stack (LIFO order)
    cout << "Printing stack elements (top to bottom):" << endl;
    while(!s.empty()){ // Continue until stack is empty
        cout << s.top() << endl; // Print the top element
        s.pop(); // Remove the top element
    }

    // After this loop, the stack is empty

    return 0;
}

/*
Dry Run:
--------
Step-by-step stack content:
1. s = []
2. s.push(10) -> [10]
3. s.push(20) -> [10, 20]
4. s.push(30) -> [10, 20, 30]
5. s.push(40) -> [10, 20, 30, 40]
6. s.pop()    -> [10, 20, 30]
7. s.top()    -> 30
8. s.size()   -> 3
9. s.empty()  -> false
10. Print and pop:
    - 30 (pop) -> [10, 20]
    - 20 (pop) -> [10]
    - 10 (pop) -> []
11. s.empty() -> true
*/