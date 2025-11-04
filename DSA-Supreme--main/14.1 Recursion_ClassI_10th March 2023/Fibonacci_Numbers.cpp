/*
    Approach Used:
    ----------------
    This code calculates the nth Fibonacci number using a simple recursive approach.
    The Fibonacci sequence is defined as:
        F(1) = 0
        F(2) = 1
        F(n) = F(n-1) + F(n-2) for n > 2

    The function 'fib' recursively calls itself to compute the (n-1)th and (n-2)th Fibonacci numbers and adds them.
    This approach is simple but inefficient for large n due to repeated calculations (exponential time complexity).
*/

#include<iostream>
using namespace std;

// Recursive function to find the nth Fibonacci number
int fib(int n){
    // Base case: if n is 1, return 0 (first term of Fibonacci sequence)
    if(n == 1){
        return 0;
    }
    // Base case: if n is 2, return 1 (second term of Fibonacci sequence)
    if(n == 2){
        return 1;
    }
    // Recursive case: sum of previous two Fibonacci numbers
    int ans = fib(n-1) + fib(n-2);
    return ans;
}

int main(){
    int n = 5; // The term of the Fibonacci sequence to compute (5th term)
    int ans = fib(n); // Call the recursive function to get the nth Fibonacci number
    cout << ans << endl; // Output the result
    return 0;
}

/*
    Better Alternatives (without code):
    -----------------------------------
    1. Memoization (Top-Down DP):
        - Store the results of already computed Fibonacci numbers in an array or map.
        - Before computing fib(n), check if it is already computed.
        - This reduces the time complexity from O(2^n) to O(n).

    2. Tabulation (Bottom-Up DP):
        - Use an array to iteratively compute Fibonacci numbers from 1 to n.
        - Start from the base cases and build up to the desired n.
        - Time complexity: O(n), Space complexity: O(n).

    3. Space Optimized Iterative Approach:
        - Only keep track of the last two computed Fibonacci numbers.
        - Reduces space complexity to O(1) while maintaining O(n) time.

    4. Matrix Exponentiation:
        - Uses properties of Fibonacci numbers and matrix multiplication.
        - Can compute nth Fibonacci number in O(log n) time.

    5. Binet's Formula (Direct Formula):
        - Uses the closed-form expression for Fibonacci numbers.
        - Not recommended for large n due to floating point precision issues.

    Note: For large values of n, recursive approach is not recommended due to stack overflow and exponential time.

    Dry Run (n = 5):
    ----------------
    fib(5)
      -> fib(4) + fib(3)
         fib(4)
           -> fib(3) + fib(2)
              fib(3)
                -> fib(2) + fib(1)
                   fib(2) = 1
                   fib(1) = 0
                => fib(3) = 1 + 0 = 1
              fib(2) = 1
           => fib(4) = 1 + 1 = 2
         fib(3)
           -> fib(2) + fib(1)
              fib(2) = 1
              fib(1) = 0
           => fib(3) = 1 + 0 = 1
      => fib(5) = 2 + 1 = 3

    Output: 3
*/