/*
Approach:
- The purpose of this program is to demonstrate the use of the 'break' statement in a loop.
- The program uses a for loop that is supposed to run 5 times.
- However, as soon as the loop starts, the 'break' statement is encountered, which causes the loop to terminate immediately after the first iteration.
- As a result, the output will be printed only once, even though the loop is set to run multiple times.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function: program execution starts here
    for(int i = 0; i < 5; i++){ // Loop from i = 0 to i < 5 (intended 5 iterations)
        cout << "Bhavya"; // Print "Bhavya" to the console
        break; // Exit the loop immediately after the first iteration
    }
    return 0; // Indicate successful program termination
}

/*
Dry Run:

Initial state:
i = 0

First iteration:
- i = 0, condition (i < 5) is true
- Print "Bhavya"
- 'break' is encountered, so exit the loop

Loop does not continue for i = 1, 2, 3, 4

Final Output:
Bhavya
*/