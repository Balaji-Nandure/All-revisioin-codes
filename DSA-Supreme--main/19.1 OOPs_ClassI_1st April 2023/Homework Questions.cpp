
/*
Approach:
This is a list of important OOPs and C++/Java memory management concepts. 
Below, each point is explained with comments, logic, and better alternatives where applicable.
A dry run is provided at the end for clarity.
*/

// 1) Study about padding and greedy alignment?
// Padding: Compilers add extra bytes (padding) to align data members in memory for faster access.
// Greedy Alignment: The compiler arranges structure/class members to minimize padding and maximize alignment.
// Example:
struct Example {
    char a;   // 1 byte
    // 3 bytes padding here for alignment
    int b;    // 4 bytes
};
// sizeof(Example) == 8 bytes due to padding
// Better Alternative: Arrange members from largest to smallest to reduce padding.
struct BetterExample {
    int b;    // 4 bytes
    char a;   // 1 byte
    // 3 bytes padding at end
};
// sizeof(BetterExample) == 8 bytes, but sometimes can reduce padding in more complex structures.
// Use #pragma pack(1) to remove padding (not recommended for performance reasons).

// 2) What is memory leak? How can we prevent it?
// Memory Leak: When dynamically allocated memory is not freed, causing wasted memory.
// Example:
int* ptr = new int[10]; // memory allocated
// ... forgot to delete[] ptr;
// Prevention:
// - Always use delete/delete[] after new/new[]
// - Prefer smart pointers (C++11): unique_ptr, shared_ptr, weak_ptr
// Example with smart pointer:
#include <memory>
std::unique_ptr<int[]> smartPtr(new int[10]); // auto-freed

// 3) What is garbage collector?
// Garbage Collector: Automatic memory management system (e.g., in Java, Python) that frees unused memory.
// C++ does NOT have a built-in garbage collector; manual memory management is required.
// Java Example:
Integer obj = new Integer(5);
// When 'obj' is no longer referenced, Java's GC will reclaim memory automatically.

// 4) Study about const keyword
// const: Used to make variables or member functions immutable (read-only).
const int x = 10; // x cannot be changed
void print() const { /* cannot modify class members */ }
// Better: Use const correctness everywhere possible for safety and clarity.

// 5) Study about static keyword
// static: 
// - For variables: retains value across function calls (local static), or shared among all objects (class static).
// - For functions: limits scope to file (global static), or class-level function (class static).
class Demo {
    static int count; // shared by all objects
    static void show() { /* ... */ } // can be called without object
};
// Use static for utility functions or shared data.

// 6) Study about initialization list
// Initialization List: Preferred way to initialize class members, especially const or reference members.
class MyClass {
    int a;
    const int b;
public:
    MyClass(int x, int y) : a(x), b(y) {} // initialization list
};
// Better: Always use initialization list for efficiency and to initialize const/reference members.

// Dry Run Example:
// struct Example { char a; int b; }; // sizeof = 8 (due to padding)
// int* ptr = new int[10]; // memory allocated
// delete[] ptr; // memory freed, no leak
// const int x = 10; // x is immutable
// static int y = 0; // y retains value across calls
// MyClass obj(1, 2); // a=1, b=2 initialized via list
