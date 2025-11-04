/*
Approach:
- Demonstrate different for-loop configurations: standard increment, printing strings, arithmetic sequences, custom step sizes, exponential growth, and compound conditions.
- Each loop has three parts: initialization; loop condition; update expression.
*/

#include<iostream> // Include I/O for cout and endl
using namespace std; // Use the standard namespace

int main(){ // Program entry point
    // Loop 1: count 0..4
    // initialization: int i = 0
    // condition: i < 5
    // update: i = i + 1
    for(int i = 0; i < 5; i = i + 1){ // Iterate i from 0 to 4
        cout << i << endl; // Print current i, then newline
    } // End loop 1

    // Loop 2: repeat a string 3 times
    // initialization: int i = 0
    // condition: i < 3
    // update: i = i + 1
    for(int i = 0; i < 3; i = i + 1){ // Run 3 iterations
        cout << "Bhavya Bhalla" << endl; // Print name each iteration
    } // End loop 2

    // Loop 3: print the 2-times table (0 to 20)
    // initialization: int i = 0
    // condition: i <= 10
    // update: i = i + 1
    for(int i = 0; i <= 10; i = i + 1){ // Iterate i from 0 to 10
        cout << 2 * i << endl; // Print 2 multiplied by i
    } // End loop 3

    // Loop 4: print even indices up to 5 with step 2
    // initialization: int i = 0
    // condition: i <= 5
    // update: i = i + 2
    for(int i = 0; i <= 5; i = i + 2){ // Iterate 0,2,4
        cout << i << endl; // Print the current i
    } // End loop 4

    // Loop 5: exponential growth (doubling)
    // initialization: int i = 1
    // condition: i <= 20
    // update: i = i * 2
    for(int i = 1; i <= 20; i = i * 2){ // Iterate 1,2,4,8,16
        cout << i << endl; // Print the current i
    } // End loop 5

    // Loop 6: custom condition with conjunction
    // initialization: int i = 5
    // condition: (i >= 0 && i <= 10)
    // update: i = i + 1
    for(int i = 5; (i >= 0 && i <= 10); i = i + 1){ // Iterate 5..10
        cout << i; // Print i without newline
    } // End loop 6

    return 0; // Successful execution
}

/*
Dry Run (selected loops):
Loop 1 (i from 0 to 4): prints lines: 0, 1, 2, 3, 4
Loop 3 (2*i for i=0..10): prints: 0 2 4 6 8 10 12 14 16 18 20 (each on new line)
Loop 6 (i from 5 to 10): prints: 5678910 (no spaces/newlines)
*/