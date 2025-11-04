/*
Approach:
- The program extracts and prints each digit of a given number starting from the last digit (rightmost).
- It repeatedly finds the last digit using the modulus operator (%) and then removes that digit by dividing the number by 10.
- This process continues until all digits are printed (i.e., until the number becomes 0).
*/

#include<iostream>
using namespace std;

int main(){
    int n = 623; // Initialize the number whose digits are to be printed

    // Loop to extract and print each digit from right to left
    while(n > 0){ // Continue until all digits are processed (n becomes 0)
        int digit = n % 10; // Get the last digit of n
        cout << digit << " "; // Print the extracted digit followed by a space
        n = n / 10; // Remove the last digit from n
    }

    return 0; // Indicate successful program termination
}

/*
Dry Run:
----------
n = 623

First iteration:
    n > 0 --> 623 > 0 (true)
    digit = 623 % 10 = 3
    print 3
    n = 623 / 10 = 62

Second iteration:
    n > 0 --> 62 > 0 (true)
    digit = 62 % 10 = 2
    print 2
    n = 62 / 10 = 6

Third iteration:
    n > 0 --> 6 > 0 (true)
    digit = 6 % 10 = 6
    print 6
    n = 6 / 10 = 0

Loop ends as n = 0

Output:
3 2 6 
*/