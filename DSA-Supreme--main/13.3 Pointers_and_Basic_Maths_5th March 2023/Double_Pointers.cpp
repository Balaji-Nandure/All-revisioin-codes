#include<iostream>
using namespace std;

/*
Approach:
-----------
This code demonstrates the concept of pointers and double pointers in C++. 
It shows how to declare a variable, a pointer to that variable, and a pointer to the pointer (double pointer).
It then prints the values and addresses at each level to illustrate how pointers and double pointers work.

Better/Alternative Approaches (without code):
---------------------------------------------
1. Use functions to manipulate values using single and double pointers to show practical use-cases (e.g., swapping values, dynamic memory allocation).
2. Use dynamic memory allocation (new/delete) to show how pointers are used with heap memory.
3. Use const correctness to prevent accidental modification of data through pointers.
4. Use smart pointers (like std::unique_ptr, std::shared_ptr) for safer memory management in modern C++.
5. Add error checking and nullptr checks for robustness in real-world scenarios.

*/

int main(){
    int a = 5; // Declare an integer variable 'a' and initialize it with 5

    int *p = &a; // Declare a pointer 'p' and store the address of 'a' in it

    int **q = &p; // Declare a double pointer 'q' and store the address of pointer 'p' in it

    // Print the address of variable 'a'
    cout << "&a (Address of a): " << &a << endl;

    // Print the value of variable 'a'
    cout << "a (Value of a): " << a << endl;

    // Print the value of pointer 'p' (which is the address of 'a')
    cout << "p (Value of p = Address of a): " << p << endl;

    // Print the value pointed to by 'p' (which is the value of 'a')
    cout << "*p (Value at address stored in p): " << *p << endl;

    // Print the address of pointer 'p'
    cout << "&p (Address of pointer p): " << &p << endl;

    // Print the value of double pointer 'q' (which is the address of 'p')
    cout << "q (Value of q = Address of p): " << q << endl;

    // Print the value pointed to by 'q' (which is the value of 'p', i.e., address of 'a')
    cout << "*q (Value at address stored in q = Value of p = Address of a): " << *q << endl;

    // Print the value pointed to by the pointer pointed to by 'q' (i.e., value of 'a')
    cout << "**q (Value at address stored in *q = Value of a): " << **q << endl;

    // Print the address of double pointer 'q'
    cout << "&q (Address of double pointer q): " << &q << endl;

    return 0;
}

/*
Dry Run:
--------
Step 1: int a = 5; 
    - 'a' is created with value 5, suppose at address 0x100

Step 2: int *p = &a;
    - 'p' stores address of 'a' (0x100), suppose 'p' itself is at 0x200

Step 3: int **q = &p;
    - 'q' stores address of 'p' (0x200), suppose 'q' itself is at 0x300

Output (addresses are hypothetical):
    &a (Address of a): 0x100
    a (Value of a): 5
    p (Value of p = Address of a): 0x100
    *p (Value at address stored in p): 5
    &p (Address of pointer p): 0x200
    q (Value of q = Address of p): 0x200
    *q (Value at address stored in q = Value of p = Address of a): 0x100
    **q (Value at address stored in *q = Value of a): 5
    &q (Address of double pointer q): 0x300

This dry run shows how each pointer and double pointer relates to the variable and each other.
*/