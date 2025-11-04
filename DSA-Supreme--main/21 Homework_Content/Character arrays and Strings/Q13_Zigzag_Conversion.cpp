/*
Approach Used in This Code:
---------------------------
- The problem is to write the string in a zigzag pattern on a given number of rows and then read it row by row.
- The code simulates the zigzag traversal by maintaining a vector of strings, one for each row.
- It iterates through the input string, appending each character to the appropriate row.
- The direction (down or up) is toggled whenever the top or bottom row is reached.
- After processing all characters, the rows are concatenated to form the final result.

Steps:
1. If numRows is 1 or greater than or equal to the string length, return the original string (no zigzag needed).
2. Create a vector of empty strings, one for each row.
3. Use a variable to track the current row and a boolean to track the direction (down or up).
4. For each character in the string:
    - Append it to the current row.
    - If at the top or bottom row, reverse the direction.
    - Move to the next row according to the direction.
5. Concatenate all rows to get the final zigzag string.

Time Complexity: O(N), where N is the length of the string (each character is processed once).
Space Complexity: O(N), for storing the rows and the result string.

Dry Run Example:
----------------
Input: s = "PAYPALISHIRING", numRows = 3

Zigzag pattern:
P   A   H   N
A P L S I I G
Y   I   R

Rows after processing:
row 0: "PAHN"
row 1: "APLSIIG"
row 2: "YIR"

Output: "PAHNAPLSIIGYIR"
*/

class Solution { // Solution class for Zigzag Conversion // main logic container
    public:
        string convert(string s, int numRows) { // Converts string s to zigzag pattern // returns final string
            int n = s.size(); // Get length of input string // used for bounds and checks
            if(numRows == 1 || numRows > n){ // If only one row or rows exceed string length // no zigzag needed
                return s; // Return original string // nothing to convert
            }
    
            vector<string> rows(numRows, ""); // Create vector to store each row's string // initialize with empty strings
            int currRow = 0; // Track current row index // starts at first row
            bool goingDown = false; // Direction flag for zigzag // true: moving down, false: up
    
            for(char c: s){ // Loop through each character in input string // process all characters
                rows[currRow] += c; // Add character to current row // build zigzag row by row
    
                // change direction at top and botton
                if(currRow == 0 || currRow == numRows - 1){ // If at first or last row // need to reverse direction
                    goingDown = !goingDown; // Flip direction flag // start moving up or down
                }
    
                currRow += goingDown? 1 : -1; // Move to next row based on direction // increment or decrement row index
            }
    
            string result = ""; // Initialize result string // will store final zigzag string
            for(string &row : rows) result += row; // Concatenate all rows // build final output
    
            return result; // Return the zigzag converted string // final answer
        }
    };