#include<iostream>
using namespace std;

/*
Approach:
- Demonstrate pointer basics: declaration, initialization, dereferencing, pointer arithmetic, and best practices.
- Show how pointers store addresses, how to access values via dereferencing, and how pointer size is independent of data type.
- Highlight pitfalls (uninitialized pointers) and their rectification.
- Illustrate pointer copying and pointer arithmetic, and discuss their implications.

Better Alternatives (in comments):
- Always initialize pointers to nullptr if not immediately assigned.
- Avoid pointer arithmetic unless working with arrays or memory blocks you own.
- Use smart pointers (like std::unique_ptr, std::shared_ptr) in modern C++ for automatic memory management.
- Avoid using raw pointers for ownership unless necessary.
*/

int main(){
    // Declare and initialize an integer variable
    int a = 5; // 'a' is stored in stack memory, value is 5

    // Print value of 'a'
    cout << a << endl; // Output: 5

    // Print address of 'a'
    cout << &a << endl; // Output: address of 'a' in hexadecimal (e.g., 0x61ff08)

    // Pointer creation and initialization
    int b = 6; // Another integer variable
    int *ptr = &b; // 'ptr' is a pointer to int, initialized to address of 'b'

    // Dereferencing pointer to get value at address
    cout << *ptr << endl; // Output: 6 (value at address stored in ptr)

    // Print address of pointer variable itself (not the value it points to)
    cout << &ptr << endl; // Output: address of 'ptr' variable

    // Character pointer example
    char ch = 'a'; // Character variable
    char *ptr1 = &ch; // Pointer to char, initialized to address of 'ch'

    cout << endl; // For better output formatting

    // Print size of int pointer and char pointer
    cout << sizeof(ptr) << endl;  // Output: size of pointer (typically 4 or 8 bytes depending on system)
    cout << sizeof(ptr1) << endl; // Output: size of pointer (same as above, pointer size is independent of data type)

    // BAD PRACTICE: Uninitialized pointer (may point to garbage)
    int *ptr2; // Should always be initialized before use

    // Rectifying above mistake: initialize to nullptr (C++11 and above)
    int *ptr3 = nullptr; // Good practice: clearly indicates pointer is not pointing to any valid memory

    // Alternative: initialize to 0 (older C++), but nullptr is preferred
    int *ptr4 = 0; // Not recommended in modern C++, use nullptr

    // Copying pointer: both point to same memory location
    int d = 5;
    int *p = &d; // 'p' points to 'd'
    int *copy = p; // 'copy' also points to 'd'

    cout << *copy << endl; // Output: 5 (value at address 'copy' points to)
    cout << *p << endl;    // Output: 5 (value at address 'p' points to)

    // Pointer arithmetic: increment pointer to point to next int in memory
    // WARNING: Only valid if pointer is pointing to an array or valid memory block
    p = p + 1; // Now 'p' points to next int-sized memory location (may be invalid here)
    cout << p << endl; // Output: new address (likely garbage, as 'p' no longer points to valid variable)

    // Dereferencing invalid pointer is undefined behavior; should be avoided
    // *p = *p + 1; // This line is dangerous and can cause crash or corruption

    // Better alternative: Only perform pointer arithmetic on arrays or allocated memory
    // Example:
    // int arr[3] = {1,2,3};
    // int *aptr = arr;
    // aptr = aptr + 1; // Now points to arr[1], safe

    // Use smart pointers for dynamic memory management (C++11 and above)
    // Example:
    // std::unique_ptr<int> uptr = std::make_unique<int>(10);

    return 0;
}

/*
Dry Run:
-------------
int a = 5;           // a = 5, &a = 0x... (some address)
cout << a;           // prints 5
cout << &a;          // prints address of a

int b = 6;           // b = 6, &b = 0x... (some address)
int *ptr = &b;       // ptr = &b
cout << *ptr;        // prints 6
cout << &ptr;        // prints address of ptr

char ch = 'a';       // ch = 'a', &ch = 0x... (some address)
char *ptr1 = &ch;    // ptr1 = &ch

cout << sizeof(ptr); // prints pointer size (e.g., 8)
cout << sizeof(ptr1);// prints pointer size (e.g., 8)

int *ptr2;           // uninitialized, BAD
int *ptr3 = nullptr; // good, points to nothing
int *ptr4 = 0;       // legacy, points to nothing

int d = 5;           // d = 5, &d = 0x... (some address)
int *p = &d;         // p = &d
int *copy = p;       // copy = &d

cout << *copy;       // prints 5
cout << *p;          // prints 5

p = p + 1;           // p now points to next int (invalid here)
cout << p;           // prints new address (not &d)

*Note: Dereferencing p after increment is undefined and should be avoided.
*/