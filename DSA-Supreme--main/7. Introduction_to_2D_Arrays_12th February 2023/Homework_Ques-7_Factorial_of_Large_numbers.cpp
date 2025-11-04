/*
Approach Used:
---------------
To compute the factorial of a large number (like 50!), the result can be too big to fit in standard data types (int, long, etc). 
So, we use an array/vector to store each digit of the result separately, simulating manual multiplication as done on paper.

Key Steps:
1. Initialize a vector with 1 (since 0! = 1! = 1).
2. For every number from 2 to N, multiply it with the current result stored in the vector, digit by digit.
3. Handle carry for each multiplication and append new digits as needed.
4. At the end, reverse the vector to print the number in correct order.

Improvements Made:
------------------
- Added detailed comments for each important line.
- Used more descriptive variable names.
- Used range-based for loop for output.
- Added function to allow user input for N.
- Added dry run for N=5 at the end.
- Provided alternative approach in comments.

Alternative Approach (using strings for even larger numbers):
-------------------------------------------------------------
/*
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Multiplies a large number (as string) by an integer
string multiply(string num, int n) {
    int carry = 0;
    string result = "";
    reverse(num.begin(), num.end());
    for(char c : num) {
        int prod = (c - '0') * n + carry;
        result += (prod % 10) + '0';
        carry = prod / 10;
    }
    while(carry) {
        result += (carry % 10) + '0';
        carry /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

void factorial_string(int N) {
    string res = "1";
    for(int i = 2; i <= N; ++i) {
        res = multiply(res, i);
    }
    cout << res << endl;
}
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to compute factorial of large numbers
void factorial(int N){
    // Vector to store digits of the result, least significant digit at index 0
    vector<int> result;
    result.push_back(1); // Start with 1 as initial factorial value

    // Loop from 2 to N to multiply each number with the current result
    for(int num = 2; num <= N; num++){
        int carry = 0; // Initialize carry for each multiplication

        // Multiply current number with each digit of the result
        for(int i = 0; i < result.size(); i++){
            int prod = result[i] * num + carry; // Multiply and add carry
            result[i] = prod % 10;              // Store the single digit at current position
            carry = prod / 10;                  // Update carry
        }

        // If carry remains, add its digits to the result vector
        while(carry){
            result.push_back(carry % 10); // Push the last digit of carry
            carry /= 10;                  // Remove the last digit from carry
        }
    }

    // The result is stored in reverse order, so reverse it to print correctly
    reverse(result.begin(), result.end());

    // Output the result
    for(int digit : result){
        cout << digit;
    }
    cout << endl;
}

int main(){
    int N;
    cout << "Enter N to compute N! : ";
    cin >> N;
    factorial(N);
    return 0;
}

/*
Dry Run for N = 5:
------------------
Initial result: [1]
Multiply by 2: [2]
Multiply by 3: [6]
Multiply by 4: 6*4=24 -> [4], carry=2; push carry: [4,2] => [2,4] after reverse
Multiply by 5: 4*5=20, [0], carry=2; 2*5=10+2=12, [2], carry=1; push carry: [0,2,1] => [1,2,0] after reverse
Final output: 120

Output:
Enter N to compute N! : 5
120
*/

//
// Note: For extremely large N (hundreds/thousands), use string-based or BigInteger libraries for better performance and memory efficiency.
//
/*
Alternative: Use GMP or Boost.Multiprecision for production-level big integer support.
*/