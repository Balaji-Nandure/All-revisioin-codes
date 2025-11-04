/*
Approach Used:
---------------
This code implements Modular Exponentiation using the Fast Exponentiation (Binary Exponentiation) method.
The goal is to compute (x^n) % m efficiently, even for very large n, by reducing the number of multiplications from O(n) to O(log n).

Key Points:
-----------
- At each step, if the current power (n) is odd, multiply the answer by the current base (x) and take modulo m.
- Square the base (x) and halve the exponent (n) at each iteration.
- This approach ensures that intermediate results never exceed m*m, preventing overflow and keeping computations efficient.

Better Alternatives (in comments):
----------------------------------
1. **Recursive Fast Exponentiation:** Can be implemented recursively, but iterative is preferred to avoid stack overflow for large n.
2. **Montgomery Multiplication:** For cryptographic applications, Montgomery reduction can be used for even faster modular multiplication.
3. **Using Built-in Functions:** Some languages/libraries provide built-in modular exponentiation (e.g., Python's pow(x, n, m)), which is highly optimized.
4. **Chinese Remainder Theorem:** For very large moduli that can be factorized, CRT can be used to split the problem into smaller moduli.

*/

#include<iostream>
using namespace std;

// Function to compute (x^n) % m using fast (binary) exponentiation
long long int powMod(long long int x, long long int n, long long int m){
    long long int ans = 1; // Initialize result

    x = x % m; // Reduce x if it is more than or equal to m

    // Loop until all bits of n are processed
    while(n > 0){
        // If current bit is set (n is odd), multiply ans with current x
        if(n & 1){
            ans = (ans * x) % m; // Update ans and take modulo to avoid overflow
        }
        x = (x * x) % m; // Square the base and take modulo
        n = n >> 1; // Shift n right by 1 (divide by 2)
    }
    return ans; // Final answer is already modulo m
}

int main(){
    long long int x = 3; // Base
    long long int n = 2; // Exponent
    long long int m = 4; // Modulus

    long long int ans = powMod(x, n, m); // Compute (x^n) % m

    cout << ans; // Output the result

    return 0;
}

/*
Dry Run:
--------
Input: x = 3, n = 2, m = 4

Step 1: ans = 1, x = 3 % 4 = 3, n = 2
Loop 1: n = 2 (binary 10), n & 1 == 0 (even), skip ans update
        x = (3*3)%4 = 9%4 = 1
        n = 2 >> 1 = 1

Loop 2: n = 1 (binary 1), n & 1 == 1 (odd), ans = (1*1)%4 = 1
        x = (1*1)%4 = 1
        n = 1 >> 1 = 0

Loop ends (n == 0)
Return ans = 1

Output: 1

Time Complexity: O(log n)
Space Complexity: O(1)
*/