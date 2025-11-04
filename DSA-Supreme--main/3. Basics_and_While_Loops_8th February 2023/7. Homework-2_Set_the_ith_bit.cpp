/*
Approach:
- The program sets the ith bit of a given integer n.
- To set the ith bit, we create a mask by left-shifting 1 by i positions (1 << i).
- We then perform a bitwise OR operation between n and the mask. This ensures the ith bit is set to 1, regardless of its previous value.
- The result is printed to the console.
*/

#include<iostream>
using namespace std;

// Function to set the ith bit of number n
void setIthBit(int n, int i){
    int mask = 1 << i; // Create a mask with only the ith bit set (left shift 1 by i positions)
    int ans = n | mask; // Set the ith bit of n using bitwise OR
    cout << ans << endl; // Output the result
}

int main(){
    int n = 3; // Example number (binary: 0011)
    setIthBit(n, 3); // Set the 3rd bit (counting from 0)
    return 0; // Indicate successful program termination
}

/*
Dry Run:
----------
n = 3 (binary: 0011)
i = 3

Step 1: mask = 1 << 3 = 8 (binary: 1000)
Step 2: ans = n | mask = 3 | 8 = 11 (binary: 1011)

Output:
11
*/