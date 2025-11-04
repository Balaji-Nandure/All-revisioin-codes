/*
Approach:
- We want to add two numbers using a function in C++.
- We'll declare the function before main, define it after main, and call it from main.
- We'll use function declaration, definition, and invocation to demonstrate function order in C++.
*/

#include<iostream> // Include input-output stream for cout and cin
using namespace std; // Use standard namespace to avoid std:: prefix

// Function Declaration: Tells the compiler that a function named 'add' exists
int add(int a, int b); 

int main(){
    // Function Invocation: Calls the 'add' function with arguments 2 and 3
    cout << add(2, 3); // Output the result of add(2,3) which should be 5
    return 0; // Return 0 to indicate successful execution
}

// Function Definition: Actual implementation of the 'add' function
int add(int a, int b){ 
    // Returns the sum of a and b
    return (a + b);
}

/*
Dry Run:
Step 1: Program starts, main() is called.
Step 2: add(2, 3) is invoked.
    - a = 2, b = 3
    - return (2 + 3) => 5
Step 3: cout prints 5 to the console.
Step 4: main returns 0, program ends.

Output:
5
*/