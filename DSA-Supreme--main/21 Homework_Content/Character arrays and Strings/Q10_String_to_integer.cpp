// https://leetcode.com/problems/string-to-integer-atoi/description/

/*
Approach Used in This Code:
---------------------------
- The function implements the classic "atoi" (ASCII to Integer) conversion, handling leading spaces, optional sign, digits, and overflow.
- Steps:
    1. Skip leading whitespaces.
    2. Check for optional '+' or '-' sign.
    3. Parse consecutive digits and build the integer.
    4. Handle integer overflow/underflow by clamping to INT_MAX/INT_MIN.
    5. Stop parsing at the first non-digit character after optional sign and digits.

Time Complexity: O(N), where N = length of the string (each character is processed at most once).
Space Complexity: O(1) extra.

Better Alternatives:
--------------------
1. Using Regular Expressions (not allowed in LeetCode, but possible in practice):
   - Use regex to extract the valid integer substring, then convert using stoll or similar.
   - Example (C++11+):
     ```
     #include <regex>
     int myAtoi(string s) {
         smatch m;
         regex_search(s, m, regex("^\\s*([+-]?\\d+)"));
         try {
             return stoi(m[1]);
         } catch (...) {
             return m[1].str()[0] == '-' ? INT_MIN : INT_MAX;
         }
     }
     ```
   - This is concise but not allowed in most coding interviews.

2. Using stringstream (C++):
   - Use stringstream to parse the integer, which handles spaces and sign.
   - Example:
     ```
     int myAtoi(string s) {
         stringstream ss(s);
         int x = 0;
         ss >> x;
         return x;
     }
     ```
   - This does not handle overflow/underflow as required by the problem.

3. Manual parsing (as in this code) is the most robust and interview-friendly.

---------------------------------
Detailed Code with Comments & Dry Run:
---------------------------------*/

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0; // Pointer to traverse the string
        long long num = 0; // Use long long to handle overflow during calculation
        int sign = 1; // Default sign is positive

        // 1. Skip leading whitespaces
        while(i < n && s[i] == ' ') {
            i++; // Move to next character until non-space is found
        }

        // 2. Check for optional sign
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1; // Set sign accordingly
            i++; // Move past the sign character
        }

        // 3. Parse digits and build the number
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0'; // Convert char to int

            // 4. Check for overflow/underflow before multiplying by 10
            if(num > (INT_MAX - digit) / 10) {
                // If adding this digit causes overflow, clamp to INT_MAX/INT_MIN
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit; // Add digit to the number
            i++; // Move to next character
        }

        // 5. Apply sign and return result
        return static_cast<int>(num) * sign;
    }
};

/*
Dry Run Example:
----------------
Input: "   -42abc"
Step 1: Skip spaces -> i = 3, s[i] = '-'
Step 2: Found '-', so sign = -1, i = 4
Step 3: s[4] = '4' (digit), num = 0*10+4 = 4, i = 5
        s[5] = '2' (digit), num = 4*10+2 = 42, i = 6
        s[6] = 'a' (not digit), stop parsing
Step 4: Apply sign: -1 * 42 = -42
Output: -42

Input: "4193 with words"
Step 1: No spaces, i = 0
Step 2: No sign, sign = 1
Step 3: s[0] = '4', num = 4
        s[1] = '1', num = 41
        s[2] = '9', num = 419
        s[3] = '3', num = 4193
        s[4] = ' ' (not digit), stop
Output: 4193

Input: "21474836460"
Step 1: No spaces, i = 0
Step 2: No sign, sign = 1
Step 3: Parse digits, num exceeds INT_MAX, so return INT_MAX (2147483647)
Output: 2147483647

Input: "-91283472332"
Step 1: No spaces, i = 0
Step 2: '-', sign = -1, i = 1
Step 3: Parse digits, num exceeds INT_MIN, so return INT_MIN (-2147483648)
Output: -2147483648
*/