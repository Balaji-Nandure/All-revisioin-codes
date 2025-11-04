/*
Approach:
- This program demonstrates the use of the 'switch' statement in C++.
- The user is prompted to enter an integer value.
- Based on the value entered, the program prints a specific message for cases 1, 2, or 3.
- If the value does not match any of these cases, the default case is executed.
- The 'break' statement is used after each case to prevent fall-through.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function: program execution starts here
    int val; // Declare an integer variable 'val' to store user input

    cin >> val; // Take input from the user and store it in 'val'

    // Switch statement to handle multiple cases based on the value of 'val'
    switch(val){ // The expression should be an integer or character
        case 1:
            cout << "Bhavya"; // Print "Bhavya" if val is 1
            break; // Exit the switch after executing this case

        case 2:
            cout << "Bhava1"; // Print "Bhava1" if val is 2
            break; // Exit the switch after executing this case

        case 3:
            cout << "Bhavya2"; // Print "Bhavya2" if val is 3
            break; // Exit the switch after executing this case

        default:
            cout << "Class is over"; // Print this if val is not 1, 2, or 3
            break; // Exit the switch after executing default case
    }
    
    return 0; // Indicate successful program termination
}

/*
Dry Run:

Case 1:
Input: 1
switch(val): val == 1 -> case 1 matches
Output: Bhavya

Case 2:
Input: 2
switch(val): val == 2 -> case 2 matches
Output: Bhava1

Case 3:
Input: 3
switch(val): val == 3 -> case 3 matches
Output: Bhavya2

Case default:
Input: 5
switch(val): val does not match 1, 2, or 3 -> default case
Output: Class is over
*/