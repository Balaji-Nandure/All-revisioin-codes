#include<iostream>
using namespace std;

/*
Approach:
-----------
This code demonstrates the difference between pass by reference and pass by value in C++. 
- Pass by reference allows the function to modify the original variable.
- Pass by value only modifies a local copy, leaving the original variable unchanged.

Better Alternatives / Detailed Approaches:
------------------------------------------
1. For more clarity, you can use 'const' with pass by value if you don't want to modify the value.
2. For large objects, prefer passing by reference (possibly const reference) to avoid unnecessary copying.
3. For functions that need to modify multiple variables, consider returning a struct or using multiple reference parameters.
4. Use modern C++ features like std::optional or std::tuple for returning multiple values.
*/

// Function to increment the value of x by reference (modifies original variable)
void solve(int &x){ 
    x++; // Increment the value of x (original variable 'a' in main will be changed)
}

// Function to increment the value of x by value (does NOT modify original variable)
void solve1(int x){ 
    x++; // Increment the local copy of x (original variable 'a' in main remains unchanged)
}

int main(){
    int a = 5; // Initialize variable a with value 5

    solve(a);  // Pass 'a' by reference, so 'a' becomes 6 after this call

    solve1(a); // Pass 'a' by value, so only a copy is incremented, 'a' remains 6

    cout << a << endl; // Output the value of 'a' (should print 6)

    return 0; // Indicate successful program termination
}

/*
Dry Run:
---------
Step 1: int a = 5;         // a = 5
Step 2: solve(a);          // a is passed by reference, so a = a + 1 => a = 6
Step 3: solve1(a);         // a is passed by value, so only a copy is incremented, a remains 6
Step 4: cout << a << endl; // Output: 6

Summary:
- After solve(a), a = 6
- After solve1(a), a = 6 (no change)
- Output is 6

*/