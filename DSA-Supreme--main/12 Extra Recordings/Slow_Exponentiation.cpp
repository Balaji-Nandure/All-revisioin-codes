/*
Approach Used:
---------------
This code implements the basic (naive) approach for exponentiation, i.e., to compute a^b, we multiply 'a' by itself 'b' times using a simple loop.

Better Alternatives:
--------------------
1. Binary Exponentiation (Exponentiation by Squaring):
   - Reduces time complexity from O(b) to O(log b).
   - Works by recursively or iteratively squaring the base and halving the exponent.
   - Much faster for large exponents.

2. Using Built-in Functions:
   - Functions like pow() in <cmath> can be used for floating point exponentiation, but may not be suitable for large integers due to precision issues.

3. Modular Exponentiation:
   - Useful when results need to be computed modulo some number (e.g., in cryptography).
   - Also uses binary exponentiation for efficiency.

Code with Comments and Improvements:
------------------------------------
*/

#include<iostream>
using namespace std;

// Function to calculate a raised to the power b (a^b) using naive approach
int power(int a, int b){
    int ans = 1; // Initialize result to 1 (as anything power 0 is 1)
    // Loop b times to multiply 'a' with itself
    for(int i = 1; i <= b; i++){
        ans = ans * a; // Multiply current result by 'a' in each iteration
    }
    return ans; // Return the final result
}

int main(){
    int a = 2; // Base value
    int b = 10; // Exponent value
    int ans = power(a, b); // Call the power function to compute 2^10
    cout << ans; // Output the result (should print 1024)
    return 0; // Indicate successful program termination
}

/*
Dry Run:
--------
Let a = 2, b = 10

Initial ans = 1

Loop runs from i = 1 to 10:
i=1: ans = 1 * 2 = 2
i=2: ans = 2 * 2 = 4
i=3: ans = 4 * 2 = 8
i=4: ans = 8 * 2 = 16
i=5: ans = 16 * 2 = 32
i=6: ans = 32 * 2 = 64
i=7: ans = 64 * 2 = 128
i=8: ans = 128 * 2 = 256
i=9: ans = 256 * 2 = 512
i=10: ans = 512 * 2 = 1024

Final ans = 1024, which is printed as output.

Summary:
--------
- This code uses a simple loop to compute a^b in O(b) time.
- For large exponents, prefer binary exponentiation for efficiency.
*/