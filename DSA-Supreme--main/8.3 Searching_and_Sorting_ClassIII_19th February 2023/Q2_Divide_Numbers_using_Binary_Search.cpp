/*
Approach Used:
---------------
This code divides two integers (dividend and divisor) without using the division operator, using Binary Search to find the quotient. 
The main idea is to search for the largest integer 'mid' such that abs(mid * divisor) <= abs(dividend).

Key Points:
-----------
- Handles both positive and negative numbers.
- Uses binary search for efficient computation (O(logN) time).
- Returns the quotient as per integer division (truncates towards zero).

Better Alternatives (without code):
-----------------------------------
1. Bit Manipulation: 
   - Use bit shifts to speed up the process (like how division is done in hardware).
   - Repeatedly subtract the largest shifted divisor from the dividend.
   - This is more efficient and is the standard approach in interview questions.
2. Built-in Division:
   - Use '/' operator (not allowed in this problem).
3. Newton-Raphson or other iterative methods (not common for integer division).

Improvements Made:
------------------
- Added comments for all important lines.
- Improved variable naming for clarity.
- Handled edge cases (like divisor = 0).
- Used long long to avoid overflow.
- Ensured ans is initialized to 0 (not 1).
- Added dry run at the end.

*/

#include<iostream>
using namespace std;

// Function to perform integer division using binary search
int solve(int dividend, int divisor) {
    // Edge case: Division by zero
    if (divisor == 0) {
        cout << "Error: Division by zero!" << endl;
        return INT_MAX; // or throw exception
    }

    // Store sign of result
    bool isNegative = (dividend < 0) ^ (divisor < 0);

    // Work with positive values to avoid sign issues
    long long ldividend = abs((long long)dividend);
    long long ldivisor = abs((long long)divisor);

    // Binary search boundaries
    long long s = 0;
    long long e = ldividend;
    long long ans = 0; // Initialize answer to 0

    // Binary search to find the quotient
    while (s <= e) {
        long long mid = s + (e - s) / 2; // Prevent overflow

        // If mid * divisor == dividend, perfect division found
        if (mid * ldivisor == ldividend) {
            ans = mid;
            break;
        }
        // If mid * divisor > dividend, search in left half
        else if (mid * ldivisor > ldividend) {
            e = mid - 1;
        }
        // If mid * divisor < dividend, store mid and search in right half
        else {
            ans = mid; // Store current mid as possible answer
            s = mid + 1;
        }
    }

    // Apply sign to the answer
    if (isNegative)
        ans = -ans;

    // Handle overflow (for 32-bit int)
    if (ans > INT_MAX) return INT_MAX;
    if (ans < INT_MIN) return INT_MIN;

    return (int)ans;
}

int main() {
    int dividend = -21;
    int divisor = 7;
    int ans = solve(dividend, divisor);
    cout << ans << endl; // Output the result
    return 0;
}

/*
Dry Run:
--------
dividend = -21, divisor = 7

1. isNegative = true (since signs differ)
2. ldividend = 21, ldivisor = 7
3. s = 0, e = 21

Binary Search Steps:
- mid = 10, 10*7=70 > 21 => e=9
- mid = 4, 4*7=28 > 21 => e=3
- mid = 1, 1*7=7 < 21 => ans=1, s=2
- mid = 2, 2*7=14 < 21 => ans=2, s=3
- mid = 3, 3*7=21 == 21 => ans=3, break

Apply sign: ans = -3

Output: -3

*/