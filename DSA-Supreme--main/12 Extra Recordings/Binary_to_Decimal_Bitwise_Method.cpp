/*
Approach Used:
---------------
- The code converts a binary number (given as an integer, e.g., 1011) to its decimal equivalent using bitwise operations.
- It processes the binary number from least significant bit (rightmost) to most significant bit (leftmost), extracting each bit using bitwise AND, and accumulates its decimal value by multiplying with the corresponding power of 2.

Better/Alternative Approaches (without code):
---------------------------------------------
1. **String Input Approach:**
   - Accept the binary number as a string (e.g., "1011") to avoid confusion with decimal representation.
   - Iterate from right to left, multiplying each character (converted to int) by the corresponding power of 2.
   - This avoids issues with leading zeros and accidental decimal interpretation.

2. **Without pow() Function:**
   - Instead of using `pow(2, i)`, maintain a variable (e.g., `base = 1`) and multiply it by 2 in each iteration for better performance and to avoid floating-point inaccuracies.

3. **Using STL Functions:**
   - In C++11 and above, use `std::stoi` with base 2 to directly convert a binary string to decimal.

4. **Input Validation:**
   - Add checks to ensure the input only contains 0s and 1s.

5. **Bitset Approach:**
   - Use `std::bitset` for fixed-size binary numbers for easy conversion and manipulation.

Improvements Made:
------------------
- Added detailed comments explaining the logic behind each important line.
- Used integer multiplication for powers of 2 instead of `pow()` for better performance and accuracy.
- Added input prompt for user to enter the binary number.
- Added input validation to ensure only binary digits are processed.
- Provided a dry run at the end of the code.

*/

#include <iostream>
#include <string>
using namespace std;

// Function to convert binary string to decimal integer
int binToDecimal(const string& binStr) {
    int ans = 0;         // Stores the final decimal value
    int base = 1;        // Represents the current power of 2 (starts at 2^0)
    // Process the binary string from right to left (least significant bit to most)
    for (int i = binStr.length() - 1; i >= 0; --i) {
        char ch = binStr[i];
        if (ch != '0' && ch != '1') {
            // Invalid character found, not a binary digit
            cout << "Invalid binary digit '" << ch << "' encountered. Aborting.\n";
            return -1;
        }
        int bit = ch - '0'; // Convert character to integer (0 or 1)
        ans += bit * base;  // Add the value of this bit to the answer
        base *= 2;          // Move to the next higher power of 2
    }
    return ans;
}

int main() {
    string binStr;
    cout << "Enter a binary number (e.g., 1011): "; // Prompt user for input
    cin >> binStr;                                  // Read binary number as string

    int decimal = binToDecimal(binStr);             // Convert binary to decimal
    if (decimal != -1) {                            // If conversion was successful
        cout << "Decimal value of binary number " << binStr << " is " << decimal << endl;
    }
    return 0;
}

/*
Dry Run:
--------
Input: binStr = "1011"

Process from right to left:
i = 3, ch = '1', bit = 1, base = 1,   ans = 0 + 1*1   = 1,   base = 2
i = 2, ch = '1', bit = 1, base = 2,   ans = 1 + 1*2   = 3,   base = 4
i = 1, ch = '0', bit = 0, base = 4,   ans = 3 + 0*4   = 3,   base = 8
i = 0, ch = '1', bit = 1, base = 8,   ans = 3 + 1*8   = 11,  base = 16

Output: Decimal value of binary number 1011 is 11
*/