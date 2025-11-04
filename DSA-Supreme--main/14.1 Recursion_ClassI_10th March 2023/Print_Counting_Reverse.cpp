/*
Approach Used:
---------------
- This code prints numbers from n down to 1 using a tail recursive function.
- Tail recursion means the recursive call is the last operation in the function, which can be optimized by the compiler to avoid extra stack frames.
- The function 'count' prints the current number and then recursively calls itself with n-1 until it reaches 0 (base case).

Better/Alternative Approaches (without code):
---------------------------------------------
1. Iterative Approach:
   - Use a simple for or while loop to print numbers from n down to 1.
   - More efficient in terms of memory (no function call stack overhead).
   - Avoids stack overflow for large n.

2. Head Recursion (for printing 1 to n):
   - If you want to print numbers from 1 to n, place the print statement after the recursive call.

3. Using STL Algorithms:
   - For more complex patterns, use STL algorithms or generate sequences and reverse them.

4. Input Validation:
   - Add checks for negative numbers or invalid input.

5. Tail Recursion Optimization:
   - Some compilers optimize tail recursion, but not all. For very large n, prefer iteration.

*/

#include<iostream>
using namespace std;

// Tail recursive function to print numbers from n down to 1
void count(int n){
    // Base case: when n reaches 0, stop recursion
    if(n == 0)
        return; // No more numbers to print, exit function

    // Print the current number (processing step)
    cout << n << " ";

    // Recursive call with n-1 (move towards base case)
    count(n-1);
}

int main(){
    int n = 5; // Initialize n with the starting number

    // Call the recursive function to print counting in reverse
    count(n);

    cout << endl; // Print newline for better output formatting

    return 0; // Indicate successful program termination
}

/*
Dry Run (n = 5):
-----------------
count(5): prints 5, calls count(4)
    count(4): prints 4, calls count(3)
        count(3): prints 3, calls count(2)
            count(2): prints 2, calls count(1)
                count(1): prints 1, calls count(0)
                    count(0): base case, returns
Output: 5 4 3 2 1

Summary:
--------
- The function prints numbers from n down to 1 using tail recursion.
- For n = 5, output is: 5 4 3 2 1
- For large n, prefer iterative approach to avoid stack overflow.
*/