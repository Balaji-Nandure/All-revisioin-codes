/*
Approach:
This code prints a fancy pattern in the shape of a diamond using numbers. 
The pattern is divided into two parts:
1. The upper half (including the middle row) is printed using the first inner loop.
2. The lower half is printed using the second inner loop.
For each row, numbers increase from 1 up to the row index, then decrease back to 1, forming a palindromic sequence.
*/

// Include the input-output stream library
#include<iostream>
// Use the standard namespace to avoid prefixing std::
using namespace std;

// Main function - entry point of the program
int main(){
    int n = 5; // Set the number of rows for the pattern (must be odd for symmetry)

    // Loop through each row
    for(int i = 0; i < n; i++){
        // For pattern-1: Print the upper half (including the middle row)
        for(int j = 0; j < 2*i+1; j++){
            // Only execute for the upper half (i <= n/2)
            if(i <= (n/2)){
                // If in the increasing part of the row
                if(j <= i)
                    cout << j+1; // Print increasing number
                else
                    cout << 2*i-j+1; // Print decreasing number
            }
        }
        // For pattern-2: Print the lower half
        for(int j = 0; j <= 2*(n-i-1); j++){
            // Only execute for the lower half (i > n/2)
            if(i > (n/2)){
                // If in the increasing part of the row
                if(j <= (n-i-1))
                    cout << j+1; // Print increasing number
                else
                    cout << 2*(n-i-1)-j+1; // Print decreasing number
            }
        }
        cout << endl; // Move to the next line after each row
    }
    return 0; // Indicate successful program termination
}

/*
Dry Run (for n = 5):

i = 0: (i <= 2)
    pattern-1: j from 0 to 0
        j=0: cout<<1
    Output: 1

i = 1: (i <= 2)
    pattern-1: j from 0 to 2
        j=0: cout<<1
        j=1: cout<<2
        j=2: cout<<1
    Output: 121

i = 2: (i <= 2)
    pattern-1: j from 0 to 4
        j=0: cout<<1
        j=1: cout<<2
        j=2: cout<<3
        j=3: cout<<2
        j=4: cout<<1
    Output: 12321

i = 3: (i > 2)
    pattern-2: j from 0 to 2
        j=0: cout<<1
        j=1: cout<<2
        j=2: cout<<1
    Output: 121

i = 4: (i > 2)
    pattern-2: j from 0 to 0
        j=0: cout<<1
    Output: 1

Final Output:
1
121
12321
121
1
*/