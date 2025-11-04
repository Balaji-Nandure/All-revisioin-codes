/*
Replace Bits in N by M

Question:
You are given two 32-bit numbers, N and M, and two bit positions, i and j.
Write a method to set all bits between i and j in N equal to M (i.e., M becomes a substring of N located at i and starting at j).

EXAMPLE:
Input:  N = 10000000000
        M =     10101
        i = 2, j = 6
Output: N = 10001010100

Approach:
1. Create a mask to clear bits i through j in N.
2. Shift M so it aligns with bits i through j.
3. OR the cleared N with the shifted M.

Steps:
- First, build a mask with 0s from i to j and 1s elsewhere.
- Clear those bits in N using the mask.
- Shift M left by i bits.
- Insert the shifted M into N using bitwise OR.

Code:
*/

#include <iostream>
using namespace std;

int replaceBits(int N, int M, int i, int j) {
    // step 1: Create mask
    int allOnes = ~0; // All 1s (32 bits)
    int left = allOnes << (j + 1); // 1s before j+1, 0s after
    int right = (1 << i) - 1;      // 1s after i-1, 0s from i upwards
    int mask = left | right;       // 0s between i and j

    // step 2: Clear i through j in N
    int n_cleared = N & mask;

    // step 3: Shift M into position
    int m_shifted = M << i;

    // step 4: Merge and return
    return n_cleared | m_shifted;
}

void printBinary(int x, int bits = 11) {
    for(int i = bits-1; i >= 0; --i) {
        cout << ((x >> i) & 1);
    }
    cout << endl;
}

int main() {
    // Given in example:
    int N = 0b10000000000; // 1024
    int M = 0b10101;       // 21
    int i = 2, j = 6;

    cout << "Input: N = ";
    printBinary(N, 11);
    cout << "M = ";
    printBinary(M, 5);
    cout << "i = " << i << ", j = " << j << endl;

    int output = replaceBits(N, M, i, j);

    cout << "Output: N = ";
    printBinary(output, 11);
    // Output should be 10001010100
    return 0;
}

