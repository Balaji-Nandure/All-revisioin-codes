// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1


/*
Approach Used in this Code:
---------------------------
- Since the factorial of a large number (like 100!) cannot be stored in standard integer types, we store the result as an array/vector of digits.
- We simulate the multiplication process as done by hand: for each number from 2 to N, we multiply it with the current result (stored as digits in a vector), taking care of carry at each step.
- The result is stored in reverse order (least significant digit at index 0) for easier multiplication and carry handling.

Time Complexity: O(N * D), where D is the number of digits in the result (which grows with N).
Space Complexity: O(D), where D is the number of digits in N!

Better Alternatives (with code in comments):
--------------------------------------------
1. **Using BigInteger Libraries (C++ does not have built-in, but in Python/Java you can use built-in big integer types):**
   - In C++, you can use libraries like GMP or Boost.Multiprecision for big integer arithmetic.
   - Example (Python):
     # Python's int can handle arbitrary precision
     def factorial(N):
         res = 1
         for i in range(2, N+1):
             res *= i
         return [int(d) for d in str(res)]

2. **Karatsuba Multiplication or FFT-based Multiplication:**
   - For extremely large N, you can use advanced multiplication algorithms to speed up the digit-wise multiplication.
   - Not required for typical competitive programming constraints.

3. **Storing Digits in Forward Order:**
   - You can store digits in forward order and reverse the multiplication logic, but storing in reverse is more natural for this simulation.

Detailed Code with Comments and Improvements:
---------------------------------------------
*/

class Solution {
public:
    vector<int> factorial(int N) {
        vector<int> ans; // To store the digits of the result (in reverse order)
        ans.push_back(1); // 0! and 1! = 1, so initialize with 1

        // Loop from 2 to N to compute N!
        for (int i = 2; i <= N; i++) {
            int carry = 0; // Initialize carry for each multiplication

            // Multiply current number i with the result stored in ans
            for (int j = 0; j < ans.size(); j++) {
                // Multiply the current digit by i and add carry from previous calculation
                int product = ans[j] * i + carry;

                // Store the last digit of product at current position
                ans[j] = product % 10;

                // Update carry for next position
                carry = product / 10;
            }

            // If carry remains after processing all digits, add its digits to ans
            while (carry) {
                ans.push_back(carry % 10); // Store the last digit of carry
                carry /= 10;               // Remove the last digit from carry
            }
        }

        // The result is stored in reverse order, so reverse it to get the correct order
        reverse(ans.begin(), ans.end());

        return ans; // Return the vector containing digits of N! in correct order
    }
};

/*
Dry Run Example:
----------------
Let's compute 5! step by step:

Initial ans: [1] (represents 1)

i = 2:
    Multiply 1 * 2 = 2
    ans: [2]

i = 3:
    Multiply 2 * 3 = 6
    ans: [6]

i = 4:
    Multiply 6 * 4 = 24
    Store 4, carry 2
    ans: [4]
    Add carry: ans: [4,2] (represents 24)

i = 5:
    Multiply 4 * 5 = 20, store 0, carry 2
    Multiply 2 * 5 = 10, add carry 2 = 12, store 2, carry 1
    ans: [0,2]
    Add carry: ans: [0,2,1] (represents 120)

Reverse ans: [1,2,0] => 120

So, 5! = 120, which matches the expected result.

*/