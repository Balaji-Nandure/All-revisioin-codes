/*
Approach:
-----------
- The program demonstrates how to use the address-of operator (&) in C++.
- It declares an integer variable and prints its memory address using the & operator.
- The address is displayed in hexadecimal format, which shows where the variable is stored in memory.
*/

#include<iostream> // Include input-output stream for cout
using namespace std; // Use standard namespace to avoid std:: prefix

int main(){
    int a = 5; // Declare an integer variable 'a' and initialize it with value 5
    cout << "Address of a is : " << &a; // Print the address of variable 'a' using the address-of operator (&)
    return 0; // Indicate successful program termination
}

/*
Dry Run:
-----------
Step 1: Program starts, main() is called.
Step 2: int a = 5; // 'a' is declared and assigned value 5. Suppose its address is 0x61ff08 (actual address will vary).
Step 3: cout prints "Address of a is : " followed by the address of 'a' (e.g., 0x61ff08).
Step 4: main returns 0, program ends.

Output (example):
Address of a is : 0x61ff08
*/