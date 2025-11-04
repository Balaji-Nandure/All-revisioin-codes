/*
Approach:
-----------
- The goal is to calculate the sum of all even numbers up to a given number n using functions in C++.
- We'll implement two methods:
    1. Method 1: Iterate from 1 to n, check if the number is even using modulus (%) and add to sum if true.
    2. Method 2: Iterate from 2 to n, incrementing by 2 (since all even numbers are separated by 2), and add each to sum.
- Both methods will be implemented as separate functions.
- In main, we'll initialize n, call both functions, and print their results.
*/

#include<iostream> // Include input-output stream for cout
using namespace std; // Use standard namespace to avoid std:: prefix

// Method - 1: Using modulus operator to check for even numbers
int printEven(int n){
    int sum = 0; // Initialize sum to 0
    for(int i = 1; i <= n; i++){ // Loop from 1 to n (inclusive)
        if(i % 2 == 0) // Check if current number is even
            sum = sum + i; // Add even number to sum
    }
    return sum; // Return the final sum of even numbers
}

// Method - 2: Increment by 2 to directly access even numbers
int printEven1(int n){
    int sum = 0; // Initialize sum to 0
    for(int i = 2; i <= n; i = i + 2){ // Start from 2, increment by 2 to get all even numbers up to n
        sum = sum + i; // Add current even number to sum
    }
    return sum; // Return the final sum of even numbers
}

int main(){
    int n = 10; // Initialize n with value 10 (can be changed as needed)
    cout << printEven(n) << endl; // Call first method and print sum of even numbers up to n
    cout << printEven1(n);        // Call second method and print sum of even numbers up to n
    return 0; // Indicate successful program termination
}

/*
Dry Run:
-----------
n = 10

Method 1 (printEven):
- sum = 0
- i = 1: 1 % 2 != 0 (skip)
- i = 2: 2 % 2 == 0 -> sum = 0 + 2 = 2
- i = 3: 3 % 2 != 0 (skip)
- i = 4: 4 % 2 == 0 -> sum = 2 + 4 = 6
- i = 5: 5 % 2 != 0 (skip)
- i = 6: 6 % 2 == 0 -> sum = 6 + 6 = 12
- i = 7: 7 % 2 != 0 (skip)
- i = 8: 8 % 2 == 0 -> sum = 12 + 8 = 20
- i = 9: 9 % 2 != 0 (skip)
- i = 10: 10 % 2 == 0 -> sum = 20 + 10 = 30
- Final sum = 30

Method 2 (printEven1):
- sum = 0
- i = 2: sum = 0 + 2 = 2
- i = 4: sum = 2 + 4 = 6
- i = 6: sum = 6 + 6 = 12
- i = 8: sum = 12 + 8 = 20
- i = 10: sum = 20 + 10 = 30
- Final sum = 30

Output:
30
30
*/