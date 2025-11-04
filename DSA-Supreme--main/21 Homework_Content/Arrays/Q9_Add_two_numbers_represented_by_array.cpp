// https://practice.geeksforgeeks.org/problems/sum-of-two-numbers-represented-as-arrays3110/1

/*
Approach:
- We simulate the addition of two numbers represented as arrays, where each array element is a digit.
- We start from the least significant digit (end of arrays) and move towards the most significant digit (start of arrays).
- We keep track of carry while adding corresponding digits.
- The result is built in reverse order and then reversed at the end.

Time Complexity: O(max(n, m)), where n and m are the sizes of the two arrays.
Space Complexity: O(max(n, m)), for the result array.

Alternative Approaches:
1. Use stacks to avoid reversing at the end (see commented code below).
2. Use linked lists if the numbers are very large and memory is a concern.
3. If arrays are guaranteed to be the same size, can simplify the loop.

Below is the improved code with detailed comments and a dry run at the end.
*/

vector<int> findSum(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size(); // Size of first number array
    int m = arr2.size(); // Size of second number array
    
    int i = n - 1; // Pointer for arr1 (starting from least significant digit)
    int j = m - 1; // Pointer for arr2 (starting from least significant digit)
    int carry = 0; // To store carry during addition
    vector<int> result; // To store the sum digits (in reverse order initially)

    // Loop until both arrays are processed and carry is zero
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry; // Start with carry from previous addition

        // If arr1 has digits left, add to sum and move pointer
        if (i >= 0) {
            sum += arr1[i];
            i--;
        }
        // If arr2 has digits left, add to sum and move pointer
        if (j >= 0) {
            sum += arr2[j];
            j--;
        }
        
        result.push_back(sum % 10); // Store the last digit of sum in result
        carry = sum / 10; // Update carry for next iteration
    }

    // The result is in reverse order, so reverse it to get the correct number
    reverse(result.begin(), result.end());
    return result;
}

/*
Alternative Approach 1: Using stacks to avoid reversing at the end
---------------------------------------------------------------
#include <stack>
vector<int> findSum(vector<int>& arr1, vector<int>& arr2) {
    stack<int> s1, s2, res;
    for (int d : arr1) s1.push(d);
    for (int d : arr2) s2.push(d);
    int carry = 0;
    while (!s1.empty() || !s2.empty() || carry) {
        int sum = carry;
        if (!s1.empty()) { sum += s1.top(); s1.pop(); }
        if (!s2.empty()) { sum += s2.top(); s2.pop(); }
        res.push(sum % 10);
        carry = sum / 10;
    }
    vector<int> result;
    while (!res.empty()) { result.push_back(res.top()); res.pop(); }
    return result;
}
---------------------------------------------------------------

Dry Run Example:
----------------
arr1 = [9, 9, 9]
arr2 = [1]

Step-by-step:
i = 2, j = 0, carry = 0
1st iteration: sum = 9 (arr1[2]) + 1 (arr2[0]) + 0 (carry) = 10
    result: [0], carry: 1
2nd iteration: sum = 9 (arr1[1]) + 0 (arr2 exhausted) + 1 (carry) = 10
    result: [0, 0], carry: 1
3rd iteration: sum = 9 (arr1[0]) + 0 + 1 = 10
    result: [0, 0, 0], carry: 1
4th iteration: sum = 0 + 0 + 1 = 1
    result: [0, 0, 0, 1], carry: 0

Reverse result: [1, 0, 0, 0] (which is 1000, as expected)
*/