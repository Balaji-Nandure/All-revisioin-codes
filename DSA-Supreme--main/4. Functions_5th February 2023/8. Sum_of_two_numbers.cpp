#include<iostream> // including input-output stream library for cin, cout
using namespace std; // using standard namespace to avoid std:: prefix

// Approach:
// 1. Create a function 'sum' that takes two integers and returns their sum.
// 2. In main, call the sum function with two numbers and store the result.
// 3. Print the result.

// Function to calculate sum of two numbers
int sum(int a, int b) { // 'a' and 'b' are input parameters, function returns their sum
    return (a + b); // returns the sum of a and b to the caller
}

int main() {
    int ans = sum(5, 3);  // Calls sum(5,3), returns 8, stores in 'ans'
    cout << "Sum is " << ans; // Prints the result: "Sum is 8"
    return 0; // Indicates successful program termination
}

/*
Dry Run:
----------
Step 1: main() starts
Step 2: Calls sum(5, 3)
        - a = 5, b = 3
        - returns 5 + 3 = 8
Step 3: ans = 8
Step 4: Prints "Sum is 8"
Step 5: Program ends
*/