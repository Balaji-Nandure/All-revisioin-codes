#include<iostream>
using namespace std;

/*
Approach:
-----------
This code demonstrates the relationship between arrays and pointers in C++, 
how pointer arithmetic works, and how character arrays (C-strings) are handled.
It also highlights the difference between arrays and pointers in terms of memory and usage.

Better Alternatives (in comments):
-----------------------------------
- For printing addresses, prefer using std::uintptr_t or casting to void* for clarity.
- Avoid using deprecated string literals with char* (e.g., char *ctr = "Bhavya";).
- Use std::string for safer and more modern string handling.
- Use size_t for array sizes and pointer arithmetic for portability.
- Always initialize arrays and pointers to avoid undefined behavior.
*/

int main(){
    // Declare and initialize an integer array of size 4
    int arr[4] = {12,13,14,15};

    // Print the base address of the array (decays to pointer to first element)
    cout << arr << endl; // Prints address (e.g., 0x7ffeea2b8b40)

    // Print the first element of the array
    cout << arr[0] << endl; // Prints 12

    // Print the address of the whole array (same as base address, but type is int(*)[4])
    cout << &arr << endl; // Prints address (same as above, but type is different)

    // Print the address of the first element (same as base address)
    cout << &arr[0] << endl; // Prints address (same as above)

    // Create a pointer to the first element of the array
    int *ptr = arr;

    // Print the value of the pointer (should be base address of array)
    cout << ptr << endl; // Prints address (same as above)

    // Print the address of the pointer variable itself (different from array address)
    cout << &ptr << endl; // Prints address of ptr variable (different from arr)

    // Demonstrate dereferencing and arithmetic
    cout << *(arr) + 1 << endl; // 12 + 1 = 13 (dereference first element, add 1)
    cout << *arr + 1 << endl;   // Same as above

    // Print the value at the second element using pointer arithmetic
    cout << *(arr + 1) << endl; // arr[1] = 13

    // Demonstrate alternative array indexing syntax
    cout << 2[arr] << endl; // arr[2] = 14 (valid but not recommended for readability)

    // arr = arr + 2; // Invalid: array name is a constant pointer, cannot be reassigned

    // Pointer arithmetic: move pointer to the third element
    int *p = arr;
    p = p + 2; // Now p points to arr[2]

    // Print the address of arr[2]
    cout << &arr[2] << endl; // Address of third element

    // Print the value of pointer p (should match address of arr[2])
    cout << p << endl; // Same as above

    // ----------- Pointer vs Array -----------
    int brr[10]; // Declare an integer array of size 10

    // Print the total size of the array in bytes (10 * 4 = 40 bytes on most systems)
    cout << sizeof(brr) << endl; // 40 (if int is 4 bytes)

    int *p1 = brr; // Pointer to first element of brr

    // Print the size of the pointer variable (typically 8 bytes on 64-bit systems)
    cout << sizeof(p) << endl; // 8

    // arr = arr + 1; // Invalid: cannot change array base address
    // p1 = p1 + 1;   // Valid: pointer arithmetic allowed

    // ----------- Character Array (C-string) -----------
    char ch[10] = "Babbar"; // Character array initialized with string literal

    char *c = ch; // Pointer to first character

    // Print the string (prints until null character)
    cout << ch << endl; // Babbar

    // Print the address of the array (prints as address, but may print string due to operator overloading)
    cout << static_cast<void*>(&ch) << endl; // Use cast to print address, not string

    // Print the first character
    cout << ch[0] << endl; // B

    // Print the address of the pointer variable c
    cout << &c << endl; // Address of c variable

    // Print the character pointed to by c
    cout << *c << endl; // B

    // Print the string starting from c
    cout << c << endl; // Babbar

    // ----------- Special Case: Single Character Pointer -----------
    char character = 'v';
    char *cptr = &character;

    // Printing cptr will print until it finds a null character, so this is unsafe and may print garbage
    cout << cptr << endl; // Undefined behavior, may print 'v' followed by garbage

    // ----------- Bad Practice: String Literal Assignment -----------
    // Assigning string literal to char* is deprecated in C++ (should be const char*)
    char *ctr = (char*)"Bhavya"; // Cast to avoid warning, but still not recommended

    // Print the string literal
    cout << ctr << endl; // Bhavya

    /*
    Better Alternatives:
    --------------------
    - Use std::string for string handling: std::string str = "Bhavya";
    - For printing addresses, use static_cast<void*>(...) to avoid confusion with char* overloads.
    - Avoid printing char* that do not point to null-terminated strings.
    - Always use const char* for string literals.
    - For array size, use std::size(arr) in C++17 or sizeof(arr)/sizeof(arr[0]) in older standards.
    */

    return 0;
}

/*
Dry Run:
---------
arr = [12, 13, 14, 15]
arr (address): 0x1000 (example)
arr[0]: 12
&arr: 0x1000
&arr[0]: 0x1000
ptr = arr -> ptr: 0x1000
&ptr: 0x2000 (example, address of pointer variable)
*(arr) + 1: 12 + 1 = 13
*arr + 1: 12 + 1 = 13
*(arr+1): arr[1] = 13
2[arr]: arr[2] = 14
p = arr + 2 -> p: 0x1008 (if int is 4 bytes)
&arr[2]: 0x1008
p: 0x1008

brr[10]: size = 40 bytes (if int is 4 bytes)
sizeof(p): 8 bytes (on 64-bit system)

ch = "Babbar"
c = ch
ch: prints "Babbar"
&ch: prints address (may print string if not cast)
ch[0]: 'B'
&c: address of c
*c: 'B'
c: prints "Babbar"

character = 'v'
cptr = &character
cout << cptr: prints 'v' + garbage (unsafe)

ctr = "Bhavya"
cout << ctr: prints "Bhavya"
*/