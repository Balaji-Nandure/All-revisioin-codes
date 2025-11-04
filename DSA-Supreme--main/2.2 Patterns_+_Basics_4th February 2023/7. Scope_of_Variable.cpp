/*
Approach:
- This program demonstrates the concept of variable scope in C++.
- It shows how variables declared inside a block (like an if statement) are local to that block and do not affect variables with the same name outside the block.
- It also shows the use of a global variable and how it can be accessed inside the main function.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int global = 6; // Declare and initialize a global variable 'global' with value 6

int main(){ // Main function: program execution starts here

    int a; // Declare an integer variable 'a' (uninitialized)
    int b = 5; // Declare and initialize integer variable 'b' with value 5

    b = 10; // Assign a new value (10) to variable 'b'

    // int b = 6; // This line would cause a redefinition error if uncommented

    if(true){ // Start of a new block (if statement), always true
        int b = 7; // Declare a new variable 'b' local to this block, initialized to 7
        cout << b << endl; // Print the value of 'b' inside the if block (outputs 7)
    }

    cout << b << endl; // Print the value of 'b' in the main function scope (outputs 10)

    cout << global << endl; // Print the value of the global variable 'global' (outputs 6)

    return 0; // Indicate successful program termination
}

/*
Dry Run:

Step 1:
global = 6

main() starts:
a is declared (uninitialized)
b = 5
b = 10

if(true) block:
    int b = 7 (this 'b' is local to the if block)
    cout << b; // prints 7

After if block:
cout << b; // prints 10 (the 'b' in main scope)

cout << global; // prints 6 (global variable)

Final Output:
7
10
6
*/