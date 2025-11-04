// // // This commented solution passes current as pass by value and hence takes more memory and time to create new string each time.
// // //  better solution is using same answer current with backtracking. (below commented code)


// #include <bits/stdc++.h>   // Includes all standard C++ libraries
// using namespace std;

// // Define a class named Solution (as per LeetCode standard)
// class Solution {
// public:
//     vector<string> result;  // To store all valid combinations of parentheses

//     // Helper function that performs backtracking
//     void backtrack(string current, int open, int close, int n) {
//         // Base case: if the current string length equals 2 * n, it’s a valid combination
//         if (current.length() == 2 * n) {
//             result.push_back(current);  // Add the valid string to the result
//             return;                     // Return to explore other possibilities
//         }

//         // If we can still add an opening parenthesis '('
//         if (open < n) {
//             // Add '(' and recurse with open count incremented
//             backtrack(current + '(', open + 1, close, n);
//         }

//         // If we can add a closing parenthesis ')'
//         // (only possible if close < open to maintain valid order)
//         if (close < open) {
//             // Add ')' and recurse with close count incremented
//             backtrack(current + ')', open, close + 1, n);
//         }
//     }

//     // Main function to generate all valid parentheses combinations
//     vector<string> generateParenthesis(int n) {
//         // Start backtracking with an empty string and zero open/close counts
//         backtrack("", 0, 0, n);
//         // Return the list of all valid combinations
//         return result;
//     }
// };

// // Driver code (for testing purposes)
// int main() {
//     Solution sol;            // Create an object of Solution class
//     int n;                   // Variable to store user input
//     cout << "Enter number of pairs: ";  
//     cin >> n;                // Read the number of pairs of parentheses

//     // Call the function to generate all valid combinations
//     vector<string> parentheses = sol.generateParenthesis(n);

//     // Output all combinations
//     cout << "All combinations of well-formed parentheses:\n";
//     for (const string &s : parentheses) {  // Iterate through the result vector
//         cout << s << "\n";                 // Print each valid combination
//     }

//     return 0;  // End of program
// }


// // Leetcode 22 generate parenthesis
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Helper function to generate all valid parenthesis combinations
void generateParenthesisHelper(int open, int close, string &current, vector<string>& result, int n) {
    // ✅ Base case: when the current string has n open and n close brackets
    if(open == n && close == n) {
        result.push_back(current); // store the valid combination
        return;
    }
    // If we can still add an open bracket (i.e., open < n)
    if(open < n) {
        current.push_back('(');        // add '('
        generateParenthesisHelper(open + 1, close, current, result, n);
        current.pop_back();            // backtrack
    }
    // We can add a close bracket only if it won't exceed the number of open brackets
    if(close < open) {
        current.push_back(')');        // add ')'
        generateParenthesisHelper(open, close + 1, current, result, n);
        current.pop_back();            // backtrack
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string current;
    generateParenthesisHelper(0, 0, current, result, n); // Start with 0 opens and closes
    return result;
}

// Uncomment below to test the function

int main() {
    int n = 3; // Example input
    vector<string> result = generateParenthesis(n);
    for(const string &s : result) {
        cout << s << endl;
    }
    return 0;
}

