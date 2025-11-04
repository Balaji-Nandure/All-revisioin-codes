// Approach: 
// The program demonstrates how the extraction operator (>>) with cin can be used inside an if statement.
// If the input operation is successful (i.e., a valid integer is entered), the if condition evaluates to true and "Bhavya" is printed.
// If the input fails (e.g., a non-integer is entered), the if condition evaluates to false and nothing is printed.

#include<iostream> // Include the input-output stream library for cin and cout
using namespace std; // Use the standard namespace to avoid writing std:: repeatedly

int main(){ // Main function - entry point of the program
    int n; // Declare an integer variable n to store user input

    // Try to read an integer from the user using cin.
    // If the input is valid (i.e., user enters an integer), cin>>n returns true (non-zero).
    // If the input is invalid (e.g., user enters a character), cin>>n returns false (zero).
    if(cin >> n){ // Check if input operation was successful
        cout << "Bhavya"; // Print "Bhavya" if input was successful
    }
    // If input fails, nothing is printed.
}

/*
Dry Run:
Case 1: User inputs 25
- cin >> n succeeds (n becomes 25) -> if(true) -> prints: Bhavya

Case 2: User inputs x (non-integer)
- cin >> n fails -> if(false) -> prints nothing
*/