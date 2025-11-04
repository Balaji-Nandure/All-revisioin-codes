/*
Approach:
- The program counts the number of set bits (bits with value 1) in the binary representation of a given integer.
- It repeatedly checks the least significant bit (LSB) of the number using bitwise AND with 1.
- If the LSB is set (i.e., equals 1), it increments the count.
- The number is then right-shifted by 1 to check the next bit.
- This process continues until the number becomes 0.
*/

#include<iostream>
using namespace std;

int main(){
    int n = 7; // Initialize the number whose set bits are to be counted

    int count = 0; // Initialize count of set bits to 0

    // Loop until all bits are processed (n becomes 0)
    while(n != 0){ 
        // Check if the least significant bit is set (1)
        if((n & 1) == 1){ // (n & 1) extracts the LSB; if it is 1, increment count
            count++; // Increment count if set bit is found
        }
        n = n >> 1; // Right shift n by 1 to check the next bit in the next iteration
    }

    cout << count << endl; // Output the total number of set bits

    return 0; // Indicate successful program termination
}

/*
Dry Run:
----------
n = 7 (binary: 111)
count = 0

First iteration:
    n = 7 (111)
    n & 1 = 1 (LSB is 1)
    count = 1
    n = n >> 1 = 3 (011)

Second iteration:
    n = 3 (011)
    n & 1 = 1 (LSB is 1)
    count = 2
    n = n >> 1 = 1 (001)

Third iteration:
    n = 1 (001)
    n & 1 = 1 (LSB is 1)
    count = 3
    n = n >> 1 = 0 (000)

Loop ends as n = 0

Output:
3
*/