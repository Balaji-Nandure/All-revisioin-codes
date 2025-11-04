/*
Approach:
-----------
- The goal is to calculate the sum of all numbers from 1 to n using a function in C++.
- We'll define a function 'sumUptoN' that takes an integer n and returns the sum of numbers from 1 to n.
- The function will use a for loop to iterate from 1 to n, adding each number to a running total.
- In main, we'll initialize n, call the function, and print the result.
*/

#include<iostream> // Include input-output stream for cout
using namespace std; // Use standard namespace to avoid std:: prefix

// Function to calculate sum of numbers from 1 to n
int sumUptoN(int n){
    int sum = 0; // Initialize sum to 0
    for(int i = 1; i <= n; i++){ // Loop from 1 to n (inclusive)
        sum = sum + i; // Add current number to sum
    }
    return sum; // Return the final sum
}

int main(){
    int n = 10; // Initialize n with value 10 (can be changed as needed)
    cout << sumUptoN(n); // Call function and print the sum of numbers from 1 to n
    return 0; // Indicate successful program termination
}

/*
Dry Run:
-----------
n = 10

Step 1: main() starts.
Step 2: n is set to 10.
Step 3: sumUptoN(10) is called.
Step 4: Inside sumUptoN:
    - sum = 0
    - i = 1: sum = 0 + 1 = 1
    - i = 2: sum = 1 + 2 = 3
    - i = 3: sum = 3 + 3 = 6
    - i = 4: sum = 6 + 4 = 10
    - i = 5: sum = 10 + 5 = 15
    - i = 6: sum = 15 + 6 = 21
    - i = 7: sum = 21 + 7 = 28
    - i = 8: sum = 28 + 8 = 36
    - i = 9: sum = 36 + 9 = 45
    - i = 10: sum = 45 + 10 = 55
Step 5: Loop ends after i = 10.
Step 6: sumUptoN() returns 55.
Step 7: cout prints 55.
Step 8: main returns 0, program ends.

Output:
55
*/