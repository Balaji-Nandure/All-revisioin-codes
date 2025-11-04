/*
Approach:
- This program demonstrates the use of pre-increment (++a) and post-increment (a++) operators in C++.
- It shows how the value of a variable changes when using pre-increment and post-increment in different contexts.
- The program also includes an example where pre-increment is used multiple times in a single expression to highlight undefined behavior.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function: program execution starts here

    int a = 10; // Initialize integer variable a with value 10

    // Pre-increment: increment 'a' first, then use its value
    cout << (++a) << endl; // Output: 11 (a becomes 11, then prints 11)

    // Post-increment: use the value of 'a' first, then increment
    cout << (a++) << endl; // Output: 11 (prints 11, then a becomes 12)

    // Print the current value of 'a'
    cout << a << endl; // Output: 12 (a was incremented in previous step)

    int c = 6; // Initialize integer variable c with value 6

    // Pre-increment c, then add 1
    int d = ++c + 1; // c becomes 7, then d = 7 + 1 = 8

    int e = 5; // Initialize integer variable e with value 5

    // Multiple pre-increments in a single expression (undefined behavior)
    cout << (++e) * (++e) << endl; // Output may vary (Homework: find out why)

    return 0; // Indicate successful program termination
}

/*
Dry Run:

Step 1:
a = 10

cout << (++a); // a becomes 11, prints 11
Output: 11

cout << (a++); // prints 11, then a becomes 12
Output: 11

cout << a; // a is now 12
Output: 12

c = 6
int d = ++c + 1; // c becomes 7, d = 7 + 1 = 8

e = 5
cout << (++e) * (++e); 
- First ++e: e becomes 6
- Second ++e: e becomes 7
- Depending on evaluation order, result may be 6*7=42 or 7*6=42, but this is undefined behavior in C++.

Final Output:
11
11
12
42 (but this line is undefined behavior and may vary)
*/