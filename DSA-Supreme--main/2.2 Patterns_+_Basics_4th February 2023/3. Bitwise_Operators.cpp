/*
Approach:
- This program demonstrates the use of bitwise operators in C++.
- It shows how bitwise AND (&), OR (|), and NOT (~) work on boolean and integer values.
- The program prints the results of these operations to the console for both boolean and integer operands.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function: program execution starts here
    bool a = false; // Initialize boolean variable a with value false (0)
    bool b = false; // Initialize boolean variable b with value false (0)

    cout << (a & b) << endl; // Bitwise AND: 0 & 0 = 0, prints 0
    cout << (a | b) << endl; // Bitwise OR: 0 | 0 = 0, prints 0
    cout << (~a) << endl;    // Bitwise NOT: ~0 = all bits set (for bool, prints -1)
    cout << (a & b) << endl; // Bitwise AND again: 0 & 0 = 0, prints 0

    cout << (2 & 3) << endl; // Bitwise AND on integers: 2 (10) & 3 (11) = 2 (10), prints 2
    cout << (3 | 4) << endl; // Bitwise OR on integers: 3 (011) | 4 (100) = 7 (111), prints 7

    int c = 12; // Initialize integer variable c with value 12
    cout << c << endl; // Print the value of c (12)

    return 0; // Indicate successful program termination
}

/*
Dry Run:

a = false (0), b = false (0)

cout << (a & b); // 0 & 0 = 0
Output: 0

cout << (a | b); // 0 | 0 = 0
Output: 0

cout << (~a); // ~0 = all bits set (for int, -1)
Output: -1

cout << (a & b); // 0 & 0 = 0
Output: 0

cout << (2 & 3); // 2: 10, 3: 11 -> 10 & 11 = 10 (2)
Output: 2

cout << (3 | 4); // 3: 011, 4: 100 -> 011 | 100 = 111 (7)
Output: 7

c = 12
cout << c;
Output: 12

Final Output:
0
0
-1
0
2
7
12
*/