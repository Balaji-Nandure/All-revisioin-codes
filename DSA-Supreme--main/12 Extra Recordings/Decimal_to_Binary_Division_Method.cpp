/*
Approach Used:
---------------
This code converts a decimal number to its binary representation using the division-by-2 method. 
It repeatedly divides the number by 2, collecting the remainders (bits), and constructs the binary number as an integer.

Better Alternatives (without code):
-----------------------------------
1. **Store bits in a string or vector**: Instead of constructing an integer (which can overflow for large numbers), store each bit in a string or vector, then reverse it at the end for the correct order.
2. **Use bitwise operators**: Bitwise operations (like n & 1, n >>= 1) are more efficient than using modulus and division.
3. **Output bits directly**: For very large numbers, print bits as you compute them or store in a string to avoid integer overflow.
4. **Use std::bitset**: For fixed-width binary representations, C++'s std::bitset is efficient and convenient.

Code with detailed comments and improvements:
--------------------------------------------
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to convert decimal to binary using division method
int decToBinMethod1(int n) {
    // Initialize variable to store the binary number (as integer)
    int binaryNumber = 0;
    // 'i' keeps track of the current bit position (power of 10)
    int i = 0;

    // Edge case: if n is 0, binary is 0
    if (n == 0) return 0;

    // Loop until all bits are processed
    while (n > 0) {
        int bit = n % 2; // Get the least significant bit (LSB)
        // Place the bit at the correct position in the resulting number
        // (e.g., for 1st bit, multiply by 10^0, for 2nd bit by 10^1, etc.)
        binaryNumber += bit * pow(10, i);

        n = n / 2; // Remove the processed bit (integer division by 2)
        i++;       // Move to the next bit position
    }
    // Return the constructed binary number (as integer)
    return binaryNumber;
}

int main() {
    int n;
    cout << "Enter a decimal number: "; // Prompt user for input
    cin >> n; // Read decimal number

    int binary = decToBinMethod1(n); // Convert to binary

    cout << "Binary number of " << n << " is " << binary << endl; // Output result

    return 0;
}

/*
Dry Run Example:
----------------
Input: n = 13

Step 1: n = 13, i = 0
    bit = 13 % 2 = 1
    binaryNumber = 1 * 10^0 + 0 = 1
    n = 13 / 2 = 6
    i = 1

Step 2: n = 6, i = 1
    bit = 6 % 2 = 0
    binaryNumber = 0 * 10^1 + 1 = 1
    n = 6 / 2 = 3
    i = 2

Step 3: n = 3, i = 2
    bit = 3 % 2 = 1
    binaryNumber = 1 * 10^2 + 1 = 100 + 1 = 101
    n = 3 / 2 = 1
    i = 3

Step 4: n = 1, i = 3
    bit = 1 % 2 = 1
    binaryNumber = 1 * 10^3 + 101 = 1000 + 101 = 1101
    n = 1 / 2 = 0
    i = 4

Loop ends (n == 0). Output: 1101

So, 13 in binary is 1101.

Note:
-----
- This method works for small numbers. For large numbers, storing binary as an integer may cause overflow.
- For large numbers, use string or vector to store bits.
- pow(10, i) can be replaced with a variable that multiplies by 10 each iteration for efficiency.
*/