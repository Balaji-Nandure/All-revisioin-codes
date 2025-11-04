/*
Approach:
---------
Given two numbers represented as arrays of digits (each element is a digit, most significant digit at index 0), we want to compute their sum and print the result as an array of digits.

- We start from the least significant digit (end of each array) and add corresponding digits, keeping track of carry.
- If one array is longer, we continue adding its remaining digits with carry.
- If there's a carry left after all digits are processed, we append it.
- Since we build the result from least to most significant digit, we reverse the result at the end.

This is similar to how we do addition by hand.

Better Alternatives:
--------------------
1. Pad the shorter array with leading zeros to make both arrays the same length, then process in a single loop.
2. Use std::string for very large numbers, or use built-in BigInteger types in languages that support them.
3. For very large numbers, process in blocks of digits (e.g., 9 digits at a time) for efficiency.

Alternative code for approach 1 (padding):
------------------------------------------
    // Pad shorter array with zeros
    int n = max(a.size(), b.size());
    while (a.size() < n) a.insert(a.begin(), 0);
    while (b.size() < n) b.insert(b.begin(), 0);
    // Now process both arrays from end as in main approach

Dry Run:
--------
a = [5,6,3]  // represents 563
b = [8,4,2]  // represents 842

Step-by-step:
i=2, j=2: 3+2+0=5, digit=5, carry=0, ans=[5]
i=1, j=1: 6+4+0=10, digit=0, carry=1, ans=[5,0]
i=0, j=0: 5+8+1=14, digit=4, carry=1, ans=[5,0,4]
carry left: 1, ans=[5,0,4,1]
Reverse: [1,4,0,5] => 1405

Code with detailed comments:
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the sum of two numbers represented by arrays
void findSum(vector<int> &a, vector<int> &b)
{
    vector<int> ans; // To store the result digits (in reverse order initially)
    int carry = 0; // Carry for addition, starts at 0

    // i and j point to the last digit (least significant) of a and b
    int i = a.size() - 1; // Index for array a
    int j = b.size() - 1; // Index for array b

    // Add digits from both arrays while both have digits left
    while (i >= 0 && j >= 0)
    {
        int x = a[i] + b[j] + carry; // Add corresponding digits and carry
        int digit = x % 10;          // Extract the unit digit for current position
        ans.push_back(digit);        // Store the digit in result
        carry = x / 10;              // Update carry for next iteration
        i--;                         // Move to next digit in a
        j--;                         // Move to next digit in b
    }

    // If a has more digits left, process them
    while (i >= 0)
    {
        int x = a[i] + carry;        // Add remaining digit and carry
        int digit = x % 10;          // Extract the unit digit
        ans.push_back(digit);        // Store in result
        carry = x / 10;              // Update carry
        i--;                         // Move to next digit
    }

    // If b has more digits left, process them
    while (j >= 0)
    {
        int x = b[j] + carry;        // Add remaining digit and carry
        int digit = x % 10;          // Extract the unit digit
        ans.push_back(digit);        // Store in result
        carry = x / 10;              // Update carry
        j--;                         // Move to next digit
    }

    // If there's any carry left after all digits are processed, add it
    if (carry)
    {
        ans.push_back(carry);
    }

    // The result is in reverse order, so reverse it to get the correct number
    reverse(ans.begin(), ans.end());

    // Print the result array (each digit separated by space)
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Example input: two numbers as arrays of digits
    vector<int> a{5,6,3}; // represents 563
    vector<int> b{8,4,2}; // represents 842

    findSum(a, b); // Output: 1 4 0 5 (i.e., 1405)

    return 0;
}

/*
Dry Run:
--------
a = [5,6,3]  // 563
b = [8,4,2]  // 842

i=2, j=2: 3+2+0=5, digit=5, carry=0, ans=[5]
i=1, j=1: 6+4+0=10, digit=0, carry=1, ans=[5,0]
i=0, j=0: 5+8+1=14, digit=4, carry=1, ans=[5,0,4]
carry left: 1, ans=[5,0,4,1]
Reverse: [1,4,0,5] => 1405

Alternative Approach (with padding):
------------------------------------
    // Pad shorter array with zeros
    int n = max(a.size(), b.size());
    while (a.size() < n) a.insert(a.begin(), 0);
    while (b.size() < n) b.insert(b.begin(), 0);
    // Now process both arrays from end as in main approach
*/