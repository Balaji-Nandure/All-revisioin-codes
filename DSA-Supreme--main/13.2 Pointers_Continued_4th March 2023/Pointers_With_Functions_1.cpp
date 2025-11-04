#include<iostream>
using namespace std;

/*
Approach Used:
---------------
- The code demonstrates how to use pointers to modify the value of a variable inside a function.
- By passing the address of a variable to a function, we can directly change its value in the calling function (main).
- This is known as "pass by reference" using pointers in C++.

Better/Alternative Approaches (without code):
---------------------------------------------
1. Pass by Reference (using reference variables):
   - Instead of passing a pointer, you can pass the variable by reference (using '&' in function parameter).
   - This is safer and more readable in C++.
2. Return the modified value:
   - Instead of modifying in place, return the new value from the function and assign it in main.
3. Use smart pointers (for dynamic memory):
   - If dynamic memory is involved, prefer smart pointers (like std::unique_ptr) for better memory management.
4. Add input validation:
   - Check for nullptr before dereferencing the pointer to avoid undefined behavior.

*/

// Function to increment the value pointed by p by 10
void solve(int *p){
    if(p != nullptr) { // Check for nullptr to avoid undefined behavior
        *p = *p + 10; // Dereference pointer and increment the value by 10
    }
    // else, do nothing or handle error (not needed here as we control the input)
}

int main(){
    int a = 5; // Initialize integer variable 'a' with value 5

    int *ptr = &a; // Create a pointer 'ptr' and store the address of 'a'

    solve(ptr); // Pass the pointer to function 'solve' to modify 'a' via its address

    cout << a << endl; // Output the modified value of 'a' (should be 15)

    return 0; // Indicate successful program termination
}

/*
Dry Run:
--------
1. a = 5
2. ptr = &a (ptr holds address of a)
3. solve(ptr) is called:
   - p points to a
   - *p = *p + 10 => a = 5 + 10 = 15
4. cout << a prints 15

Summary:
--------
- The value of 'a' is modified inside the function using its pointer.
- Output: 15
*/