/*
Approach:
-----------
- The goal is to print numbers from 1 to n using a function in C++.
- We'll define a function 'printCounting' that takes an integer n and prints numbers from 1 to n.
- The function will use a for loop to iterate from 1 to n and print each number.
- We'll call this function from main with a sample value of n.
*/

#include<iostream> // Include input-output stream for cout
using namespace std; // Use standard namespace to avoid std:: prefix

// Function to print counting from 1 to n
void printCounting(int n){
    // Loop from 1 to n (inclusive)
    for(int i = 1; i <= n; i++){
        cout << i << " "; // Print current number followed by a space
    }
}

int main(){
    int n = 5; // Initialize n with value 5 (can be changed as needed)
    printCounting(n); // Call function to print counting from 1 to n
    return 0; // Indicate successful program termination
}

/*
Dry Run:
-----------
n = 5

Step 1: main() starts.
Step 2: n is set to 5.
Step 3: printCounting(5) is called.
Step 4: Inside printCounting:
    - i = 1: prints "1 "
    - i = 2: prints "2 "
    - i = 3: prints "3 "
    - i = 4: prints "4 "
    - i = 5: prints "5 "
Step 5: Loop ends after i = 5.
Step 6: printCounting() ends, returns to main().
Step 7: main() returns 0, program ends.

Output:
1 2 3 4 5 
*/