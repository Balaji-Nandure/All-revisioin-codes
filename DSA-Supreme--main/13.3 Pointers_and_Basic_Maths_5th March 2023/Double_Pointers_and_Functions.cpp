#include<iostream>
using namespace std;

/*
Approach:
- Demonstrate the use of double pointers (pointer to pointer) and how passing them to functions can affect the original data, pointer, or neither, depending on how they're manipulated.
- Show the difference between changing the pointer itself, the address it points to, and the value at the final address.
- Illustrate the effect of each operation with before/after output.
- This is useful for understanding pointer arithmetic, indirection, and function parameter passing in C++.

Better Alternatives (in comments):
- Use references to pointers (int*& or int**&) to actually modify the original pointer in the caller.
- Use const correctness to prevent accidental modification.
- Use smart pointers for safer memory management in real-world code.

*/

// Function that tries to change the double pointer itself (no effect outside function)
void solve(int **q){
    // q = q + 1; // This only changes the local copy of q, not the original pointer in main
    // No effect on caller
}

// Function that changes the address stored in the pointer (i.e., makes p point somewhere else)
void solve1(int **q){
    // *q = *q + 1; // This changes the address stored in p (i.e., p now points to next int location)
    // This can cause undefined behavior if p is not pointing to an array
    // To actually change p in main, pass int*& p or int**& q
}

// Function that changes the value at the address pointed by the pointer (i.e., changes x)
void solve2(int **q){
    // **q = **q + 1; // This increments the value of x by 1
    // This is the only function here that safely changes the actual data
}

int main(){
    int x = 12;           // Declare integer variable x and initialize to 12
    int *p = &x;          // p is a pointer to x
    int **q = &p;         // q is a pointer to pointer p

    cout<<"Before"<<endl;
    cout<<"x: "<<x<<endl; // Print value of x
    cout<<"p: "<<p<<endl; // Print address stored in p (address of x)
    cout<<"q: "<<q<<endl; // Print address stored in q (address of p)

    // Uncomment one function at a time to see the effect

    // solve(q);   // No change to any variable
    // solve1(q);  // Changes p to point to next int (unsafe if not array)
    solve2(q);     // Increments value of x by 1

    cout<<"After"<<endl;
    cout<<"x: "<<x<<endl; // Print value of x after function call
    cout<<"p: "<<p<<endl; // Print address stored in p after function call
    cout<<"q: "<<q<<endl; // Print address stored in q after function call

    return 0;
}

/*
Dry Run:
----------
Initial values:
x = 12
p = address of x (e.g., 0x61ff08)
q = address of p (e.g., 0x61ff04)

Case 1: solve(q)
- q is incremented locally, no effect on main variables.
- Output: x=12, p=address of x, q=address of p

Case 2: solve1(q)
- *q = *q + 1; p now points to next int location (may be garbage/unsafe)
- x remains 12, p changes, q remains same

Case 3: solve2(q)
- **q = **q + 1; x becomes 13, p and q remain same

Better/safer approach:
- To actually change p in main, use void solve1(int*& p) and call solve1(p);
- Use const correctness to prevent accidental modification.
- Use smart pointers for dynamic memory.

Summary:
- q = q + 1; // No effect outside function
- *q = *q + 1; // Changes p (dangerous if not array)
- **q = **q + 1; // Safely changes x

*/