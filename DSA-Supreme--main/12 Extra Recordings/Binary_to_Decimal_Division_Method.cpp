/*
Approach Used:
---------------
This code converts a binary number (given as an integer, e.g., 1011) to its decimal equivalent using the division method. 
It extracts each digit (bit) from right to left, multiplies it by the corresponding power of 2, and accumulates the result.

Better Alternatives (without code):
-----------------------------------
1. **String Input Approach:** Accept the binary number as a string to handle leading zeros and very large binary numbers that can't fit in an int.
2. **Bitwise Approach:** If the binary is stored as an integer, use bitwise operations to extract bits and compute the decimal value.
3. **Built-in Functions:** In some languages, you can directly convert binary strings to decimal using built-in functions.
4. **Validation:** Add input validation to ensure the number is a valid binary.

Code with detailed comments and improvements:
--------------------------------------------
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to convert binary (given as integer) to decimal
int binToDecimal(int bin) {
    int ans = 0;    // Stores the final decimal value
    int i = 0;      // Power index for 2^i

    // Process each digit (bit) from right to left
    while (bin > 0) {
        int bit = bin % 10; // Extract the last digit (rightmost bit)
        // Check if the digit is valid (should be 0 or 1)
        if (bit != 0 && bit != 1) {
            cout << "Invalid binary digit encountered: " << bit << endl;
            return -1; // Return error code for invalid input
        }
        // Add the value of the current bit times its positional value (2^i)
        ans += bit * (1 << i); // (1 << i) is faster than pow(2, i)
        i++;                   // Move to the next higher power of 2
        bin /= 10;             // Remove the last digit
    }
    return ans;
}

int main() {
    int bin = 1011; // Example binary number (as integer)
    int decimal = binToDecimal(bin); // Convert to decimal

    if (decimal != -1) {
        cout << "Decimal value of binary number " << bin << " is " << decimal << endl;
    } else {
        cout << "Conversion failed due to invalid input." << endl;
    }
    return 0;
}

/*
Dry Run:
--------
Input: bin = 1011

Step 1: i=0, bin=1011, bit=1, ans=0 + 1*2^0 = 1, bin=101
Step 2: i=1, bin=101,  bit=1, ans=1 + 1*2^1 = 3, bin=10
Step 3: i=2, bin=10,   bit=0, ans=3 + 0*2^2 = 3, bin=1
Step 4: i=3, bin=1,    bit=1, ans=3 + 1*2^3 = 11, bin=0

Output: Decimal value of binary number 1011 is 11

Note:
-----
- This approach works only for binary numbers that can be represented as integers and do not have leading zeros.
- For large binary numbers or those with leading zeros, use string input and process each character.
- Using (1 << i) is more efficient than pow(2, i) for integer powers of 2.
*/