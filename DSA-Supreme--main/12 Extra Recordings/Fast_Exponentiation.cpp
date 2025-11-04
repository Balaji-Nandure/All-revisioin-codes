/*
    Approach Used:
    ----------------
    This code implements "Fast Exponentiation" (also known as "Exponentiation by Squaring").
    The idea is to compute a^b in O(log b) time instead of O(b) by using the binary representation of b.
    For every bit in b:
        - If the bit is set (odd), multiply the answer by current a.
        - Square a for the next bit.
        - Right shift b to process the next bit.

    Better Alternatives (without code):
    -----------------------------------
    1. Recursive Fast Exponentiation:
        - Can be implemented recursively for cleaner code, but may have higher stack usage.
    2. Modular Exponentiation:
        - For very large numbers, use modulo at each step to prevent overflow.
    3. Built-in Functions:
        - For floating point, use pow() from <cmath>, but for integers, this method is more precise and faster.
    4. Matrix Exponentiation:
        - For problems like Fibonacci, matrix exponentiation is used for O(log n) computation.

    Dry Run Example (a=2, b=10):
    ----------------------------
    b in binary: 1010
    Iteration 1: b=10 (even), a=2, ans=1
        - a = 2*2 = 4, b = 5
    Iteration 2: b=5 (odd), a=4, ans=1*4=4
        - a = 4*4 = 16, b = 2
    Iteration 3: b=2 (even), a=16, ans=4
        - a = 16*16 = 256, b = 1
    Iteration 4: b=1 (odd), a=256, ans=4*256=1024
        - a = 256*256 = 65536, b = 0
    End: ans = 1024

    Final Output: 1024
*/

#include<iostream>
using namespace std;

// Function to calculate a^b using fast exponentiation (Exponentiation by Squaring)
int power(int a, int b) {
    int ans = 1; // Initialize result as 1 (since anything power 0 is 1)
    while (b > 0) { // Loop until all bits of b are processed
        // If current bit of b is set (i.e., b is odd)
        if (b & 1) { // Bitwise AND is faster than modulo for checking odd
            ans = ans * a; // Multiply current a to result
        }
        a = a * a; // Square a for next bit
        b = b >> 1; // Right shift b to process next bit
    }
    return ans; // Return the final answer
}

int main() {
    int a = 2; // Base
    int b = 10; // Exponent
    int ans = power(a, b); // Calculate a^b
    cout << ans; // Output the result
    return 0;
}

/*
    Dry Run for a=2, b=10:
    ----------------------
    b = 10 (1010 in binary)
    ans = 1

    1st Iteration: b=10 (even)
        - b&1 = 0 (no multiply)
        - a = 2*2 = 4
        - b = 10>>1 = 5

    2nd Iteration: b=5 (odd)
        - b&1 = 1 (multiply)
        - ans = 1*4 = 4
        - a = 4*4 = 16
        - b = 5>>1 = 2

    3rd Iteration: b=2 (even)
        - b&1 = 0 (no multiply)
        - a = 16*16 = 256
        - b = 2>>1 = 1

    4th Iteration: b=1 (odd)
        - b&1 = 1 (multiply)
        - ans = 4*256 = 1024
        - a = 256*256 = 65536
        - b = 1>>1 = 0

    Loop ends, ans = 1024
*/