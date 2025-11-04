/*
Approach Used:
---------------
This code converts a decimal number to its binary representation using bitwise operations.
It extracts each bit from the least significant to the most significant, and constructs the binary number as an integer (not as a string).

Key Steps:
1. Extract the least significant bit using bitwise AND (&).
2. Multiply the extracted bit by the corresponding power of 10 to place it in the correct position in the resulting integer.
3. Right shift the number to process the next bit.
4. Repeat until the number becomes zero.

Note:
- This approach builds the binary as an integer, which can cause issues for large numbers (since leading zeros are lost and the result may overflow for large input).
- For large numbers or to preserve leading zeros, it's better to build the binary as a string or use a vector to store bits.

Alternative (Better) Approaches (without code):
------------------------------------------------
1. **String Approach:** Extract bits and append/prepend to a string, then print the string. This avoids integer overflow and preserves leading zeros.
2. **Vector Approach:** Store bits in a vector, then reverse and print. This is efficient and flexible.
3. **Built-in Functions:** In C++, you can use std::bitset for fixed-width binary representation.
4. **Recursive Approach:** Recursively print bits from the most significant to least significant.

*/

// Include necessary headers
#include<iostream>
#include<cmath>
using namespace std;

// Function to convert decimal to binary using bitwise method
int decToBinMethod1(int n){
    // Initialize variable to store the binary number (as integer)
    int binaryNumber = 0;
    // Position index for placing the bit at correct decimal place
    int i = 0;
    // Loop until all bits are processed
    while(n > 0){
        // Extract the least significant bit using bitwise AND
        int bit = n & 1;
        // Place the bit at the correct position in the binary number
        // (e.g., for i=0, units place; i=1, tens place, etc.)
        binaryNumber = bit * pow(10, i) + binaryNumber;
        // Right shift n to process the next bit
        n = n >> 1;
        // Increment position index
        i++;
    }
    // Return the constructed binary number (as integer)
    return binaryNumber;
}

int main(){
    int n;
    // Input the decimal number from user
    cin >> n;
    // Convert decimal to binary using bitwise method
    int binary = decToBinMethod1(n);
    // Output the result
    cout << "Binary number of " << n << " is " << binary << endl;
    return 0;
}

/*
Dry Run Example:
----------------
Input: 13

Step-by-step:
n = 13 (1101 in binary)
i = 0, n = 13, bit = 13 & 1 = 1, binaryNumber = 1 * 10^0 + 0 = 1
i = 1, n = 6,  bit = 6 & 1 = 0,  binaryNumber = 0 * 10^1 + 1 = 1
i = 2, n = 3,  bit = 3 & 1 = 1,  binaryNumber = 1 * 10^2 + 1 = 100 + 1 = 101
i = 3, n = 1,  bit = 1 & 1 = 1,  binaryNumber = 1 * 10^3 + 101 = 1000 + 101 = 1101
n = 0, loop ends

Output: Binary number of 13 is 1101

Note: For large n, this method may not work due to integer overflow or loss of leading zeros.
*/