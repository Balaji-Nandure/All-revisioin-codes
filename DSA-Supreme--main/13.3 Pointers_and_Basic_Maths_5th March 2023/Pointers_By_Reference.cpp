/*
Approach:
-----------
- Demonstrate how passing a pointer by reference allows us to modify the pointer itself (i.e., its address), not just the value it points to.
- Show the effect of pointer arithmetic when the pointer is passed by reference to a function.

Better Alternatives (in comments):
-----------------------------------
1. Instead of incrementing the pointer (which may lead to undefined behavior if not pointing to an array), demonstrate pointer reference by changing what it points to (e.g., point to another variable).
2. If the goal is to modify the value pointed to, pass pointer by value and dereference inside the function.
3. For safety, always ensure pointer arithmetic is done within valid memory (e.g., within an array bounds).

*/

#include<iostream>
using namespace std;

// Function to modify the pointer itself by reference
void solve(int*& p){
    // Logic: Increment the pointer to point to the next integer in memory
    // Since p is passed by reference, the change will reflect in the caller
    p = p + 1; // WARNING: Only safe if p points to an array or valid memory block
}

int main(){
    int a = 5; // Declare an integer variable
    int *p = &a; // Pointer p initialized to address of a

    // Print the address stored in p before modification
    cout << "Before: " << p << endl; // Shows address of a

    solve(p); // Pass pointer by reference to modify its address

    // Print the address stored in p after modification
    cout << "After: " << p << endl; // Shows address after increment (may be invalid)

    // Note: Accessing *p now is undefined behavior, as p may not point to valid memory

    return 0;
}

/*
Dry Run:
---------
1. int a = 5;           // a is stored at address, say, 0x100
2. int *p = &a;         // p = 0x100
3. cout << p;           // Output: Before: 0x100
4. solve(p);            // p is passed by reference, inside solve: p = p + 1;
                        // Now p = 0x100 + sizeof(int) = 0x104 (assuming 4-byte int)
5. cout << p;           // Output: After: 0x104

Key Point:
----------
- After solve(), p points to a new address (0x104), which is not guaranteed to be valid.
- This demonstrates pointer reference, but in real code, pointer arithmetic should be done only on arrays or valid memory blocks.

Better Alternative (in words):
------------------------------
- If you want to demonstrate pointer reference safely, use an array:
    int arr[2] = {5, 10};
    int *p = arr;
    // Now, incrementing p is safe: p = p + 1; // p points to arr[1]
- Or, to change what p points to:
    void solve(int*& p, int& b) { p = &b; }
    // Now, p can be made to point to another variable safely.
*/