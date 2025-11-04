/*
    Approach Used:
    ----------------
    This code uses **head recursion** to print numbers from 1 to n in increasing order.
    In head recursion, the recursive call is made before processing the current value.
    This means the function keeps calling itself until the base case is reached, and then processes (prints) the values while unwinding the recursion stack.

    Better Alternatives (without code):
    -----------------------------------
    1. **Tail Recursion**: Instead of head recursion, we can use tail recursion by processing (printing) the value before the recursive call. This prints numbers in decreasing order. Tail recursion can be optimized by compilers to iterative loops in some languages.
    2. **Iterative Approach**: Use a simple for or while loop to print numbers from 1 to n. This is more memory efficient as it avoids the overhead of recursive calls and stack usage.
    3. **Parameterization**: We can use an extra parameter to control the direction of printing (increasing or decreasing) or to accumulate results.

    Dry Run (for n = 5):
    ---------------------
    count(5) -> count(4) -> count(3) -> count(2) -> count(1) -> count(0)
    Now, as the stack unwinds:
    cout << 1 << " ";
    cout << 2 << " ";
    cout << 3 << " ";
    cout << 4 << " ";
    cout << 5 << " ";
    Output: 1 2 3 4 5
*/

// Head Recursion example: Print numbers from 1 to n in increasing order using recursion

#include<iostream>
using namespace std;

// Function to print numbers from 1 to n using head recursion
void count(int n){
    // Base case: If n is 0, stop recursion (no numbers left to print)
    if(n == 0)
        return;

    // Recursive call: Move towards the base case by reducing n
    count(n-1);

    // Processing: Print the current number after all smaller numbers have been printed
    cout << n << " ";
}

int main(){
    int n = 5; // Number up to which counting is to be printed

    // Function call to print counting from 1 to n
    count(n);

    // Return 0 to indicate successful execution
    return 0;
}

/*
    Dry Run for n = 5:
    -------------------
    Call Stack (before unwinding):
        count(5)
            count(4)
                count(3)
                    count(2)
                        count(1)
                            count(0) // base case, returns

    Unwinding (printing):
        cout << 1 << " ";
        cout << 2 << " ";
        cout << 3 << " ";
        cout << 4 << " ";
        cout << 5 << " ";

    Output: 1 2 3 4 5
*/