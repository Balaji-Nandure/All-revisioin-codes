/*
Approach:
- The program reverses the digits of an integer, handling both positive and negative numbers.
- If the number is negative, it takes the absolute value for reversal and restores the sign at the end.
- It extracts digits from the end using modulus (%) and builds the reversed number by multiplying the current answer by 10 and adding the digit.
- After all digits are processed, if the original number was negative, the result is made negative.
*/

#include<iostream>
using namespace std;

int main(){
    int num = -124; // Initialize the number to be reversed (can be negative)
    int temp = num; // Store original number to check sign later
    int ans = 0;    // Will store the reversed number

    num = abs(num);  // Take absolute value to handle negative numbers

    // Loop to reverse the digits of the number
    while(num > 0){
        int digit = num % 10;      // Extract the last digit of num
        ans = ans * 10 + digit;    // Append digit to the reversed number
        num = num / 10;            // Remove the last digit from num
    }

    // If original number was negative, make the reversed number negative
    if(temp < 0){
        ans = -ans;
    }

    cout << "reversed number is " << ans << endl; // Output the reversed number

    return 0; // Indicate successful program termination
}

/*
Dry Run:
----------
num = -124

Step 1: temp = -124
Step 2: num = abs(-124) = 124
Step 3: ans = 0

First iteration:
    num > 0 --> 124 > 0 (true)
    digit = 124 % 10 = 4
    ans = 0 * 10 + 4 = 4
    num = 124 / 10 = 12

Second iteration:
    num > 0 --> 12 > 0 (true)
    digit = 12 % 10 = 2
    ans = 4 * 10 + 2 = 42
    num = 12 / 10 = 1

Third iteration:
    num > 0 --> 1 > 0 (true)
    digit = 1 % 10 = 1
    ans = 42 * 10 + 1 = 421
    num = 1 / 10 = 0

Loop ends as num = 0

Check if original number was negative:
    temp < 0 --> -124 < 0 (true)
    ans = -421

Output:
reversed number is -421
*/