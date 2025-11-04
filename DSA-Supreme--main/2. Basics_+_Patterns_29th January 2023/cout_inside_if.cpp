/*
Approach:
- Use the fact that output stream insertion (`cout << n`) returns a stream that is contextually convertible to true.
- Inside an if condition, `if(cout << n)` prints the number first, then the if body executes.
- This prints the number regardless of its sign, then prints "Bhavya".
*/

#include<iostream> // Include standard I/O
using namespace std; // Use the standard namespace

int main(){ // Program entry
    int n; // Variable to hold input number
    cin >> n; // Read integer from input
    if(cout << n){ // Output n as part of the condition; the stream is truthy if no error
        cout << "Bhavya"; // Then print the string
    } // End if
    return 0; // Successful execution
}

/*
Dry Run:
Input: -7
- Condition writes "-7" to output, evaluates to true -> body prints "Bhavya"
- Final output: -7Bhavya

Input: 0
- Condition writes "0" -> body prints "Bhavya"
- Final output: 0Bhavya
*/