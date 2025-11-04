#include<iostream>
using namespace std;

// Approach:
// We use the ternary operator to check if a person is eligible to vote based on their age.
// If age is greater than or equal to 18, print "Vote", else print "Not Vote".

int main(){
    int age = 15; // Initialize age variable with value 15

    // Ternary operator to check voting eligibility
    // If age >= 18, prints "Vote", else prints "Not Vote"
    age >= 18 ? cout << "Vote" : cout << "Not Vote"; // Just like if-else blocks

    return 0; // End of program
}

/*
Dry Run:
----------
age = 15

Step 1: Check if age >= 18
        15 >= 18 --> false

Step 2: Since condition is false, cout << "Not Vote" is executed.

Output:
Not Vote
*/