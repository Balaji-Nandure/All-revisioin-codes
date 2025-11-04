/*
Approach:
-----------
This code demonstrates the concept of reference variables in C++. 
A reference variable acts as an alias for another variable, allowing both names to refer to the same memory location.
Any modification through the reference variable directly affects the original variable.

Better/Alternative Approaches (in comments):
--------------------------------------------
1. Instead of using reference variables, pointers can be used to achieve similar functionality, but with more explicit memory management.
2. For more complex scenarios, such as function parameter passing, references are preferred over pointers for safety and clarity.
3. In modern C++, using 'const' references is a good practice when you don't want to modify the original variable.
4. For large objects, passing by reference avoids unnecessary copying and improves performance.

Code with detailed comments:
---------------------------
*/

#include<iostream>
using namespace std;

int main(){
    int a = 5;           // Declare and initialize integer variable 'a' with value 5

    int &b = a;          // Create reference variable 'b' which refers to 'a'
                         // Now, 'b' is just another name for 'a'

    cout << a << endl;   // Output the value of 'a' (prints 5)
    cout << b << endl;   // Output the value of 'b' (also prints 5, since 'b' is an alias for 'a')

    b++;                 // Increment the value of 'b' by 1
                         // Since 'b' is a reference to 'a', 'a' is also incremented

    cout << a << endl;   // Output the value of 'a' after increment (prints 6)
    cout << b << endl;   // Output the value of 'b' after increment (also prints 6)

    return 0;            // Indicate successful program termination
}

// int main(){
//     for(int i = 0; i < 10000000; ++i) {
//         cout << i + 1 << " dipti" << endl;
//     }
// }

/*
Dry Run:
---------
Step 1: int a = 5;         // a = 5
Step 2: int &b = a;        // b is reference to a, so b = 5 (same memory as a)
Step 3: cout << a;         // Output: 5
Step 4: cout << b;         // Output: 5
Step 5: b++;               // a = 6, b = 6 (since both refer to same memory)
Step 6: cout << a;         // Output: 6
Step 7: cout << b;         // Output: 6

Summary:
--------
- Reference variable 'b' is just another name for 'a'.
- Any change to 'b' reflects in 'a' and vice versa.
- Useful for efficient memory usage and parameter passing in functions.
*/




