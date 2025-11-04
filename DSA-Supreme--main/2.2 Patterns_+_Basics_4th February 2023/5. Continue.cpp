/*
Approach:
- The purpose of this program is to demonstrate the use of the 'continue' statement in a loop.
- The program uses a for loop that iterates from 0 to 4 (total 5 iterations).
- Inside the loop, if the value of i is 2, the 'continue' statement is executed, which skips the rest of the loop body for that iteration.
- As a result, all values of i except 2 (i.e., 0, 1, 3, 4) are printed to the console.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function: program execution starts here
    for(int i = 0; i < 5; i++){ // Loop from i = 0 to i < 5 (5 iterations)
        if(i == 2) // Check if the current value of i is 2
            continue; // Skip the rest of the loop body for i = 2
        cout << i << endl; // Print the value of i followed by a newline
    }
    return 0; // Indicate successful program termination
}

/*
Dry Run:

Initial state:
i = 0

First iteration:
- i = 0, condition (i < 5) is true
- i == 2? No
- Print 0

Second iteration:
- i = 1, condition (i < 5) is true
- i == 2? No
- Print 1

Third iteration:
- i = 2, condition (i < 5) is true
- i == 2? Yes
- 'continue' is executed, so skip printing

Fourth iteration:
- i = 3, condition (i < 5) is true
- i == 2? No
- Print 3

Fifth iteration:
- i = 4, condition (i < 5) is true
- i == 2? No
- Print 4

Loop ends when i = 5 (i < 5 is false)

Final Output:
0
1
3
4
*/