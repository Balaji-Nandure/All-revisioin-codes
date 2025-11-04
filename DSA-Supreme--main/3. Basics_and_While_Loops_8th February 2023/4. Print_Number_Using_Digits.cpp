/*
Approach:
- The program reconstructs a number from its individual digits stored in an array.
- It iterates through the array, and for each digit, it multiplies the current answer by 10 and adds the digit.
- This process effectively shifts the previous digits to the left and appends the new digit at the end, building the number as if writing the digits in order.
*/

#include<iostream>
using namespace std;

int main(){
    int digit[4] = {8,2,3,7}; // Digits are given in the form of an array: 8, 2, 3, 7

    int ans = 0; // Initialize ans to 0, will store the final number

    // Loop through each digit in the array
    for(int i = 0; i < 4; i++){ 
        // Multiply current ans by 10 (shift left) and add the current digit
        ans = ans * 10 + digit[i]; // Builds the number step by step
    }

    cout << ans << endl; // Output the final number formed from the digits

    return 0; // Indicate successful program termination
}

/*
Dry Run:
----------
digit = {8, 2, 3, 7}
ans = 0

First iteration (i=0):
    ans = 0 * 10 + 8 = 8

Second iteration (i=1):
    ans = 8 * 10 + 2 = 82

Third iteration (i=2):
    ans = 82 * 10 + 3 = 823

Fourth iteration (i=3):
    ans = 823 * 10 + 7 = 8237

Output:
8237
*/