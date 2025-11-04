#include<iostream>
using namespace std;

/*
Approach:
-----------
- Demonstrate how pointer arguments work in functions.
- Show that passing a pointer by value means changes to the pointer itself (not the data it points to) are local to the function.
- Show how pointer arithmetic and dereferencing work.

Better Alternatives (in comments):
-----------------------------------
1. If the intention is to modify the value at the original address, directly dereference the pointer without changing its address.
2. If the intention is to change the pointer itself (e.g., make it point elsewhere in the caller), pass the pointer by reference (int *&p).
3. For clarity and safety, avoid pointer arithmetic unless necessary, and always ensure the pointer points to valid memory.

*/

void util(int *p){ 
    // Function receives a copy of the pointer 'p' (pointer passed by value)
    p = p + 1; // Pointer arithmetic: moves pointer to next int location (may be invalid if not an array)
    *p = *p + 1; // Attempts to increment value at new location (undefined behavior if not valid memory)
    // Note: This does NOT affect the original pointer in main, nor does it safely update 'a'
    // This line is dangerous unless p points to a valid array element after increment
}

int main(){
    int a = 5; // Declare integer variable 'a' and initialize to 5
    int *p = &a; // Pointer 'p' stores address of 'a'

    // Print values before function call
    cout<<"Before "<<endl;
    cout<<"a: "<<a<<endl; // Value of 'a'
    cout<<"p (address of a): "<<p<<endl; // Address stored in pointer 'p'
    cout<<"*p (value at address p): "<<*p<<endl; // Value at address pointed by 'p' (should be 5)

    util(p); // Call function with pointer 'p'
    // After util, 'a' remains unchanged because util does not modify value at original address

    // Print values after function call
    cout<<"After "<<endl;
    cout<<"a: "<<a<<endl; // Value of 'a' (should still be 5)
    cout<<"p (address of a): "<<p<<endl; // Address stored in pointer 'p' (unchanged)
    cout<<"*p (value at address p): "<<*p<<endl; // Value at address pointed by 'p' (should still be 5)

    return 0;
}

/*
Dry Run:
---------
main:
    a = 5
    p = &a

    Before
    a: 5
    p: (address of a, e.g., 0x61ff08)
    *p: 5

    util(p):
        p is a copy of main's p (points to a)
        p = p + 1; // p now points to next int (invalid, since 'a' is not in an array)
        *p = *p + 1; // undefined behavior (may crash or corrupt memory)

    After
    a: 5 (unchanged, unless memory corruption occurred)
    p: (address of a, e.g., 0x61ff08)
    *p: 5

Better/safer approach:
----------------------
- If you want to increment the value of 'a' via pointer, do: (*p)++;
- If you want to change the pointer itself in main, pass by reference: void util(int *&p)
- Avoid pointer arithmetic unless working with arrays.

Summary:
---------
- Passing pointer by value means changes to pointer itself are local to function.
- Pointer arithmetic can be dangerous if not pointing to valid memory.
- To modify the value at the original address, dereference the pointer directly.
*/