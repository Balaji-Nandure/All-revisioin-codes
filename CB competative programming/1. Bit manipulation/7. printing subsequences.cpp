/*
Printing Subsequences using Bit Manipulation

Approach:
Given a string of length n, there are 2^n subsequences possible (including the empty subsequence).
Each subsequence can be represented by a n-bit number: for each bit position, 
if the bit is 1, include the corresponding character in the subsequence.
Iterate mask from 0 to 2^n - 1, and for each mask, generate the corresponding subsequence.

Time Complexity: O(n * 2^n)
*/

#include <iostream>            // Include header for input and output streams
#include <string>              // Include header for using strings
using namespace std;           // Use the standard namespace

// tc = O(n * 2^n)
// Function to print all subsequences of a string using bit manipulation
void printSubsequences(const string& str) {
    int n = str.length();              // Get the length of the string
    int total = 1 << n;                // Compute 2^n, total possible subsequences

    // Loop through all possible masks from 0 to (2^n)-1
    for (int mask = 0; mask < total; ++mask) {
        string subseq = "";            // Initialize an empty string to store current subsequence
        // For each bit position in the mask
        for (int j = 0; j < n; ++j) {
            // If the j-th bit is set in mask, include str[j] in subsequence
            if ((mask >> j) & 1) {
                subseq += str[j];      // Add the character at position j
            }
        }
        cout << subseq << endl;        // Print the generated subsequence for this mask
    }
}

// Main function
int main() {
    string s;                              // Declare a string variable to store user input
    cout << "Enter a string: ";            // Prompt the user to enter a string
    cin >> s;                              // Read the string from user input
    cout << "All subsequences are:" << endl; // Output heading before listing subsequences
    printSubsequences(s);                  // Call the function to print all subsequences
    return 0;                              // Return 0 to indicate successful execution
}
