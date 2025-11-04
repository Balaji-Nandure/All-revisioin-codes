#include<iostream>
using namespace std;

/*
Approach:
-----------
- This code calculates the factorial of a given number using recursion.
- The factorial of a number n (denoted as n!) is the product of all positive integers less than or equal to n.
- The recursive approach breaks the problem into smaller subproblems: n! = n * (n-1)!
- The recursion stops at the base case: 0! = 1! = 1

Better/Alternative Approaches (without code):
---------------------------------------------
1. Iterative Approach:
   - Use a loop to multiply numbers from 1 to n.
   - More efficient in terms of memory (no function call stack overhead).
   - Avoids stack overflow for large n.

2. Memoization (Dynamic Programming):
   - Store already computed factorials to avoid redundant calculations (useful if factorial is called repeatedly for overlapping subproblems).

3. Using BigInteger/Arbitrary Precision Libraries:
   - For very large n, use libraries that support big integers to avoid integer overflow.

4. Tail Recursion:
   - Use tail recursion to optimize stack usage (if compiler supports tail call optimization).

5. Input Validation:
   - Add checks for negative numbers and handle accordingly (factorial is not defined for negative integers).

*/

// Recursive function to calculate factorial of n
int factorial(int n){
    // Base case: factorial of 0 or 1 is 1
    if(n == 0 || n == 1)
        return 1; // Stop recursion here

    // Recursive case: n! = n * (n-1)!
    int ans = n * factorial(n-1); // Multiply n by factorial of (n-1)
    return ans; // Return the computed factorial
}

int main(){
    int n = 5; // Input number for which factorial is to be calculated

    // Calculate factorial of n using the recursive function
    int ans = factorial(n);

    // Output the result
    cout << ans << endl;

    return 0; // Indicate successful program termination
}

/*
Dry Run:
---------
Let n = 5

factorial(5)
    = 5 * factorial(4)
        = 4 * factorial(3)
            = 3 * factorial(2)
                = 2 * factorial(1)
                    = 1 (base case)
                = 2 * 1 = 2
            = 3 * 2 = 6
        = 4 * 6 = 24
    = 5 * 24 = 120

So, output will be: 120
*/