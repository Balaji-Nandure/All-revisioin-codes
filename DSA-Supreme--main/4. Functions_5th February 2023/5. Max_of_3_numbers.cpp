#include<iostream>
using namespace std;

// Approach:
// The function 'maxi' takes three integers as input and returns the maximum among them.
// It uses conditional statements to compare the values and returns the largest.

// Function to find maximum of three numbers
int maxi(int a, int b, int c){
    // If 'a' is greater than both 'b' and 'c', return 'a'
    if(a > b && a > c){
        return a;
    }
    // Else if 'b' is greater than both 'a' and 'c', return 'b'
    else if(b > a && b > c){
        return b;
    }
    // Otherwise, 'c' is the greatest (or equal to the greatest), return 'c'
    else{
        return c;
    }
}

int main(){
    int a = 7, b = 5, c = 4; // Initialize three numbers
    cout << maxi(a, b, c);    // Output the maximum of the three numbers
    return 0;                 // Indicate successful program termination
}

/*
Approach:
- Define a function 'maxi' to compare three numbers and return the largest.
- In main, initialize three numbers and print the result of 'maxi'.

Dry Run:
a = 7, b = 5, c = 4
Call maxi(7, 5, 4)
    - Check if 7 > 5 && 7 > 4 -> true
    - So, return 7
Output: 7
*/