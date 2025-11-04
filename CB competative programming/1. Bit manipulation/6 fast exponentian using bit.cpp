/*
Approach:
To compute a^b (a raised to the power b) efficiently, we use the fast exponentiation (exponentiation by squaring) technique using bit manipulation. 
The idea is:
- Every number b can be represented as a sum of powers of 2 (its binary representation).
- If the ith bit in b is set, we multiply the result by a^(2^i).
- We iteratively square the base 'a' and move through the bits of b from least significant to most significant.
- For each bit:
    - If the bit is 1, multiply the current result by the current base.
    - Square the base.
    - Right shift b to check the next bit.
- This reduces the complexity from O(b) to O(log b).
*/

#include <iostream>
using namespace std;

// Function to calculate a^b using fast exponentiation (bit manipulation)
// Time Complexity: O(log b)
long long fastExponentiation(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        // If the current bit is set
        if (b & 1) {
            result *= a;
        }
        a = a * a;
        b = b >> 1;
    }
    return result;
}

int main() {
    long long a, b;
    cout << "Enter base (a): ";
    cin >> a;
    cout << "Enter exponent (b): ";
    cin >> b;
    cout << a << "^" << b << " = " << fastExponentiation(a, b) << endl;
    return 0;
}

